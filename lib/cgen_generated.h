#ifndef __CGEN_H__
#define __CGEN_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Global types part */

typedef enum sort_aim
{
    DURATION_STABILITY = 1,
    MEMORY_USAGE = 2
} sort_aim;
typedef enum sort_location
{
    CURRENT_COLLECTION = 1,
    NEW_COLLECTION = 2
} sort_location;
typedef enum enumerable_implementation
{
    ARRAY_T = 1,
    LINKEDLIST_T = 2,
    LIST_T = 4,
    COLLECTION_I = LINKEDLIST_T | LIST_T,
    ENUMERABLE_I = COLLECTION_I | ARRAY_T
} enumerable_implementation;


/* Generics interfaces part */

#define IENUMERABLE_INTERFACE_BODY(type)                                                                                                                      \
    enumerable_implementation enumerable_code;

#define ICOLLECTION_INTERFACE_BODY(type)                                                                                                                      \
    IENUMERABLE_INTERFACE_BODY(type)                                                                                                                          \
    int64_t count;

/* Compile-time type-safety validation macros */

#define __CGEN_IENUMERABLE_COMPILE_VAL__(obj) (obj)->enumerable_code
#define __CGEN_ICOLLECTION_COMPILE_VAL__(obj) __CGEN_IENUMERABLE_COMPILE_VAL__(obj) && (obj)->count

/* Interface descriptors and lib types descriptors macros */

#define CGen_SortOptions(type) sort_##type##_options
#define CGen_Enumerator(type) enumerator_##type
#define CGen_IEnumerable(type) i_enumerable_##type
#define CGen_ICollection(type) i_collection_##type

/* Polymorphism verification macros */

#define CGen_Is_IEnumerable(obj) (obj)->enumerable_code & ENUMERABLE_I
#define CGen_Is_ICollection(obj) (obj)->enumerable_code & COLLECTION_I

/* Enumerable interface functions macros */

#define CGen_Finalize(type, enumerable)                        \
    cgen_finalize_##type((i_enumerable_##type *)(enumerable)); \
    __CGEN_IENUMERABLE_COMPILE_VAL__(*(enumerable))
#define CGen_GetEnumerator(type, enumerable)                       \
    cgen_get_enumerator_##type((i_enumerable_##type)(enumerable)); \
    __CGEN_IENUMERABLE_COMPILE_VAL__(enumerable)
#define CGen_Clone(type, enumerable)                      \
    cgen_clone_##type((i_enumerable_##type)(enumerable)); \
    __CGEN_IENUMERABLE_COMPILE_VAL__(enumerable)
#define CGen_Sort(type, enumerable, options)                      \
    cgen_sort_##type((i_enumerable_##type)(enumerable), options); \
    __CGEN_IENUMERABLE_COMPILE_VAL__(enumerable)

/* Collection interface functions macros */

#define CGen_Clear(type, collection)                      \
    cgen_clear_##type((i_collection_##type)(collection)); \
    __CGEN_ICOLLECTION_COMPILE_VAL__(collection)

/* Enumerables types descriptors, constructors and functions macros */

#define CGen_Array(type) array_##type
#define CGen_New_Array(type) cgen_array_##type##__create()

#define CGen_LinkedList(type) linkedlist_##type
#define CGen_New_LinkedList(type) cgen_linkedlist_##type##__create()
#define CGen_AddFirst(type, list, content) cgen_linkedlist_##type##__add_first(list, content)
#define CGen_AddLast(type, list, content) cgen_linkedlist_##type##__add_last(list, content)
#define CGen_RemoveFirst(type, list) cgen_linkedlist_##type##__remove_first(list)
#define CGen_RemoveLast(type, list) cgen_linkedlist_##type##__remove_last(list)

