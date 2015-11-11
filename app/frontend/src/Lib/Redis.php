<?php
namespace YbApp\Frontend\Lib;

use Exception;

class Redis
{
    protected $handler;

    public function pipeline()
    {
        $r = [];

        $this->write(['ping']);
        $this->write(['ping']);

        $this->write(['ping']);

        $r[] = $this->read();

        $r[] = $this->read();
        $r[] = $this->read();

        return $r;
    }

    public function __construct($host, $port = 6379, $timeout = 5)
    {
        $handler = fsockopen($host, $port, $en, $es, $timeout);
        if (!$handler) {
            throw new Exception("Cannot open socket");
        }

        if (!stream_set_blocking($handler, 1)) {
            throw new Exception("Cannot set blocking socket");
        }
        /*
        */

        $this->handler = $handler;
    }

    public function __call($method, array $a)
    {
        array_unshift($a, $method);

        $this->write($a);

        return $this->read();
    }

    protected function write($data)
    {
        if (is_array($data)) {
            $line = sprintf("*%d\r\n", count($data));
            if (fwrite($this->handler, $line) === false) {
                throw new Exception("Cannot write");
            }
            foreach ($data as $d) {
                $this->write($d);
            }
            return;
        }

        $data = (string) $data;
        $line = sprintf("$%d\r\n%s\r\n", strlen($data), $data);
        if (fwrite($this->handler, $line) === false) {
            throw new Exception("Cannot write");
        }
    }

    protected function read()
    {
        $line = (string) $this->readLine();

        $c = $line[0];
        $line = (string) substr($line, 1, -2);

        // echo $c, PHP_EOL;

        switch ($c) {
            case '+':
                return $line;

            case '-':
                throw new Exception($line);

            case ':':
                if ($line > PHP_INT_MAX) {
                    return $line;
                }
                return intval($line);

            case '$':
                $l = intval($line);
                if ($l < 0) {
                    return;
                }
                $line = (string) $this->readLine($l + 2);
                if (strlen($line) != $l + 2) {
                    throw new Exception("Invalid bulk string");
                }
                return substr($line, 0, -2);

            case '*':
                $l = intval($line);
                if ($l < 0) {
                    return;
                }
                $a = [];
                while ($l > 0) {
                    $l--;
                    $a[] = $this->read();
                }
                return $a;

            default:
                throw new Exception("Invalid line type: " . $line);
        }
    }

    protected function readLine($len = 0)
    {
        if ($len > 0) {
            $line = stream_get_contents($this->handler, $len);
        } else {
            $line = fgets($this->handler);
        }

        if ($line === false) {
            throw new Exception("Cannot fgets");
        }

        if (!is_string($line)) {
            throw new Exception("Invalid line data type");
        }

        $len = strlen($line);
        if ($line[$len - 2] != "\r" || $line[$len - 1] != "\n") {
            // echo json_encode($line), PHP_EOL;
            // print_R(debug_print_backtrace());
            throw new Exception("Invalid line end");
        }

        return $line;
    }

}