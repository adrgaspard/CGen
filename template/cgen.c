#ifndef __CGEN_H__
#define __CGEN_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#pragma region Custom assertions and error messages

int32_t __cgen_raise_error__(const char *file, const int line, const char *message);

#define __CGEN_ASSERT__(expression, context, error_message) (void)((!!(expression)) || __cgen_raise_error__(__FILE__, __LINE__, "[" context "] " error_message))
#define __CGEN_METHOD_STR__(implementation, type, operation) implementation "(" #type "):" operation

#define __CGEN_ERR_MEMALLOC__(error_source) "Memory allocation error. Failed to allocate the " error_source "."
#define __CGEN_ERR_NULLREF__(error_source) "Null reference error. The " error_source " can't be null."
#define __CGEN_ERR_NOTPOS__(error_source) "Invalid value. The " error_source " must be positive."
#define __CGEN_ERR_UNKNOW_ENUM_VAL__(error_source, enumeration) "Invalid value. The " error_source " must have a valid " #enumeration " value."
#define __CGEN_ERR_NOT_EXPECTED_ENUM_VAL__(error_source, enumeration) "Invalid value. The " error_source " has not an expected " #enumeration " value in this context."
#define __CGEN_ERR_NOT_ENUMERABLE__(type, error_source) "Invalid value. The " error_source " is not an implementation of IEnumerable(" #type ") interface."
#define __CGEN_ERR_NOT_COLLECTION__(type, error_source) "Invalid value. The " error_source " is not an implementation of ICollection(" #type ") interface."

#pragma endregion

#pragma region Default comparators

/**
 * @brief Compares the int8 x1 to the int8 x2. 
 * 
 * @param x1 The first int8 to be compared.
 * @param x2 The other int8 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is lower than x2, 0 when x1 and x2 are equal, >0 when x1 is upper than x2.
 */
int32_t cgen_compare_int8_asc(const int8_t x1, const int8_t x2);
/**
 * @brief Compares the int8 x1 to the int8 x2. 
 * 
 * @param x1 The first int8 to be compared.
 * @param x2 The other int8 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is upper than x2, 0 when x1 and x2 are equal, >0 when x1 is lower than x2.
 */
int32_t cgen_compare_int8_desc(const int8_t x1, const int8_t x2);
/**
 * @brief Compares the int16 x1 to the int16 x2. 
 * 
 * @param x1 The first int16 to be compared.
 * @param x2 The other int16 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is lower than x2, 0 when x1 and x2 are equal, >0 when x1 is upper than x2.
 */
int32_t cgen_compare_int16_asc(const int16_t x1, const int16_t x2);
/**
 * @brief Compares the int16 x1 to the int16 x2. 
 * 
 * @param x1 The first int16 to be compared.
 * @param x2 The other int16 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is upper than x2, 0 when x1 and x2 are equal, >0 when x1 is lower than x2.
 */
int32_t cgen_compare_int16_desc(const int16_t x1, const int16_t x2);
/**
 * @brief Compares the int32 x1 to the int32 x2. 
 * 
 * @param x1 The first int32 to be compared.
 * @param x2 The other int32 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is lower than x2, 0 when x1 and x2 are equal, >0 when x1 is upper than x2.
 */
int32_t cgen_compare_int32_asc(const int32_t x1, const int32_t x2);
/**
 * @brief Compares the int32 x1 to the int32 x2. 
 * 
 * @param x1 The first int32 to be compared.
 * @param x2 The other int32 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is upper than x2, 0 when x1 and x2 are equal, >0 when x1 is lower than x2.
 */
int32_t cgen_compare_int32_desc(const int32_t x1, const int32_t x2);
/**
 * @brief Compares the int64 x1 to the int64 x2. 
 * 
 * @param x1 The first int64 to be compared.
 * @param x2 The other int64 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is lower than x2, 0 when x1 and x2 are equal, >0 when x1 is upper than x2.
 */
int32_t cgen_compare_int64_asc(const int64_t x1, const int64_t x2);
/**
 * @brief Compares the int64 x1 to the int64 x2. 
 * 
 * @param x1 The first int64 to be compared.
 * @param x2 The other int64 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is upper than x2, 0 when x1 and x2 are equal, >0 when x1 is lower than x2.
 */
int32_t cgen_compare_int64_desc(const int64_t x1, const int64_t x2);
/**
 * @brief Compares the uint8 x1 to the uint8 x2. 
 * 
 * @param x1 The first uint8 to be compared.
 * @param x2 The other uint8 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is lower than x2, 0 when x1 and x2 are equal, >0 when x1 is upper than x2.
 */
int32_t cgen_compare_uint8_asc(const uint8_t x1, const uint8_t x2);
/**
 * @brief Compares the uint8 x1 to the uint8 x2. 
 * 
 * @param x1 The first uint8 to be compared.
 * @param x2 The other uint8 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is upper than x2, 0 when x1 and x2 are equal, >0 when x1 is lower than x2.
 */
int32_t cgen_compare_uint8_desc(const uint8_t x1, const uint8_t x2);
/**
 * @brief Compares the uint16 x1 to the uint16 x2. 
 * 
 * @param x1 The first uint16 to be compared.
 * @param x2 The other uint16 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is lower than x2, 0 when x1 and x2 are equal, >0 when x1 is upper than x2.
 */
