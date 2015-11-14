
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yb_Redis_Connection) {

	ZEPHIR_REGISTER_CLASS(Yb\\Redis, Connection, yb, redis_connection, yb_redis_connection_method_entry, 0);

	zend_declare_property_null(yb_redis_connection_ce, SL("handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Redis_Connection, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	long port, timeout;
	zval *host_param = NULL, *port_param = NULL, *timeout_param = NULL, *handler = NULL, *_0, *_1, *_2, *_3, _4, *_5 = NULL;
	zval *host = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &host_param, &port_param, &timeout_param);

	if (!host_param) {
		ZEPHIR_INIT_VAR(host);
		ZVAL_STRING(host, "127.0.0.1", 1);
	} else {
		zephir_get_strval(host, host_param);
	}
	if (!port_param) {
		port = 6379;
	} else {
		port = zephir_get_intval(port_param);
	}
	if (!timeout_param) {
		timeout = 5;
	} else {
		timeout = zephir_get_intval(timeout_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, port);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_NULL(_1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, timeout);
	ZEPHIR_MAKE_REF(_1);
	ZEPHIR_CALL_FUNCTION(&handler, "fsockopen", NULL, 78, host, _0, _1, _2, _3);
	ZEPHIR_UNREF(_1);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_redis_socketexception_ce, "Cannot open socket", "yb/redis/connection.zep", 13);
		return;
	}
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(&_5, "stream_set_blocking", NULL, 81, handler, &_4);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_redis_socketexception_ce, "Cannot set blocking socket", "yb/redis/connection.zep", 17);
		return;
	}
	zephir_update_property_this(this_ptr, SL("handler"), handler TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_Connection, getInternalHandler) {

	

	RETURN_MEMBER(this_ptr, "handler");

}

PHP_METHOD(Yb_Redis_Connection, runCommand) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cmd_param = NULL;
	zval *cmd = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cmd_param);

	zephir_get_arrval(cmd, cmd_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, cmd);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "read", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Redis_Connection, runCommands) {

	HashTable *_1, *_6;
	HashPosition _0, _5;
	zephir_fcall_cache_entry *_3 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *cmds_param = NULL, *index = NULL, *cmd = NULL, *results = NULL, **_2, *_4 = NULL, **_7, *_8$$4 = NULL;
	zval *cmds = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cmds_param);

	zephir_get_arrval(cmds, cmds_param);


	ZEPHIR_INIT_VAR(results);
	array_init(results);
	zephir_is_iterable(cmds, &_1, &_0, 0, 0, "yb/redis/connection.zep", 42);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(cmd, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", &_3, 0, cmd);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_is_iterable(cmds, &_6, &_5, 0, 0, "yb/redis/connection.zep", 46);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(index, _6, _5);
		ZEPHIR_GET_HVALUE(_4, _7);
		ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "read", &_9, 0);
		zephir_check_call_status();
		zephir_array_update_zval(&results, index, &_8$$4, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(results);

}

PHP_METHOD(Yb_Redis_Connection, __destruct) {

	zval *_0, *_1$$3;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
		zephir_fclose(_1$$3 TSRMLS_CC);
	}

}

