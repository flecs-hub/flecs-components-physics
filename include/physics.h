#ifndef REFLECS_COMPONENTS_PHYSICS_H
#define REFLECS_COMPONENTS_PHYSICS_H

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
    EcsEntity Speed;
    EcsEntity Velocity2D;
    EcsEntity Velocity3D;
    EcsEntity AngularSpeed;
    EcsEntity AngularVelocity;
    EcsEntity Collider;
    EcsEntity Collision2D;
    EcsEntity Polygon8Collider;
    EcsEntity CircleCollider;
    EcsEntity Polygon8ColliderWorld;
    EcsEntity CircleColliderWorld;
} EcsComponentsPhysicsHandles;

void EcsComponentsPhysics(
    EcsWorld *world,
    int flags,
    void *handles_out);

#define EcsComponentsPhysics_DeclareHandles(handles)\
    EcsDeclareHandle(handles, Speed);\
    EcsDeclareHandle(handles, Velocity2D);\
    EcsDeclareHandle(handles, Velocity3D);\
    EcsDeclareHandle(handles, AngularSpeed);\
    EcsDeclareHandle(handles, AngularVelocity);\
    EcsDeclareHandle(handles, Collider);\
    EcsDeclareHandle(handles, Polygon8Collider);\
    EcsDeclareHandle(handles, CircleCollider);

#ifdef __cplusplus
}
#endif

#endif
