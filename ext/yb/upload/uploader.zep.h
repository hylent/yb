
extern zend_class_entry *yb_upload_uploader_ce;

ZEPHIR_INIT_CLASS(Yb_Upload_Uploader);

PHP_METHOD(Yb_Upload_Uploader, __construct);
PHP_METHOD(Yb_Upload_Uploader, setStorage);
PHP_METHOD(Yb_Upload_Uploader, getStorage);
PHP_METHOD(Yb_Upload_Uploader, newUploadedFile);
PHP_METHOD(Yb_Upload_Uploader, saveUploadedFile);
PHP_METHOD(Yb_Upload_Uploader, pick);
PHP_METHOD(Yb_Upload_Uploader, pickArray);
PHP_METHOD(Yb_Upload_Uploader, getImageExtension);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_uploader___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, validExtensions)
	ZEND_ARG_INFO(0, validImageExtensions)
	ZEND_ARG_INFO(0, maxSize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_uploader_setstorage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, Yb\\Upload\\StorageAbstract, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_uploader_saveuploadedfile, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, uploadedFile, Yb\\Upload\\UploadedFile, 0)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, keep)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_uploader_pick, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_uploader_pickarray, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_uploader_getimageextension, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_upload_uploader_method_entry) {
	PHP_ME(Yb_Upload_Uploader, __construct, arginfo_yb_upload_uploader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Upload_Uploader, setStorage, arginfo_yb_upload_uploader_setstorage, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Upload_Uploader, getStorage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Upload_Uploader, newUploadedFile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Upload_Uploader, saveUploadedFile, arginfo_yb_upload_uploader_saveuploadedfile, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Upload_Uploader, pick, arginfo_yb_upload_uploader_pick, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Upload_Uploader, pickArray, arginfo_yb_upload_uploader_pickarray, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Upload_Uploader, getImageExtension, arginfo_yb_upload_uploader_getimageextension, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
