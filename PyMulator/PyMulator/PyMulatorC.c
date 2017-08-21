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

#include "csrc/interface.h"

//prototyping 
static PyObject * py_call_to_mulator (PyObject * self, PyObject * args);
static PyObject * py_register_callback( PyObject * dummy, PyObject * args);

//declares an exception class
static PyObject * PyMulatorCError;

//tells python our methods
static PyMethodDef PyMulatorCMethods[] = {
    {"call_to_mulator", py_call_to_mulator, METH_VARARGS,
        "a gdb-like wrapper for M-ulator in Python."},
    {"register_callback", py_register_callback, METH_VARARGS,
        "register a callback for Mulator" },
    {NULL, NULL, 0, NULL}
};


//inializer for our class
PyMODINIT_FUNC
initPyMulatorC(void)
{
    PyObject *m;

    m = Py_InitModule("PyMulatorC", PyMulatorCMethods);
    if (m == NULL)
        return;

    PyMulatorCError = PyErr_NewException("PyMulatorC.error", NULL, NULL);
    Py_INCREF(PyMulatorCError);
    PyModule_AddObject(m, "error", PyMulatorCError);
}

//wrapper into C-land
static PyObject * py_call_to_mulator(PyObject * self, PyObject * args)
{

    char * input;
    PyObject * ret;

    // parse arguments
    if (!PyArg_ParseTuple(args, "s", &input)) {
        return NULL;
    }

    // run the instruction
    call_to_mulator(input);
    int err = 0;
    
    // build the result into a Python object.
    ret = PyBool_FromLong(err); 

    return ret;
}

static PyObject *py_callback = NULL;

static PyObject * 
py_register_callback( PyObject * dummy, PyObject * args)
{
    PyObject *result = NULL;
    PyObject *temp;

    if (PyArg_ParseTuple(args, "O:set_callback", &temp)) {
        if (!PyCallable_Check(temp)) {
            PyErr_SetString(PyExc_TypeError, "parameter must be callable");
            return NULL;
        }
        Py_XINCREF(temp);         /* Add a reference to new callback */
        Py_XDECREF(py_callback);  /* Dispose of previous callback */
        py_callback = temp;       /* Remember new callback */
        /* Boilerplate to return "None" */
        Py_INCREF(Py_None);
        result = Py_None;
    }
    return result;
}

void call_from_mulator( char * command, char ** result)
{
    PyObject *arglist;
    PyObject *pyresult;
    
    //fixme
    if (py_callback == NULL){
        printf("Found NULL py_callback function, aborting\n");
        return;
    }

    /* Time to call the callback */
    arglist = Py_BuildValue("(s)", command);
    pyresult = PyObject_CallObject(py_callback, arglist);
    Py_DECREF(arglist);

    if (pyresult == NULL){
        printf("Found NULL pyresult, aborting\n");
        PyErr_SetString(PyMulatorCError, "bad result from callback");
        *result= NULL; 

    } else {
       
        const char * pyresult_str = PyString_AsString(pyresult);
        
        /* Here maybe use the result */
        asprintf( result, "%s", pyresult_str); 

        Py_DECREF(pyresult);

    }

}

