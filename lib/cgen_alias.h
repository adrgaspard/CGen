#ifndef __CGEN_ALIAS_H__
#define __CGEN_ALIAS_H__

#define Array(type) array_##type
#define LinkedList(type) linkedlist_##type

#define Create(collection, type, ...) collection##_##type##__create(__VA_ARGS__)

#endif