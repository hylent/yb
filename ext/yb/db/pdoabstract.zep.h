
extern zend_class_entry *yb_db_pdoabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Db_PdoAbstract);

PHP_METHOD(Yb_Db_PdoAbstract, __construct);
PHP_METHOD(Yb_Db_PdoAbstract, getInternalHandler);
PHP_METHOD(Yb_Db_PdoAbstract, quote);
PHP_METHOD(Yb_Db_PdoAbstract, query);
PHP_METHOD(Yb_Db_PdoAbstract, tryToBegin);
PHP_METHOD(Yb_Db_PdoAbstract, tryToCommit);
PHP_METHOD(Yb_Db_PdoAbstract, tryToRollback);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_pdoabstract_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_pdoabstract_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_db_pdoabstract_method_entry) {
	PHP_ME(Yb_Db_PdoAbstract, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Db_PdoAbstract, getInternalHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_PdoAbstract, quote, arginfo_yb_db_pdoabstract_quote, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_PdoAbstract, query, arginfo_yb_db_pdoabstract_query, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_PdoAbstract, tryToBegin, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_PdoAbstract, tryToCommit, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_PdoAbstract, tryToRollback, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
