/** 
 * Library to wrap M-ulator into the 
 * M3 soft-DBG project
 *
 * Andrew Lukefahr
 * lukefahr@umich.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <Python.h>

#include "step.h"

//prototyping 
static PyObject * step_wrapper(PyObject * self, PyObject * args);

//declares an exception class
static PyObject * StepError;

//tells python our methods
static PyMethodDef StepMethods[] = {
    {"step", step_wrapper, METH_VARARGS,
        "single step an instruction."},
    {NULL, NULL, 0, NULL}
};


//inializer for our class
PyMODINIT_FUNC
initstep(void)
{
    PyObject *m;

    m = Py_InitModule("step", StepMethods);
    if (m == NULL)
        return;

    StepError = PyErr_NewException("step.error", NULL, NULL);
    Py_INCREF(StepError);
    PyModule_AddObject(m, "error", StepError);
}

//wrapper into C-land
static PyObject * step_wrapper(PyObject * self, PyObject * args)
{
    PyObject * ret;

    uint32_t inst;
    uint32_t err;

    // parse arguments
    if (!PyArg_ParseTuple(args, "I", &inst)) {
        return NULL;
    }

    // run the instruction
    err = step(inst);

    // build the result into a Python object.
    ret = PyBool_FromLong(err); 

    return ret;
}




