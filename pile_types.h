#ifndef _PILE_TYPES_H_
#define _PILE_TYPES_H_ true

/* Platform-Related Types : */

#ifndef PILE_PLATFORM_TYPE_INT
#define PILE_PLATFORM_TYPE_INT int
#endif
#ifndef PILE_PLATFORM_TYPE_LONG
#define PILE_PLATFORM_TYPE_LONG long long
#endif
#ifndef PILE_PLATFORM_TYPE_SHORT
#define PILE_PLATFORM_TYPE_SHORT short
#endif
#ifndef PILE_PLATFORM_TYPE_CHAR
#define PILE_PLATFORM_TYPE_CHAR char
#endif
#ifndef PILE_PLATFORM_TYPE_FLOAT
#define PILE_PLATFORM_TYPE_FLOAT float
#endif
#ifndef PILE_PLATFORM_TYPE_DOUBLE
#define PILE_PLATFORM_TYPE_DOUBLE double
#endif
#ifndef PILE_PLATFORM_TYPE_STR
#define PILE_PLATFORM_TYPE_STR const char *
#endif
#ifndef PILE_PLATFORM_TYPE_MUT_STR
#define PILE_PLATFORM_TYPE_MUT_STR char *
#endif
#ifndef PILE_PLATFORM_TYPE_BOOL
#define PILE_PLATFORM_TYPE_BOOL char
#endif

#ifndef true
#define true 1
#define false 0
#endif

typedef PILE_PLATFORM_TYPE_INT pile_int_t;
typedef PILE_PLATFORM_TYPE_LONG pile_long_t;
typedef PILE_PLATFORM_TYPE_SHORT pile_short_t;
typedef PILE_PLATFORM_TYPE_CHAR pile_char_t;
typedef PILE_PLATFORM_TYPE_FLOAT pile_float_t;
typedef PILE_PLATFORM_TYPE_DOUBLE pile_double_t;
typedef PILE_PLATFORM_TYPE_STR pile_str_t;
typedef PILE_PLATFORM_TYPE_MUT_STR pile_mut_str_t;
typedef PILE_PLATFORM_TYPE_BOOL pile_bool_t;

typedef void *pile_any_t;

/* End; */

/* Type Enums : */

#define PILE_TYPE_ENUM_BASE 10

typedef pile_short_t pile_type_t;

#define PILE_TYPE_MODULE (PILE_TYPE_ENUM_BASE + 0)
#define PILE_TYPE_INT (PILE_TYPE_ENUM_BASE + 1)
#define PILE_TYPE_LONG (PILE_TYPE_ENUM_BASE + 2)
#define PILE_TYPE_SHORT (PILE_TYPE_ENUM_BASE + 4)
#define PILE_TYPE_CHAR (PILE_TYPE_ENUM_BASE + 5)
#define PILE_TYPE_FLOAT (PILE_TYPE_ENUM_BASE + 6)
#define PILE_TYPE_DOUBLE (PILE_TYPE_ENUM_BASE + 7)
#define PILE_TYPE_STR (PILE_TYPE_ENUM_BASE + 8)
#define PILE_TYPE_MUT_STR (PILE_TYPE_ENUM_BASE + 9)
#define PILE_TYPE_VECTOR (PILE_TYPE_ENUM_BASE + 10)
#define PILE_TYPE_STRING (PILE_TYPE_ENUM_BASE + 11)

#ifndef _MACRO_CASE_INSENSITIVE
// In order to be compatible with PILE_VALUE_CONTAINER
#define pile_type_module PILE_TYPE_MODULE
#define pile_type_int PILE_TYPE_INT
#define pile_type_long PILE_TYPE_LONG
#define pile_type_short PILE_TYPE_SHORT
#define pile_type_char PILE_TYPE_CHAR
#define pile_type_float PILE_TYPE_FLOAT
#define pile_type_double PILE_TYPE_DOUBLE
#define pile_type_str PILE_TYPE_STR
#define pile_type_mut_str PILE_TYPE_MUT_STR
#define pile_type_vector PILE_TYPE_VECTOR
#define pile_type_string PILE_TYPE_STRING
#endif

/* End; */

/* Pile Containers: */

typedef struct pile_container
{
    void *content;
    pile_type_t type;
    union {
        pile_int_t v_int;
        pile_short_t v_short;
        pile_long_t v_long;
        pile_float_t v_float;
        pile_str_t v_str;
        pile_mut_str_t v_mut_str;
        pile_double_t v_double;
        pile_bool_t v_bool;
        pile_char_t v_char;
    } values;
} pile_container_t;

typedef pile_container_t *pile_container_ptr_t;

#define PILE_MAKE_PTR(type, name, data) \
    type *name = &data

#define PILE_MAKE_PTR_LITERAL(name, data) \
    typeof(data) name##_origin = data;    \
    PILE_MAKE_PTR(typeof(data), name, name##_origin);

#define PILE_MAKE_PTR_LITERAL_CONTAINER(type, name, data) \
    PILE_MAKE_PTR_LITERAL(name##_prototype, data)         \
    pile_container_t name =                               \
        pile_make_container(type, name##_prototype)

#define PILE_VALUE_CONTAINER(v_type, data) \
    {                                      \
        .type = pile_type_##v_type,        \
        .values = {                        \
            .v_##v_type = data,            \
        },                                 \
    }

/* End; */

#include "pile_types.c"

#endif