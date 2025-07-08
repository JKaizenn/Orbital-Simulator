/***********************************************************************
 * Source File:
 *    TEST SPUTNIK
 * Author:
 *    Roger Galan & Jessen Forbush
 * Summary:
 *    The unit tests for Sputnik
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "sputnik.h"
#include "testSputnik.h"
#include <math.h>

/*************************************
 * DEFAULT CONSTRUCTOR
 * input: nothing
 * output: position (-36515095.13, 21082000.0), velocity (2050.0, 2684.68), dead(false), angularVelocity(0.05), radius(4.0)
 **************************************/
void TestSputnik::defaultConstructor()
{
   // SETUP
   
   // EXERCISE
   Sputnik s;
   
   // VERIFY
   assertEquals(s.position.x, -36515095.13);
   assertEquals(s.position.y, 21082000.0);
   assertEquals(s.velocity.dx, 2050.0);
   assertEquals(s.velocity.dy, 2684.68);
   assertEquals(s.dead, false);
   assertEquals(s.angularVelocity, 0.05); 
   assertEquals(s.radius, 4.0);
   assertEquals(s.direction.radians, 0.0);
   
   // TEARDOWN
}
