#include <include/physics.h>
#include <string.h>

void EcsComponentsPhysics(
    EcsWorld *world,
    int flags,
    void *handles_out)
{
    bool do_2d = !flags || flags & ECS_2D;
    bool do_3d = !flags || flags & ECS_3D;
    EcsComponentsPhysicsHandles *handles = handles_out;
    memset(handles, 0, sizeof(EcsComponentsPhysicsHandles));

    ECS_COMPONENT(world, EcsSpeed);
    handles->Speed = EcsSpeed_h;

    ECS_COMPONENT(world, EcsAngularSpeed);
    handles->AngularSpeed = EcsAngularSpeed_h;

    if (do_2d) {
        ECS_TAG(world, EcsCollider);
        ECS_COMPONENT(world, EcsPolygon8Collider);
        ECS_COMPONENT(world, EcsCircleCollider);
        ECS_COMPONENT(world, EcsCollision2D);
        ECS_COMPONENT(world, EcsPolygon8ColliderWorld);
        ECS_COMPONENT(world, EcsCircleColliderWorld);
        ECS_COMPONENT(world, EcsVelocity2D);

        handles->Collider = EcsCollider_h;
        handles->Collision2D = EcsCollision2D_h;
        handles->Polygon8Collider = EcsPolygon8Collider_h;
        handles->CircleCollider = EcsCircleCollider_h;
        handles->Polygon8ColliderWorld = EcsPolygon8ColliderWorld_h;
        handles->CircleColliderWorld = EcsCircleColliderWorld_h;
        handles->Velocity2D = EcsVelocity2D_h;
    }

    if (do_3d) {
        ECS_COMPONENT(world, EcsVelocity3D);
        ECS_COMPONENT(world, EcsAngularVelocity);
        handles->Velocity3D = EcsVelocity3D_h;
        handles->AngularVelocity = EcsAngularVelocity_h;
    }
}
