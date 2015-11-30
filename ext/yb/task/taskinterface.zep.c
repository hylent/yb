
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Task_TaskInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Task, TaskInterface, yb, task_taskinterface, yb_task_taskinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Task_TaskInterface, __invoke);

ZEPHIR_DOC_METHOD(Yb_Task_TaskInterface, onReturn);

ZEPHIR_DOC_METHOD(Yb_Task_TaskInterface, onException);
