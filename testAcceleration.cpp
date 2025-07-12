/***********************************************************************
 * Source File:
 *    Test Acceleration : Test the Acceleration class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Acceleration
 ************************************************************************/

#include "testAcceleration.h"
#include "acceleration.h"
#include "angle.h"
#define _USE_MATH_DEFINES
#include <math.h>

/*************************************
 * DEFAULT CONSTRUCTOR
 * input: nothing
 * output: zeros
 **************************************/
void TestAcceleration::constructor_default()
{
   // SETUP
   
   // EXERCISE
   Acceleration a;
   
   // VERIFY
   assertEquals(a.ddx, 0.0);
   assertEquals(a.ddy, 0.0);
   
   // TEARDOWN
}

/*************************************
 * NON-DEFAULT CONSTRUCTOR
 * input: 2.3, 4.5
 * output: (2.3, 4.5)
 **************************************/
void TestAcceleration::constructor_nonDefault()
{
   // SETUP
   double ddx = 2.3;
   double ddy = 4.5;
   
   // EXERCISE
   Acceleration a(ddx, ddy);
   
   // VERIFY
   assertEquals(a.ddx, 2.3);
   assertEquals(a.ddy, 4.5);
   assertEquals(ddx, 2.3);
   assertEquals(ddy, 4.5);
   
   // TEARDOWN
}

/*************************************
 * GET DDX
 * input: (2.3, 4.5)
 * output: 2.3
 **************************************/
void TestAcceleration::getDDX()
{
   // SETUP
   Acceleration a;
   a.ddx = 2.3;
   a.ddy = 4.5;
   
   // EXERCISE
   double ddx = a.getDDX();
   
   // VERIFY
   assertEquals(ddx, 2.3);
   assertEquals(a.ddx, 2.3);
   assertEquals(a.ddy, 4.5);
   
   // TEARDOWN
}

/*************************************
 * GET DDY
 * input: (2.3, 4.5)
 * output: 4.5
 **************************************/
void TestAcceleration::getDDY()
{
   // SETUP
   Acceleration a;
   a.ddx = 2.3;
   a.ddy = 4.5;
   
   // EXERCISE
   double ddy = a.getDDY();
   
   // VERIFY
   assertEquals(ddy, 4.5);
   assertEquals(a.ddx, 2.3);
   assertEquals(a.ddy, 4.5);
   
   // TEARDOWN
}

/*************************************
 * SET DDX
 * input: (-99.9, -88.8) 2.3
 * output: (2.3, -88.8)
 **************************************/
void TestAcceleration::setDDX()
{
   // SETUP
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   double ddx = 2.3;
   
   // EXERCISE
   a.setDDX(ddx);
   
   // VERIFY
   assertEquals(a.ddx, 2.3);
   assertEquals(a.ddy, -88.8);
   assertEquals(ddx, 2.3);
   
   // TEARDOWN
}

/*************************************
 * SET DDY
 * input: (-99.9, -88.8) 4.5
 * output: (-99.9, 4.5)
 **************************************/
void TestAcceleration::setDDY()
{
   // SETUP
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   double ddy = 4.5;
   
   // EXERCISE
   a.setDDY(ddy);
   
   // VERIFY
   assertEquals(a.ddx, -99.9);
   assertEquals(a.ddy, 4.5);
   assertEquals(ddy, 4.5);
   
   // TEARDOWN
}

/*************************************
 * SET UP
 * input: (-99.9, -88.8) 0 degrees, 3.3
 * output: (0.0, 3.3)
 **************************************/
void TestAcceleration::set_up()
{
   // SETUP
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   Angle angle;
   angle.radians = 0.0; // UP
   double magnitude = 3.3;
   
   // EXERCISE
   a.set(angle, magnitude);
   
   // VERIFY
   assertEquals(a.ddx, 0.0);
   assertEquals(a.ddy, 3.3);
   assertEquals(angle.radians, 0.0);
   assertEquals(magnitude, 3.3);
   
   // TEARDOWN
}

