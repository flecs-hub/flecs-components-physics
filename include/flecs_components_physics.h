#ifndef FLECS_COMPONENTS_PHYSICS_H
#define FLECS_COMPONENTS_PHYSICS_H

#include <flecs-components-physics/bake_config.h>

// Reflection system boilerplate
#undef ECS_META_IMPL
#ifndef flecs_components_physics_EXPORTS
#define ECS_META_IMPL EXTERN // Ensure meta symbols are only defined once
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

#ifdef __cplusplus
extern "C" {
#endif

FLECS_COMPONENTS_PHYSICS_API
void FlecsComponentsPhysicsImport(
    ecs_world_t *world);

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
        FlecsComponentsPhysicsImport(ecs);

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
