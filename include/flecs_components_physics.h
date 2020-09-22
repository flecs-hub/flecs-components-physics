#ifndef FLECS_COMPONENTS_PHYSICS_H
#define FLECS_COMPONENTS_PHYSICS_H

#include <flecs-components-physics/bake_config.h>

#ifdef __cplusplus
extern "C" {
#endif

ECS_STRUCT(EcsVelocity2, {
    float x;
    float y;
});

ECS_STRUCT(EcsVelocity3, {
    float x;
    float y;
    float z;
});

ECS_STRUCT(EcsAngularSpeed, {
    float value;
});

ECS_STRUCT(EcsAngularVelocity, {
    float x;
    float y;
    float z;
});

ECS_STRUCT(EcsBounciness, {
    float value;
});

ECS_STRUCT(EcsFriction, {
    float value;
});

typedef struct FlecsComponentsPhysics {
    ECS_DECLARE_ENTITY(EcsCollider);
    ECS_DECLARE_ENTITY(EcsRigidBody);    
    ECS_DECLARE_COMPONENT(EcsVelocity2);
    ECS_DECLARE_COMPONENT(EcsVelocity3);
    ECS_DECLARE_COMPONENT(EcsAngularSpeed);
    ECS_DECLARE_COMPONENT(EcsAngularVelocity);
    ECS_DECLARE_COMPONENT(EcsBounciness);
    ECS_DECLARE_COMPONENT(EcsFriction);
} FlecsComponentsPhysics;

void FlecsComponentsPhysicsImport(
    ecs_world_t *world);

#define FlecsComponentsPhysicsImportHandles(handles)\
    ECS_IMPORT_ENTITY(handles, EcsCollider);\
    ECS_IMPORT_ENTITY(handles, EcsRigidBody);\
    ECS_IMPORT_COMPONENT(handles, EcsVelocity2);\
    ECS_IMPORT_COMPONENT(handles, EcsVelocity3);\
    ECS_IMPORT_COMPONENT(handles, EcsAngularSpeed);\
    ECS_IMPORT_COMPONENT(handles, EcsAngularVelocity);\
    ECS_IMPORT_COMPONENT(handles, EcsBounciness);\
    ECS_IMPORT_COMPONENT(handles, EcsFriction);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

namespace flecs {
namespace components {

class physics : FlecsComponentsPhysics {
public:
    using Velocity2 = EcsVelocity2;
    using Velocity3 = EcsVelocity3;
    using AngularSpeed = EcsAngularSpeed;
    using AngularVelocity = EcsAngularVelocity;
    using Bounciness = EcsBounciness;
    using Friction = EcsFriction;

    physics(flecs::world& ecs) {
        FlecsComponentsPhysicsImport(ecs.c_ptr());

        ecs.module<flecs::components::physics>();

        ecs.pod_component<Velocity2>("flecs::components::physics::Velocity2");
        ecs.pod_component<Velocity3>("flecs::components::physics::Velocity3");
        ecs.pod_component<AngularSpeed>("flecs::components::physics::AngularSpeed");
        ecs.pod_component<AngularVelocity>("flecs::components::physics::AngularVelocity");
        ecs.pod_component<Bounciness>("flecs::components::physics::Bounciness");
        ecs.pod_component<Friction>("flecs::components::physics::Friction");
    }
};

}
}

#endif

#endif
