/***********************************************************************
 * Source File:
 *    TEST Satellite
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for Satellite
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "satellite.h"
#include "testSatellite.h"
#include <math.h>

/*************************************
 * DEFAULT CONSTRUCTOR
 * input: nothing
 * output: position(200.0, 200.0), velocity(0.0, 0.0), dead(false), angularVelocity(1.0), radius(0.0)
 **************************************/
void TestSatellite::defaultConstructor()
{
   // SETUP
   
   // EXERCISE
   SatelliteDerived s;
   
   // VERIFY
   assertEquals(s.position.x, 200.0);
   assertEquals(s.position.y, 200.0);
   assertEquals(s.velocity.dx, 0.0);
   assertEquals(s.velocity.dy, 0.0);
   assertEquals(s.dead, false);
   assertEquals(s.angularVelocity, 1.0);
   assertEquals(s.radius, 0.0);
   assertEquals(s.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * CONSTRUCTOR WITH POSITION
 * input: another satellite and angle
 * output: satellite with copied position, velocity, and angular velocity
 **************************************/
void TestSatellite::constructorWithPosition()
{
   // SETUP
   SatelliteDerived s1;
   s1.position.x = 100.0;
   s1.position.y = 150.0;
   s1.velocity.dx = 5.0;
   s1.velocity.dy = 10.0;
   s1.angularVelocity = 2.5;
   Angle a;
   a.radians = M_PI / 2.0;                          // PI/2 = 90 degrees
   
   // EXERCISE
   SatelliteDerived s2(s1, a);
   
   // VERIFY
   assertEquals(s2.position.x, 100.0);
   assertEquals(s2.position.y, 150.0);
   assertEquals(s2.velocity.dx, 5.0);
   assertEquals(s2.velocity.dy, 10.0);
   assertEquals(s2.angularVelocity, 2.5);
   assertEquals(s2.direction.radians, M_PI / 2.0); // PI/2 = 90 degrees
   assertEquals(s2.dead, false);
   assertEquals(s2.radius, 0.0);
   
   // Verify original unchanged
   assertEquals(s1.position.x, 100.0);
   assertEquals(s1.position.y, 150.0);
   assertEquals(s1.velocity.dx, 5.0);
   assertEquals(s1.velocity.dy, 10.0);
   assertEquals(s1.angularVelocity, 2.5);
   assertEquals(a.radians, M_PI / 2.0);             // PI/2 = 90 degrees
   
   // TEARDOWN
}

/*************************************
 * GET RADIUS - DEFAULT
 * input: default satellite
 * output: radius = 0.0
 **************************************/
void TestSatellite::getRadiusDefault()
{
   // SETUP
   SatelliteDerived s;
   
   // EXERCISE
   double radius = s.getRadius();
   
   // VERIFY
   assertEquals(radius, 0.0);
   assertEquals(s.position.x, 200.0);
   assertEquals(s.position.y, 200.0);
   assertEquals(s.velocity.dx, 0.0);
   assertEquals(s.velocity.dy, 0.0);
   assertEquals(s.dead, false);
   assertEquals(s.angularVelocity, 1.0);
   assertEquals(s.radius, 0.0);
   assertEquals(s.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * IS DEAD - INITIAL
 * input: default satellite
 * output: dead = false
 **************************************/
void TestSatellite::isDeadInitial()
{
   // SETUP
   SatelliteDerived s;
   
   // EXERCISE
   bool isDead = s.isDead();
   
   // VERIFY
   assertEquals(isDead, false);
   assertEquals(s.position.x, 200.0);
   assertEquals(s.position.y, 200.0);
   assertEquals(s.velocity.dx, 0.0);
   assertEquals(s.velocity.dy, 0.0);
   assertEquals(s.dead, false);
   assertEquals(s.angularVelocity, 1.0);
   assertEquals(s.radius, 0.0);
   assertEquals(s.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * IS DEAD - AFTER KILL
 * input: satellite that has been killed
 * output: dead = true
 **************************************/
void TestSatellite::isDeadAfterKill()
{
   // SETUP
   SatelliteDerived s;
   s.kill();
   
   // EXERCISE
   bool isDead = s.isDead();
   
   // VERIFY
   assertEquals(isDead, true);
   assertEquals(s.position.x, 200.0);
   assertEquals(s.position.y, 200.0);
   assertEquals(s.velocity.dx, 0.0);
   assertEquals(s.velocity.dy, 0.0);
   assertEquals(s.angularVelocity, 1.0);
   assertEquals(s.radius, 0.0);
   assertEquals(s.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * GET POSITION - INITIAL
 * input: default satellite
 * output: position = (200.0, 200.0)
 **************************************/
void TestSatellite::getPositionInitial()
{
   // SETUP
   SatelliteDerived s;
   
   // EXERCISE
   const Position& pos = s.getPosition();
   
   // VERIFY
   assertEquals(pos.x, 200.0);
   assertEquals(pos.y, 200.0);
   assertEquals(s.position.x, 200.0);
   assertEquals(s.position.y, 200.0);
   assertEquals(s.velocity.dx, 0.0);
   assertEquals(s.velocity.dy, 0.0);
   assertEquals(s.dead, false);
   assertEquals(s.angularVelocity, 1.0);
   assertEquals(s.radius, 0.0);
   assertEquals(s.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * KILL - ALIVE TO DEAD
 * input: alive satellite
 * output: dead = true
 **************************************/
void TestSatellite::killAliveToDead()
{
   // SETUP
   SatelliteDerived s;
   assertEquals(s.dead, false);
   
   // EXERCISE
   s.kill();
   
   // VERIFY
   assertEquals(s.dead, true);
   assertEquals(s.position.x, 200.0);
   assertEquals(s.position.y, 200.0);
   assertEquals(s.velocity.dx, 0.0);
   assertEquals(s.velocity.dy, 0.0);
   assertEquals(s.angularVelocity, 1.0);
   assertEquals(s.radius, 0.0);
   assertEquals(s.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * KILL - ALREADY DEAD
 * input: dead satellite
 * output: dead = true (remains dead)
 **************************************/
void TestSatellite::killAlreadyDead()
{
   // SETUP
   SatelliteDerived s;
   s.kill();
   assertEquals(s.dead, true);
   
   // EXERCISE
   s.kill();
   
   // VERIFY
   assertEquals(s.dead, true);
   assertEquals(s.position.x, 200.0);
   assertEquals(s.position.y, 200.0);
   assertEquals(s.velocity.dx, 0.0);
   assertEquals(s.velocity.dy, 0.0);
   assertEquals(s.angularVelocity, 1.0);
   assertEquals(s.radius, 0.0);
   assertEquals(s.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * MOVE - ZERO TIME
 * input: satellite with time = 0
 * output: no change in position or velocity, but direction still changes due to implementation
 **************************************/
void TestSatellite::moveZeroTime()
{
   // SETUP
   SatelliteDerived s;
   s.position.x = 1000000.0;
   s.position.y = 1000000.0;
   s.velocity.dx = 100.0;
   s.velocity.dy = 200.0;
   Position initialPos = s.position;
   Velocity initialVel = s.velocity;
   double time = 0.0;
   
   // EXERCISE
   s.move(time);
   
   // VERIFY
   assertEquals(s.position.x, initialPos.x);        // s = s0 + v*t + (1/2)*a*t^2 = s0 + v*0 + (1/2)*a*0 = s0
   assertEquals(s.position.y, initialPos.y);        // s = s0 + v*t + (1/2)*a*t^2 = s0 + v*0 + (1/2)*a*0 = s0
   assertEquals(s.velocity.dx, initialVel.dx);      // v = v0 + a*t = v0 + a*0 = v0
   assertEquals(s.velocity.dy, initialVel.dy);      // v = v0 + a*t = v0 + a*0 = v0
   assertEquals(s.dead, false);
   assertEquals(s.radius, 0.0);
   assertEquals(s.angularVelocity, 1.0);
   assertEquals(s.direction.radians, 1.0);   
   
   // TEARDOWN
}

/*************************************
 * MOVE - WITH VELOCITY
 * input: satellite with velocity
 * output: position changes according to physics
 **************************************/
void TestSatellite::moveWithVelocity()
{
   // SETUP
   SatelliteDerived s;
   s.position.x = 1000000.0;
   s.position.y = 1000000.0;
   s.velocity.dx = 100.0;
   s.velocity.dy = 200.0;
   Position initialPos = s.position;
   Velocity initialVel = s.velocity;
   double time = 1.0;
   
   // EXERCISE
   s.move(time);
   
   // VERIFY
   assertEquals(s.position.x != initialPos.x, true);        // s = s0 + v*t + (1/2)*a*t^2
   assertEquals(s.position.y != initialPos.y, true);        // s = s0 + v*t + (1/2)*a*t^2
   assertEquals((s.velocity.dx != initialVel.dx || s.velocity.dy != initialVel.dy), true);  // v = v0 + a*t
   assertEquals(s.dead, false);
   assertEquals(s.radius, 0.0);
   assertEquals(s.angularVelocity, 1.0);
   assertEquals(s.direction.radians, 1.0);                  // angle = angle0 + w*t = 0 + 1.0*1.0
   
   // TEARDOWN
}

/*************************************
 * MOVE - WITH ANGULAR VELOCITY
 * input: satellite with angular velocity
 * output: direction changes by angular velocity
 **************************************/
void TestSatellite::moveWithAngularVelocity()
{
   // SETUP
   SatelliteDerived s;
   s.position.x = 1000000.0;
   s.position.y = 1000000.0;
   s.angularVelocity = 0.5;
   double initialDirection = s.direction.radians;
   double time = 1.0;
   
   // EXERCISE
   s.move(time);
   
   // VERIFY
   double expectedDirection = initialDirection + (0.5 * time); // angle = angle0 + w*t
   assertEquals(s.direction.radians, expectedDirection);       // angle = 0 + 0.5*1.0 = 0.5
   assertEquals(s.position.x != 1000000.0, true);              // s = s0 + v*t + (1/2)*a*t^2
   assertEquals(s.position.y != 1000000.0, true);              // s = s0 + v*t + (1/2)*a*t^2
   assertEquals(s.dead, false);
   assertEquals(s.radius, 0.0);
   assertEquals(s.angularVelocity, 0.5);
   
   // TEARDOWN
}

/*************************************
 * MOVE - ZERO VELOCITY
 * input: satellite with zero velocity
 * output: position changes only due to gravity
 **************************************/
void TestSatellite::moveZeroVelocity()
{
   // SETUP
   SatelliteDerived s;
   s.position.x = 1000000.0;
   s.position.y = 1000000.0;
   s.velocity.dx = 0.0;
   s.velocity.dy = 0.0;
   s.angularVelocity = 0.0;
   Position initialPos = s.position;
   Velocity initialVel = s.velocity;
   double time = 1.0;
   
   // EXERCISE
   s.move(time);
   
   // VERIFY
   assertEquals(s.position.x != initialPos.x, true);        // s = s0 + v*t + (1/2)*a*t^2
   assertEquals(s.position.y != initialPos.y, true);        // s = s0 + v*t + (1/2)*a*t^2
   assertEquals((s.velocity.dx != initialVel.dx || s.velocity.dy != initialVel.dy), true);  // v = v0 + a*t
   assertEquals(s.dead, false);
   assertEquals(s.radius, 0.0);
   assertEquals(s.angularVelocity, 0.0);
   assertEquals(s.direction.radians, 0.0);                  // angle = angle0 + w*t = 0 + 0*1.0
   
   // TEARDOWN
}

/*************************************
 * GET POSITION - AFTER MOVE
 * input: satellite with velocity, moved for time
 * output: position changed due to physics
 **************************************/
void TestSatellite::getPositionAfterMove()
{
   // SETUP
   SatelliteDerived s;
   s.position.x = 0.0;
   s.position.y = 26560000.0;                       // High altitude for orbital mechanics
   s.velocity.dx = -3880.0;                         // Orbital velocity
   s.velocity.dy = 0.0;
   Position initialPos = s.position;
   double time = 1.0;
   
   // EXERCISE
   s.move(time);
   
   // VERIFY
   assertEquals(s.position.x != initialPos.x, true);        // s = s0 + v*t + (1/2)*a*t^2
   assertEquals(s.position.y != initialPos.y, true);        // s = s0 + v*t + (1/2)*a*t^2
   assertEquals(s.dead, false);
   assertEquals(s.angularVelocity, 1.0);
   assertEquals(s.radius, 0.0);
   assertEquals((s.velocity.dx != -3880.0 || s.velocity.dy != 0.0), true);  // v = v0 + a*t
   
   // TEARDOWN
}

/*************************************
 * MOVE - AT EARTH SURFACE
 * input: satellite at earth surface with high velocity
 * output: strong gravitational effects
 **************************************/
void TestSatellite::moveAtEarthSurface()
{
   // SETUP
   SatelliteDerived s;
   s.position.x = 6378000.0;                        // At earth's radius (surface)
   s.position.y = 0.0;
   s.velocity.dx = 1000.0;
   s.velocity.dy = 0.0;
   s.angularVelocity = 0.0;
   Position initialPos = s.position;
   Velocity initialVel = s.velocity;
   double time = 1.0;
   
   // EXERCISE
   s.move(time);
   
   // VERIFY
   assertEquals(s.position.x != initialPos.x, true);        // s = s0 + v*t + (1/2)*a*t^2
   assertEquals(s.position.y != initialPos.y, true);        // s = s0 + v*t + (1/2)*a*t^2
   assertEquals((s.velocity.dx != initialVel.dx || s.velocity.dy != initialVel.dy), true);  // v = v0 + a*t
   assertEquals(s.dead, false);
   assertEquals(s.radius, 0.0);
   assertEquals(s.angularVelocity, 0.0);
   assertEquals(s.direction.radians, 0.0);                  // angle = angle0 + w*t = 0 + 0*1.0
   
   // TEARDOWN
}
