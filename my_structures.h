#ifndef __MY_STRUCTURES_H__
#define __MY_STRUCTURES_H__

#include "lib/ctuple.h"

typedef char *string;

typedef struct person
{
    char name[20];
    int age;
} person;

INCLUDE_TUPLE2(float, person);

#endif
