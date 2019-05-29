#ifndef FLECS_COMPONENTS_PHYSICS_H
#define FLECS_COMPONENTS_PHYSICS_H

#include <flecs-components-physics/bake_config.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsSpeed {
    float value;
} EcsSpeed;

typedef EcsVec2 EcsVelocity2D;

typedef EcsVec3 EcsVelocity3D;

typedef struct EcsAngularSpeed {
    float value;
} EcsAngularSpeed;

typedef EcsVec3 EcsAngularVelocity;

typedef float EcsBounciness;
typedef float EcsFriction;

typedef struct EcsDrag {
    float c;
} EcsDrag;

typedef EcsVec4 EcsAABB;

typedef struct EcsCollision2D {
    EcsVec2 normal;
    float distance;
    ecs_entity_t entity_1;
    ecs_entity_t entity_2;
} EcsCollision2D;

typedef struct EcsCircleCollider {
    EcsPosition2D position;
    float radius;
} EcsCircleCollider;

typedef struct EcsPolygon8Collider {
    int8_t point_count;
    EcsPoint2D points[8];
} EcsPolygon8Collider;

typedef EcsCircleCollider EcsCircleColliderWorld;
typedef EcsPolygon8Collider EcsPolygon8ColliderWorld;

typedef struct FlecsComponentsPhysics {
    ECS_DECLARE_COMPONENT(EcsSpeed);
    ECS_DECLARE_COMPONENT(EcsVelocity2D);
    ECS_DECLARE_COMPONENT(EcsVelocity3D);
    ECS_DECLARE_COMPONENT(EcsAngularSpeed);
    ECS_DECLARE_COMPONENT(EcsAngularVelocity);
    ECS_DECLARE_COMPONENT(EcsBounciness);
    ECS_DECLARE_COMPONENT(EcsFriction);
    ECS_DECLARE_ENTITY(EcsCollider);
    ECS_DECLARE_ENTITY(EcsRigidBody);
    ECS_DECLARE_COMPONENT(EcsCollision2D);
    ECS_DECLARE_COMPONENT(EcsPolygon8Collider);
    ECS_DECLARE_COMPONENT(EcsCircleCollider);
    ECS_DECLARE_COMPONENT(EcsPolygon8ColliderWorld);
    ECS_DECLARE_COMPONENT(EcsCircleColliderWorld);
} FlecsComponentsPhysics;

void FlecsComponentsPhysicsImport(
    ecs_world_t *world,
    int flags);

#define FlecsComponentsPhysicsImportHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, EcsSpeed);\
    ECS_IMPORT_COMPONENT(handles, EcsVelocity2D);\
    ECS_IMPORT_COMPONENT(handles, EcsVelocity3D);\
    ECS_IMPORT_COMPONENT(handles, EcsAngularSpeed);\
    ECS_IMPORT_COMPONENT(handles, EcsAngularVelocity);\
    ECS_IMPORT_COMPONENT(handles, EcsBounciness);\
    ECS_IMPORT_COMPONENT(handles, EcsFriction);\
    ECS_IMPORT_ENTITY(handles, EcsCollider);\
    ECS_IMPORT_ENTITY(handles, EcsRigidBody);\
    ECS_IMPORT_COMPONENT(handles, EcsPolygon8Collider);\
    ECS_IMPORT_COMPONENT(handles, EcsCircleCollider);

#ifdef __cplusplus
}
#endif

#endif
