
extern zend_class_entry *yb_db_oci8_ce;

ZEPHIR_INIT_CLASS(Yb_Db_Oci8);

PHP_METHOD(Yb_Db_Oci8, __construct);
PHP_METHOD(Yb_Db_Oci8, getInternalHandler);
PHP_METHOD(Yb_Db_Oci8, quote);
PHP_METHOD(Yb_Db_Oci8, query);
PHP_METHOD(Yb_Db_Oci8, paginationSql);
PHP_METHOD(Yb_Db_Oci8, randomOrderSql);
PHP_METHOD(Yb_Db_Oci8, tryToBegin);
PHP_METHOD(Yb_Db_Oci8, tryToCommit);
PHP_METHOD(Yb_Db_Oci8, tryToRollback);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, passwd)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8_paginationsql, 0, 0, 3)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_db_oci8_method_entry) {
	PHP_ME(Yb_Db_Oci8, __construct, arginfo_yb_db_oci8___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Db_Oci8, getInternalHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, quote, arginfo_yb_db_oci8_quote, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, query, arginfo_yb_db_oci8_query, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, paginationSql, arginfo_yb_db_oci8_paginationsql, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, randomOrderSql, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, tryToBegin, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_Oci8, tryToCommit, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_Oci8, tryToRollback, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
