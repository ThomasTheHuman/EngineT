#include <stdbool.h>
#include <stdio.h>
#include "Python/Python.h"
#include "../EngineT/EngineT.h"
#include "ComponentType.h"

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
    Py_RETURN_NONE;
}

static PyObject *_addComponentToEntity(PyObject *self, PyObject *args) {
    int entityId = PyLong_AsLong(PyNumber_Long(PyTuple_GetItem(args, 0)));
    enum ComponentType componentType = PyLong_AsLong(PyTuple_GetItem(args, 1));
    switch (componentType) {
        case AI:
        {
            int speed;
            bool enemy;
            if (!PyArg_ParseTuple(args, "iiip", &entityId, &componentType, &speed, &enemy))
                return NULL;
            addAIComponent(entityId, speed, enemy);
            break;
        }
        case ANIMATION:
            addAnimationComponent(entityId);
            break;
        case ATTACK:
        {
            int frames, damageFrame, damage;
            if (!PyArg_ParseTuple(args, "iiiii", &entityId, &componentType, &frames, &damageFrame, &damage))
                return NULL;
            addAttackComponent(entityId, frames, damageFrame, damage);
            break;
        }
        case COLLISION:
            addCollisionComponent(entityId);
            break;
        case FORCE:
        {
            float x, y;
            if (!PyArg_ParseTuple(args, "iiff", &entityId, &componentType, &x, &y))
                return NULL;
            addForceComponent(entityId, x, y);
            break;
        }
        case HEALTH:
        {
            int health, maxHealth;
            bool isPlayer;
            if (!PyArg_ParseTuple(args, "iiiip", &entityId, &componentType, &health, &maxHealth, &isPlayer))
                return NULL;
            addHealthComponent(entityId, health, maxHealth, isPlayer);
            break;
        }
        case PLAYER:
        {
            int speed;
            if (!PyArg_ParseTuple(args, "iii", &entityId, &componentType, &speed))
                return NULL;
            addPlayerComponent(entityId, speed);
            break;
        }
        case SPRITE:
        {
            const char *id, *path;
            int w, h, x, y;
            float scale;
            if (!PyArg_ParseTuple(args, "iissiiiif", &entityId, &componentType, &id, &path, &w, &h, &x, &y, &scale))
                return NULL;
            addSpriteComponent(entityId, id, path, w, h, x, y, scale);
            break;
        }
        case TRANSFORM:
        {
            int x, y;
            if (!PyArg_ParseTuple(args, "iiii", &entityId, &componentType, &x, &y))
                return NULL;
            addTransformComponent(entityId, x, y);
            break;
        }
    }
    Py_RETURN_NONE;
}

static PyObject *_addAnimation(PyObject *self, PyObject *args) {
    int entityId, id, startX, startY, frames;
    if (!PyArg_ParseTuple(args, "iiiii", &entityId, &id, &startX, &startY, &frames))
        return NULL;
    addAnimation(entityId, id, startX, startY, frames);
    Py_RETURN_NONE;
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
        {"add_component_to_entity", _addComponentToEntity, METH_VARARGS, "Adds component to entity"},
        {"add_animation", _addAnimation, METH_VARARGS, "Adds animation to entity with animation component"},
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