/*************************************
 * SET DOWN
 * input: (-99.9, -88.8) 180 degrees, 3.3
 * output: (0.0, -3.3)
 **************************************/
void TestAcceleration::set_down()
{
   // SETUP
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   Angle angle;
   angle.radians = M_PI; // DOWN
   double magnitude = 3.3;
   
   // EXERCISE
   a.set(angle, magnitude);
   
   // VERIFY
   assertEquals(a.ddx, 0.0);
   assertEquals(a.ddy, -3.3);
   assertEquals(angle.radians, M_PI);
   assertEquals(magnitude, 3.3);
   
   // TEARDOWN
}

/*************************************
 * SET RIGHT
 * input: (-99.9, -88.8) 90 degrees, 3.3
 * output: (3.3, 0.0)
 **************************************/
void TestAcceleration::set_right()
{
   // SETUP
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   Angle angle;
   angle.radians = M_PI_2; // RIGHT
   double magnitude = 3.3;
   
   // EXERCISE
   a.set(angle, magnitude);
   
   // VERIFY
   assertEquals(a.ddx, 3.3);
   assertEquals(a.ddy, 0.0);
   assertEquals(angle.radians, M_PI_2);
   assertEquals(magnitude, 3.3);
   
   // TEARDOWN
}

/*************************************
 * SET LEFT
 * input: (-99.9, -88.8) 270 degrees, 3.3
 * output: (-3.3, 0.0)
 **************************************/
void TestAcceleration::set_left()
{
   // SETUP
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   Angle angle;
   angle.radians = M_PI_2 + M_PI; // LEFT
   double magnitude = 3.3;
   
   // EXERCISE
   a.set(angle, magnitude);
   
   // VERIFY
   assertEquals(a.ddx, -3.3);
   assertEquals(a.ddy, 0.0);
   assertEquals(angle.radians, M_PI_2 + M_PI);
   assertEquals(magnitude, 3.3);
   
   // TEARDOWN
}

/*************************************
 * SET DIAGONAL
 * input: (-99.9, -88.8) 57 degrees, 1.0
 * output: (0.84, 0.54)
 **************************************/
void TestAcceleration::set_diagonal()
{
   // SETUP
   Acceleration a;
   a.ddx = -99.9;
   a.ddy = -88.8;
   Angle angle;
   angle.radians = 1.0; // up and right somewhat
   double magnitude = 1.0;
   
   // EXERCISE
   a.set(angle, magnitude);
   
   // VERIFY
   assertEquals(a.ddx, 0.8414);
   assertEquals(a.ddy, 0.5403);
   assertEquals(angle.radians, 1.0);
   assertEquals(magnitude, 1.0);
   
   // TEARDOWN
}

/*************************************
 * ADD DDX ZERO
 * input: (2.3, 4.5) 0.0
 * output: (2.3, 4.5)
 **************************************/
void TestAcceleration::addDDX_zero()
{
   // SETUP
   Acceleration a;
   a.ddx = 2.3;
   a.ddy = 4.5;
   double ddx = 0.0;
   
   // EXERCISE
   a.addDDX(ddx);
   
   // VERIFY
   assertEquals(a.ddx, 2.3);
   assertEquals(a.ddy, 4.5);
   assertEquals(ddx, 0.0);
   
   // TEARDOWN
}

/*************************************
 * ADD DDX VALUE
 * input: (2.3, 4.5) 4.1
 * output: (6.4, 4.5)
 **************************************/
void TestAcceleration::addDDX_value()
{
   // SETUP
   Acceleration a;
   a.ddx = 2.3;
   a.ddy = 4.5;
   double ddx = 4.1;
   
   // EXERCISE
   a.addDDX(ddx);
   
   // VERIFY
   assertEquals(a.ddx, 6.4);
   assertEquals(a.ddy, 4.5);
   assertEquals(ddx, 4.1);
   
   // TEARDOWN
}

/*************************************
 * ADD DDY ZERO
 * input: (2.3, 4.5) 0.0
 * output: (2.3, 4.5)
 **************************************/
