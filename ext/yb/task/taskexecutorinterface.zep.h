
extern zend_class_entry *yb_task_taskexecutorinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Task_TaskExecutorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskexecutorinterface_executetask, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, task, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskexecutorinterface_ontaskreturn, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, task, 0)
	ZEND_ARG_INFO(0, re)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskexecutorinterface_ontaskexception, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, task, 0)
	ZEND_ARG_OBJ_INFO(0, ex, Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_task_taskexecutorinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Task_TaskExecutorInterface, executeTask, arginfo_yb_task_taskexecutorinterface_executetask)
	PHP_ABSTRACT_ME(Yb_Task_TaskExecutorInterface, onTaskReturn, arginfo_yb_task_taskexecutorinterface_ontaskreturn)
	PHP_ABSTRACT_ME(Yb_Task_TaskExecutorInterface, onTaskException, arginfo_yb_task_taskexecutorinterface_ontaskexception)
	PHP_FE_END
};
