#include "Python/Python.h"
#include "../EngineT/EngineT.h"

static PyObject *_init(PyObject *self, PyObject *args) {
    init();
    Py_RETURN_NONE;
}

static PyObject *_configure(PyObject *self, PyObject *args) {
    configure();
    Py_RETURN_NONE;
}

static PyObject *_createEntity(PyObject *self, PyObject *args) {
    return Py_BuildValue("i", createEntity());
}

static PyObject *_addEntityToGroup(PyObject *self, PyObject *args) {
    int entityId, groupId;
    if (!PyArg_ParseTuple(args, "ii", &entityId, &groupId))
        return NULL;
    addEntityToGroup(entityId, groupId);
    PyReturn_NONE;
}

static PyObject *_run(PyObject *self, PyObject *args) {
    run();
    Py_RETURN_NONE;
}

static PyMethodDef engineTMethods[] = {
        {"init", _init, METH_VARARGS, "Initializes engine"},
        {"configure", _configure, METH_VARARGS, "Applies game parameters"},
        {"create_entity", _createEntity, METH_VARARGS, "Creates game entity and returns it's id"},
        {"add_entity_to_group", _addEntityToGroup, METH_VARARGS, "Adds entity to group"},
        {"run", _run, METH_VARARGS, "Starts game"},
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

