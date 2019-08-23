#include <flecs_components_physics.h>

#include <string.h>

void FlecsComponentsPhysicsImport(
    ecs_world_t *world,
    int flags)
{
    bool do_2d = !flags || flags & ECS_2D;
    bool do_3d = !flags || flags & ECS_3D;

    ECS_MODULE(world, FlecsComponentsPhysics);

    if (do_2d) {
        ECS_TAG(world, EcsCollider);
        ECS_TAG(world, EcsRigidBody);
        ECS_COMPONENT(world, EcsPolygon8Collider);
        ECS_COMPONENT(world, EcsCircleCollider);
        ECS_COMPONENT(world, EcsCollision2D);
        ECS_COMPONENT(world, EcsPolygon8ColliderWorld);
        ECS_COMPONENT(world, EcsCircleColliderWorld);
        ECS_COMPONENT(world, EcsVelocity2D);
        ECS_COMPONENT(world, EcsSpeed);
        ECS_COMPONENT(world, EcsAngularSpeed);
        ECS_COMPONENT(world, EcsBounciness);
        ECS_COMPONENT(world, EcsFriction);

        ECS_SET_ENTITY(EcsCollider);
        ECS_SET_ENTITY(EcsRigidBody);
        ECS_SET_COMPONENT(EcsCollision2D);
        ECS_SET_COMPONENT(EcsPolygon8Collider);
        ECS_SET_COMPONENT(EcsCircleCollider);
        ECS_SET_COMPONENT(EcsPolygon8ColliderWorld);
        ECS_SET_COMPONENT(EcsCircleColliderWorld);
        ECS_SET_COMPONENT(EcsVelocity2D);
        ECS_SET_COMPONENT(EcsSpeed);
        ECS_SET_COMPONENT(EcsAngularSpeed);
        ECS_SET_COMPONENT(EcsBounciness); 
        ECS_SET_COMPONENT(EcsFriction);
    }

    if (do_3d) {
        ECS_COMPONENT(world, EcsVelocity3D);
        ECS_COMPONENT(world, EcsAngularVelocity);
        
        ECS_SET_COMPONENT(EcsVelocity3D);
        ECS_SET_COMPONENT(EcsAngularVelocity);
    }
}
