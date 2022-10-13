#ifndef __CGEN_H__
#define __CGEN_H__

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Global types part */

typedef enum sort_aim { DURATION_STABILITY, MEMORY_USAGE } sort_aim;
typedef enum sort_result_type { CURRENT_COLLECTION, NEW_COLLECTION } sort_result_type;

/* Generics types part */

#define INCLUDE_GENERICS_ABSTRACTION(type)																														\
/* Type declarations */																																			\
typedef struct array_##type##_struct																															\
{																																								\
	type *items;																																				\
	int64_t length;																																				\
} *array_##type;																																				\
typedef struct list_##type##_struct																																\
{																																								\
	type *items;																																				\
	int64_t length;																																				\
	int64_t capacity;																																			\
} *list_##type;																																					\
typedef struct linkednode_##type##_struct																														\
{										    																													\
	struct linkednode_##type##_struct *previous;																												\
	struct linkednode_##type##_struct *next;        																											\
	type content;						    																													\
} *linkednode_##type;					    																													\
typedef struct linkedlist_##type##_struct		    																											\
{										    																													\
	linkednode_##type first;			    																													\
	linkednode_##type last;			    																														\
	int64_t count;																																				\
} *linkedlist_##type;																																			\
																																								\
/* Private core sort functions */																																\
void __generics_##type##__merge_sort__(type* _array, type* _tmp, int64_t _start, int64_t _end, int32_t (*_compare)(type _x, type _y));							\
int64_t __generics_##type##__partition__(type* _array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y));										\
void __generics_##type##__quick_sort__(type* _array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y));										\
																																								\
/* Array functions */																																			\
array_##type array_##type##__create(int64_t length);																											\
void array_##type##__finalize(array_##type *array);																												\
array_##type array_##type##__clone(array_##type array);																											\
array_##type array_##type##__sort(array_##type array, int32_t (*compare)(type x, type y), sort_aim aim, sort_result_type result_type);							\
																																								\
/* Linked list functions */																																		\
linkedlist_##type linkedlist_##type##__create();																												\
void linkedlist_##type##__finalize(linkedlist_##type *list);																									\
linkedlist_##type linkedlist_##type##__clone(linkedlist_##type list);																							\
void linkedlist_##type##__add_first(linkedlist_##type list, type content);																						\
void linkedlist_##type##__add_last(linkedlist_##type list, type content);																						\
void linkedlist_##type##__remove_first(linkedlist_##type list);																									\
void linkedlist_##type##__remove_last(linkedlist_##type list);																									\
void linkedlist_##type##__clear(linkedlist_##type list);																										\
linkedlist_##type linkedlist_##type##__sort(linkedlist_##type list, int32_t (*compare)(type x, type y), sort_aim aim, sort_result_type result_type);			\
																																								\

