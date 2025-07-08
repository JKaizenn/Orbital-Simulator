/***********************************************************************
 * Source File:
 *    SATELLITE
 * Author:
 *    Roger Galan
 * Summary:
 *    base class for every moving and destroyable object
 ************************************************************************/

#include "satellite.h"
#include "acceleration.h"

/******************************************
 * SATELLITE : CONSTRUCTOR WITH SATELLITE AND ANGLE
 * Initialize satellite by copying from another with new direction
 *****************************************/
Satellite::Satellite(Satellite& s, Angle a)
{
   position = s.position;
   velocity = s.velocity;
   direction = a;
   angularVelocity = s.angularVelocity;
   dead = false;        // Initialize dead
   radius = 0.0;        // Initialize radius
}

/******************************************
 * SATELLITE : MOVE
 * Move satellite according to physics and angular velocity
 *****************************************/
void Satellite::move(double time)
{
   // Calculate gravity effects
   double height = computeHeightAboveEarth(position);
   double aGravity = getGravity(height);
   Angle gravityAngle;
   gravityAngle.setRadians(directionOfGravityPull(position));
   
   // Create acceleration due to gravity
   Acceleration accel;
   accel.set(gravityAngle, aGravity);
   
   double diff = 2;     // Number of sub-steps for better accuracy
   for (int i = 0;  i < diff; i++)
   {
      // Update velocity with acceleration
      velocity.add(accel, time / (double)diff);
      
      // Update position with velocity and acceleration
      position.add(accel, velocity, time / (double)diff);
      
      // Update rotation
      direction.rotate(angularVelocity / (double)diff);
   }
}
