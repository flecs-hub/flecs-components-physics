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

ECS_STRUCT(EcsAABB, {
    float x;
    float y;
    float z;
    float w;
});

ECS_STRUCT(EcsCollision2, {
    ecs_vert2_t normal;
    float distance;
    ecs_entity_t entity_1;
    ecs_entity_t entity_2;
});

ECS_STRUCT(EcsCircleCollider, {
    ecs_vert2_t position;
    float radius;
});

ECS_STRUCT(EcsPolygon8Collider, {
    ecs_poly8_t value;
});

typedef EcsCircleCollider EcsCircleColliderWorld;
typedef EcsPolygon8Collider EcsPolygon8ColliderWorld;

typedef struct FlecsComponentsPhysics {
    ECS_DECLARE_ENTITY(EcsCollider);
    ECS_DECLARE_ENTITY(EcsRigidBody);    
    ECS_DECLARE_COMPONENT(EcsVelocity2);
    ECS_DECLARE_COMPONENT(EcsVelocity3);
    ECS_DECLARE_COMPONENT(EcsAngularSpeed);
    ECS_DECLARE_COMPONENT(EcsAngularVelocity);
    ECS_DECLARE_COMPONENT(EcsBounciness);
    ECS_DECLARE_COMPONENT(EcsFriction);
    ECS_DECLARE_COMPONENT(EcsCollision2);
    ECS_DECLARE_COMPONENT(EcsPolygon8Collider);
    ECS_DECLARE_COMPONENT(EcsCircleCollider);
    ECS_DECLARE_COMPONENT(EcsPolygon8ColliderWorld);
    ECS_DECLARE_COMPONENT(EcsCircleColliderWorld);
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
    ECS_IMPORT_COMPONENT(handles, EcsFriction);\
    ECS_IMPORT_COMPONENT(handles, EcsCollision2);\
    ECS_IMPORT_COMPONENT(handles, EcsPolygon8Collider);\
    ECS_IMPORT_COMPONENT(handles, EcsCircleCollider);\
    ECS_IMPORT_COMPONENT(handles, EcsPolygon8ColliderWorld);\
    ECS_IMPORT_COMPONENT(handles, EcsCircleColliderWorld);

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
    using Collision2 = EcsCollision2;
    using Polygon8Collider = EcsPolygon8Collider;
    using CircleCollider = EcsCircleCollider;

    struct Polygon8ColliderWorld : EcsPolygon8ColliderWorld { };
    struct CircleColliderWorld : EcsCircleColliderWorld { };

    physics(flecs::world& ecs) {
        FlecsComponentsPhysicsImport(ecs.c_ptr());

        ecs.module<flecs::components::physics>();

        ecs.component<Velocity2>("flecs::components::physics::Velocity2");
        ecs.component<Velocity3>("flecs::components::physics::Velocity3");
        ecs.component<AngularSpeed>("flecs::components::physics::AngularSpeed");
        ecs.component<AngularVelocity>("flecs::components::physics::AngularVelocity");
        ecs.component<Bounciness>("flecs::components::physics::Bounciness");
        ecs.component<Friction>("flecs::components::physics::Friction");
        ecs.component<Collision2>("flecs::components::physics::Collision2");
        ecs.component<Polygon8Collider>("flecs::components::physics::Polygon8Collider");
        ecs.component<CircleCollider>("flecs::components::physics::CircleCollider");
        ecs.component<Polygon8ColliderWorld>("flecs::components::physics::Polygon8ColliderWorld");
        ecs.component<CircleColliderWorld>("flecs::components::physics::CircleColliderWorld");
    }
};

}
}

#endif

#endif