int32_t cgen_compare_uint16_asc(const uint16_t x1, const uint16_t x2);
/**
 * @brief Compares the uint16 x1 to the uint16 x2. 
 * 
 * @param x1 The first uint16 to be compared.
 * @param x2 The other uint16 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is upper than x2, 0 when x1 and x2 are equal, >0 when x1 is lower than x2.
 */
int32_t cgen_compare_uint16_desc(const uint16_t x1, const uint16_t x2);
/**
 * @brief Compares the uint32 x1 to the uint32 x2. 
 * 
 * @param x1 The first uint32 to be compared.
 * @param x2 The other uint32 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is lower than x2, 0 when x1 and x2 are equal, >0 when x1 is upper than x2.
 */
int32_t cgen_compare_uint32_asc(const uint32_t x1, const uint32_t x2);
/**
 * @brief Compares the uint32 x1 to the uint32 x2. 
 * 
 * @param x1 The first uint32 to be compared.
 * @param x2 The other uint32 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is upper than x2, 0 when x1 and x2 are equal, >0 when x1 is lower than x2.
 */
int32_t cgen_compare_uint32_desc(const uint32_t x1, const uint32_t x2);
/**
 * @brief Compares the uint64 x1 to the uint64 x2. 
 * 
 * @param x1 The first uint64 to be compared.
 * @param x2 The other uint64 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is lower than x2, 0 when x1 and x2 are equal, >0 when x1 is upper than x2.
 */
int32_t cgen_compare_uint64_asc(const uint64_t x1, const uint64_t x2);
/**
 * @brief Compares the uint64 x1 to the uint64 x2. 
 * 
 * @param x1 The first uint64 to be compared.
 * @param x2 The other uint64 to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is upper than x2, 0 when x1 and x2 are equal, >0 when x1 is lower than x2.
 */
int32_t cgen_compare_uint64_desc(const uint64_t x1, const uint64_t x2);
/**
 * @brief Compares the short x1 to the short x2. 
 * 
 * @param x1 The first short to be compared.
 * @param x2 The other short to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is lower than x2, 0 when x1 and x2 are equal, >0 when x1 is upper than x2.
 */
int32_t cgen_compare_short_asc(const short x1, const short x2);
/**
 * @brief Compares the short x1 to the short x2. 
 * 
 * @param x1 The first short to be compared.
 * @param x2 The other short to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is upper than x2, 0 when x1 and x2 are equal, >0 when x1 is lower than x2.
 */
int32_t cgen_compare_short_desc(const short x1, const short x2);
/**
 * @brief Compares the float x1 to the float x2. 
 * 
 * @param x1 The first float to be compared.
 * @param x2 The other float to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is lower than x2, 0 when x1 and x2 are equal, >0 when x1 is upper than x2.
 */
int32_t cgen_compare_float_asc(const float x1, const float x2);
/**
 * @brief Compares the float x1 to the float x2. 
 * 
 * @param x1 The first float to be compared.
 * @param x2 The other float to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is upper than x2, 0 when x1 and x2 are equal, >0 when x1 is lower than x2.
 */
int32_t cgen_compare_float_desc(const float x1, const float x2);
/**
 * @brief Compares the double x1 to the double x2. 
 * 
 * @param x1 The first double to be compared.
 * @param x2 The other double to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is lower than x2, 0 when x1 and x2 are equal, >0 when x1 is upper than x2.
 */
int32_t cgen_compare_double_asc(const double x1, const double x2);
/**
 * @brief Compares the double x1 to the double x2. 
 * 
 * @param x1 The first double to be compared.
 * @param x2 The other double to be compared.
 * @return An integral value indicating the relationship between the values. <0 when x1 is upper than x2, 0 when x1 and x2 are equal, >0 when x1 is lower than x2.
 */
int32_t cgen_compare_double_desc(const double x1, const double x2);
/**
 * @brief Compares (with ignoring the case) the string x1 to the string x2. 
 * 
 * @param x1 The first string to be compared.
 * @param x2 The other string to be compared.
 * @return An integral value indicating the relationship between the strings. <0 when the first character that does not match has a lower value in x1 than in x2, 0 when the contents of both strings are equal, >0 when the first character that does not match has a greater value in x1 than in x2.
 */
int32_t cgen_compare_str_asc(char *x1, char *x2);
/**
 * @brief Compares (with ignoring the case) the string x1 to the string x2. 
 * 
 * @param x1 The first string to be compared.
 * @param x2 The other string to be compared.
 * @return An integral value indicating the relationship between the strings. <0 when the first character that does not match has a greater value in x1 than in x2, 0 when the contents of both strings are equal, >0 when the first character that does not match has a lower value in x1 than in x2.
 */
int32_t cgen_compare_str_desc(char *x1, char *x2);
/**
 * @brief Compares (with case sensitive) the string x1 to the string x2. 
 * 
 * @param x1 The first string to be compared.
 * @param x2 The other string to be compared.
 * @return An integral value indicating the relationship between the strings. <0 when the first character that does not match has a lower value in x1 than in x2, 0 when the contents of both strings are equal, >0 when the first character that does not match has a greater value in x1 than in x2.
 */
int32_t cgen_compare_str_case_insensitive_asc(char *x1, char *x2);
/**
 * @brief Compares (with case sensitive) the string x1 to the string x2. 
 * 
 * @param x1 The first string to be compared.
 * @param x2 The other string to be compared.
 * @return An integral value indicating the relationship between the strings. <0 when the first character that does not match has a greater value in x1 than in x2, 0 when the contents of both strings are equal, >0 when the first character that does not match has a lower value in x1 than in x2.
 */
