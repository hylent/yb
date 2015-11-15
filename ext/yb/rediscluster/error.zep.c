
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


ZEPHIR_INIT_CLASS(Yb_RedisCluster_Error) {

	ZEPHIR_REGISTER_CLASS(Yb\\RedisCluster, Error, yb, rediscluster_error, NULL, 0);

	zend_declare_property_null(yb_rediscluster_error_ce, SL("error"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