void TestAcceleration::addDDY_zero()
{
   // SETUP
   Acceleration a;
   a.ddx = 2.3;
   a.ddy = 4.5;
   double ddy = 0.0;
   
   // EXERCISE
   a.addDDY(ddy);
   
   // VERIFY
   assertEquals(a.ddx, 2.3);
   assertEquals(a.ddy, 4.5);
   assertEquals(ddy, 0.0);
   
   // TEARDOWN
}

/*************************************
 * ADD DDY VALUE
 * input: (2.3, 4.5) 4.1
 * output: (2.3, 8.6)
 **************************************/
void TestAcceleration::addDDY_value()
{
   // SETUP
   Acceleration a;
   a.ddx = 2.3;
   a.ddy = 4.5;
   double ddy = 4.1;
   
   // EXERCISE
   a.addDDY(ddy);
   
   // VERIFY
   assertEquals(a.ddx, 2.3);
   assertEquals(a.ddy, 8.6);
   assertEquals(ddy, 4.1);
   
   // TEARDOWN
}

/*************************************
 * ADD NOTHING TO NOTHING
 * input: (0.0, 0.0) (0.0, 0.0)
 * output: (0.0, 0.0)
 **************************************/
void TestAcceleration::add_zeroZero()
{
   // SETUP
   Acceleration a;
   a.ddx = 0.0;
   a.ddy = 0.0;
   Acceleration aRHS;
   aRHS.ddx = 0.0;
   aRHS.ddy = 0.0;
   
   // EXERCISE
   a.add(aRHS);
   
   // VERIFY
   assertEquals(a.ddx, 0.0);
   assertEquals(a.ddy, 0.0);
   assertEquals(aRHS.ddx, 0.0);
   assertEquals(aRHS.ddy, 0.0);
   
   // TEARDOWN
}

/*************************************
 * ADD NOTHING TO A VALUE
 * input: (1.1, 2.2) (0.0, 0.0)
 * output: (1.1, 2.2)
 **************************************/
void TestAcceleration::add_valueZero()
{
   // SETUP
   Acceleration a;
   a.ddx = 1.1;
   a.ddy = 2.2;
   Acceleration aRHS;
   aRHS.ddx = 0.0;
   aRHS.ddy = 0.0;
   
   // EXERCISE
   a.add(aRHS);
   
   // VERIFY
   assertEquals(a.ddx, 1.1);
   assertEquals(a.ddy, 2.2);
   assertEquals(aRHS.ddx, 0.0);
   assertEquals(aRHS.ddy, 0.0);
   
   // TEARDOWN
}

/*************************************
 * ADD A VALUE TO NOTHING
 * input: (0.0, 0.0) (4.4, 7.7)
 * output: (4.4, 7.7)
 **************************************/
void TestAcceleration::add_zeroValue()
{
   // SETUP
   Acceleration a;
   a.ddx = 0.0;
   a.ddy = 0.0;
   Acceleration aRHS;
   aRHS.ddx = 4.4;
   aRHS.ddy = 7.7;
   
   // EXERCISE
   a.add(aRHS);
   
   // VERIFY
   assertEquals(a.ddx, 4.4);
   assertEquals(a.ddy, 7.7);
   assertEquals(aRHS.ddx, 4.4);
   assertEquals(aRHS.ddy, 7.7);
   
   // TEARDOWN
}

/*************************************
 * ADD A VALUE TO ANOTHER VALUE
 * input: (1.1, 2.2) (4.4, 7.7)
 * output: (5.5, 9.9)
 **************************************/
void TestAcceleration::add_valueValue()
{
   // SETUP
   Acceleration a;
   a.ddx = 1.1;
   a.ddy = 2.2;
   Acceleration aRHS;
   aRHS.ddx = 4.4;
   aRHS.ddy = 7.7;
   
   // EXERCISE
   a.add(aRHS);
   
   // VERIFY
   assertEquals(a.ddx, 5.5);
   assertEquals(a.ddy, 9.9);
   assertEquals(aRHS.ddx, 4.4);
   assertEquals(aRHS.ddy, 7.7);
   
   // TEARDOWN
}
