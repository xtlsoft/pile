#ifndef _PILE_CLASS_H_
#define _PILE_CLASS_H_ true

#ifdef __cplusplus
extern "C"
{
#endif

#include "pile_memory.h"
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

#define PILE_CLASS(CLASS_NAME)                  \
    typedef struct CLASS_NAME CLASS_NAME##_t;   \
    typedef CLASS_NAME##_t *CLASS_NAME##_ptr_t; \
    struct CLASS_NAME

#define PILE_RENEW(CLASS_NAME, VARIABLE_NAME, args...)           \
    VARIABLE_NAME =                                              \
        (CLASS_NAME##_ptr_t)PILE_MALLOC(sizeof(CLASS_NAME##_t)); \
    VARIABLE_NAME->destruct = _class_##CLASS_NAME##_destruct;    \
    _class_##CLASS_NAME##_construct(VARIABLE_NAME, ##args)

#define PILE_NEW(CLASS_NAME, VARIABLE_NAME, args...) \
    CLASS_NAME##_ptr_t VARIABLE_NAME;                \
    PILE_RENEW(CLASS_NAME, VARIABLE_NAME, ##args)

#define PILE_NEW_INDIRECT(CLASS_NAME, VARIABLE_NAME, args...) \
    CLASS_NAME##_t VARIABLE_NAME##_prototype;                 \
    CLASS_NAME##_ptr_t VARIABLE_NAME =                        \
        &VARIABLE_NAME##_prototype;                           \
    _class_##CLASS_NAME##_construct(VARIABLE_NAME, ##args)

#define PILE_DEL(VARIABLE_NAME)             \
    VARIABLE_NAME->destruct(VARIABLE_NAME); \
    PILE_FREE(VARIABLE_NAME)

#define PILE_CLASS_CONSTRUCTOR(CLASS_NAME, args...) \
    void _class_##CLASS_NAME##_construct(           \
        CLASS_NAME##_ptr_t self, ##args)

#define PILE_CLASS_METHOD(CLASS_NAME, NAME, args...) \
    _class_##CLASS_NAME##_##NAME(                    \
        CLASS_NAME##_ptr_t self, ##args)

#define PILE_ASSIGN_METHOD(CLASS_NAME, NAME) \
    self->NAME = _class_##CLASS_NAME##_##NAME;

#define PILE_DEFINE_METHOD(CLASS_NAME, NAME, args...) \
    (*NAME)(CLASS_NAME##_ptr_t self, ##args)

#define PILE_DEFINE_DESTRUCT(CLASS_NAME) \
    void (*destruct)(CLASS_NAME##_ptr_t self)

#define PILE_CLASS_DESTRUCTOR(CLASS_NAME, args...) \
    void _class_##CLASS_NAME##_destruct(           \
        CLASS_NAME##_ptr_t self, ##args)

#define PILE_CLASS_DESTRUCTOR_DEFAULT(CLASS_NAME)   \
    void _class_##CLASS_NAME##_destruct(void *self) \
    {                                               \
        return;                                     \
    }

#define PILE_CALL(VARIABLE_NAME, METHOD_NAME, args...) \
    VARIABLE_NAME->METHOD_NAME(VARIABLE_NAME, ##args)

#ifdef PILE_CLASS_SHORTCUTS

#define class PILE_CLASS
#define new PILE_NEW
#define del PILE_DEL
#define impl_fn PILE_CLASS_METHOD
#define impl_construct PILE_CLASS_CONSTRUCTOR
#define impl_destruct PILE_CLASS_DESTRUCTOR
#define impl_default_destruct PILE_CLASS_DESTRUCTOR_DEFAULT
#define _assign PILE_ASSIGN_METHOD
#define def_fn PILE_DEFINE_METHOD
#define def_destruct PILE_DEFINE_DESTRUCT
#define call PILE_CALL

#endif

#endif

#ifdef __cplusplus
}
#endif