#define INCLUDE_GENERICS_IMPLEMENTATION(type)																													\
/* Private core sort functions */																																\
void __generics_##type##__merge_sort__(type* _array, type* _tmp, int64_t _start, int64_t _end, int32_t (*_compare)(type _x, type _y))							\
{																																								\
	int64_t _middle, _i, _j, _k;																																\
	if (_end <= _start)																																			\
	{																																							\
		return;																																					\
	}																																							\
	_middle = (_start + _end) / 2;																																\
	__generics_##type##__merge_sort__(_array, _tmp, _start, _middle, _compare);																					\
	__generics_##type##__merge_sort__(_array, _tmp, _middle + 1, _end, _compare);																				\
	_i = _start;																																				\
	_j = _middle + 1;																																			\
	for (_k = _start; _k <= _end; _k++)																															\
	{																																							\
		if (_i > _middle)																																		\
		{																																						\
			_tmp[_k] = _array[_j];																																\
			_j++;																																				\
		}																																						\
		else if (_j > _end)																																		\
		{																																						\
			_tmp[_k] = _array[_i];																																\
			_i++;																																				\
		}																																						\
		else if (_compare(_array[_i], _array[_j]) < 0)																											\
		{																																						\
			_tmp[_k] = _array[_i];																																\
			_i++;																																				\
		}																																						\
		else																																					\
		{																																						\
			_tmp[_k] = _array[_j];																																\
			_j++;																																				\
		}																																						\
	}																																							\
	for (_k = _start; _k <= _end; _k++)																															\
	{																																							\
		_array[_k] = _tmp[_k];																																	\
	}																																							\
}																																								\
int64_t __generics_##type##__partition__(type* _array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y))										\
{																																								\
	type _pivot , _tmp;																																			\
	int64_t _i, _j;																																				\
	_i = _low;																																					\
	_pivot = _array[_high];																																		\
	for (_j = _low; _j < _high; _j++)																															\
	{																																							\
		if (_compare(_array[_j], _pivot) <= 0)																													\
		{																																						\
			_tmp = _array[_i];																																	\
			_array[_i] = _array[_j];																															\
			_array[_j] = _tmp;																																	\
			_i++;																																				\
		}																																						\
	}																																							\
	_tmp = _array[_i];																																			\
	_array[_i] = _array[_high];																																	\
	_array[_high] = _tmp;																																		\
	return _i;																																					\
}																																								\
void __generics_##type##__quick_sort__(type* _array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y))										\
{																																								\
	int64_t _pivot_index;																																		\
	if (_low < _high)																																			\
	{																																							\
		_pivot_index = __generics_##type##__partition__(_array, _low, _high, _compare);																			\
		__generics_##type##__quick_sort__(_array, _low, _pivot_index - 1, _compare);																			\
		__generics_##type##__quick_sort__(_array, _pivot_index + 1, _high, _compare);																			\
	}																																							\
}																																								\
																																								\
/* Array functions */																																			\
array_##type array_##type##__create(int64_t length)																												\
{																																								\
	array_##type _array = (array_##type)calloc(1, sizeof(struct array_##type##_struct));																		\
	assert(_array);																																				\
	_array->length = length;																																	\
	_array->items = (type*)calloc(length, sizeof(type));																										\
	assert(_array->items);																																		\
	return _array;																																				\
}																																								\
void array_##type##__finalize(array_##type *array)																												\
{																																								\
	assert(array && *array && (*array)->items);																													\
	free((*array)->items);																																		\
	free(*array);																																				\
	*array = NULL;																																				\
}																																								\
array_##type array_##type##__clone(array_##type array)																											\
{																																								\
	array_##type _clone;																																		\
	assert(array && array->items && array->length);																												\
	_clone = array_##type##__create(array->length);																												\
	memcpy(_clone->items, array->items, _clone->length * sizeof(type));																							\
	return _clone;																																				\
}																																								\
array_##type array_##type##__sort(array_##type array, int32_t (*compare)(type x, type y), sort_aim aim, sort_result_type result_type)							\
{																																								\
	array_##type _result;																																		\
	type *_tmp = NULL;																																			\
	assert(array && compare && array->items && array->length);																									\
	switch (result_type)																																		\
	{																																							\
		case CURRENT_COLLECTION:																																\
			_result = array;																																	\
			break;																																				\
		case NEW_COLLECTION:																																	\
			_result = array_##type##__clone(array);																												\
			break;																																				\
		default:																																				\
			assert(false && (result_type == CURRENT_COLLECTION || result_type == NEW_COLLECTION));																\
	}																																							\
	switch (aim)																																				\
	{																																							\
		case DURATION_STABILITY:																																\
			_tmp = (type*)malloc(_result->length * sizeof(type));																								\
			assert(_tmp);																																		\
			__generics_##type##__merge_sort__(_result->items, _tmp, 0, _result->length - 1, compare);															\
			free(_tmp);																																			\
			break;																																				\
		case MEMORY_USAGE:																																		\
			__generics_##type##__quick_sort__(_result->items, 0, _result->length - 1, compare);																	\
			break;																																				\
		default:																																				\
			assert(false && (aim == DURATION_STABILITY || aim == MEMORY_USAGE));																				\
	}																																							\
	return _result;																																				\
}																																								\
																																								\
