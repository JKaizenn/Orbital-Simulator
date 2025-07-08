/***********************************************************************
 * Source File:
 *    TEST STARLINK
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for Starlink
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "starlink.h"
#include "testStarlink.h"
#include <math.h>

/*************************************
 * DEFAULT CONSTRUCTOR
 * input: nothing
 * output: position (0.0, -13020000.0), velocity (5800.0, 0.0), dead(false), angularVelocity(0.05), radius(6.0)
 **************************************/
void TestStarlink::defaultConstructor()
{
   // SETUP
   
   // EXERCISE
   Starlink s;
   
   // VERIFY
   assertEquals(s.position.x, 0.0);
   assertEquals(s.position.y, -13020000.0);
   assertEquals(s.velocity.dx, 5800.0);
   assertEquals(s.velocity.dy, 0.0);
   assertEquals(s.dead, false);
   assertEquals(s.angularVelocity, 0.05);
   assertEquals(s.radius, 6.0);
   assertEquals(s.direction.radians, 0.0);
   
   // TEARDOWN
}
