#include <include/physics.h>
#include <string.h>

void EcsComponentsPhysics(
    ecs_world_t *world,
    int flags,
    void *handles_out)
{
    bool do_2d = !flags || flags & ECS_2D;
    bool do_3d = !flags || flags & ECS_3D;
    EcsComponentsPhysicsHandles *handles = handles_out;
    memset(handles, 0, sizeof(EcsComponentsPhysicsHandles));

    ECS_COMPONENT(world, EcsSpeed);
    ECS_SET_COMPONENT(handles, EcsSpeed);

    ECS_COMPONENT(world, EcsAngularSpeed);
    ECS_SET_COMPONENT(handles, EcsAngularSpeed);

    if (do_2d) {
        ECS_TAG(world, EcsCollider);
        ECS_COMPONENT(world, EcsPolygon8Collider);
        ECS_COMPONENT(world, EcsCircleCollider);
        ECS_COMPONENT(world, EcsCollision2D);
        ECS_COMPONENT(world, EcsPolygon8ColliderWorld);
        ECS_COMPONENT(world, EcsCircleColliderWorld);
        ECS_COMPONENT(world, EcsVelocity2D);

        ECS_SET_COMPONENT(handles, EcsCollider);
        ECS_SET_COMPONENT(handles, EcsCollision2D);
        ECS_SET_COMPONENT(handles, EcsPolygon8Collider);
        ECS_SET_COMPONENT(handles, EcsCircleCollider);
        ECS_SET_COMPONENT(handles, EcsPolygon8ColliderWorld);
        ECS_SET_COMPONENT(handles, EcsCircleColliderWorld);
        ECS_SET_COMPONENT(handles, EcsVelocity2D);
    }

    if (do_3d) {
        ECS_COMPONENT(world, EcsVelocity3D);
        ECS_COMPONENT(world, EcsAngularVelocity);
        
        ECS_SET_COMPONENT(handles, EcsVelocity3D);
        ECS_SET_COMPONENT(handles, EcsAngularVelocity);
    }
}