int32_t cgen_compare_str_case_insensitive_desc(char *x1, char *x2);

#pragma endregion

/* ===== UTILS SECTION ===== */

/* Global types */

typedef enum SortAim
{
	DURATION_STABILITY = 1,
	MEMORY_USAGE = 2
} SortAim;
typedef enum SortLocation
{
	CURRENT_COLLECTION = 1,
	NEW_COLLECTION = 2
} SortLocation;
typedef enum EnumerableTypeDescriptor
{
	ARRAY_T = 1,
	LINKEDLIST_T = 2,
	LIST_T = 4,
	COLLECTION_I = LINKEDLIST_T | LIST_T,
	ENUMERABLE_I = COLLECTION_I | ARRAY_T
} EnumerableTypeDescriptor;
/* --- Ignore --- */ typedef int type;

/* Interfaces bodies section */

/* --- Ignore --- */ typedef struct to_ignore
/* --- Ignore --- */ {
	/* --- macro_start --- IENUMERABLE_INTERFACE_BODY(type) */
	EnumerableTypeDescriptor __descriptor;
	/* --- macro_end --- */

	/* --- macro_start --- ICOLLECTION_INTERFACE_BODY(type) */
	/* --- macro_usage --- IENUMERABLE_INTERFACE_BODY(type) */
	int64_t _count;
	/* --- macro_end --- */
/* --- Ignore --- */ };

/* Global types and interfaces type descriptors macros */

#define CGen_SortOptions(type) SortOptions_##type
#define CGen_Enumerator(type) Enumerator_##type
#define CGen_IEnumerable(type) IEnumerable_##type
#define CGen_ICollection(type) ICollection_##type

/* Polymorphism verification tools macros */

#define CGen_Is_IEnumerable(obj) ((obj)->__descriptor & ENUMERABLE_I)
#define CGen_Is_ICollection(obj) ((obj)->__descriptor & COLLECTION_I)

/* IEnumerable interface functions macros */

#define CGen_Finalize(type, enumerable) gen_finalize_##type((IEnumerable_##type *)(enumerable))
#define CGen_GetEnumerator(type, enumerable) cgen_get_enumerator_##type((IEnumerable_##type)(enumerable))
#define CGen_Clone(type, enumerable) cgen_clone_##type((IEnumerable_##type)(enumerable))
#define CGen_Sort(type, enumerable, options) cgen_sort_##type((IEnumerable_##type)(enumerable), options)

/* ICollection interface functions macros */

#define CGen_Clear(type, collection) cgen_clear_##type((ICollection_##type)(collection))

/* Array macros : type descriptor, constructor and any specifics functions */

#define CGen_Array(type) Array_##type
#define CGen_New_Array(type, size) cgen_array_##type##__create(size)

/* Linked list macros : type descriptor, constructor and any specifics functions */

#define CGen_LinkedList(type) LinkedList_##type
#define CGen_New_LinkedList(type) cgen_linkedlist_##type##__create()
#define CGen_AddFirst(type, list, content) cgen_linkedlist_##type##__add_first(list, content)
#define CGen_AddLast(type, list, content) cgen_linkedlist_##type##__add_last(list, content)
#define CGen_RemoveFirst(type, list) cgen_linkedlist_##type##__remove_first(list)
#define CGen_RemoveLast(type, list) cgen_linkedlist_##type##__remove_last(list)

/* ===== GENERICS ABSTRACTION SECTION ===== */

/* --- macro_start --- CGen_Include_Generics_Abstraction(type) */
/* Generics types declarations structures */

typedef struct SortOptions_type
{
	int32_t (*const _compare)(const type x, const type y);
	const SortAim _aim;
	const SortLocation _location;
} SortOptions_type;
typedef struct IndexedEnumeratorData_type
{
	type *__data;
	uint64_t __count;
	uint64_t __index;
} IndexedEnumeratorData_type;
typedef struct LinkedEnumeratorData_type
{
	struct LinkedNode_type_Struct *__first;
	struct LinkedNode_type_Struct *__node;
} LinkedEnumeratorData_type;
typedef struct Enumerator_type
{
	type *_current;
	void (*_move_next)(struct Enumerator_type *enumerator);
	void (*_reset)(struct Enumerator_type *enumerator);
	union
	{
		IndexedEnumeratorData_type __indexed;
		LinkedEnumeratorData_type __linked;
	};
} Enumerator_type;
typedef struct IEnumerable_type_Struct
{
	/* --- Ignore --- */ EnumerableTypeDescriptor __descriptor;
	/* --- macro_usage --- IENUMERABLE_INTERFACE_BODY(type) */
} * IEnumerable_type;
typedef struct ICollection_type_Struct
{
	/* --- Ignore --- */ EnumerableTypeDescriptor __descriptor;
	/* --- Ignore --- */ int64_t _count;
	/* --- macro_usage --- IENUMERABLE_INTERFACE_BODY(type) */
} * ICollection_type;
typedef struct Array_type_Struct
{
	/* --- macro_usage --- IENUMERABLE_INTERFACE_BODY(type) */
	/* --- Ignore --- */ EnumerableTypeDescriptor __descriptor;
	type *_items;
	int64_t _length;
} * Array_type;
typedef struct List_type_struct
{
	/* --- macro_usage --- IENUMERABLE_INTERFACE_BODY(type) */
	type *_items;
	int64_t _length;
	int64_t _capacity;
} * List_type;
typedef struct LinkedNode_type_Struct
{
	struct LinkedNode_type_Struct *_previous;
	struct LinkedNode_type_Struct *_next;
	type _content;
} * LinkedNode_type;
typedef struct LinkedList_type_Struct
{
	/* --- macro_usage --- ICOLLECTION_INTERFACE_BODY(type) */
	/* --- Ignore --- */ EnumerableTypeDescriptor __descriptor;
	/* --- Ignore --- */ int64_t _count;
	LinkedNode_type _first;
	LinkedNode_type _last;
} * LinkedList_type;

