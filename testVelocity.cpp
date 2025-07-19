/***********************************************************************
 * Source File:
 *    TEST VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The unit tests for the Velocity class
 ************************************************************************/

#include "testVelocity.h"
#include "velocity.h"
#include "acceleration.h"
#include "angle.h"
#define _USE_MATH_DEFINES
#include <math.h>

/*****************************************************************
 *****************************************************************
 * CONSTRUCTOR
 *****************************************************************
 *****************************************************************/

/*********************************************
 * name:    DEFAULT CONSTRUCTOR
 * input:   nothing
 * output:  zero
 *********************************************/
void TestVelocity::constructor_default()
{
   // SETUP
   
   // EXERCISE
   Velocity v;
   
   // VERIFY
   assertEquals(v.dx, 0.0);
   assertEquals(v.dy, 0.0);
   
   // TEARDOWN
}

/*********************************************
 * name:    NON DEFAULT CONSTRUCTOR
 * input:   2.3, 4.5
 * output:  (2.3, 4.5)
 *********************************************/
void TestVelocity::constructor_nonDefault()
{
   // SETUP
   double dx = 2.3;
   double dy = 4.5;
   
   // EXERCISE
   Velocity v(dx, dy);
   
   // VERIFY
   assertEquals(v.dx, 2.3);
   assertEquals(v.dy, 4.5);
   assertEquals(dx, 2.3);
   assertEquals(dy, 4.5);
   
   // TEARDOWN
}

/*****************************************************************
 *****************************************************************
 * GETTERS
 *****************************************************************
 *****************************************************************/

/*********************************************
 * name:    GET DX
 * input:   (2.3, 4.5)
 * output:  2.3
 *********************************************/
void TestVelocity::getDX()
{
   // SETUP
   Velocity v;
   v.dx = 2.3;
   v.dy = 4.5;
   double dx = 99.9;
   
   // EXERCISE
   dx = v.getDX();
   
   // VERIFY
   assertEquals(v.dx, 2.3);
   assertEquals(v.dy, 4.5);
   assertEquals(dx, 2.3);
   
   // TEARDOWN
}

/*********************************************
 * name:    GET DY
 * input:   (2.3, 4.5)
 * output:  4.5
 *********************************************/
void TestVelocity::getDY()
{
   // SETUP
   Velocity v;
   v.dx = 2.3;
   v.dy = 4.5;
   double dy = 99.9;
   
   // EXERCISE
   dy = v.getDY();
   
   // VERIFY
   assertEquals(v.dx, 2.3);
   assertEquals(v.dy, 4.5);
   assertEquals(dy, 4.5);
   
   // TEARDOWN
}

/*********************************************
 * name:    GET SPEED ZERO
 * input:   (0.0, 0.0)
 * output:  0.0
 *********************************************/
void TestVelocity::getSpeed_zero()
{
   // SETUP
   Velocity v;
   v.dx = 0.0;
   v.dy = 0.0;
   double s = 99.9;
   
   // EXERCISE
   s = v.getSpeed();
   
   // VERIFY
   assertEquals(v.dx, 0.0);
   assertEquals(v.dy, 0.0);
   assertEquals(s, 0.0);
   
   // TEARDOWN
}

/*********************************************
 * name:    GET SPEED RIGHT
 * input:   (2.3, 0.0)
 * output:  2.3
 *********************************************/
void TestVelocity::getSpeed_right()
{
   // SETUP
   Velocity v;
   v.dx = 2.3;
   v.dy = 0.0;
   double s = 99.9;
   
   // EXERCISE
   s = v.getSpeed();
   
   // VERIFY
   assertEquals(v.dx, 2.3);
   assertEquals(v.dy, 0.0);
   assertEquals(s, 2.3);
   
   // TEARDOWN
}

/*********************************************
 * name:    GET SPEED UP
 * input:   (0.0, 4.5)
 * output:  4.5
 *********************************************/
