#ifndef _PILE_MEMORY_H_
#define _PILE_MEMORY_H_ true

#ifndef PILE_CUSTOM_ALLOC

#ifndef _STDLIB_H_
#define _STDLIB_H_ true
#include "stdlib.h"
#endif

#ifndef _STRING_H_
#define _STRING_H_ true
#include "string.h"
#endif

#define PILE_MALLOC malloc
#define PILE_REALLOC realloc
#define PILE_FREE free
#define PILE_MEMCPY memcpy

#endif

#ifndef PILE_STRCPY
#define PILE_STRCPY strcpy
#endif

#endif
