
extern zend_class_entry *yb_serializer_serializerinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Serializer_SerializerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_serializer_serializerinterface_serialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_serializer_serializerinterface_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_serializer_serializerinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Serializer_SerializerInterface, serialize, arginfo_yb_serializer_serializerinterface_serialize)
	PHP_ABSTRACT_ME(Yb_Serializer_SerializerInterface, unserialize, arginfo_yb_serializer_serializerinterface_unserialize)
	PHP_FE_END
};
