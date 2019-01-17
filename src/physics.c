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
        ECS_COMPONENT(world, EcsPolygonCollider);
        ECS_COMPONENT(world, EcsCircleCollider);
        ECS_COMPONENT(world, EcsVelocity2D);

        handles->Collider = EcsCollider_h;
        handles->PolygonCollider = EcsPolygonCollider_h;
        handles->CircleCollider = EcsCircleCollider_h;
        handles->Velocity2D = EcsVelocity2D_h;
    }

    if (do_3d) {
        ECS_COMPONENT(world, EcsVelocity3D);
        ECS_COMPONENT(world, EcsAngularVelocity);
        handles->Velocity3D = EcsVelocity3D_h;
        handles->AngularVelocity = EcsAngularVelocity_h;
    }
}