#define CGen_Include_Generics_Abstraction(type)                                                                                                               \
typedef struct sort_##type##_options                                                                                                                          \
{                                                                                                                                                             \
    int32_t (*compare)(type x, type y);                                                                                                                       \
    sort_aim aim;                                                                                                                                             \
    sort_location location;                                                                                                                                   \
} sort_##type##_options;                                                                                                                                      \
typedef struct indexed_##type##_data                                                                                                                          \
{                                                                                                                                                             \
    type *data;                                                                                                                                               \
    uint64_t count;                                                                                                                                           \
    uint64_t index;                                                                                                                                           \
} indexed_##type##_data;                                                                                                                                      \
typedef struct linked_##type##_data                                                                                                                           \
{                                                                                                                                                             \
    struct linkednode_##type##_struct *first;                                                                                                                 \
    struct linkednode_##type##_struct *node;                                                                                                                  \
} linked_##type##_data;                                                                                                                                       \
typedef struct enumerator_##type                                                                                                                              \
{                                                                                                                                                             \
    type *current;                                                                                                                                            \
    void (*move_next)(struct enumerator_##type *enumerator);                                                                                                  \
    void (*reset)(struct enumerator_##type *enumerator);                                                                                                      \
    union                                                                                                                                                     \
    {                                                                                                                                                         \
        indexed_##type##_data indexed;                                                                                                                        \
        linked_##type##_data linked;                                                                                                                          \
    };                                                                                                                                                        \
} enumerator_##type;                                                                                                                                          \
typedef struct i_enumerable_##type##_struct                                                                                                                   \
{                                                                                                                                                             \
    IENUMERABLE_INTERFACE_BODY(type)                                                                                                                          \
} * i_enumerable_##type;                                                                                                                                      \
typedef struct i_collection_##type##_struct                                                                                                                   \
{                                                                                                                                                             \
    IENUMERABLE_INTERFACE_BODY(type)                                                                                                                          \
} * i_collection_##type;                                                                                                                                      \
typedef struct array_##type##_struct                                                                                                                          \
{                                                                                                                                                             \
    IENUMERABLE_INTERFACE_BODY(type)                                                                                                                          \
    type *items;                                                                                                                                              \
    int64_t length;                                                                                                                                           \
} * array_##type;                                                                                                                                             \
typedef struct list_##type##_struct                                                                                                                           \
{                                                                                                                                                             \
    IENUMERABLE_INTERFACE_BODY(type)                                                                                                                          \
    type *items;                                                                                                                                              \
    int64_t length;                                                                                                                                           \
    int64_t capacity;                                                                                                                                         \
} * list_##type;                                                                                                                                              \
typedef struct linkednode_##type##_struct                                                                                                                     \
{                                                                                                                                                             \
    struct linkednode_##type##_struct *previous;                                                                                                              \
    struct linkednode_##type##_struct *next;                                                                                                                  \
    type content;                                                                                                                                             \
} * linkednode_##type;                                                                                                                                        \
typedef struct linkedlist_##type##_struct                                                                                                                     \
{                                                                                                                                                             \
    ICOLLECTION_INTERFACE_BODY(type)                                                                                                                          \
    linkednode_##type first;                                                                                                                                  \
    linkednode_##type last;                                                                                                                                   \
} * linkedlist_##type;                                                                                                                                        \
                                                                                                                                                              \
/* Enumerable interface functions */                                                                                                                          \
void cgen_finalize_##type(CGen_IEnumerable(type) * enumerable);                                                                                               \
CGen_Enumerator(type) cgen_get_enumerator_##type(CGen_IEnumerable(type) enumerable);                                                                          \
CGen_IEnumerable(type) cgen_clone_##type(CGen_IEnumerable(type) enumerable);                                                                                  \
CGen_IEnumerable(type) cgen_sort_##type(CGen_IEnumerable(type) enumerable, CGen_SortOptions(type) options);                                                   \
                                                                                                                                                              \
/* Collection interface functions */                                                                                                                          \
void cgen_clear_##type(CGen_ICollection(type) collection);                                                                                                    \
                                                                                                                                                              \
/* Array functions */                                                                                                                                         \
CGen_Array(type) cgen_array_##type##__create(int64_t length);                                                                                                 \
                                                                                                                                                              \
/* Linked list functions */                                                                                                                                   \
CGen_LinkedList(type) cgen_linkedlist_##type##__create();                                                                                                     \
void cgen_linkedlist_##type##__add_first(CGen_LinkedList(type) list, type content);                                                                           \
void cgen_linkedlist_##type##__add_last(CGen_LinkedList(type) list, type content);                                                                            \
void cgen_linkedlist_##type##__remove_first(CGen_LinkedList(type) list);                                                                                      \
void cgen_linkedlist_##type##__remove_last(CGen_LinkedList(type) list);                                                                                       \


#define CGen_Include_Generics_Implementation(type)                                                                                                            \
/* Private core sort functions */                                                                                                                             \
static void __cgen_##type##__merge_sort__(type *_array, type *_tmp, int64_t _start, int64_t _end, int32_t (*_compare)(type _x, type _y));                     \
static int64_t __cgen_##type##__partition__(type *_array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y));                                \
static void __cgen_##type##__quick_sort__(type *_array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y));                                  \
static void __cgen_##type##__merge_sort__(type *_array, type *_tmp, int64_t _start, int64_t _end, int32_t (*_compare)(type _x, type _y))                      \
{                                                                                                                                                             \
    int64_t _middle, _i, _j, _k;                                                                                                                              \
    if (_end <= _start)                                                                                                                                       \
    {                                                                                                                                                         \
        return;                                                                                                                                               \
    }                                                                                                                                                         \
    _middle = (_start + _end) / 2;                                                                                                                            \
    __cgen_##type##__merge_sort__(_array, _tmp, _start, _middle, _compare);                                                                                   \
    __cgen_##type##__merge_sort__(_array, _tmp, _middle + 1, _end, _compare);                                                                                 \
    _i = _start;                                                                                                                                              \
    _j = _middle + 1;                                                                                                                                         \
    for (_k = _start; _k <= _end; _k++)                                                                                                                       \
    {                                                                                                                                                         \
        if (_i > _middle)                                                                                                                                     \
        {                                                                                                                                                     \
            _tmp[_k] = _array[_j];                                                                                                                            \
            _j++;                                                                                                                                             \
        }                                                                                                                                                     \
        else if (_j > _end)                                                                                                                                   \
        {                                                                                                                                                     \
            _tmp[_k] = _array[_i];                                                                                                                            \
            _i++;                                                                                                                                             \
        }                                                                                                                                                     \
        else if (_compare(_array[_i], _array[_j]) < 0)                                                                                                        \
        {                                                                                                                                                     \
            _tmp[_k] = _array[_i];                                                                                                                            \
            _i++;                                                                                                                                             \
        }                                                                                                                                                     \
        else                                                                                                                                                  \
        {                                                                                                                                                     \
            _tmp[_k] = _array[_j];                                                                                                                            \
            _j++;                                                                                                                                             \
        }                                                                                                                                                     \
    }                                                                                                                                                         \
    for (_k = _start; _k <= _end; _k++)                                                                                                                       \
    {                                                                                                                                                         \
        _array[_k] = _tmp[_k];                                                                                                                                \
    }                                                                                                                                                         \
}                                                                                                                                                             \
static int64_t __cgen_##type##__partition__(type *_array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y))                                 \
{                                                                                                                                                             \
    type _pivot, _tmp;                                                                                                                                        \
    int64_t _i, _j;                                                                                                                                           \
    _i = _low;                                                                                                                                                \
    _pivot = _array[_high];                                                                                                                                   \
    for (_j = _low; _j < _high; _j++)                                                                                                                         \
    {                                                                                                                                                         \
        if (_compare(_array[_j], _pivot) <= 0)                                                                                                                \
        {                                                                                                                                                     \
            _tmp = _array[_i];                                                                                                                                \
            _array[_i] = _array[_j];                                                                                                                          \
            _array[_j] = _tmp;                                                                                                                                \
            _i++;                                                                                                                                             \
        }                                                                                                                                                     \
    }                                                                                                                                                         \
    _tmp = _array[_i];                                                                                                                                        \
    _array[_i] = _array[_high];                                                                                                                               \
    _array[_high] = _tmp;                                                                                                                                     \
    return _i;                                                                                                                                                \
}                                                                                                                                                             \
static void __cgen_##type##__quick_sort__(type *_array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y))                                   \
{                                                                                                                                                             \
    int64_t _pivot_index;                                                                                                                                     \
    if (_low < _high)                                                                                                                                         \
    {                                                                                                                                                         \
        _pivot_index = __cgen_##type##__partition__(_array, _low, _high, _compare);                                                                           \
        __cgen_##type##__quick_sort__(_array, _low, _pivot_index - 1, _compare);                                                                              \
        __cgen_##type##__quick_sort__(_array, _pivot_index + 1, _high, _compare);                                                                             \
    }                                                                                                                                                         \
}                                                                                                                                                             \
                                                                                                                                                              \
/* Private enumerator utils functions */                                                                                                                      \
static void __cgen_##type##__move_next_indexed__(enumerator_##type *enumerator)                                                                               \
{                                                                                                                                                             \
    if (enumerator->indexed.index >= enumerator->indexed.count)                                                                                               \
    {                                                                                                                                                         \
        enumerator->current = NULL;                                                                                                                           \
    }                                                                                                                                                         \
    else                                                                                                                                                      \
    {                                                                                                                                                         \
        enumerator->indexed.index++;                                                                                                                          \
        enumerator->current = &(enumerator->indexed.data[enumerator->indexed.index]);                                                                         \
    }                                                                                                                                                         \
}                                                                                                                                                             \
static void __cgen_##type##__move_next_linked__(enumerator_##type *enumerator)                                                                                \
{                                                                                                                                                             \
    if (enumerator->linked.node->next)                                                                                                                        \
    {                                                                                                                                                         \
        enumerator->linked.node = enumerator->linked.node->next;                                                                                              \
        enumerator->current = &(enumerator->linked.node->content);                                                                                            \
    }                                                                                                                                                         \
    else                                                                                                                                                      \
    {                                                                                                                                                         \
        enumerator->linked.node = NULL;                                                                                                                       \
        enumerator->current = NULL;                                                                                                                           \
    }                                                                                                                                                         \
}                                                                                                                                                             \
static void __cgen_##type##__reset_indexed__(enumerator_##type *enumerator)                                                                                   \
{                                                                                                                                                             \
    enumerator->indexed.index = 0;                                                                                                                            \
    enumerator->current = enumerator->indexed.count ? &(enumerator->indexed.data[0]) : NULL;                                                                  \
}                                                                                                                                                             \
static void __cgen_##type##__reset_linked__(enumerator_##type *enumerator)                                                                                    \
{                                                                                                                                                             \
    enumerator->linked.node = enumerator->linked.first;                                                                                                       \
    enumerator->current = enumerator->linked.node ? &(enumerator->linked.node->content) : NULL;                                                               \
}                                                                                                                                                             \
                                                                                                                                                              \
/* Array functions */                                                                                                                                         \
CGen_Array(type) cgen_array_##type##__create(int64_t length)                                                                                                  \
{                                                                                                                                                             \
    array_##type _array = (array_##type)calloc(1, sizeof(struct array_##type##_struct));                                                                      \
    assert(_array);                                                                                                                                           \
    _array->enumerable_code = ARRAY_T;                                                                                                                        \
    _array->length = length;                                                                                                                                  \
    _array->items = (type *)calloc(length, sizeof(type));                                                                                                     \
    assert(_array->items);                                                                                                                                    \
    return _array;                                                                                                                                            \
}                                                                                                                                                             \
static enumerator_##type __cgen_array_##type##__get_enumerator__(array_##type array)                                                                          \
{                                                                                                                                                             \
    enumerator_##type result;                                                                                                                                 \
    result.move_next = __cgen_##type##__move_next_indexed__;                                                                                                  \
    result.reset = __cgen_##type##__reset_indexed__;                                                                                                          \
    result.indexed.data = ((array_##type)array)->items;                                                                                                       \
    result.indexed.count = ((array_##type)array)->length;                                                                                                     \
    result.indexed.index = 0;                                                                                                                                 \
    return result;                                                                                                                                            \
}                                                                                                                                                             \
static void __cgen_array_##type##__finalize__(array_##type *array)                                                                                            \
{                                                                                                                                                             \
    assert(array && *array && (*array)->items);                                                                                                               \
    free((*array)->items);                                                                                                                                    \
    free(*array);                                                                                                                                             \
    *array = NULL;                                                                                                                                            \
}                                                                                                                                                             \
static array_##type __cgen_array_##type##__clone__(array_##type array)                                                                                        \
{                                                                                                                                                             \
    array_##type _clone;                                                                                                                                      \
    assert(array && array->items && array->length);                                                                                                           \
    _clone = cgen_array_##type##__create(array->length);                                                                                                      \
    memcpy(_clone->items, array->items, _clone->length * sizeof(type));                                                                                       \
    return _clone;                                                                                                                                            \
}                                                                                                                                                             \
static array_##type __cgen_array_##type##__sort__(array_##type array, int32_t (*compare)(type x, type y), sort_aim aim, sort_location location)               \
{                                                                                                                                                             \
    array_##type _result;                                                                                                                                     \
    type *_tmp = NULL;                                                                                                                                        \
    assert(array && compare && array->items && array->length);                                                                                                \
    switch (location)                                                                                                                                         \
    {                                                                                                                                                         \
    case CURRENT_COLLECTION:                                                                                                                                  \
        _result = array;                                                                                                                                      \
        break;                                                                                                                                                \
    case NEW_COLLECTION:                                                                                                                                      \
        _result = __cgen_array_##type##__clone__(array);                                                                                                      \
        break;                                                                                                                                                \
    default:                                                                                                                                                  \
        assert(false && (location == CURRENT_COLLECTION || location == NEW_COLLECTION));                                                                      \
    }                                                                                                                                                         \
    switch (aim)                                                                                                                                              \
    {                                                                                                                                                         \
    case DURATION_STABILITY:                                                                                                                                  \
        _tmp = (type *)malloc(_result->length * sizeof(type));                                                                                                \
        assert(_tmp);                                                                                                                                         \
        __cgen_##type##__merge_sort__(_result->items, _tmp, 0, _result->length - 1, compare);                                                                 \
        free(_tmp);                                                                                                                                           \
        break;                                                                                                                                                \
    case MEMORY_USAGE:                                                                                                                                        \
        __cgen_##type##__quick_sort__(_result->items, 0, _result->length - 1, compare);                                                                       \
        break;                                                                                                                                                \
    default:                                                                                                                                                  \
        assert(false && (aim == DURATION_STABILITY || aim == MEMORY_USAGE));                                                                                  \
    }                                                                                                                                                         \
    return _result;                                                                                                                                           \
}                                                                                                                                                             \
                                                                                                                                                              \
/* Linked list functions */                                                                                                                                   \
static void __cgen_linkedlist_##type##__clear__(linkedlist_##type list);                                                                                      \
CGen_LinkedList(type) cgen_linkedlist_##type##__create()                                                                                                      \
{                                                                                                                                                             \
    linkedlist_##type _list = (linkedlist_##type)calloc(1, sizeof(struct linkedlist_##type##_struct));                                                        \
    assert(_list);                                                                                                                                            \
    _list->enumerable_code = LINKEDLIST_T;                                                                                                                    \
    return _list;                                                                                                                                             \
}                                                                                                                                                             \
void cgen_linkedlist_##type##__add_first(CGen_LinkedList(type) list, type content)                                                                            \
{                                                                                                                                                             \
    linkednode_##type _new;                                                                                                                                   \
    assert(list);                                                                                                                                             \
    _new = (linkednode_##type)calloc(1, sizeof(struct linkednode_##type##_struct));                                                                           \
    assert(_new);                                                                                                                                             \
    _new->content = content;                                                                                                                                  \
    _new->previous = NULL;                                                                                                                                    \
    _new->next = list->first;                                                                                                                                 \
    if (list->first)                                                                                                                                          \
    {                                                                                                                                                         \
        list->first->previous = _new;                                                                                                                         \
    }                                                                                                                                                         \
    else                                                                                                                                                      \
    {                                                                                                                                                         \
        list->last = _new;                                                                                                                                    \
    }                                                                                                                                                         \
    list->first = _new;                                                                                                                                       \
    list->count++;                                                                                                                                            \
}                                                                                                                                                             \
void cgen_linkedlist_##type##__add_last(CGen_LinkedList(type) list, type content)                                                                             \
{                                                                                                                                                             \
    linkednode_##type _new;                                                                                                                                   \
    assert(list);                                                                                                                                             \
    _new = (linkednode_##type)calloc(1, sizeof(struct linkednode_##type##_struct));                                                                           \
    assert(_new);                                                                                                                                             \
    _new->content = content;                                                                                                                                  \
    _new->previous = list->last;                                                                                                                              \
    _new->next = NULL;                                                                                                                                        \
    if (list->last)                                                                                                                                           \
    {                                                                                                                                                         \
        list->last->next = _new;                                                                                                                              \
    }                                                                                                                                                         \
    else                                                                                                                                                      \
    {                                                                                                                                                         \
        list->first = _new;                                                                                                                                   \
    }                                                                                                                                                         \
    list->last = _new;                                                                                                                                        \
    list->count++;                                                                                                                                            \
}                                                                                                                                                             \
void cgen_linkedlist_##type##__remove_first(CGen_LinkedList(type) list)                                                                                       \
{                                                                                                                                                             \
    linkednode_##type _tmp;                                                                                                                                   \
    assert(list && list->first);                                                                                                                              \
    _tmp = list->first;                                                                                                                                       \
    if (list->first == list->last)                                                                                                                            \
    {                                                                                                                                                         \
        list->last = NULL;                                                                                                                                    \
    }                                                                                                                                                         \
    else                                                                                                                                                      \
    {                                                                                                                                                         \
        list->first->next->previous = NULL;                                                                                                                   \
    }                                                                                                                                                         \
    list->first = list->first->next;                                                                                                                          \
    free(_tmp);                                                                                                                                               \
    list->count--;                                                                                                                                            \
}                                                                                                                                                             \
void cgen_linkedlist_##type##__remove_last(CGen_LinkedList(type) list)                                                                                        \
{                                                                                                                                                             \
    linkednode_##type _tmp;                                                                                                                                   \
    assert(list && list->last);                                                                                                                               \
    _tmp = list->last;                                                                                                                                        \
    if (list->last == list->first)                                                                                                                            \
    {                                                                                                                                                         \
        list->first = NULL;                                                                                                                                   \
    }                                                                                                                                                         \
    else                                                                                                                                                      \
    {                                                                                                                                                         \
        list->last->previous->next = NULL;                                                                                                                    \
    }                                                                                                                                                         \
    list->last = list->last->previous;                                                                                                                        \
    free(_tmp);                                                                                                                                               \
    list->count--;                                                                                                                                            \
}                                                                                                                                                             \
static enumerator_##type __cgen_linkedlist_##type##__get_enumerator__(linkedlist_##type list)                                                                 \
{                                                                                                                                                             \
    enumerator_##type result;                                                                                                                                 \
    result.move_next = __cgen_##type##__move_next_linked__;                                                                                                   \
    result.reset = __cgen_##type##__reset_linked__;                                                                                                           \
    result.linked.first = list->first;                                                                                                                        \
    result.linked.node = result.linked.first;                                                                                                                 \
    return result;                                                                                                                                            \
}                                                                                                                                                             \
static void __cgen_linkedlist_##type##__finalize__(linkedlist_##type *list)                                                                                   \
{                                                                                                                                                             \
    assert(list && *list);                                                                                                                                    \
    __cgen_linkedlist_##type##__clear__(*list);                                                                                                               \
    free(*list);                                                                                                                                              \
    *list = NULL;                                                                                                                                             \
}                                                                                                                                                             \
static linkedlist_##type __cgen_linkedlist_##type##__clone__(linkedlist_##type list)                                                                          \
{                                                                                                                                                             \
    linkedlist_##type _list;                                                                                                                                  \
    linkednode_##type _iterator;                                                                                                                              \
    assert(list);                                                                                                                                             \
    _list = cgen_linkedlist_##type##__create();                                                                                                               \
    _iterator = list->first;                                                                                                                                  \
    while (_iterator)                                                                                                                                         \
    {                                                                                                                                                         \
        cgen_linkedlist_##type##__add_last(_list, _iterator->content);                                                                                        \
        _iterator = _iterator->next;                                                                                                                          \
    }                                                                                                                                                         \
    return _list;                                                                                                                                             \
}                                                                                                                                                             \
static void __cgen_linkedlist_##type##__clear__(linkedlist_##type list)                                                                                       \
{                                                                                                                                                             \
    linkednode_##type _current, _next;                                                                                                                        \
    assert(list);                                                                                                                                             \
    _current = list->first;                                                                                                                                   \
    while (_current)                                                                                                                                          \
    {                                                                                                                                                         \
        _next = _current->next;                                                                                                                               \
        free(_current);                                                                                                                                       \
        _current = _next;                                                                                                                                     \
    }                                                                                                                                                         \
    list->first = NULL;                                                                                                                                       \
    list->last = NULL;                                                                                                                                        \
    list->count = 0;                                                                                                                                          \
}                                                                                                                                                             \
static linkedlist_##type __cgen_linkedlist_##type##__sort__(linkedlist_##type list, int32_t (*compare)(type x, type y), sort_aim aim, sort_location location) \
{                                                                                                                                                             \
    linkedlist_##type _result;                                                                                                                                \
    type *_tmp, *_save;                                                                                                                                       \
    linkednode_##type _iterator, _current;                                                                                                                    \
    int64_t _counter, _i;                                                                                                                                     \
    assert(list && compare);                                                                                                                                  \
    if (!list->count)                                                                                                                                         \
    {                                                                                                                                                         \
        switch (location)                                                                                                                                     \
        {                                                                                                                                                     \
        case CURRENT_COLLECTION:                                                                                                                              \
            return list;                                                                                                                                      \
        case NEW_COLLECTION:                                                                                                                                  \
            return cgen_linkedlist_##type##__create();                                                                                                        \
        default:                                                                                                                                              \
            assert(false && (location == CURRENT_COLLECTION || location == NEW_COLLECTION));                                                                  \
        }                                                                                                                                                     \
    }                                                                                                                                                         \
    _tmp = NULL;                                                                                                                                              \
    _save = (type *)calloc(list->count, sizeof(type));                                                                                                        \
    assert(_save);                                                                                                                                            \
    _iterator = list->first;                                                                                                                                  \
    for (_counter = 0; _counter < list->count; _counter++)                                                                                                    \
    {                                                                                                                                                         \
        _save[_counter] = _iterator->content;                                                                                                                 \
        _iterator = _iterator->next;                                                                                                                          \
    }                                                                                                                                                         \
    switch (aim)                                                                                                                                              \
    {                                                                                                                                                         \
    case DURATION_STABILITY:                                                                                                                                  \
        _tmp = (type *)malloc(list->count * sizeof(type));                                                                                                    \
        assert(_tmp);                                                                                                                                         \
        __cgen_##type##__merge_sort__(_save, _tmp, 0, list->count - 1, compare);                                                                              \
        free(_tmp);                                                                                                                                           \
        break;                                                                                                                                                \
    case MEMORY_USAGE:                                                                                                                                        \
        __cgen_##type##__quick_sort__(_save, 0, list->count - 1, compare);                                                                                    \
        break;                                                                                                                                                \
    default:                                                                                                                                                  \
        assert(false);                                                                                                                                        \
    }                                                                                                                                                         \
    switch (location)                                                                                                                                         \
    {                                                                                                                                                         \
    case CURRENT_COLLECTION:                                                                                                                                  \
        _result = list;                                                                                                                                       \
        _current = list->first;                                                                                                                               \
        for (_i = 0; _i < list->count; _i++)                                                                                                                  \
        {                                                                                                                                                     \
            _current->content = _save[_i];                                                                                                                    \
            _current = _current->next;                                                                                                                        \
        }                                                                                                                                                     \
        break;                                                                                                                                                \
    case NEW_COLLECTION:                                                                                                                                      \
        _result = cgen_linkedlist_##type##__create();                                                                                                         \
        for (_i = 0; _i < list->count; _i++)                                                                                                                  \
        {                                                                                                                                                     \
            cgen_linkedlist_##type##__add_last(_result, _save[_i]);                                                                                           \
        }                                                                                                                                                     \
        break;                                                                                                                                                \
    default:                                                                                                                                                  \
        assert(false);                                                                                                                                        \
    }                                                                                                                                                         \
    free(_save);                                                                                                                                              \
    return _result;                                                                                                                                           \
}                                                                                                                                                             \
                                                                                                                                                              \
/* Enumerable interface functions */                                                                                                                          \
void cgen_finalize_##type(CGen_IEnumerable(type) * enumerable)                                                                                                \
{                                                                                                                                                             \
    assert(enumerable && *enumerable && CGen_Is_IEnumerable(*enumerable));                                                                                    \
    switch ((*enumerable)->enumerable_code)                                                                                                                   \
    {                                                                                                                                                         \
    case ARRAY_T:                                                                                                                                             \
        __cgen_array_##type##__finalize__((array_##type *)enumerable);                                                                                        \
        return;                                                                                                                                               \
    case LINKEDLIST_T:                                                                                                                                        \
        __cgen_linkedlist_##type##__finalize__((linkedlist_##type *)enumerable);                                                                              \
        return;                                                                                                                                               \
    default:                                                                                                                                                  \
        assert(false);                                                                                                                                        \
        return;                                                                                                                                               \
    }                                                                                                                                                         \
}                                                                                                                                                             \
CGen_Enumerator(type) cgen_get_enumerator_##type(CGen_IEnumerable(type) enumerable)                                                                           \
{                                                                                                                                                             \
    enumerator_##type result;                                                                                                                                 \
    assert(enumerable && CGen_Is_IEnumerable(enumerable));                                                                                                    \
    switch (enumerable->enumerable_code)                                                                                                                      \
    {                                                                                                                                                         \
    case ARRAY_T:                                                                                                                                             \
        result = __cgen_array_##type##__get_enumerator__((array_##type)enumerable);                                                                           \
        break;                                                                                                                                                \
    case LINKEDLIST_T:                                                                                                                                        \
        result = __cgen_linkedlist_##type##__get_enumerator__((linkedlist_##type)enumerable);                                                                 \
        break;                                                                                                                                                \
    default:                                                                                                                                                  \
        assert(false);                                                                                                                                        \
        break;                                                                                                                                                \
    }                                                                                                                                                         \
    result.reset(&result);                                                                                                                                    \
    return result;                                                                                                                                            \
}                                                                                                                                                             \
CGen_IEnumerable(type) cgen_clone_##type(CGen_IEnumerable(type) enumerable)                                                                                   \
{                                                                                                                                                             \
    assert(enumerable && CGen_Is_IEnumerable(enumerable));                                                                                                    \
    switch (enumerable->enumerable_code)                                                                                                                      \
    {                                                                                                                                                         \
    case ARRAY_T:                                                                                                                                             \
        return (i_enumerable_##type)__cgen_array_##type##__clone__((array_##type)enumerable);                                                                 \
    case LINKEDLIST_T:                                                                                                                                        \
        return (i_enumerable_##type)__cgen_linkedlist_##type##__clone__((linkedlist_##type)enumerable);                                                       \
    default:                                                                                                                                                  \
        assert(false);                                                                                                                                        \
        return NULL;                                                                                                                                          \
    }                                                                                                                                                         \
}                                                                                                                                                             \
CGen_IEnumerable(type) cgen_sort_##type(CGen_IEnumerable(type) enumerable, CGen_SortOptions(type) options)                                                    \
{                                                                                                                                                             \
    assert(enumerable && CGen_Is_IEnumerable(enumerable) && options.compare && options.aim && options.location);                                              \
    switch (enumerable->enumerable_code)                                                                                                                      \
    {                                                                                                                                                         \
    case ARRAY_T:                                                                                                                                             \
        return (i_enumerable_##type)__cgen_array_##type##__sort__((array_##type)enumerable, options.compare, options.aim, options.location);                  \
    case LINKEDLIST_T:                                                                                                                                        \
        return (i_enumerable_##type)__cgen_linkedlist_##type##__sort__((linkedlist_##type)enumerable, options.compare, options.aim, options.location);        \
    default:                                                                                                                                                  \
        assert(false);                                                                                                                                        \
        return NULL;                                                                                                                                          \
    }                                                                                                                                                         \
}                                                                                                                                                             \
                                                                                                                                                              \
/* Collection interface functions */                                                                                                                          \
void cgen_clear_##type(CGen_ICollection(type) collection)                                                                                                     \
{                                                                                                                                                             \
    assert(collection && CGen_Is_ICollection(collection));                                                                                                    \
    switch (collection->enumerable_code)                                                                                                                      \
    {                                                                                                                                                         \
    case LINKEDLIST_T:                                                                                                                                        \
        __cgen_linkedlist_##type##__clear__((linkedlist_##type)collection);                                                                                   \
        break;                                                                                                                                                \
    default:                                                                                                                                                  \
        assert(false);                                                                                                                                        \
        break;                                                                                                                                                \
    }                                                                                                                                                         \
}

/* Iterate over an enumerable (this operation is a for each loop). 
Warning : the enumerable can't be modified during a foreach operation ! */
#define CGen_ForEach(type, enumerable, element_name, action)                                                                                                  \
do                                                                                                                                                            \
{                                                                                                                                                             \
    type *element_name;                                                                                                                                       \
    CGen_Enumerator(type) _enumerator = CGen_GetEnumerator(type, enumerable);                                                                                 \
    while (_enumerator.current)                                                                                                                               \
    {                                                                                                                                                         \
        element_name = _enumerator.current;                                                                                                                   \
        action;                                                                                                                                               \
        _enumerator.move_next(&(_enumerator));                                                                                                                \
    }                                                                                                                                                         \
} while (false)

#endif