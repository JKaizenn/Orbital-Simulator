/***********************************************************************
 * Source File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#include "velocity.h"
#include "acceleration.h"
#include "angle.h"
#include <math.h>  // for sqrt()

/*********************************************
 * VELOCITY : ADD
 *  v = v_0 + a t
 *********************************************/
void Velocity::add(const Acceleration& acceleration, double time)
{
   dx += acceleration.getDDX() * time;
   dy += acceleration.getDDY() * time;
}

/*********************************************
 * VELOCITY : GET SPEED
 *  Find the magnitude of velocity
 *  Use Pythagorean theorum: sqrt( x^2 + y^2 )
 *********************************************/
double Velocity::getSpeed() const
{
   return sqrt((dx * dx) + (dy * dy));
}

/*********************************************
 * VELOCITY : SET
 *  Set from angle and direction
 *********************************************/
void Velocity::set(const Angle & angle, double magnitude)
{
   dx = magnitude * sin(angle.getRadians());
   dy = magnitude * cos(angle.getRadians());
}

