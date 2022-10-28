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
	DURATION_STABILITY,
	MEMORY_USAGE
} sort_aim;
typedef enum sort_location
{
	CURRENT_COLLECTION,
	NEW_COLLECTION
} sort_location;
typedef enum enumerable_implementation
{
	ARRAY = 0b10000000,
	LINKEDLIST = 0b10000001,
	LIST = 0b10000010
} enumerable_implementation;

#define IS_ENUMERABLE(obj) obj->enumerable_code & 0b10000000

/* --- Ignore --- */ typedef int type;

/* Generics interfaces body parts */

/* --- macro_start --- ENUMERABLE_INTERFACE_BODY(type) */
enumerable_implementation enumerable_code;
/* --- macro_end --- */

/* Generics types part */

/* --- macro_start --- INCLUDE_GENERICS_ABSTRACTION(type) */
typedef struct indexed_type_data
{
	type *data;
	uint64_t count;
	uint64_t index;
} indexed_type_data;
typedef struct linked_type_data
{
	struct linkednode_type_struct *first;
	struct linkednode_type_struct *node;
} linked_type_data;
typedef struct enumerator_type
{
	type *current;
	void (*move_next)(struct enumerator_type *enumerator);
	void (*reset)(struct enumerator_type *enumerator);
	union {
		indexed_type_data indexed;
		linked_type_data linked;
	};
} enumerator_type;
typedef struct enumerable_type_struct
{
	/* --- Ignore --- */ enumerable_implementation enumerable_code;
	/* --- macro_usage --- ENUMERABLE_INTERFACE_BODY(type) */
} * enumerable_type;
typedef struct array_type_struct
{
	/* --- macro_usage --- ENUMERABLE_INTERFACE_BODY(type) */
	type *items;
	int64_t length;
} * array_type;
typedef struct list_type_struct
{
	/* --- macro_usage --- ENUMERABLE_INTERFACE_BODY(type) */
	type *items;
	int64_t length;
	int64_t capacity;
} * list_type;
typedef struct linkednode_type_struct
{
	struct linkednode_type_struct *previous;
	struct linkednode_type_struct *next;
	type content;
} * linkednode_type;
typedef struct linkedlist_type_struct
{
	/* --- macro_usage --- ENUMERABLE_INTERFACE_BODY(type) */
	linkednode_type first;
	linkednode_type last;
	int64_t count;
} * linkedlist_type;

/* Enumerator function */
enumerator_type get_enumerator_type(enumerable_type enumerable);

/* Array functions */
array_type array_type__create(int64_t length);
void array_type__finalize(array_type *array);
array_type array_type__clone(array_type array);
array_type array_type__sort(array_type array, int32_t (*compare)(type x, type y), sort_aim aim, sort_location location);

/* Linked list functions */
linkedlist_type linkedlist_type__create();
void linkedlist_type__finalize(linkedlist_type *list);
linkedlist_type linkedlist_type__clone(linkedlist_type list);
void linkedlist_type__add_first(linkedlist_type list, type content);
void linkedlist_type__add_last(linkedlist_type list, type content);
void linkedlist_type__remove_first(linkedlist_type list);
void linkedlist_type__remove_last(linkedlist_type list);
void linkedlist_type__clear(linkedlist_type list);
linkedlist_type linkedlist_type__sort(linkedlist_type list, int32_t (*compare)(type x, type y), sort_aim aim, sort_location location);
/* --- macro_end --- */

/* --- macro_start --- INCLUDE_GENERICS_IMPLEMENTATION(type) */
/* Private core sort functions */
void __generics_type__merge_sort__(type *_array, type *_tmp, int64_t _start, int64_t _end, int32_t (*_compare)(type _x, type _y));
int64_t __generics_type__partition__(type *_array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y));
void __generics_type__quick_sort__(type *_array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y));
void __generics_type__merge_sort__(type *_array, type *_tmp, int64_t _start, int64_t _end, int32_t (*_compare)(type _x, type _y))
{
	int64_t _middle, _i, _j, _k;
	if (_end <= _start)
	{
		return;
	}
	_middle = (_start + _end) / 2;
	__generics_type__merge_sort__(_array, _tmp, _start, _middle, _compare);
	__generics_type__merge_sort__(_array, _tmp, _middle + 1, _end, _compare);
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
int64_t __generics_type__partition__(type *_array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y))
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
void __generics_type__quick_sort__(type *_array, int64_t _low, int64_t _high, int32_t (*_compare)(type _x, type _y))
{
	int64_t _pivot_index;
	if (_low < _high)
	{
		_pivot_index = __generics_type__partition__(_array, _low, _high, _compare);
		__generics_type__quick_sort__(_array, _low, _pivot_index - 1, _compare);
		__generics_type__quick_sort__(_array, _pivot_index + 1, _high, _compare);
	}
}

