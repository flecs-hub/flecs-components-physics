#define FLECS_COMPONENTS_PHYSICS_IMPL
#include <flecs_components_physics.h>

void FlecsComponentsPhysicsImport(
    ecs_world_t *world)
{
    ECS_MODULE(world, FlecsComponentsPhysics);
    ECS_IMPORT(world, FlecsComponentsGraphics);

    ecs_set_name_prefix(world, "Ecs");

    ECS_TAG(world, EcsCollider);
    ECS_TAG(world, EcsRigidBody);
    ECS_META_COMPONENT(world, EcsVelocity2);
    ECS_META_COMPONENT(world, EcsVelocity3);
    ECS_META_COMPONENT(world, EcsAngularSpeed);
    ECS_META_COMPONENT(world, EcsAngularVelocity);
    ECS_META_COMPONENT(world, EcsBounciness);
    ECS_META_COMPONENT(world, EcsFriction);
}