/* Linked list functions */																																		\
linkedlist_##type linkedlist_##type##__create()																													\
{																																								\
	linkedlist_##type _list = (linkedlist_##type)calloc(1, sizeof(struct linkedlist_##type##_struct));															\
	assert(_list);																																				\
	return _list;																																				\
}																																								\
void linkedlist_##type##__finalize(linkedlist_##type *list)																										\
{																																								\
	assert(list && *list);																																		\
	linkedlist_##type##__clear(*list);																															\
	free(*list);																																				\
	*list = NULL;																																				\
}																																								\
linkedlist_##type linkedlist_##type##__clone(linkedlist_##type list)																							\
{																																								\
	linkedlist_##type _list;																																	\
	linkednode_##type _iterator;																																\
	assert(list);																																				\
	_list = linkedlist_##type##__create();																														\
	_iterator = list->first;																																	\
	while (_iterator)																																			\
	{																																							\
		linkedlist_##type##__add_last(_list, _iterator->content);																								\
		_iterator = _iterator->next;																															\
	}																																							\
	return _list;																																				\
}																																								\
void linkedlist_##type##__add_first(linkedlist_##type list, type content)																						\
{																																								\
	linkednode_##type _new;																																		\
	assert(list);																																				\
	_new = (linkednode_##type)calloc(1, sizeof(struct linkednode_##type##_struct));																				\
	assert(_new);																																				\
	_new->content = content;																																	\
	_new->previous = NULL;																																		\
	_new->next = list->first;																																	\
	if (list->first)																																			\
	{																																							\
		list->first->previous = _new;																															\
	}																																							\
	else																																						\
	{																																							\
		list->last = _new;																																		\
	}																																							\
	list->first = _new;																																			\
	list->count++;																																				\
}																																								\
void linkedlist_##type##__add_last(linkedlist_##type list, type content)																						\
{																																								\
	linkednode_##type _new;																																		\
	assert(list);																																				\
	_new = (linkednode_##type)calloc(1, sizeof(struct linkednode_##type##_struct));																				\
	assert(_new);																																				\
	_new->content = content;																																	\
	_new->previous = list->last;																																\
	_new->next = NULL;																																			\
	if (list->last)																																				\
	{																																							\
		list->last->next = _new;																																\
	}																																							\
	else																																						\
	{																																							\
		list->first = _new;																																		\
	}																																							\
	list->last = _new;																																			\
	list->count++;																																				\
}																																								\
void linkedlist_##type##__remove_first(linkedlist_##type list)																									\
{																																								\
	linkednode_##type _tmp;																																		\
	assert(list && list->first);																																\
	_tmp = list->first;																																			\
	if (list->first == list->last)																																\
	{																																							\
		list->last = NULL;																																		\
	}																																							\
	else																																						\
	{																																							\
		list->first->next->previous = NULL;																														\
	}																																							\
	list->first = list->first->next;																															\
	free(_tmp);																																					\
	list->count--;																																				\
}																																								\
void linkedlist_##type##__remove_last(linkedlist_##type list)																									\
{																																								\
	linkednode_##type _tmp;																																		\
	assert(list && list->last);																																	\
	_tmp = list->last;																																			\
	if (list->last == list->first)																																\
	{																																							\
		list->first = NULL;																																		\
	}																																							\
	else																																						\
	{																																							\
		list->last->previous->next = NULL;																														\
	}																																							\
	list->last = list->last->previous;																															\
	free(_tmp);																																					\
	list->count--;																																				\
}																																								\
void linkedlist_##type##__clear(linkedlist_##type list)																											\
{																																								\
	linkednode_##type _current, _next;																															\
	assert(list);																																				\
	_current = list->first;																																		\
	while (_current)																																			\
	{																																							\
		_next = _current->next;																																	\
		free(_current);																																			\
		_current = _next;																																		\
	}																																							\
	list->first = NULL;																																			\
	list->last = NULL;																																			\
	list->count = 0;																																			\
}																																								\
linkedlist_##type linkedlist_##type##__sort(linkedlist_##type list, int32_t (*compare)(type x, type y), sort_aim aim, sort_result_type result_type)				\
{																																								\
	linkedlist_##type _result;																																	\
	type *_tmp, *_save;																																			\
	linkednode_##type _iterator, _current;																														\
	int64_t _counter, _i;																																		\
	assert(list && compare);																																	\
	if (!list->count)																																			\
	{																																							\
		switch (result_type)																																	\
		{																																						\
			case CURRENT_COLLECTION:																															\
				return list;																																	\
			case NEW_COLLECTION:																																\
				return linkedlist_##type##__create();																											\
			default:																																			\
				assert(false && (result_type == CURRENT_COLLECTION || result_type == NEW_COLLECTION));															\
		}																																						\
	}																																							\
	_tmp = NULL;																																				\
	_save = (type*)calloc(list->count, sizeof(type));																											\
	assert(_save);																																				\
	_iterator = list->first;																																	\
	for (_counter = 0; _counter < list->count; _counter++) 																										\
	{																																							\
		_save[_counter] = _iterator->content;																													\
		_iterator = _iterator->next;																															\
	}																																							\
	switch (aim)																																				\
	{																																							\
		case DURATION_STABILITY:																																\
			_tmp = (type*)malloc(list->count * sizeof(type));																									\
			assert(_tmp);																																		\
			__generics_##type##__merge_sort__(_save, _tmp, 0, list->count - 1, compare);																		\
			free(_tmp);																																			\
			break;																																				\
		case MEMORY_USAGE:																																		\
			__generics_##type##__quick_sort__(_save, 0, list->count - 1, compare);																				\
			break;																																				\
		default:																																				\
			assert(false && (aim == DURATION_STABILITY || aim == MEMORY_USAGE));																				\
	}																																							\
	switch (result_type)																																		\
	{																																							\
		case CURRENT_COLLECTION:																																\
			_result = list;																																		\
			_current = list->first;																																\
			for (_i = 0; _i < list->count; _i++)																												\
			{																																					\
				_current->content = _save[_i];																													\
				_current = _current->next;																														\
			}																																					\
			break;																																				\
		case NEW_COLLECTION:																																	\
			_result = linkedlist_##type##__create();																											\
			for (_i = 0; _i < list->count; _i++)																												\
			{																																					\
				linkedlist_##type##__add_last(_result, _save[_i]);																								\
			}																																					\
			break;																																				\
		default:																																				\
			assert(false && (result_type == CURRENT_COLLECTION || result_type == NEW_COLLECTION));																\
	}																																							\
	free(_save);																																				\
	return _result;																																				\
}																																								\

/* Array iterator */
#define ARRAY_FOREACH(type, array, index_name, element_name, action)																							\
do																																								\
{																																								\
	int64_t index_name;																																			\
	type element_name;																																			\
	assert(array);																																				\
	for (index_name = 0; index_name < array->length; index_name++)																								\
	{																																							\
		element_name = array->items[index_name];																												\
		action;																																					\
	}																																							\
} while (0)

/* Linked list iterator */
/* Warning : the linked list can't be modified during a foreach operation ! */
#define LINKEDLIST_FOREACH(type, list, element_name, action)																									\
do																																								\
{																																								\
	linkednode_##type _linkedlist_##type##_##element_name##_it;																									\
	type element_name;																																			\
	assert(list);																																				\
	_linkedlist_##type##_##element_name##_it = (list)->first;																									\
	while (_linkedlist_##type##_##element_name##_it)																											\
	{																																							\
		element_name = _linkedlist_##type##_##element_name##_it->content;																						\
		action;																																					\
		_linkedlist_##type##_##element_name##_it = _linkedlist_##type##_##element_name##_it->next;																\
	}																																							\
} while (0)

#endif