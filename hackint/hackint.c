#include "hackint.h"
#include <stdio.h>

extern int small_neg_ints;
extern int small_pos_ints;

//print the range of small ints
void printRange()
{
    if (small_neg_ints + small_pos_ints <= 0)
    {
        printf("small int is no available\n");
        return;
    }
    printf("small ints's range: -%d <= %d\n", small_neg_ints, small_pos_ints);
}
//

extern PyIntBlock * block_list;
void printBlockInfo()
{
    int count = 0; // number of PyIntBlock
    PyIntBlock * p = block_list;
    while (p != NULL)
    {
        ++count;
        p = p->next;
    }
    printf("block_list size: %d\n", count);
}

PyObject * wrap_printInt(PyObject* self, PyObject* args)
{
    printRange();
    printBlockInfo();
    return  Py_None;
}

PyObject * wrap_printAddr(PyObject* self, PyObject* args)
{
    PyTupleObject * tupleArgs = (PyTupleObject *)args;
    printf("arg size: %d\n", (int)tupleArgs->ob_size);
    printf("first args addr: %p\n", *(tupleArgs->ob_item));
    return Py_None;
}

static PyMethodDef hackintMethods[] =
{
    {"printInt", wrap_printInt, METH_VARARGS, "print some infomation"},
    {"printAddr", wrap_printAddr, METH_VARARGS, "print addr of agrs"},
    {NULL, NULL}
};

void inithackint()
{
    Py_InitModule("hackint", hackintMethods);
}

