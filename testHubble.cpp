/***********************************************************************
 * Source File:
 *    TEST HUBBLE
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for Hubble
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "hubble.h"
#include "testHubble.h"
#include <math.h>

/*************************************
 * DEFAULT CONSTRUCTOR
 * input: nothing
 * output: position(0.0, -42164000.0), velocity(3100.0, 0.0), dead(false), angularVelocity(0.05), radius(10.0)
 **************************************/
void TestHubble::defaultConstructor()
{
   // SETUP
   
   // EXERCISE
   Hubble h;
   
   // VERIFY
   assertEquals(h.position.x, 0.0);
   assertEquals(h.position.y, -42164000.0);
   assertEquals(h.velocity.dx, 3100.0);
   assertEquals(h.velocity.dy, 0.0);
   assertEquals(h.dead, false);
   assertEquals(h.angularVelocity, 0.05);  
   assertEquals(h.radius, 10.0);
   assertEquals(h.direction.radians, 0.0);
   
   // TEARDOWN
}