/* IEnumerable interface functions prototypes */

void cgen_finalize_type(CGen_IEnumerable(type) * enumerable);
CGen_Enumerator(type) cgen_get_enumerator_type(CGen_IEnumerable(type) enumerable);
CGen_IEnumerable(type) cgen_clone_type(CGen_IEnumerable(type) enumerable);
CGen_IEnumerable(type) cgen_sort_type(CGen_IEnumerable(type) enumerable, CGen_SortOptions(type) options);

/* ICollection interface functions prototypes */

void cgen_clear_type(CGen_ICollection(type) collection);

/* Array functions prototypes */

CGen_Array(type) cgen_array_type__create(int64_t length);

/* Linked list functions prototypes */

CGen_LinkedList(type) cgen_linkedlist_type__create();
void cgen_linkedlist_type__add_first(CGen_LinkedList(type) list, type content);
void cgen_linkedlist_type__add_last(CGen_LinkedList(type) list, type content);
void cgen_linkedlist_type__remove_first(CGen_LinkedList(type) list);
void cgen_linkedlist_type__remove_last(CGen_LinkedList(type) list);
/* --- macro_end --- */

/* ===== GENERICS IMPLEMENTATION SECTION ===== */

/* --- macro_start --- CGen_Include_Generics_Implementation(type) */
/* Private core sort functions */

static void __cgen_type__merge_sort__(type *_array, type *_tmp, int64_t _start, int64_t _end, int32_t (*_compare)(type _x, type _y));
static int64_t __cgen_type__partition__(type *_array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y));
static void __cgen_type__quick_sort__(type *_array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y));
static void __cgen_type__merge_sort__(type *_array, type *_tmp, int64_t _start, int64_t _end, int32_t (*_compare)(type _x, type _y))
{
	int64_t _middle, _i, _j, _k;
	if (_end <= _start)
	{
		return;
	}
	_middle = (_start + _end) / 2;
	__cgen_type__merge_sort__(_array, _tmp, _start, _middle, _compare);
	__cgen_type__merge_sort__(_array, _tmp, _middle + 1, _end, _compare);
	_i = _start;
	_j = _middle + 1;
	for (_k = _start; _k <= _end; _k++)
	{
		if (_i > _middle)
		{
			_tmp[_k] = _array[_j];
			_j++;
		}
		else if (_j > _end)
		{
			_tmp[_k] = _array[_i];
			_i++;
		}
		else if (_compare(_array[_i], _array[_j]) < 0)
		{
			_tmp[_k] = _array[_i];
			_i++;
		}
		else
		{
			_tmp[_k] = _array[_j];
			_j++;
		}
	}
	for (_k = _start; _k <= _end; _k++)
	{
		_array[_k] = _tmp[_k];
	}
}
static int64_t __cgen_type__partition__(type *_array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y))
{
	type _pivot, _tmp;
	int64_t _i, _j;
	_i = _low;
	_pivot = _array[_high];
	for (_j = _low; _j < _high; _j++)
	{
		if (_compare(_array[_j], _pivot) <= 0)
		{
			_tmp = _array[_i];
			_array[_i] = _array[_j];
			_array[_j] = _tmp;
			_i++;
		}
	}
	_tmp = _array[_i];
	_array[_i] = _array[_high];
	_array[_high] = _tmp;
	return _i;
}
static void __cgen_type__quick_sort__(type *_array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y))
{
	int64_t _pivot_index;
	if (_low < _high)
	{
		_pivot_index = __cgen_type__partition__(_array, _low, _high, _compare);
		__cgen_type__quick_sort__(_array, _low, _pivot_index - 1, _compare);
		__cgen_type__quick_sort__(_array, _pivot_index + 1, _high, _compare);
	}
}

/* Private enumerator utils functions */

static void __cgen_type__move_next_indexed__(Enumerator_type *enumerator)
{
	if (++enumerator->__indexed.__index >= enumerator->__indexed.__count)
	{
		enumerator->_current = NULL;
	}
	else
	{
		enumerator->_current = &(enumerator->__indexed.__data[enumerator->__indexed.__index]);
	}
}
static void __cgen_type__move_next_linked__(Enumerator_type *enumerator)
{
	if (enumerator->__linked.__node->_next)
	{
		enumerator->__linked.__node = enumerator->__linked.__node->_next;
		enumerator->_current = &(enumerator->__linked.__node->_content);
	}
	else
	{
		enumerator->__linked.__node = NULL;
		enumerator->_current = NULL;
	}
}
static void __cgen_type__reset_indexed__(Enumerator_type *enumerator)
{
	enumerator->__indexed.__index = 0;
	enumerator->_current = enumerator->__indexed.__count ? &(enumerator->__indexed.__data[0]) : NULL;
}
static void __cgen_type__reset_linked__(Enumerator_type *enumerator)
{
	enumerator->__linked.__node = enumerator->__linked.__first;
	enumerator->_current = enumerator->__linked.__node ? &(enumerator->__linked.__node->_content) : NULL;
}

