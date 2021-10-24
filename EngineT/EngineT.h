#pragma once
#ifdef __cplusplus
extern "C" {
#endif

    extern void init();
    extern void configure();

    extern int createEntity();
    extern void addEntityToGroup(int entityId, int groupId);

    extern void run();

#ifdef __cplusplus
}
#endif