#include <stdio.h>
#include "pile_vector.h"

int main()
{
    printf("compile_successful\r\n");
    new (pile_vector, arr, 0);
    PILE_MAKE_PTR_LITERAL(a, 80);
    PILE_MAKE_PTR_LITERAL(b, 90);
    PILE_MAKE_PTR_LITERAL(c, 20);
    PILE_MAKE_PTR_LITERAL(d, 10);
    PILE_MAKE_PTR_LITERAL(e, 30);
    arr->push(arr, pile_make_container(PILE_TYPE_INT, a));
    call(arr, resize, 10);
    arr->push(arr, pile_make_container(PILE_TYPE_INT, a));
    arr->push(arr, pile_make_container(PILE_TYPE_INT, a));
    arr->push(arr, pile_make_container(PILE_TYPE_INT, b));
    arr->push(arr, pile_make_container(PILE_TYPE_INT, a));
    arr->push(arr, pile_make_container(PILE_TYPE_INT, b));
    arr->push(arr, pile_make_container(PILE_TYPE_INT, c));
    arr->push(arr, pile_make_container(PILE_TYPE_INT, d));
    arr->push(arr, pile_make_container(PILE_TYPE_INT, e));
    PILE_MAKE_PTR_LITERAL_CONTAINER(PILE_TYPE_INT, f, 12);
    call(arr, push, f);
    arr->slice(arr, 1, 3);
    arr->insert(arr, 1, f);
    while (!arr->is_empty(arr))
    {
        printf("%d ", *((int *)arr->top(arr).content));
        call(arr, pop);
    }
    del(arr);
    printf("\r\n");
    return 0;
}