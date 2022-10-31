#include <stdio.h>
#include "my_collections.h"

int main(void)
{
    CGen_SortOptions(myint) intoptions = { ._compare = cgen_compare_int32_desc, ._aim = DURATION_STABILITY, ._location = CURRENT_COLLECTION };
    CGen_SortOptions(string) stroptions = { ._compare = cgen_compare_str_case_insensitive_asc, ._aim = DURATION_STABILITY, ._location = CURRENT_COLLECTION };
    CGen_Array(string) arr = CGen_New_Array(string, 4);
    CGen_ForEach(string, arr, my_element, printf("- %s\n", *my_element));
    printf("-----\n");
    arr->_items[0] = "Bonjour";
    arr->_items[1] = "Oui";
    arr->_items[2] = "ahhahah";
    arr->_items[3] = "mmh pouler...";
    CGen_ForEach(string, arr, my_element, printf("- %s\n", *my_element));
    printf("-----\n");
    CGen_Sort(string, arr, stroptions);
    CGen_ForEach(string, arr, my_element, printf("- %s\n", *my_element));
    printf("-----\n");
    CGen_LinkedList(myint) my_list = CGen_New_LinkedList(myint);
    CGen_AddLast(myint, my_list, 2);
    CGen_AddFirst(myint, my_list, 1);
    CGen_ForEach(myint, my_list, my_element, 
    {
        printf("- %d\n", *my_element);
    });
    printf("-----\n");
    CGen_Sort(myint, my_list, intoptions);
    CGen_ForEach(myint, my_list, my_element, 
    {
        printf("- %d\n", *my_element);
    });
    tuple_float_person test = { .item1 = 1.2, .item2 = { .age = 5, .name = "Quentin" } };
    printf("%s\n", test.item2.name);
    CGen_Clear(myint, CGen_New_Array(myint, 5));
    return 0;
}