]#ifndef ENGINEJ_SYSTEM_H
#define ENGINEJ_SYSTEM_H

#include "../core/Entity.h"

class System {
protected:
    Entity *root;
public:
    System() = delete;
    explicit System(Entity *_root);
    virtual void update() {}
    virtual ~System() = default;
};

#endif //ENGINEJ_SYSTEM_H
