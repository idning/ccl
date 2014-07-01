/*
 * file   : test_array.c
 * author : ning
 * date   : 2014-06-30 17:26:37
 */

#include "nc_core.h"
#include "testhelp.h"

rstatus_t
array_check(void *elem, void *data)
{
    int       *pi = elem;

    printf("got pi: %p %d\n", pi, *pi);
    return 0;
}

void
test_array()
{
    struct array       *arr;
    int                 i;
    int                *pi;

    arr = array_create(3, sizeof(int));
    for (i = 0; i < 5; i++) {
        pi = array_push(arr);
        *pi = i;
    }

    for (i = 0; i < 5; i++) {
        pi = array_get(arr, i);
        test_cond("assert_n", i == *pi);
    }
    test_cond("array_n", 5 == array_n(arr));


    array_each(arr, array_check, NULL);
}

int
main()
{
    test_array();
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
