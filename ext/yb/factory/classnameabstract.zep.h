
extern zend_class_entry *yb_factory_classnameabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Factory_ClassNameAbstract);

PHP_METHOD(Yb_Factory_ClassNameAbstract, __isset);
PHP_METHOD(Yb_Factory_ClassNameAbstract, __get);
PHP_METHOD(Yb_Factory_ClassNameAbstract, setArgs);
PHP_METHOD(Yb_Factory_ClassNameAbstract, setArgArray);
PHP_METHOD(Yb_Factory_ClassNameAbstract, getArgArray);
PHP_METHOD(Yb_Factory_ClassNameAbstract, getClassName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_classnameabstract___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_classnameabstract___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_classnameabstract_setargarray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_classnameabstract_getclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_factory_classnameabstract_method_entry) {
	PHP_ME(Yb_Factory_ClassNameAbstract, __isset, arginfo_yb_factory_classnameabstract___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_ClassNameAbstract, __get, arginfo_yb_factory_classnameabstract___get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_ClassNameAbstract, setArgs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_ClassNameAbstract, setArgArray, arginfo_yb_factory_classnameabstract_setargarray, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_ClassNameAbstract, getArgArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_ClassNameAbstract, getClassName, arginfo_yb_factory_classnameabstract_getclassname, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
