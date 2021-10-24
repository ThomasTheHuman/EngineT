#include "Python/Python.h"
//#include "EngineT.h"

static PyObject *start_engine(PyObject *self, PyObject *args) {
    //start();
    Py_RETURN_NONE;
}

static PyMethodDef engineTMethods[] = {
        {"start_engine", start_engine, METH_VARARGS, "Starts engine"},
        {NULL, NULL, 0, NULL}
};

static struct PyModuleDef engineTModule = {
        PyModuleDef_HEAD_INIT,
        "_pyenginet",
        "Python interface for EngineT 2D game engine",
        -1,
        engineTMethods
};

PyMODINIT_FUNC PyInit__pyenginet(void) {
    return PyModule_Create(&engineTModule);
}

