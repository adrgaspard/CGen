#include <stdio.h>
#include "my_collections.h"

int main(void)
{
    CGen_LinkedList(int32_t) my_list = CGen_New_LinkedList(int32_t);
    CGen_AddLast(int32_t, my_list, 2);
    CGen_AddFirst(int32_t, my_list, 1);
    CGen_ForEach(int32_t, my_list, my_element, 
    {
        printf("- %d\n", *my_element);
    });
    tuple_float_person test = { .item1 = 1.2, .item2 = { .age = 5, .name = "Quentin" } };
    printf("%s\n", test.item2.name);
    return 0;
}