/* Private enumerator utils functions */
void __generics_type__move_next_indexed__(enumerator_type *enumerator)
{
	if (enumerator->indexed.index >= enumerator->indexed.count)
	{
		enumerator->current = NULL;
	}
	else
	{
		enumerator->indexed.index++;
		enumerator->current = &(enumerator->indexed.data[enumerator->indexed.index]);
	}
}
void __generics_type__move_next_linked__(enumerator_type *enumerator)
{
	if (enumerator->linked.node->next)
	{
		enumerator->linked.node = enumerator->linked.node->next;
		enumerator->current = &(enumerator->linked.node->content);
	}
	else
	{
		enumerator->linked.node = NULL;
		enumerator->current = NULL;
	}
}
void __generics_type__reset_indexed__(enumerator_type *enumerator)
{
	enumerator->indexed.index = 0;
	enumerator->current = enumerator->indexed.count ? &(enumerator->indexed.data[0]) : NULL;
}
void __generics_type__reset_linked__(enumerator_type *enumerator)
{
	enumerator->linked.node = enumerator->linked.first;
	enumerator->current = enumerator->linked.node ? &(enumerator->linked.node->content) : NULL;
}

/* Enumerator function */
enumerator_type get_enumerator_type(enumerable_type enumerable)
{
	enumerator_type result;
	assert(enumerable);
	switch (enumerable->enumerable_code)
	{
	case ARRAY:
		result.move_next = __generics_type__move_next_indexed__;
		result.reset = __generics_type__reset_indexed__;
		result.indexed.data = ((array_type)enumerable)->items;
		result.indexed.count = ((array_type)enumerable)->length;
		result.indexed.index = 0;
		break;
	case LINKEDLIST:
		result.move_next = __generics_type__move_next_linked__;
		result.reset = __generics_type__reset_linked__;
		result.linked.first = ((linkedlist_type)enumerable)->first;
		result.linked.node = result.linked.first;
		break;
	default:
		assert(false);
		break;
	}
	result.reset(&result);
	return result;
}

/* Array functions */
array_type array_type__create(int64_t length)
{
	array_type _array = (array_type)calloc(1, sizeof(struct array_type_struct));
	assert(_array);
	_array->enumerable_code = ARRAY;
	_array->length = length;
	_array->items = (type *)calloc(length, sizeof(type));
	assert(_array->items);
	return _array;
}
void array_type__finalize(array_type *array)
{
	assert(array && *array && (*array)->items);
	free((*array)->items);
	free(*array);
	*array = NULL;
}
array_type array_type__clone(array_type array)
{
	array_type _clone;
	assert(array && array->items && array->length);
	_clone = array_type__create(array->length);
	memcpy(_clone->items, array->items, _clone->length * sizeof(type));
	return _clone;
}
array_type array_type__sort(array_type array, int32_t (*compare)(type x, type y), sort_aim aim, sort_location location)
{
	array_type _result;
	type *_tmp = NULL;
	assert(array && compare && array->items && array->length);
	switch (location)
	{
	case CURRENT_COLLECTION:
		_result = array;
		break;
	case NEW_COLLECTION:
		_result = array_type__clone(array);
		break;
	default:
		assert(false && (location == CURRENT_COLLECTION || location == NEW_COLLECTION));
	}
	switch (aim)
	{
	case DURATION_STABILITY:
		_tmp = (type *)malloc(_result->length * sizeof(type));
		assert(_tmp);
		__generics_type__merge_sort__(_result->items, _tmp, 0, _result->length - 1, compare);
		free(_tmp);
		break;
	case MEMORY_USAGE:
		__generics_type__quick_sort__(_result->items, 0, _result->length - 1, compare);
		break;
	default:
		assert(false && (aim == DURATION_STABILITY || aim == MEMORY_USAGE));
	}
	return _result;
}