void TestVelocity::getSpeed_up()
{
   // SETUP
   Velocity v;
   v.dx = 0.0;
   v.dy = 4.5;
   double s = 99.9;
   
   // EXERCISE
   s = v.getSpeed();
   
   // VERIFY
   assertEquals(v.dx, 0.0);
   assertEquals(v.dy, 4.5);
   assertEquals(s, 4.5);
   
   // TEARDOWN
}

/*********************************************
 * name:    GET SPEED LEFT
 * input:   (-2.3, 0.0)
 * output:  2.3
 *********************************************/
void TestVelocity::getSpeed_left()
{
   // SETUP
   Velocity v;
   v.dx = -2.3;
   v.dy = 0.0;
   double s = 99.9;
   
   // EXERCISE
   s = v.getSpeed();
   
   // VERIFY
   assertEquals(v.dx, -2.3);
   assertEquals(v.dy, 0.0);
   assertEquals(s, 2.3);
   
   // TEARDOWN
}

/*********************************************
 * name:    GET SPEED DOWN
 * input:   (0.0, -4.5)
 * output:  4.5
 *********************************************/
void TestVelocity::getSpeed_down()
{
   // SETUP
   Velocity v;
   v.dx = 0.0;
   v.dy = -4.5;
   double s = 99.9;
   
   // EXERCISE
   s = v.getSpeed();
   
   // VERIFY
   assertEquals(v.dx, 0.0);
   assertEquals(v.dy, -4.5);
   assertEquals(s, 4.5);
   
   // TEARDOWN
}

/*********************************************
 * name:    GET SPEED DIAGONAL
 * input:   (3.0, -4.0)
 * output:  5.0
 *********************************************/
void TestVelocity::getSpeed_diagonal()
{
   // SETUP
   Velocity v;
   v.dx = 3.0;
   v.dy = -4.0;
   double s = 99.9;
   
   // EXERCISE
   s = v.getSpeed();
   
   // VERIFY
   assertEquals(v.dx, 3.0);
   assertEquals(v.dy, -4.0);
   assertEquals(s, 5.0);
   
   // TEARDOWN
}

/*****************************************************************
 *****************************************************************
 * SETTERS
 *****************************************************************
 *****************************************************************/

/*********************************************
 * name:    SET DX
 * input:   (99.9, 88.8) -1.1
 * output:  (-1.1, 88.8)
 *********************************************/