/* Array functions */

CGen_Array(type) cgen_array_type__create(int64_t length)
{
	type *_tmp = (type *)calloc(length, sizeof(type));
	struct Array_type_Struct _array_content = {.__descriptor = ARRAY_T, ._length = length, ._items = _tmp};
	Array_type _array = (Array_type)calloc(1, sizeof(struct Array_type_Struct));
	__CGEN_ASSERT__(_array, __CGEN_METHOD_STR__("Array", type, "New"), __CGEN_ERR_MEMALLOC__("array structure"));
	__CGEN_ASSERT__(_tmp, __CGEN_METHOD_STR__("Array", type, "New"), __CGEN_ERR_MEMALLOC__("array items memory segment"));
	*_array = _array_content;
	return _array;
}
static Enumerator_type __cgen_array_type__get_enumerator__(Array_type array)
{
	Enumerator_type result = {
		._move_next = __cgen_type__move_next_indexed__,
		._reset = __cgen_type__reset_indexed__,
		.__indexed.__data = ((Array_type)array)->_items,
		.__indexed.__count = ((Array_type)array)->_length,
		.__indexed.__index = 0};
	return result;
}
static void __cgen_array_type__finalize__(Array_type *array)
{
	__CGEN_ASSERT__(array, __CGEN_METHOD_STR__("Array", type, "Finalize"), __CGEN_ERR_NULLREF__("array pointer"));
	__CGEN_ASSERT__(*array, __CGEN_METHOD_STR__("Array", type, "Finalize"), __CGEN_ERR_NULLREF__("array"));
	__CGEN_ASSERT__((*array)->_items, __CGEN_METHOD_STR__("Array", type, "Finalize"), __CGEN_ERR_NULLREF__("array items memory segment"));
	free((*array)->_items);
	free(*array);
	*array = NULL;
}
static Array_type __cgen_array_type__clone__(Array_type array)
{
	Array_type _clone;
	__CGEN_ASSERT__(array, __CGEN_METHOD_STR__("Array", type, "Clone"), __CGEN_ERR_NULLREF__("array"));
	__CGEN_ASSERT__(array->_items, __CGEN_METHOD_STR__("Array", type, "Clone"), __CGEN_ERR_NULLREF__("array items memory segment"));
	__CGEN_ASSERT__(array->_length > 0, __CGEN_METHOD_STR__("Array", type, "Clone"), __CGEN_ERR_NOTPOS__("array length"));
	_clone = cgen_array_type__create(array->_length);
	memcpy(_clone->_items, array->_items, _clone->_length * sizeof(type));
	return _clone;
}
static Array_type __cgen_array_type__sort__(Array_type array, int32_t (*compare)(type x, type y), SortAim aim, SortLocation location)
{
	Array_type _result;
	type *_tmp = NULL;
	__CGEN_ASSERT__(array, __CGEN_METHOD_STR__("Array", type, "Sort"), __CGEN_ERR_NULLREF__("array"));
	__CGEN_ASSERT__(compare, __CGEN_METHOD_STR__("Array", type, "Sort"), __CGEN_ERR_NULLREF__("comparator function pointer"));
	__CGEN_ASSERT__(array->_items, __CGEN_METHOD_STR__("Array", type, "Sort"), __CGEN_ERR_NULLREF__("array items memory segment"));
	__CGEN_ASSERT__(array->_length > 0, __CGEN_METHOD_STR__("Array", type, "Sort"), __CGEN_ERR_NOTPOS__("array length"));
	switch (location)
	{
	case CURRENT_COLLECTION:
		_result = array;
		break;
	case NEW_COLLECTION:
		_result = __cgen_array_type__clone__(array);
		break;
	default:
		__CGEN_ASSERT__(false, __CGEN_METHOD_STR__("Array", type, "Sort"), __CGEN_ERR_UNKNOW_ENUM_VAL__("location", SortLocation));
		break;
	}
	switch (aim)
	{
	case DURATION_STABILITY:
		_tmp = (type *)malloc(_result->_length * sizeof(type));
		__CGEN_ASSERT__(array, __CGEN_METHOD_STR__("Array", type, "Sort"), __CGEN_ERR_MEMALLOC__("temporary array used for sort"));
		__cgen_type__merge_sort__(_result->_items, _tmp, 0, _result->_length - 1, compare);
		free(_tmp);
		break;
	case MEMORY_USAGE:
		__cgen_type__quick_sort__(_result->_items, 0, _result->_length - 1, compare);
		break;
	default:
		__CGEN_ASSERT__(false, __CGEN_METHOD_STR__("Array", type, "Sort"), __CGEN_ERR_UNKNOW_ENUM_VAL__("aim", SortAim));
		break;
	}
	return _result;
}

/* Linked list functions */

