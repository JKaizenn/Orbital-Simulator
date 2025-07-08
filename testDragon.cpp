/***********************************************************************
 * Source File:
 *    TEST DRAGON
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for Dragon
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "dragon.h"
#include "testDragon.h"
#include <math.h>

/*************************************
 * DEFAULT CONSTRUCTOR
 * input: nothing
 * output: position (0.0, 8000000.0), velocity (-7900.0, 0.0), dead(false), angularVelocity(0.05), radius(7.0)
 **************************************/
void TestDragon::defaultConstructor()
{
   // SETUP
   
   // EXERCISE
   Dragon d;
   
   // VERIFY
   assertEquals(d.position.x, 0.0);
   assertEquals(d.position.y, 8000000.0);
   assertEquals(d.velocity.dx, -7900.0);
   assertEquals(d.velocity.dy, 0.0);
   assertEquals(d.dead, false);
   assertEquals(d.angularVelocity, 0.05);
   assertEquals(d.radius, 7.0);
   assertEquals(d.direction.radians, 0.0);
   
   // TEARDOWN
}
