namespace Yb\Image;

abstract class ImageAbstract
{
    protected backend;
    protected properties;

    public function __construct(<ImageBackendAbstract> backend, array properties = null) -> void
    {
        let this->backend = backend;
        let this->properties = properties;
    }

    public function __set(string name, var value) -> void
    {
        let this->properties[name] = value;
    }

    public function __get(string name)
    {
        var value;

        if fetch value, this->properties[name] {
            return value;
        }
    }

    public function __destruct() -> void
    {
        this->backend->destroy(this);
    }
}