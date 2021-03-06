
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


ZEPHIR_INIT_CLASS(Yb_Logger_LoggerAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Logger, LoggerAbstract, yb, logger_loggerabstract, yb_logger_loggerabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_string(yb_logger_loggerabstract_ce, SL("EMERGENCY"), "emergency" TSRMLS_CC);

	zend_declare_class_constant_string(yb_logger_loggerabstract_ce, SL("ALERT"), "alert" TSRMLS_CC);

	zend_declare_class_constant_string(yb_logger_loggerabstract_ce, SL("CRITICAL"), "critical" TSRMLS_CC);

	zend_declare_class_constant_string(yb_logger_loggerabstract_ce, SL("ERROR"), "error" TSRMLS_CC);

	zend_declare_class_constant_string(yb_logger_loggerabstract_ce, SL("WARNING"), "warning" TSRMLS_CC);

	zend_declare_class_constant_string(yb_logger_loggerabstract_ce, SL("NOTICE"), "notice" TSRMLS_CC);

	zend_declare_class_constant_string(yb_logger_loggerabstract_ce, SL("INFO"), "info" TSRMLS_CC);

	zend_declare_class_constant_string(yb_logger_loggerabstract_ce, SL("DEBUG"), "debug" TSRMLS_CC);

	zend_class_implements(yb_logger_loggerabstract_ce TSRMLS_CC, 1, yb_logger_loggerbackendinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Logger_LoggerAbstract, emergency) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "emergency", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Logger_LoggerAbstract, alert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "alert", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Logger_LoggerAbstract, critical) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "critical", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Logger_LoggerAbstract, error) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "error", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Logger_LoggerAbstract, warning) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "warning", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Logger_LoggerAbstract, notice) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "notice", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Logger_LoggerAbstract, info) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "info", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Logger_LoggerAbstract, debug) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "debug", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

