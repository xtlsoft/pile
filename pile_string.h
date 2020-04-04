#ifndef _PILE_STRING_H_
#define _PILE_STRING_H_ true
#include "pile_types.h"
#define PILE_CLASS_SHORTCUTS true
#include "pile_class.h"

class(pile_string)
{
    pile_int_t length;
    pile_mut_str_t c_str;

    pile_int_t def_fn(pile_string, reset, pile_str_t str);
    pile_int_t def_fn(pile_string, append, pile_char_t ch);
    pile_int_t def_fn(pile_string, concat, pile_str_t str);

    def_destruct(pile_string);
};

#include "pile_string.c"

#endif