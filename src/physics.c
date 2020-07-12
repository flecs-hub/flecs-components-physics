#include <flecs_components_physics.h>

#include <string.h>

void FlecsComponentsPhysicsImport(
    ecs_world_t *world)
{
    ECS_MODULE(world, FlecsComponentsPhysics);

    ECS_IMPORT(world, FlecsMeta);
    ECS_IMPORT(world, FlecsComponentsGraphics);

    ECS_TAG(world, EcsCollider);
    ECS_TAG(world, EcsRigidBody);
    ECS_META(world, EcsVelocity2);
    ECS_META(world, EcsVelocity3);
    ECS_META(world, EcsAngularSpeed);
    ECS_META(world, EcsAngularVelocity);
    ECS_META(world, EcsPolygon8Collider);
    ECS_META(world, EcsCircleCollider);
    ECS_META(world, EcsCollision2);
    ECS_META(world, EcsBounciness);
    ECS_META(world, EcsFriction);
    ECS_COMPONENT(world, EcsPolygon8ColliderWorld);
    ECS_COMPONENT(world, EcsCircleColliderWorld);

    ECS_EXPORT_ENTITY(EcsCollider);
    ECS_EXPORT_ENTITY(EcsRigidBody);
    ECS_EXPORT_COMPONENT(EcsVelocity2);
    ECS_EXPORT_COMPONENT(EcsVelocity3);
    ECS_EXPORT_COMPONENT(EcsAngularSpeed);
    ECS_EXPORT_COMPONENT(EcsAngularVelocity);
    ECS_EXPORT_COMPONENT(EcsPolygon8Collider);
    ECS_EXPORT_COMPONENT(EcsCircleCollider);
    ECS_EXPORT_COMPONENT(EcsCollision2);
    ECS_EXPORT_COMPONENT(EcsPolygon8ColliderWorld);
    ECS_EXPORT_COMPONENT(EcsCircleColliderWorld);
    ECS_EXPORT_COMPONENT(EcsBounciness);
    ECS_EXPORT_COMPONENT(EcsFriction);
}