void TestVelocity::setDX()
{
   // SETUP
   Velocity v;
   v.dx = 99.9;
   v.dy = 88.8;
   double dx = -1.1;
   
   // EXERCISE
   v.setDX(dx);
   
   // VERIFY
   assertEquals(v.dx, -1.1);
   assertEquals(v.dy, 88.8);
   assertEquals(dx, -1.1);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET DY
 * input:   (99.9, 88.8) -1.1
 * output:  (99.9, -1.1)
 *********************************************/
void TestVelocity::setDY()
{
   // SETUP
   Velocity v;
   v.dx = 99.9;
   v.dy = 88.8;
   double dy = -1.1;
   
   // EXERCISE
   v.setDY(dy);
   
   // VERIFY
   assertEquals(v.dx, 99.9);
   assertEquals(v.dy, -1.1);
   assertEquals(dy, -1.1);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET UP
 * input:   (-99.9, -88.8) 0 degrees, 3.3
 * output:  (0.0, 3.3)
 *********************************************/
void TestVelocity::set_up()
{
   // SETUP
   Velocity v;
   v.dx = -99.9;
   v.dy = -88.8;
   Angle angle;
   angle.radians = 0.0;
   double magnitude = 3.3;
   
   // EXERCISE
   v.set(angle, magnitude);
   
   // VERIFY
   assertEquals(v.dx, 0.0);
   assertEquals(v.dy, 3.3);
   assertEquals(angle.radians, 0.0);
   assertEquals(magnitude, 3.3);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET DOWN
 * input:   (-99.9, -88.8) 180 degrees, 3.3
 * output:  (0.0, -3.3)
 *********************************************/
void TestVelocity::set_down()
{
   // SETUP
   Velocity v;
   v.dx = -99.9;
   v.dy = -88.8;
   Angle angle;
   angle.radians = M_PI;
   double magnitude = 3.3;
   
   // EXERCISE
   v.set(angle, magnitude);
   
   // VERIFY
   assertEquals(v.dx, 0.0);
   assertEquals(v.dy, -3.3);
   assertEquals(angle.radians, M_PI);
   assertEquals(magnitude, 3.3);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET LEFT
 * input:   (-99.9, -88.8) 270 degrees, 3.3
 * output:  (-3.3, 0.0)
 *********************************************/
void TestVelocity::set_left()
{
   // SETUP
   Velocity v;
   v.dx = -99.9;
   v.dy = -88.8;
   Angle angle;
   angle.radians = M_PI_2 + M_PI;
   double magnitude = 3.3;
   
   // EXERCISE
   v.set(angle, magnitude);
   
   // VERIFY
   assertEquals(v.dx, -3.3);
   assertEquals(v.dy, 0.0);
   assertEquals(angle.radians, M_PI_2 + M_PI);
   assertEquals(magnitude, 3.3);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET RIGHT
 * input:   (-99.9, -88.8) 90 degrees, 3.3
 * output:  (3.3, 0.0)
 *********************************************/
void TestVelocity::set_right()
{
   // SETUP
   Velocity v;
   v.dx = -99.9;
   v.dy = -88.8;
   Angle angle;
   angle.radians = M_PI_2;
   double magnitude = 3.3;
   
   // EXERCISE
   v.set(angle, magnitude);
   
   // VERIFY
   assertEquals(v.dx, 3.3);
   assertEquals(v.dy, 0.0);
   assertEquals(angle.radians, M_PI_2);
   assertEquals(magnitude, 3.3);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET DIAGONAL
 * input:   (-99.9, -88.8) 57 degrees, 1.0
 * output:  (0.84, 0.54)
 *********************************************/
void TestVelocity::set_diagonal()
{
   // SETUP
   Velocity v;
   v.dx = -99.9;
   v.dy = -88.8;
   Angle angle;
   angle.radians = 1.0;
   double magnitude = 1.0;
   
   // EXERCISE
   v.set(angle, magnitude);
   
   // VERIFY
   assertEquals(v.dx, 0.8414);
   assertEquals(v.dy, 0.5403);
   assertEquals(angle.radians, 1.0);
   assertEquals(magnitude, 1.0);
   
   // TEARDOWN
}

/*****************************************************************
 *****************************************************************
 * ADD
 *****************************************************************
 *****************************************************************/

/*********************************************
 * name:    ADD DX ZERO
 * input:   (2.3, 4.5) 0.0
 * output:  (2.3, 4.5)
 *********************************************/
void TestVelocity::addDX_zero()
{
   // SETUP
   Velocity v;
   v.dx = 2.3;
   v.dy = 4.5;
   double dx = 0.0;
   
   // EXERCISE
   v.addDX(dx);
   
   // VERIFY
   assertEquals(v.dx, 2.3);
   assertEquals(v.dy, 4.5);
   assertEquals(dx, 0.0);
   
   // TEARDOWN
}

/*********************************************
 * name:    ADD DX VALUE
 * input:   (2.3, 4.5) 4.1
 * output:  (6.4, 4.5)
 *********************************************/
void TestVelocity::addDX_value()
{
   // SETUP
   Velocity v;
   v.dx = 2.3;
   v.dy = 4.5;
   double dx = 4.1;
   
   // EXERCISE
   v.addDX(dx);
   
   // VERIFY
   assertEquals(v.dx, 6.4);
   assertEquals(v.dy, 4.5);
   assertEquals(dx, 4.1);
   
   // TEARDOWN
}

/*********************************************
 * name:    ADD DY ZERO
 * input:   (2.3, 4.5) 0.0
 * output:  (2.3, 4.5)
 *********************************************/
void TestVelocity::addDY_zero()
{
   // SETUP
   Velocity v;
   v.dx = 2.3;
   v.dy = 4.5;
   double dy = 0.0;
   
   // EXERCISE
   v.addDY(dy);
   
   // VERIFY
   assertEquals(v.dx, 2.3);
   assertEquals(v.dy, 4.5);
   assertEquals(dy, 0.0);
   
   // TEARDOWN
}

/*********************************************
 * name:    ADD DY VALUE
 * input:   (2.3, 4.5) 4.1
 * output:  (2.3, 8.6)
 *********************************************/
void TestVelocity::addDY_value()
{
   // SETUP
   Velocity v;
   v.dx = 2.3;
   v.dy = 4.5;
   double dy = 4.1;
   
   // EXERCISE
   v.addDY(dy);
   
   // VERIFY
   assertEquals(v.dx, 2.3);
   assertEquals(v.dy, 8.6);
   assertEquals(dy, 4.1);
   
   // TEARDOWN
}

/*********************************************
 * name:    ADD  STATIONARY
 * input:   v=(2.3, 4.5) a=(0.0, 0.0) t=0.0
 * output:  (2.3, 4.5)
 *********************************************/
void TestVelocity::add_stationary()
{
   // SETUP
   Velocity v;
   v.dx = 2.3;
   v.dy = 4.5;
   Acceleration a;
   a.ddx = 0.0;
   a.ddy = 0.0;
   double t = 0.0;
   
   // EXERCISE
   v.add(a, t);
   
   // VERIFY
   assertEquals(v.dx, 2.3);
   assertEquals(v.dy, 4.5);
   assertEquals(a.ddx, 0.0);
   assertEquals(a.ddy, 0.0);
   assertEquals(t, 0.0);
   
   // TEARDOWN
}

/*********************************************
 * name:    ADD  TIME IS ZERO
 * input:   v=(2.3, 4.5) a=(6.0, 7.0) t=0.0
 * output:  (2.3, 4.5)
 *********************************************/
void TestVelocity::add_noTime()
{
   // SETUP
   Velocity v;
   v.dx = 2.3;
   v.dy = 4.5;
   Acceleration a;
   a.ddx = 6.0;
   a.ddy = 7.0;
   double t = 0.0;
   
   // EXERCISE
   v.add(a, t);
   
   // VERIFY
   assertEquals(v.dx, 2.3);
   assertEquals(v.dy, 4.5);
   assertEquals(a.ddx, 6.0);
   assertEquals(a.ddy, 7.0);
   assertEquals(t, 0.0);
   
   // TEARDOWN
}

/*********************************************
 * name:    ADD  ONE SECOND
 * input:   v=(2.3, 4.5) a=(6.0, 7.0) t=1.0
 * output:  (8.3, 11.5)
 *********************************************/
void TestVelocity::add_moving1Second()
{
   // SETUP
   Velocity v;
   v.dx = 2.3;
   v.dy = 4.5;
   Acceleration a;
   a.ddx = 6.0;
   a.ddy = 7.0;
   double t = 1.0;
   
   // EXERCISE
   v.add(a, t);
   
   // VERIFY
   assertEquals(v.dx, 8.3);  // 2.3 + 6.0*1
   assertEquals(v.dy, 11.5); // 4.5 + 7.0*1
   assertEquals(a.ddx, 6.0);
   assertEquals(a.ddy, 7.0);
   assertEquals(t, 1.0);
   
   // TEARDOWN
}

/*********************************************
 * name:    ADD  FOUR SECONDS
 * input:   v=(2.3, 4.5) a=(6.0, 7.0) t=4.0
 * output:  (14.3, 24.5)
 *********************************************/
void TestVelocity::add_moving4Seconds()
{
   // SETUP
   Velocity v;
   v.dx = 2.3;
   v.dy = 4.5;
   Acceleration a;
   a.ddx = 3.0;
   a.ddy = 5.0;
   double t = 4.0;
   
   // EXERCISE
   v.add(a, t);
   
   // VERIFY
   assertEquals(v.dx, 14.3); // 2.3 + 3.0*4
   assertEquals(v.dy, 24.5); // 4.5 + 5.0*4
   assertEquals(a.ddx, 3.0);
   assertEquals(a.ddy, 5.0);
   assertEquals(t, 4.0);
   
   // TEARDOWN
}
