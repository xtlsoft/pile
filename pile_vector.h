#ifndef _PILE_VECTOR_H_
#define _PILE_VECTOR_H_ true
#include "pile_types.h"
#define PILE_CLASS_SHORTCUTS true
#include "pile_class.h"
#include "pile_memory.h"
#pragma GCC diagnostic ignored "-Wunused-result"

class(pile_vector)
{
    pile_int_t size;
    pile_int_t end;
    pile_container_ptr_t data;
    pile_type_t type;

    pile_int_t def_fn(pile_vector, resize, pile_int_t size);
    pile_int_t def_fn(pile_vector, push, pile_container_t item);
    pile_int_t def_fn(pile_vector, append, pile_vector_ptr_t vec);
    pile_int_t def_fn(pile_vector, pop);
    pile_container_t def_fn(pile_vector, top);
    pile_container_t def_fn(pile_vector, bottom);
    pile_bool_t def_fn(pile_vector, is_empty);
    pile_int_t def_fn(pile_vector, slice,
                      pile_int_t start, pile_int_t length);
    pile_int_t def_fn(pile_vector, insert,
                      pile_int_t pos, pile_container_t val);

    def_destruct(pile_vector);
};

#include "pile_vector.c"

#endif