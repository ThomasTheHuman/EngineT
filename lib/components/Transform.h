#ifndef ENGINEJ_TRANSFORM_H
#define ENGINEJ_TRANSFORM_H


#include "Component.h"
#include "../core/Vector3D.h"
#include <atomic>

struct Transform : Component {
    Vector3D position = Vector3D();
    Vector3D velocity = Vector3D();
    Vector3D acceleration = Vector3D();

    std::atomic<float> rotation = 0;
    std::atomic<float> angularVelocity = 0;
    std::atomic<float> angularAcceleration = 0;
};

#endif //ENGINEJ_TRANSFORM_H
