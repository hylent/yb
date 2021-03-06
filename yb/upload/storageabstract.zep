namespace Yb\Upload;

use Yb\Std;

abstract class StorageAbstract implements UriGeneratorInterface
{
    const COPY                  = 0;
    const MOVE                  = 1;
    const MOVE_UPLOADED_FILE    = 2;

    protected uriGenerator;

    public function setUriGenerator(<UriGeneratorInterface> uriGenerator) -> void
    {
        let this->uriGenerator = uriGenerator;
    }

    public function getUriGenerator() -> <UriGeneratorInterface>
    {
        return this->uriGenerator;
    }

    abstract public function store(string source, string prefix = "", string extension = "", long flag = 0) -> string;
    abstract public function remove(string uri) -> bool;
    abstract public function exists(string uri) -> bool;

    public function generateUri(string source, string prefix, string extension) -> string
    {
        string uri = "/", uuid;

        if this->uriGenerator {
            return this->uriGenerator->generateUri(source, prefix, extension);
        }

        if prefix->length() > 0 {
            if unlikely ! preg_match("#^(\\w+/)*\\w*$#", prefix) {
                throw new Exception("Invalid prefix: " . prefix);
            }
            let uri .= prefix;
        }

        let uuid = (string) Std::uuid(source . extension);

        let uri .= uuid[0];
        let uri .= uuid[1];
        let uri .= '/';
        let uri .= uuid[2];
        let uri .= uuid[3];
        let uri .= '/';
        let uri .= uuid;

        if extension {
            let uri .= "." . extension;
        }

        return uri;
    }

}
