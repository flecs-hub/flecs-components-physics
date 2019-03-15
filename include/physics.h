#ifndef FLECS_COMPONENTS_PHYSICS_H
#define FLECS_COMPONENTS_PHYSICS_H

#include "bake_config.h"

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

typedef EcsVec4 EcsAABB;
typedef EcsVec2 EcsPoint2D;

typedef struct EcsCollision2D {
    EcsVec2 normal;
    float distance;
    EcsEntity entity_1;
    EcsEntity entity_2;
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

typedef struct EcsComponentsPhysicsHandles {
    ECS_DECLARE_COMPONENT(EcsSpeed);
    ECS_DECLARE_COMPONENT(EcsVelocity2D);
    ECS_DECLARE_COMPONENT(EcsVelocity3D);
    ECS_DECLARE_COMPONENT(EcsAngularSpeed);
    ECS_DECLARE_COMPONENT(EcsAngularVelocity);
    ECS_DECLARE_COMPONENT(EcsCollider);
    ECS_DECLARE_COMPONENT(EcsCollision2D);
    ECS_DECLARE_COMPONENT(EcsPolygon8Collider);
    ECS_DECLARE_COMPONENT(EcsCircleCollider);
    ECS_DECLARE_COMPONENT(EcsPolygon8ColliderWorld);
    ECS_DECLARE_COMPONENT(EcsCircleColliderWorld);
} EcsComponentsPhysicsHandles;

void EcsComponentsPhysics(
    EcsWorld *world,
    int flags,
    void *handles_out);

#define EcsComponentsPhysics_DeclareHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, Speed);\
    ECS_IMPORT_COMPONENT(handles, Velocity2D);\
    ECS_IMPORT_COMPONENT(handles, Velocity3D);\
    ECS_IMPORT_COMPONENT(handles, AngularSpeed);\
    ECS_IMPORT_COMPONENT(handles, AngularVelocity);\
    ECS_IMPORT_COMPONENT(handles, Collider);\
    ECS_IMPORT_COMPONENT(handles, Polygon8Collider);\
    ECS_IMPORT_COMPONENT(handles, CircleCollider);

#ifdef __cplusplus
}
#endif

#endif
