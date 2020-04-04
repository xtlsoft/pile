#ifndef _PILE_TYPES_H_
#include "pile_types.h"
#endif

pile_container_t pile_make_container(
    pile_type_t type, pile_any_t data)
{
    pile_container_t rslt;
    rslt.content = data;
    rslt.type = type;
    return rslt;
}