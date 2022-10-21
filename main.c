#include <stdio.h>
#include "my_collections.h"

int main(void)
{
    linkedlist_int32_t my_list = linkedlist_int32_t__create();
    linkedlist_int32_t__add_last(my_list, 2);
    linkedlist_int32_t__add_first(my_list, 1);
    LINKEDLIST_FOREACH(int32_t, my_list, item, printf("%d\n", item));
    tuple_float_person test = { .item1 = 1.2, .item2 = { .age = 5, .name = "Quentin" } };
    printf("%s\n", test.item2.name);
    return 0;
}