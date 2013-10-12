#ifndef HACK_INT_H
#define HACK_INT_H

#include "Python.h"
#include "modsupport.h"

struct _PyIntBlock {
    struct _PyIntBlock * next;
    PyIntObject objects[257];
};

typedef struct _PyIntBlock PyIntBlock;

#endif
