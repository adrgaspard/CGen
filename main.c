#include <stdio.h>
#include "my_collections.h"

int main(void)
{
    CGen_SortOptions(int32_t) intoptions = { .compare = CGen_Comparators.compare_int32_desc, .aim = DURATION_STABILITY, .location = CURRENT_COLLECTION };
    CGen_SortOptions(string) stroptions = { .compare = CGen_Comparators.compare_str_case_insensitive_asc, .aim = DURATION_STABILITY, .location = CURRENT_COLLECTION };
    CGen_Array(string) arr = CGen_New_Array(string, 4);
    CGen_ForEach(string, arr, my_element, printf("- %s\n", *my_element));
    printf("-----\n");
    arr->items[0] = "Bonjour";
    arr->items[1] = "Oui";
    arr->items[2] = "ahhahah";
    arr->items[3] = "mmh pouler...";
    CGen_ForEach(string, arr, my_element, printf("- %s\n", *my_element));
    printf("-----\n");
    CGen_Sort(string, arr, stroptions);
    CGen_ForEach(string, arr, my_element, printf("- %s\n", *my_element));
    printf("-----\n");
    CGen_LinkedList(int32_t) my_list = CGen_New_LinkedList(int32_t);
    CGen_AddLast(int32_t, my_list, 2);
    CGen_AddFirst(int32_t, my_list, 1);
    CGen_ForEach(int32_t, my_list, my_element, 
    {
        printf("- %d\n", *my_element);
    });
    printf("-----\n");
    CGen_Sort(int32_t, my_list, intoptions);
    CGen_ForEach(int32_t, my_list, my_element, 
    {
        printf("- %d\n", *my_element);
    });
    tuple_float_person test = { .item1 = 1.2, .item2 = { .age = 5, .name = "Quentin" } };
    printf("%s\n", test.item2.name);
    CGen_Clear(int32_t, CGen_New_Array(int32_t, 5));
    return 0;
}