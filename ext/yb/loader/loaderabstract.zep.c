
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


ZEPHIR_INIT_CLASS(Yb_Loader_LoaderAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Loader, LoaderAbstract, yb, loader_loaderabstract, yb_loader_loaderabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(Yb_Loader_LoaderAbstract, register) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("spl_autoload_register", NULL, 1, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Loader_LoaderAbstract, unregister) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("spl_autoload_unregister", NULL, 2, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Loader_LoaderAbstract, __invoke) {

}