PHP_METHOD(Yb_Redis_Connection, write) {

	HashTable *_6$$3;
	HashPosition _5$$3;
	zval *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_8 = NULL;
	zval *data, *d = NULL, *s = NULL, _10, _11, *_12, *_13, _0$$3, _1$$3, *_3$$3, *_4$$3, **_7$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "*%d\r\n", 0);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, zephir_fast_count_int(data TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&s, "sprintf", &_2, 1, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
		zephir_fwrite(_3$$3, _4$$3, s TSRMLS_CC);
		if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(_3$$3))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_redis_socketexception_ce, "Cannot write to socket", "yb/redis/connection.zep", 64);
			return;
		}
		zephir_is_iterable(data, &_6$$3, &_5$$3, 0, 0, "yb/redis/connection.zep", 71);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$3, (void**) &_7$$3, &_5$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$3, &_5$$3)
		) {
			ZEPHIR_GET_HVALUE(d, _7$$3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", &_8, 96, d);
			zephir_check_call_status();
		}
		RETURN_MM_NULL();
	}
	zephir_get_strval(_9, data);
	ZEPHIR_CPY_WRT(d, _9);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_STRING(&_10, "$%d\r\n%s\r\n", 0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, zephir_fast_strlen_ev(d));
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", &_2, 1, &_10, &_11, d);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_12);
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	zephir_fwrite(_12, _13, s TSRMLS_CC);
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(_12))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_redis_socketexception_ce, "Cannot write to socket", "yb/redis/connection.zep", 78);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_Connection, read) {

	zval *a = NULL, *_0 = NULL, _3, _4, *_5, *_7$$5, *_8$$7 = NULL, *_9$$7, _11$$7, _12$$7, *_13$$11 = NULL, *_15$$13, *_16$$13, *_17$$13;
	long l = 0;
	char c = 0;
	zval *line = NULL, *_2 = NULL, *_6 = NULL, *_10$$7 = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "readline", &_1, 0);
	zephir_check_call_status();
	zephir_get_strval(_2, _0);
	ZEPHIR_CPY_WRT(line, _2);
	c = ZEPHIR_STRING_OFFSET(line, 0);
	c = c;
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, -2);
	ZEPHIR_INIT_VAR(_5);
	zephir_substr(_5, line, 1 , -2 , 0);
	zephir_get_strval(_6, _5);
	ZEPHIR_CPY_WRT(line, _6);
	do {
		if (c == '+') {
			RETURN_CTOR(line);
		}
		if (c == '-') {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newerror", NULL, 0, line);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (c == ':') {
			ZEPHIR_INIT_VAR(_7$$5);
			ZEPHIR_GET_CONSTANT(_7$$5, "PHP_INT_MAX");
			if (ZEPHIR_GT(line, _7$$5)) {
				RETURN_CTOR(line);
			}
			RETURN_MM_LONG(zephir_get_intval(line));
		}
		if (c == '$') {
			l = zephir_get_intval(line);
			if (l < 0) {
				RETURN_MM_NULL();
			}
			ZEPHIR_INIT_VAR(_9$$7);
			ZVAL_LONG(_9$$7, (l + 2));
			ZEPHIR_CALL_METHOD(&_8$$7, this_ptr, "readline", &_1, 0, _9$$7);
			zephir_check_call_status();
			zephir_get_strval(_10$$7, _8$$7);
			ZEPHIR_CPY_WRT(line, _10$$7);
			ZEPHIR_SINIT_VAR(_11$$7);
			ZVAL_LONG(&_11$$7, 0);
			ZEPHIR_SINIT_VAR(_12$$7);
			ZVAL_LONG(&_12$$7, -2);
			zephir_substr(return_value, line, 0 , -2 , 0);
			RETURN_MM();
		}
		if (c == '*') {
			l = zephir_get_intval(line);
			if (l < 0) {
				RETURN_MM_NULL();
			}
			ZEPHIR_INIT_VAR(a);
			array_init(a);
			while (1) {
				if (l <= 0) {
					break;
				}
				l--;
				ZEPHIR_CALL_METHOD(&_13$$11, this_ptr, "read", &_14, 97);
				zephir_check_call_status();
				zephir_array_append(&a, _13$$11, PH_SEPARATE, "yb/redis/connection.zep", 126);
			}
			RETURN_CCTOR(a);
		}
		ZEPHIR_INIT_VAR(_15$$13);
		object_init_ex(_15$$13, yb_redis_exception_ce);
		ZEPHIR_INIT_VAR(_16$$13);
		zephir_json_encode(_16$$13, &(_16$$13), line, 0  TSRMLS_CC);
		ZEPHIR_INIT_VAR(_17$$13);
		ZEPHIR_CONCAT_SV(_17$$13, "Invalid line type: ", _16$$13);
		ZEPHIR_CALL_METHOD(NULL, _15$$13, "__construct", NULL, 2, _17$$13);
		zephir_check_call_status();
		zephir_throw_exception_debug(_15$$13, "yb/redis/connection.zep", 131 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_Connection, readLine) {

	zend_bool _5;
	unsigned char _4, _6;
	zval *s = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *len_param = NULL, *line = NULL, *_0$$3, _1$$3, *_2$$4, *_7$$6, *_8$$6, *_9$$6;
	long len;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len_param);

	if (!len_param) {
		len = 0;
	} else {
		len = zephir_get_intval(len_param);
	}


	if (len > 0) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, len);
		ZEPHIR_CALL_FUNCTION(&line, "stream_get_contents", NULL, 98, _0$$3, &_1$$3);
		zephir_check_call_status();
	} else {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&line, "fgets", NULL, 99, _2$$4);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(line)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_redis_socketexception_ce, "Cannot read from socket", "yb/redis/connection.zep", 147);
		return;
	}
	zephir_get_strval(_3, line);
	ZEPHIR_CPY_WRT(s, _3);
	len = zephir_fast_strlen_ev(s);
	_4 = ZEPHIR_STRING_OFFSET(s, (len - 2));
	_5 = _4 != '\r';
	if (!(_5)) {
		_6 = ZEPHIR_STRING_OFFSET(s, (len - 1));
		_5 = _6 != '\n';
	}
	if (unlikely(_5)) {
		ZEPHIR_INIT_VAR(_7$$6);
		object_init_ex(_7$$6, yb_redis_exception_ce);
		ZEPHIR_INIT_VAR(_8$$6);
		zephir_json_encode(_8$$6, &(_8$$6), line, 0  TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9$$6);
		ZEPHIR_CONCAT_SV(_9$$6, "Invalid line end: ", _8$$6);
		ZEPHIR_CALL_METHOD(NULL, _7$$6, "__construct", NULL, 2, _9$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$6, "yb/redis/connection.zep", 154 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Yb_Redis_Connection, newError) {

	unsigned char _2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *error_param = NULL, *m = NULL, *e = NULL, *_0, _1, *_3$$4, *_4$$4, *_5$$4, *_6$$5, *_7$$5, *_8$$5;
	zval *error = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &error_param);

	zephir_get_strval(error, error_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "#^(MOVED|ASK) (\\d+) ([\\d\\.]+):(\\d+)$#", 0);
	zephir_preg_match(_0, &_1, error, m, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_0)) {
		_2$$3 = ZEPHIR_STRING_OFFSET(error, 0);
		do {
			if (_2$$3 == 'M') {
				ZEPHIR_INIT_VAR(e);
				object_init_ex(e, yb_redis_errormoved_ce);
				if (zephir_has_constructor(e TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, e, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				zephir_update_property_zval(e, SL("error"), error TSRMLS_CC);
				zephir_array_fetch_long(&_3$$4, m, 2, PH_NOISY | PH_READONLY, "yb/redis/connection.zep", 169 TSRMLS_CC);
				zephir_update_property_zval(e, SL("slot"), _3$$4 TSRMLS_CC);
				zephir_array_fetch_long(&_4$$4, m, 3, PH_NOISY | PH_READONLY, "yb/redis/connection.zep", 170 TSRMLS_CC);
				zephir_update_property_zval(e, SL("host"), _4$$4 TSRMLS_CC);
				zephir_array_fetch_long(&_5$$4, m, 4, PH_NOISY | PH_READONLY, "yb/redis/connection.zep", 171 TSRMLS_CC);
				zephir_update_property_zval(e, SL("port"), _5$$4 TSRMLS_CC);
				RETURN_CCTOR(e);
			}
			if (_2$$3 == 'A') {
				ZEPHIR_INIT_NVAR(e);
				object_init_ex(e, yb_redis_errorask_ce);
				if (zephir_has_constructor(e TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, e, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				zephir_update_property_zval(e, SL("error"), error TSRMLS_CC);
				zephir_array_fetch_long(&_6$$5, m, 2, PH_NOISY | PH_READONLY, "yb/redis/connection.zep", 177 TSRMLS_CC);
				zephir_update_property_zval(e, SL("slot"), _6$$5 TSRMLS_CC);
				zephir_array_fetch_long(&_7$$5, m, 3, PH_NOISY | PH_READONLY, "yb/redis/connection.zep", 178 TSRMLS_CC);
				zephir_update_property_zval(e, SL("host"), _7$$5 TSRMLS_CC);
				zephir_array_fetch_long(&_8$$5, m, 4, PH_NOISY | PH_READONLY, "yb/redis/connection.zep", 179 TSRMLS_CC);
				zephir_update_property_zval(e, SL("port"), _8$$5 TSRMLS_CC);
				RETURN_CCTOR(e);
			}
		} while(0);

	}
	ZEPHIR_INIT_NVAR(e);
	object_init_ex(e, yb_redis_error_ce);
	if (zephir_has_constructor(e TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, e, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(e, SL("error"), error TSRMLS_CC);
	RETURN_CCTOR(e);

}

