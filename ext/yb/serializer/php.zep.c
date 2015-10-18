
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Yb_Serializer_Php) {

	ZEPHIR_REGISTER_CLASS(Yb\\Serializer, Php, yb, serializer_php, yb_serializer_php_method_entry, 0);

	zend_class_implements(yb_serializer_php_ce TSRMLS_CC, 1, yb_serializer_serializerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Serializer_Php, serialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 44, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Serializer_Php, unserialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_RETURN_CALL_FUNCTION("unserialize", NULL, 45, str);
	zephir_check_call_status();
	RETURN_MM();

}