static void __cgen_linkedlist_type__clear__(LinkedList_type list);
CGen_LinkedList(type) cgen_linkedlist_type__create()
{
	struct LinkedList_type_Struct _list_content = {.__descriptor = LINKEDLIST_T, ._count = 0, ._first = NULL, ._last = NULL };
	LinkedList_type _list = (LinkedList_type)calloc(1, sizeof(struct LinkedList_type_Struct));
	__CGEN_ASSERT__(_list, __CGEN_METHOD_STR__("LinkedList", type, "New"), __CGEN_ERR_MEMALLOC__("linked list structure"));
	*_list = _list_content;
	return _list;
}
void cgen_linkedlist_type__add_first(CGen_LinkedList(type) list, type content)
{
	LinkedNode_type _new;
	__CGEN_ASSERT__(list, __CGEN_METHOD_STR__("LinkedList", type, "AddFirst"), __CGEN_ERR_NULLREF__("linked list"));
	_new = (LinkedNode_type)calloc(1, sizeof(struct LinkedNode_type_Struct));
	__CGEN_ASSERT__(_new, __CGEN_METHOD_STR__("LinkedList", type, "AddFirst"), __CGEN_ERR_MEMALLOC__("new linked node structure"));
	_new->_content = content;
	_new->_previous = NULL;
	_new->_next = list->_first;
	if (list->_first)
	{
		list->_first->_previous = _new;
	}
	else
	{
		list->_last = _new;
	}
	list->_first = _new;
	list->_count++;
}
void cgen_linkedlist_type__add_last(CGen_LinkedList(type) list, type content)
{
	LinkedNode_type _new;
	__CGEN_ASSERT__(list, __CGEN_METHOD_STR__("LinkedList", type, "AddLast"), __CGEN_ERR_NULLREF__("linked list"));
	_new = (LinkedNode_type)calloc(1, sizeof(struct LinkedNode_type_Struct));
	__CGEN_ASSERT__(_new, __CGEN_METHOD_STR__("LinkedList", type, "AddLast"), __CGEN_ERR_MEMALLOC__("new linked node structure"));
	_new->_content = content;
	_new->_previous = list->_last;
	_new->_next = NULL;
	if (list->_last)
	{
		list->_last->_next = _new;
	}
	else
	{
		list->_first = _new;
	}
	list->_last = _new;
	list->_count++;
}
void cgen_linkedlist_type__remove_first(CGen_LinkedList(type) list)
{
	LinkedNode_type _tmp;
	__CGEN_ASSERT__(list, __CGEN_METHOD_STR__("LinkedList", type, "RemoveFirst"), __CGEN_ERR_NULLREF__("linked list"));
	__CGEN_ASSERT__(list->_first, __CGEN_METHOD_STR__("LinkedList", type, "RemoveFirst"), __CGEN_ERR_NULLREF__("linked list first element"));
	_tmp = list->_first;
	if (list->_first == list->_last)
	{
		list->_last = NULL;
	}
	else
	{
		list->_first->_next->_previous = NULL;
	}
	list->_first = list->_first->_next;
	free(_tmp);
	list->_count--;
}
void cgen_linkedlist_type__remove_last(CGen_LinkedList(type) list)
{
	LinkedNode_type _tmp;
	__CGEN_ASSERT__(list, __CGEN_METHOD_STR__("LinkedList", type, "RemoveLast"), __CGEN_ERR_NULLREF__("linked list"));
	__CGEN_ASSERT__(list->_last, __CGEN_METHOD_STR__("LinkedList", type, "RemoveLast"), __CGEN_ERR_NULLREF__("linked list last element"));
	_tmp = list->_last;
	if (list->_last == list->_first)
	{
		list->_first = NULL;
	}
	else
	{
		list->_last->_previous->_next = NULL;
	}
	list->_last = list->_last->_previous;
	free(_tmp);
	list->_count--;
}
static Enumerator_type __cgen_linkedlist_type__get_enumerator__(LinkedList_type list)
{
	Enumerator_type result = {
		._move_next = __cgen_type__move_next_linked__,
		._reset = __cgen_type__reset_linked__,
		.__linked.__first = list->_first,
		.__linked.__node = result.__linked.__first};
	return result;
}
static void __cgen_linkedlist_type__finalize__(LinkedList_type *list)
{
	__CGEN_ASSERT__(list, __CGEN_METHOD_STR__("LinkedList", type, "Finalize"), __CGEN_ERR_NULLREF__("linked list pointer"));
	__CGEN_ASSERT__(*list, __CGEN_METHOD_STR__("LinkedList", type, "Finalize"), __CGEN_ERR_NULLREF__("linked list"));
	__cgen_linkedlist_type__clear__(*list);
	free(*list);
	*list = NULL;
}
static LinkedList_type __cgen_linkedlist_type__clone__(LinkedList_type list)
{
	LinkedList_type _list;
	LinkedNode_type _iterator;
	__CGEN_ASSERT__(list, __CGEN_METHOD_STR__("LinkedList", type, "Clone"), __CGEN_ERR_NULLREF__("linked list"));
	_list = cgen_linkedlist_type__create();
	_iterator = list->_first;
	while (_iterator)
	{
		cgen_linkedlist_type__add_last(_list, _iterator->_content);
		_iterator = _iterator->_next;
	}
	return _list;
}
static void __cgen_linkedlist_type__clear__(LinkedList_type list)
{
	LinkedNode_type _current, _next;
	__CGEN_ASSERT__(list, __CGEN_METHOD_STR__("LinkedList", type, "Clear"), __CGEN_ERR_NULLREF__("linked list"));
	_current = list->_first;
	while (_current)
	{
		_next = _current->_next;
		free(_current);
		_current = _next;
	}
	list->_first = NULL;
	list->_last = NULL;
	list->_count = 0;
}
static LinkedList_type __cgen_linkedlist_type__sort__(LinkedList_type list, int32_t (*compare)(type x, type y), SortAim aim, SortLocation location)
{
	LinkedList_type _result;
	type *_tmp, *_save;
	LinkedNode_type _iterator, _current;
	int64_t _counter, _i;
	__CGEN_ASSERT__(list, __CGEN_METHOD_STR__("LinkedList", type, "Sort"), __CGEN_ERR_NULLREF__("linked list"));
	__CGEN_ASSERT__(compare, __CGEN_METHOD_STR__("LinkedList", type, "Sort"), __CGEN_ERR_NULLREF__("comparator function pointer"));
	if (!list->_count)
	{
		switch (location)
		{
		case CURRENT_COLLECTION:
			return list;
		case NEW_COLLECTION:
			return cgen_linkedlist_type__create();
		default:
			__CGEN_ASSERT__(false, __CGEN_METHOD_STR__("LinkedList", type, "Sort"), __CGEN_ERR_UNKNOW_ENUM_VAL__("location", SortLocation));
			break;
		}
	}
	_tmp = NULL;
	_save = (type *)calloc(list->_count, sizeof(type));
	__CGEN_ASSERT__(_save, __CGEN_METHOD_STR__("LinkedList", type, "Sort"), __CGEN_ERR_MEMALLOC__("temporary array used for sort"));
	_iterator = list->_first;
	for (_counter = 0; _counter < list->_count; _counter++)
	{
		_save[_counter] = _iterator->_content;
		_iterator = _iterator->_next;
	}
	switch (aim)
	{
	case DURATION_STABILITY:
		_tmp = (type *)malloc(list->_count * sizeof(type));
		__CGEN_ASSERT__(_tmp, __CGEN_METHOD_STR__("LinkedList", type, "Sort"), __CGEN_ERR_MEMALLOC__("temporary array used for sort (in aim of duration stability)"));
		__cgen_type__merge_sort__(_save, _tmp, 0, list->_count - 1, compare);
		free(_tmp);
		break;
	case MEMORY_USAGE:
		__cgen_type__quick_sort__(_save, 0, list->_count - 1, compare);
		break;
	default:
		__CGEN_ASSERT__(false, __CGEN_METHOD_STR__("LinkedList", type, "Sort"), __CGEN_ERR_UNKNOW_ENUM_VAL__("aim", SortAim));
		break;
	}
	switch (location)
	{
	case CURRENT_COLLECTION:
		_result = list;
		_current = list->_first;
		for (_i = 0; _i < list->_count; _i++)
		{
			_current->_content = _save[_i];
			_current = _current->_next;
		}
		break;
	case NEW_COLLECTION:
		_result = cgen_linkedlist_type__create();
		for (_i = 0; _i < list->_count; _i++)
		{
			cgen_linkedlist_type__add_last(_result, _save[_i]);
		}
		break;
	default:
		__CGEN_ASSERT__(false, __CGEN_METHOD_STR__("LinkedList", type, "Sort"), __CGEN_ERR_UNKNOW_ENUM_VAL__("location", SortLocation));
		break;
	}
	free(_save);
	return _result;
}

