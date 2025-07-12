/***********************************************************************
 * Source File:
 *    Test Angle : Test the Angle class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Angle
 ************************************************************************/

#include "testAngle.h"
#include "angle.h"
#define _USE_MATH_DEFINES
#include <math.h>

/*************************************
 * DEFAULT CONSTRUCTOR
 * input: nothing
 * output: zero
 **************************************/
void TestAngle::defaultConstructor()
{
   // SETUP
   
   // EXERCISE
   Angle a;
   
   // VERIFY
   assertUnit(a.radians == 0.0);
   
   // TEARDOWN
}

/*************************************
 * SET UP
 * input: nothing
 * output: 0 degrees
 **************************************/
void TestAngle::setUp()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setUp();
   
   // VERIFY
   assertUnit(a.radians == 0.0);
   
   // TEARDOWN
}

/*************************************
 * SET DOWN
 * input: nothing
 * output: 180 degrees
 **************************************/
void TestAngle::setDown()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setDown();
   
   // VERIFY
   assertUnit(a.radians == M_PI);
   
   // TEARDOWN
}

/*************************************
 * SET RIGHT
 * input: nothing
 * output: 90 degrees
 **************************************/
void TestAngle::setRight()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRight();
   
   // VERIFY
   assertUnit(a.radians == M_PI_2);
   
   // TEARDOWN
}

/*************************************
 * SET LEFT
 * input: nothing
 * output: 270 degrees
 **************************************/
void TestAngle::setLeft()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setLeft();
   
   // VERIFY
   assertUnit(a.radians == M_PI + M_PI_2);
   
   // TEARDOWN
}

/*************************************
 * REVERSE
 * input: 90 degrees
 * output: 270 degrees
 **************************************/
void TestAngle::reverse()
{
   // SETUP
   Angle a;
   a.radians = M_PI_2;
   
   // EXERCISE
   a.reverse();
   
   // VERIFY
   assertUnit(a.radians == M_PI + M_PI_2);
   
   // TEARDOWN
}

/*************************************
 * SET RADIANS - NO NORMALIZATION
 * input: 1.23 radians
 * output: 1.23 radians
 **************************************/
void TestAngle::setRadians_noNormalize()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(1.23);
   
   // VERIFY
   assertEquals(a.radians, 1.23);
   
   // TEARDOWN
}

/*************************************
 * SET DEGREES - NO NORMALIZATION
 * input: 45 degrees
 * output: 45 degrees
 **************************************/
void TestAngle::setDegrees_noNormalize()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setDegrees(45.0);
   
   // VERIFY
   assertEquals(a.radians, 0.785398);
   
   // TEARDOWN
}

/*************************************
 * GET DEGREES - 0
 * input: 0 radians
 * output: 0 degrees
 **************************************/
void TestAngle::getDegrees_0()
{
   // SETUP
   Angle a;
   a.radians = 0.0;
   
   // EXERCISE
   double degrees = a.getDegrees();
   
   // VERIFY
   assertEquals(degrees, 0.0);
   assertEquals(a.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * GET DEGREES - 270
 * input: 1.5π radians
 * output: 270 degrees
 **************************************/
void TestAngle::getDegrees_270()
{
   // SETUP
   Angle a;
   a.radians = M_PI + M_PI_2;
   
   // EXERCISE
   double degrees = a.getDegrees();
   
   // VERIFY
   assertEquals(degrees, 270.0);
   assertEquals(a.radians, M_PI + M_PI_2);
   
   // TEARDOWN
}

/*************************************
 * GET RADIANS - 0
 * input: 0 radians
 * output: 0 radians
 **************************************/
void TestAngle::getRadians_0()
{
   // SETUP
   Angle a;
   a.radians = 0.0;
   
   // EXERCISE
   double radians = a.getRadians();
   
   // VERIFY
   assertEquals(radians, 0.0);
   assertEquals(a.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * GET RADIANS - 270
 * input: 1.5π radians
 * output: 1.5π radians
 **************************************/
void TestAngle::getRadians_270()
{
   // SETUP
   Angle a;
   a.radians = M_PI + M_PI_2;
   
   // EXERCISE
   double radians = a.getRadians();
   
   // VERIFY
   assertEquals(radians, M_PI + M_PI_2);
   assertEquals(a.radians, M_PI + M_PI_2);
   
   // TEARDOWN
}

/*************************************
 * ADD - 0
 * input: 2.3 radians + 0.0 radians
 * output: 2.3 radians
 **************************************/
void TestAngle::add_0()
{
   // SETUP
   Angle a;
   a.radians = 2.3;
   double delta = 0.0;
   
   // EXERCISE
   a.add(delta);
   
   // VERIFY
   assertEquals(a.radians, 2.3);
   assertEquals(delta, 0.0);
   
   // TEARDOWN
}

/*************************************
 * ADD - VALUE
 * input: (45 degrees) 180 degrees
 * output: 225 degrees
 **************************************/
void TestAngle::add_value()
{
   // SETUP
   Angle a;
   a.radians = 0.785398;
   double r = M_PI;
   
   // EXERCISE
   a.add(r);
   
   // VERIFY
   assertEquals(a.radians, 0.785398 + M_PI);
   assertEquals(r, M_PI);
   
   // TEARDOWN
}

/*************************************
 * SET RADIANS - NEGATIVE
 * input: -90 radians
 * output: 270 degrees (normalized)
 **************************************/
void TestAngle::setRadians_negative()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(-M_PI_2);
   
   // VERIFY
   assertEquals(a.radians, M_PI + M_PI_2);
   
   // TEARDOWN
}

/*************************************
 * SET RADIANS - ONE LAP
 * input: 1.23 + 2π radians
 * output: 1.23 radians
 **************************************/
void TestAngle::setRadians_oneLap()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(1.23 + 2.0 * M_PI);
   
   // VERIFY
   assertEquals(a.radians, 1.23);
   
   // TEARDOWN
}

/*************************************
 * SET RADIANS - SIX LAPS
 * input: 1.23 + 6×2π radians
 * output: 1.23 radians
 **************************************/
void TestAngle::setRadians_sixLaps()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(1.23 + 6.0 * 2.0 * M_PI);
   
   // VERIFY
   assertEquals(a.radians, 1.23);
   
   // TEARDOWN
}

/*************************************
 * SET RADIANS - NEGATIVE THREE QUARTERS
 * input: -3π/2 radians
 * output: π/2 radians (90 degrees)
 **************************************/
void TestAngle::setRadians_negativeThreeQuarters()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(-M_PI - M_PI_2);
   
   // VERIFY
   assertEquals(a.radians, M_PI_2);
   
   // TEARDOWN
}

