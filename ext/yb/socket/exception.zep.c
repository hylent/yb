
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


ZEPHIR_INIT_CLASS(Yb_Socket_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Socket, Exception, yb, socket_exception, yb_exception_ce, NULL, 0);

	return SUCCESS;

}