/* IEnumerable interface functions */

void cgen_finalize_type(CGen_IEnumerable(type) * enumerable)
{
	__CGEN_ASSERT__(enumerable, __CGEN_METHOD_STR__("IEnumerable", type, "Finalize"), __CGEN_ERR_NULLREF__("enumerable pointer"));
	__CGEN_ASSERT__(*enumerable, __CGEN_METHOD_STR__("IEnumerable", type, "Finalize"), __CGEN_ERR_NULLREF__("enumerable"));
	__CGEN_ASSERT__(CGen_Is_IEnumerable(*enumerable), __CGEN_METHOD_STR__("IEnumerable", type, "Finalize"), __CGEN_ERR_NOT_ENUMERABLE__(type, "supposed enumerable passed in argument"));
	switch ((*enumerable)->__descriptor)
	{
	case ARRAY_T:
		__cgen_array_type__finalize__((Array_type *)enumerable);
		return;
	case LINKEDLIST_T:
		__cgen_linkedlist_type__finalize__((LinkedList_type *)enumerable);
		return;
	default:
		__CGEN_ASSERT__(false, __CGEN_METHOD_STR__("IEnumerable", type, "Finalize"), __CGEN_ERR_NOT_EXPECTED_ENUM_VAL__("enumerable type descriptor", EnumerableTypeDescriptor));
		return;
	}
}
CGen_Enumerator(type) cgen_get_enumerator_type(CGen_IEnumerable(type) enumerable)
{
	Enumerator_type result;
	__CGEN_ASSERT__(enumerable, __CGEN_METHOD_STR__("IEnumerable", type, "GetEnumerator"), __CGEN_ERR_NULLREF__("enumerable"));
	__CGEN_ASSERT__(CGen_Is_IEnumerable(enumerable), __CGEN_METHOD_STR__("IEnumerable", type, "GetEnumerator"), __CGEN_ERR_NOT_ENUMERABLE__(type, "supposed enumerable passed in argument"));
	switch (enumerable->__descriptor)
	{
	case ARRAY_T:
		result = __cgen_array_type__get_enumerator__((Array_type)enumerable);
		break;
	case LINKEDLIST_T:
		result = __cgen_linkedlist_type__get_enumerator__((LinkedList_type)enumerable);
		break;
	default:
		__CGEN_ASSERT__(false, __CGEN_METHOD_STR__("IEnumerable", type, "GetEnumerator"), __CGEN_ERR_NOT_EXPECTED_ENUM_VAL__("enumerable type descriptor", EnumerableTypeDescriptor));
		break;
	}
	result._reset(&result);
	return result;
}
CGen_IEnumerable(type) cgen_clone_type(CGen_IEnumerable(type) enumerable)
{
	__CGEN_ASSERT__(enumerable, __CGEN_METHOD_STR__("IEnumerable", type, "Clone"), __CGEN_ERR_NULLREF__("enumerable"));
	__CGEN_ASSERT__(CGen_Is_IEnumerable(enumerable), __CGEN_METHOD_STR__("IEnumerable", type, "Clone"), __CGEN_ERR_NOT_ENUMERABLE__(type, "supposed enumerable passed in argument"));
	switch (enumerable->__descriptor)
	{
	case ARRAY_T:
		return (IEnumerable_type)__cgen_array_type__clone__((Array_type)enumerable);
	case LINKEDLIST_T:
		return (IEnumerable_type)__cgen_linkedlist_type__clone__((LinkedList_type)enumerable);
	default:
		__CGEN_ASSERT__(false, __CGEN_METHOD_STR__("IEnumerable", type, "Clone"), __CGEN_ERR_NOT_EXPECTED_ENUM_VAL__("enumerable type descriptor", EnumerableTypeDescriptor));
		return NULL;
	}
}
CGen_IEnumerable(type) cgen_sort_type(CGen_IEnumerable(type) enumerable, CGen_SortOptions(type) options)
{
	__CGEN_ASSERT__(enumerable, __CGEN_METHOD_STR__("IEnumerable", type, "Sort"), __CGEN_ERR_NULLREF__("enumerable"));
	__CGEN_ASSERT__(CGen_Is_IEnumerable(enumerable), __CGEN_METHOD_STR__("IEnumerable", type, "Sort"), __CGEN_ERR_NOT_ENUMERABLE__(type, "supposed enumerable passed in argument"));
	__CGEN_ASSERT__(options._compare, __CGEN_METHOD_STR__("IEnumerable", type, "Sort"), __CGEN_ERR_NULLREF__("comparator function pointer"));
	__CGEN_ASSERT__(options._aim == DURATION_STABILITY || options._aim == MEMORY_USAGE, __CGEN_METHOD_STR__("IEnumerable", type, "Sort"), __CGEN_ERR_UNKNOW_ENUM_VAL__("sort aim passed in sort options", SortAim));
	__CGEN_ASSERT__(options._location == CURRENT_COLLECTION || options._location == NEW_COLLECTION, __CGEN_METHOD_STR__("IEnumerable", type, "Sort"), __CGEN_ERR_UNKNOW_ENUM_VAL__("sort location passed in sort options", SortLocation));
	switch (enumerable->__descriptor)
	{
	case ARRAY_T:
		return (IEnumerable_type)__cgen_array_type__sort__((Array_type)enumerable, options._compare, options._aim, options._location);
	case LINKEDLIST_T:
		return (IEnumerable_type)__cgen_linkedlist_type__sort__((LinkedList_type)enumerable, options._compare, options._aim, options._location);
	default:
		__CGEN_ASSERT__(false, __CGEN_METHOD_STR__("IEnumerable", type, "Sort"), __CGEN_ERR_NOT_EXPECTED_ENUM_VAL__("enumerable type descriptor", EnumerableTypeDescriptor));
		return NULL;
	}
}