/* Linked list functions */
linkedlist_type linkedlist_type__create()
{
	linkedlist_type _list = (linkedlist_type)calloc(1, sizeof(struct linkedlist_type_struct));
	assert(_list);
	_list->enumerable_code = LINKEDLIST;
	return _list;
}
void linkedlist_type__finalize(linkedlist_type *list)
{
	assert(list && *list);
	linkedlist_type__clear(*list);
	free(*list);
	*list = NULL;
}
linkedlist_type linkedlist_type__clone(linkedlist_type list)
{
	linkedlist_type _list;
	linkednode_type _iterator;
	assert(list);
	_list = linkedlist_type__create();
	_iterator = list->first;
	while (_iterator)
	{
		linkedlist_type__add_last(_list, _iterator->content);
		_iterator = _iterator->next;
	}
	return _list;
}
void linkedlist_type__add_first(linkedlist_type list, type content)
{
	linkednode_type _new;
	assert(list);
	_new = (linkednode_type)calloc(1, sizeof(struct linkednode_type_struct));
	assert(_new);
	_new->content = content;
	_new->previous = NULL;
	_new->next = list->first;
	if (list->first)
	{
		list->first->previous = _new;
	}
	else
	{
		list->last = _new;
	}
	list->first = _new;
	list->count++;
}
void linkedlist_type__add_last(linkedlist_type list, type content)
{
	linkednode_type _new;
	assert(list);
	_new = (linkednode_type)calloc(1, sizeof(struct linkednode_type_struct));
	assert(_new);
	_new->content = content;
	_new->previous = list->last;
	_new->next = NULL;
	if (list->last)
	{
		list->last->next = _new;
	}
	else
	{
		list->first = _new;
	}
	list->last = _new;
	list->count++;
}
void linkedlist_type__remove_first(linkedlist_type list)
{
	linkednode_type _tmp;
	assert(list && list->first);
	_tmp = list->first;
	if (list->first == list->last)
	{
		list->last = NULL;
	}
	else
	{
		list->first->next->previous = NULL;
	}
	list->first = list->first->next;
	free(_tmp);
	list->count--;
}
void linkedlist_type__remove_last(linkedlist_type list)
{
	linkednode_type _tmp;
	assert(list && list->last);
	_tmp = list->last;
	if (list->last == list->first)
	{
		list->first = NULL;
	}
	else
	{
		list->last->previous->next = NULL;
	}
	list->last = list->last->previous;
	free(_tmp);
	list->count--;
}
void linkedlist_type__clear(linkedlist_type list)
{
	linkednode_type _current, _next;
	assert(list);
	_current = list->first;
	while (_current)
	{
		_next = _current->next;
		free(_current);
		_current = _next;
	}
	list->first = NULL;
	list->last = NULL;
	list->count = 0;
}
linkedlist_type linkedlist_type__sort(linkedlist_type list, int32_t (*compare)(type x, type y), sort_aim aim, sort_location location)
{
	linkedlist_type _result;
	type *_tmp, *_save;
	linkednode_type _iterator, _current;
	int64_t _counter, _i;
	assert(list && compare);
	if (!list->count)
	{
		switch (location)
		{
		case CURRENT_COLLECTION:
			return list;
		case NEW_COLLECTION:
			return linkedlist_type__create();
		default:
			assert(false && (location == CURRENT_COLLECTION || location == NEW_COLLECTION));
		}
	}
	_tmp = NULL;
	_save = (type *)calloc(list->count, sizeof(type));
	assert(_save);
	_iterator = list->first;
	for (_counter = 0; _counter < list->count; _counter++)
	{
		_save[_counter] = _iterator->content;
		_iterator = _iterator->next;
	}
	switch (aim)
	{
	case DURATION_STABILITY:
		_tmp = (type *)malloc(list->count * sizeof(type));
		assert(_tmp);
		__generics_type__merge_sort__(_save, _tmp, 0, list->count - 1, compare);
		free(_tmp);
		break;
	case MEMORY_USAGE:
		__generics_type__quick_sort__(_save, 0, list->count - 1, compare);
		break;
	default:
		assert(false);
	}
	switch (location)
	{
	case CURRENT_COLLECTION:
		_result = list;
		_current = list->first;
		for (_i = 0; _i < list->count; _i++)
		{
			_current->content = _save[_i];
			_current = _current->next;
		}
		break;
	case NEW_COLLECTION:
		_result = linkedlist_type__create();
		for (_i = 0; _i < list->count; _i++)
		{
			linkedlist_type__add_last(_result, _save[_i]);
		}
		break;
	default:
		assert(false);
	}
	free(_save);
	return _result;
}
/* --- macro_end --- */

/* Warning : the enumerable can't be modified during a foreach operation ! */
/* --- macro_start --- FOREACH(type, enumerable, element_name, action) */
do
{
	type *element_name;
	enumerator_type _enumerator = get_enumerator_JOINtype((enumerable_type)enumerable);
	while (_enumerator.current)
	{
		element_name = _enumerator.current;
		action;
		_enumerator.move_next(&(_enumerator));
	}
}
while (false)
/* --- macro_end --- */

#endif