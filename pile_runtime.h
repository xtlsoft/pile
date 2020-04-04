#ifndef _PILE_RUNTIME_H_
#define _PILE_RUNTIME_H_ true
#include "pile_string.h"

typedef struct pile_module
{
    pile_string_t name;
    void *content;
};

#include "pile_runtime.c"

#endif