/* ICollection interface functions */

void cgen_clear_type(CGen_ICollection(type) collection)
{
	__CGEN_ASSERT__(collection, __CGEN_METHOD_STR__("ICollection", type, "Clear"), __CGEN_ERR_NULLREF__("collection"));
	__CGEN_ASSERT__(CGen_Is_ICollection(collection), __CGEN_METHOD_STR__("ICollection", type, "Clear"), __CGEN_ERR_NOT_COLLECTION__(type, "supposed collection passed in argument"));
	switch (collection->__descriptor)
	{
	case LINKEDLIST_T:
		__cgen_linkedlist_type__clear__((LinkedList_type)collection);
		break;
	default:
		__CGEN_ASSERT__(false, __CGEN_METHOD_STR__("ICollection", type, "Clear"), __CGEN_ERR_NOT_EXPECTED_ENUM_VAL__("collection type descriptor", EnumerableTypeDescriptor));
		break;
	}
}
/* --- macro_end --- */

/* ===== GENERICS MULTILINES MACROS ===== */

/* Foreach operator macro */

/* Iterate over an enumerable (this operation is a for each loop).
Warning : the enumerable can't be modified during a foreach operation ! */
/* --- macro_start --- CGen_ForEach(type, enumerable, element_name, action) */
do
{
	type *element_name;
	CGen_Enumerator(type) __enumerator = CGen_GetEnumerator(type, enumerable);
	while (__enumerator._current)
	{
		element_name = __enumerator._current;
		action;
		__enumerator._move_next(&(__enumerator));
	}
} while (false)
/* --- macro_end --- */

#endif