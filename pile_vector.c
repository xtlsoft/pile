#ifndef _PILE_VECTOR_H_
#include "pile_vector.h"
#endif

pile_int_t impl_fn(pile_vector, resize, pile_int_t size)
{
    self->size = size;
    PILE_REALLOC(self->data, size * sizeof(pile_container_t));
    return self->size;
}

pile_int_t impl_fn(pile_vector, push, pile_container_t item)
{
    if (self->end >= self->size)
    {
        self->resize(self, self->end + 1);
    }
    self->data[self->end] = item;
    self->end++;
    return self->end;
}

pile_int_t impl_fn(pile_vector, pop)
{
    if (self->end == self->size)
    {
        self->resize(self, self->size - 1);
    }
    self->end--;
    return self->end;
}

pile_container_t impl_fn(pile_vector, top)
{
    return self->data[self->end - 1];
}

pile_container_t impl_fn(pile_vector, bottom)
{
    return self->data[0];
}

pile_int_t impl_fn(pile_vector, append, pile_vector_ptr_t vec)
{
    pile_int_t new_size = self->end + vec->end;
    if (new_size > self->size)
    {
        self->resize(self, new_size);
    }
    PILE_MEMCPY(self->data + self->end, vec->data,
                vec->end * sizeof(pile_container_t));
    self->end = new_size;
    return self->end;
}

pile_bool_t impl_fn(pile_vector, is_empty)
{
    return (self->end == 0);
}

pile_int_t impl_fn(pile_vector, slice,
                   pile_int_t start, pile_int_t length)
{
    pile_container_ptr_t origin = self->data;
    self->data = (pile_container_ptr_t)
        PILE_MALLOC(length * sizeof(pile_container_t));
    PILE_MEMCPY(self->data, origin + start,
                length * sizeof(pile_container_t));
    self->size -= start;
    self->end = length;
    PILE_FREE(origin);
    return length;
}

pile_int_t impl_fn(pile_vector, insert,
                   pile_int_t pos, pile_container_t val)
{
    if (self->end >= self->size)
    {
        self->resize(self, self->size + 1);
    }
    PILE_MEMCPY(self->data + pos + 1,
                self->data + pos,
                (self->end - pos) * sizeof(pile_container_t));
    self->data[pos] = val;
    self->end++;
    return self->end;
}

impl_construct(pile_vector, pile_int_t size)
{
    self->size = size;
    self->end = 0;
    self->data = (pile_container_ptr_t)
        PILE_MALLOC(size * sizeof(pile_container_t));
    _assign(pile_vector, push);
    _assign(pile_vector, resize);
    _assign(pile_vector, pop);
    _assign(pile_vector, top);
    _assign(pile_vector, bottom);
    _assign(pile_vector, append);
    _assign(pile_vector, is_empty);
    _assign(pile_vector, slice);
    _assign(pile_vector, insert);
}

impl_destruct(pile_vector)
{
    PILE_FREE(self->data);
}