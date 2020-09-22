#include <flecs_components_physics.h>

#include <string.h>

void FlecsComponentsPhysicsImport(
    ecs_world_t *world)
{
    ECS_MODULE(world, FlecsComponentsPhysics);

    ECS_IMPORT(world, FlecsMeta);
    ECS_IMPORT(world, FlecsComponentsGraphics);

    ecs_set_name_prefix(world, "Ecs");

    ECS_TAG(world, EcsCollider);
    ECS_TAG(world, EcsRigidBody);
    ECS_META(world, EcsVelocity2);
    ECS_META(world, EcsVelocity3);
    ECS_META(world, EcsAngularSpeed);
    ECS_META(world, EcsAngularVelocity);
    ECS_META(world, EcsBounciness);
    ECS_META(world, EcsFriction);

    ECS_EXPORT_ENTITY(EcsCollider);
    ECS_EXPORT_ENTITY(EcsRigidBody);
    ECS_EXPORT_COMPONENT(EcsVelocity2);
    ECS_EXPORT_COMPONENT(EcsVelocity3);
    ECS_EXPORT_COMPONENT(EcsAngularSpeed);
    ECS_EXPORT_COMPONENT(EcsAngularVelocity);
    ECS_EXPORT_COMPONENT(EcsBounciness);
    ECS_EXPORT_COMPONENT(EcsFriction);
}
