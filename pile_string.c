#ifndef _PILE_STRING_H_
#include "pile_string.h"
#endif

pile_int_t impl_fn(pile_string, reset, pile_str_t str)
{
    self->c_str = PILE_MALLOC(strlen(str));
    PILE_STRCPY(self->c_str, str);
    self->length = strlen(str);
    return self->length;
}

impl_construct(pile_string, pile_str_t str)
{
    _assign(pile_string, reset);
    self->reset(self, str);
}

impl_destruct(pile_string)
{
    PILE_FREE(self->c_str);

    _assign(pile_string, reset);
}