/*************************************
 * SET RADIANS - NEGATIVE ONE LAP
 * input: 1.23 - 2π radians
 * output: 1.23 radians
 **************************************/
void TestAngle::setRadians_negativeOneLap()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(1.23 - 2.0 * M_PI);
   
   // VERIFY
   assertEquals(a.radians, 1.23);
   
   // TEARDOWN
}

/*************************************
 * SET RADIANS - NEGATIVE SIX LAPS
 * input: 1.23 - 6×2π radians
 * output: 1.23 radians
 **************************************/
void TestAngle::setRadians_negativeSixLaps()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(1.23 - 6.0 * 2.0 * M_PI);
   
   // VERIFY
   assertEquals(a.radians, 1.23);
   
   // TEARDOWN
}

/*************************************
 * SET DEGREES - NEGATIVE
 * input: -90 degrees
 * output: 270 degrees
 **************************************/
void TestAngle::setDegrees_negative()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setDegrees(-90.0);
   
   // VERIFY
   assertEquals(a.radians, M_PI + M_PI_2);
   
   // TEARDOWN
}

/*************************************
 * SET DEGREES - ONE LAP
 * input: 45 + 360 degrees
 * output: 45 degrees
 **************************************/
void TestAngle::setDegrees_oneLap()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setDegrees(45.0 + 360.0);
   
   // VERIFY
   assertEquals(a.radians, 0.785398);
   
   // TEARDOWN
}

/*************************************
 * SET DEGREES - SIX LAPS
 * input: 45 + (6 × 360) degrees
 * output: 45 degrees
 **************************************/
void TestAngle::setDegrees_sixLaps()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setDegrees(45.0 + 360.0 * 6.0);
   
   // VERIFY
   assertEquals(a.radians, 0.785398);
   
   // TEARDOWN
}

/*************************************
 * SET DEGREES - NEGATIVE THREE QUARTERS
 * input: -270 degrees
 * output: 90 degrees
 **************************************/
void TestAngle::setDegrees_negativeThreeQuarters()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setDegrees(-270.0);
   
   // VERIFY
   assertEquals(a.radians, M_PI_2);
   
   // TEARDOWN
}

/*************************************
 * SET DEGREES - NEGATIVE ONE LAP
 * input: -45 - 360 degrees
 * output: 315 degrees
 **************************************/
void TestAngle::setDegrees_negativeOneLap()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setDegrees(-45.0 - 360.0);
   
   // VERIFY
   assertEquals(a.radians, 5.497787);
   
   // TEARDOWN
}

/*************************************
 * SET DEGREES - NEGATIVE SIX LAPS
 * input: -45 - (6 × 360) degrees
 * output: 315 degrees
 **************************************/
void TestAngle::setDegrees_negativeSixLaps()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setDegrees(-45.0 - 360.0 * 6.0);
   
   // VERIFY
   assertEquals(a.radians, 5.497787);
   
   // TEARDOWN
}

/*************************************
 * ADD - POSITIVE LAP
 * input: 1.23 + 2π radians
 * output: 1.23 radians
 **************************************/
void TestAngle::add_positiveLap()
{
   // SETUP
   Angle a;
   a.radians = 1.23;
   double delta = 2.0 * M_PI;
   
   // EXERCISE
   a.add(delta);
   
   // VERIFY
   assertEquals(a.radians, 1.23);
   assertEquals(delta, 2.0 * M_PI);
   
   // TEARDOWN
}

/*************************************
 * ADD - NEGATIVE LAP
 * input: 1.23 - 2π radians
 * output: 1.23 radians
 **************************************/
void TestAngle::add_negativeLap()
{
   // SETUP
   Angle a;
   a.radians = 1.23;
   double delta = -2.0 * M_PI;
   
   // EXERCISE
   a.add(delta);
   
   // VERIFY
   assertEquals(a.radians, 1.23);
   assertEquals(delta, -2.0 * M_PI);
   
   // TEARDOWN
}
