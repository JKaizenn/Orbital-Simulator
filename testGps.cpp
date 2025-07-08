/***********************************************************************
 * Source File:
 *    TEST GPS
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for GPS
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "gps.h"
#include "testGps.h"
#include <math.h>

/*************************************
 * DEFAULT CONSTRUCTOR 0
 * input: nothing (GPS satellite 0)
 * output: position (0.0, 26560000.0), velocity (-3880.0, 0.0), dead(false), angularVelocity(0.05), radius(12.0)
 **************************************/
void TestGps::defaultConstructor0()
{
   // SETUP
   
   // EXERCISE
   Gps gps0(0);
   
   // VERIFY
   assertEquals(gps0.position.x, 0.0);
   assertEquals(gps0.position.y, 26560000.0);
   assertEquals(gps0.velocity.dx, -3880.0);
   assertEquals(gps0.velocity.dy, 0.0);
   assertEquals(gps0.dead, false);
   assertEquals(gps0.angularVelocity, 0.05);
   assertEquals(gps0.radius, 12.0);
   assertEquals(gps0.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * DEFAULT CONSTRUCTOR 1
 * input: nothing (GPS satellite 1)
 * output: position (23001634.72, 13280000.0), velocity (-1940.0, 3360.18), dead(false), angularVelocity(0.05), radius(12.0)
 **************************************/
void TestGps::defaultConstructor1()
{
   // SETUP
   
   // EXERCISE
   Gps gps1(1);
   
   // VERIFY
   assertEquals(gps1.position.x, 23001634.72);
   assertEquals(gps1.position.y, 13280000.0);
   assertEquals(gps1.velocity.dx, -1940.0);
   assertEquals(gps1.velocity.dy, 3360.18);
   assertEquals(gps1.dead, false);
   assertEquals(gps1.angularVelocity, 0.05);
   assertEquals(gps1.radius, 12.0);
   assertEquals(gps1.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * DEFAULT CONSTRUCTOR 2
 * input: nothing (GPS satellite 2)
 * output: position (23001634.72, -13280000.0), velocity (1940.0, 3360.18), dead(false), angularVelocity(0.05), radius(12.0)
 **************************************/
void TestGps::defaultConstructor2()
{
   // SETUP
   
   // EXERCISE
   Gps gps2(2);
   
   // VERIFY
   assertEquals(gps2.position.x, 23001634.72);
   assertEquals(gps2.position.y, -13280000.0);
   assertEquals(gps2.velocity.dx, 1940.0);
   assertEquals(gps2.velocity.dy, 3360.18);
   assertEquals(gps2.dead, false);
   assertEquals(gps2.angularVelocity, 0.05);
   assertEquals(gps2.radius, 12.0);
   assertEquals(gps2.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * DEFAULT CONSTRUCTOR 3
 * input: nothing (GPS satellite 3)
 * output: position (0.0, -26560000.0), velocity (3880.0, 0.0), dead(false), angularVelocity(0.05), radius(12.0)
 **************************************/
void TestGps::defaultConstructor3()
{
   // SETUP
   
   // EXERCISE
   Gps gps3(3);
   
   // VERIFY
   assertEquals(gps3.position.x, 0.0);
   assertEquals(gps3.position.y, -26560000.0);
   assertEquals(gps3.velocity.dx, 3880.0);
   assertEquals(gps3.velocity.dy, 0.0);
   assertEquals(gps3.dead, false);
   assertEquals(gps3.angularVelocity, 0.05);
   assertEquals(gps3.radius, 12.0);
   assertEquals(gps3.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * DEFAULT CONSTRUCTOR 4
 * input: nothing (GPS satellite 4)
 * output: position (-23001634.72, -13280000.0), velocity (1940.0, -3360.18), dead(false), angularVelocity(0.05), radius(12.0)
 **************************************/
void TestGps::defaultConstructor4()
{
   // SETUP
   
   // EXERCISE
   Gps gps4(4);
   
   // VERIFY
   assertEquals(gps4.position.x, -23001634.72);
   assertEquals(gps4.position.y, -13280000.0);
   assertEquals(gps4.velocity.dx, 1940.0);
   assertEquals(gps4.velocity.dy, -3360.18);
   assertEquals(gps4.dead, false);
   assertEquals(gps4.angularVelocity, 0.05);
   assertEquals(gps4.radius, 12.0);
   assertEquals(gps4.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * DEFAULT CONSTRUCTOR 5
 * input: nothing (GPS satellite 5)
 * output: position (-23001634.72, 13280000.0), velocity (-1940.0, -3360.18), dead(false), angularVelocity(0.05), radius(12.0)
 **************************************/
void TestGps::defaultConstructor5()
{
   // SETUP
   
   // EXERCISE
   Gps gps5(5);
   
   // VERIFY
   assertEquals(gps5.position.x, -23001634.72);
   assertEquals(gps5.position.y, 13280000.0);
   assertEquals(gps5.velocity.dx, -1940.0);
   assertEquals(gps5.velocity.dy, -3360.18);
   assertEquals(gps5.dead, false);
   assertEquals(gps5.angularVelocity, 0.05);
   assertEquals(gps5.radius, 12.0);
   assertEquals(gps5.direction.radians, 0.0);
   
   // TEARDOWN
}
