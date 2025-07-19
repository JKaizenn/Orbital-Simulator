/***********************************************************************
 * Source File:
 *    TEST ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The unit tests for the Angle class
 ************************************************************************/

#include "testAngle.h"
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
void TestAngle::defaultConstructor()
{
   // SETUP
   
   // EXERCISE
   Angle a;
   
   // VERIFY
   assertUnit(a.radians == 0.0);
   
   // TEARDOWN
}

/*****************************************************************
 *****************************************************************
 * SETTERS
 *****************************************************************
 *****************************************************************/

/*********************************************
 * name:    SET UP
 * input:   nothing
 * output:  0 degrees
 *********************************************/
void TestAngle::setUp()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setUp();
   
   // VERIFY
   assertEquals(a.radians, 0.0);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET DOWN
 * input:   nothing
 * output:  180 degrees
 *********************************************/
void TestAngle::setDown()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setDown();
   
   // VERIFY
   assertEquals(a.radians, M_PI);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET RIGHT
 * input:   nothing
 * output:  90 degrees
 *********************************************/
void TestAngle::setRight()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRight();
   
   // VERIFY
   assertEquals(a.radians, M_PI_2);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET LEFT
 * input:   nothing
 * output:  270 degrees
 *********************************************/
void TestAngle::setLeft()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setLeft();
   
   // VERIFY
   assertEquals(a.radians, M_PI + M_PI_2);
   
   // TEARDOWN
}

/*********************************************
 * name:    REVERSE
 * input:   90
 * output:  270 degrees
 *********************************************/
void TestAngle::reverse()
{
   // SETUP
   Angle a;
   a.radians = M_PI_2; // 90 degrees
   
   // EXERCISE
   a.reverse();
   
   // VERIFY
   assertEquals(a.radians, M_PI_2 + M_PI);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET RADIANS - NO NORMALIZATION
 * input:   45 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setRadians_noNormalize()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(0.785398);
   
   // VERIFY
   assertEquals(a.radians, 0.785398);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET DEGREES - NO NORMALIZATION
 * input:   45 degrees
 * output:  45 degrees
 *********************************************/
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

/*****************************************************************
 *****************************************************************
 * GETTERS
 *****************************************************************
 *****************************************************************/

/*********************************************
 * name:    GET DEGREES - 0
 * input:   0 degrees
 * output:  0 degrees
 *********************************************/
void TestAngle::getDegrees_0()
{
   // SETUP
   Angle a;
   a.radians = 0.0;
   double d = -99.9;
   
   // EXERCISE
   d = a.getDegrees();
   
   // VERIFY
   assertEquals(d, 0.0);
   assertEquals(a.radians, 0.0);
   
   // TEARDOWN
}

/*********************************************
 * name:    GET DEGREES - 270
 * input:   270 degrees
 * output:  270 degrees
 *********************************************/
void TestAngle::getDegrees_270()
{
   // SETUP
   Angle a;
   a.radians = M_PI + M_PI_2;
   double d = -99.9;
   
   // EXERCISE
   d = a.getDegrees();
   
   // VERIFY
   assertEquals(d, 270.0);
   assertEquals(a.radians, M_PI + M_PI_2);
   
   // TEARDOWN
}

/*********************************************
 * name:    GET RADIANS - 0
 * input:   0 degrees
 * output:  0 degrees
 *********************************************/
void TestAngle::getRadians_0()
{
   // SETUP
   Angle a;
   a.radians = 0.0;
   double r = -99.9;
   
   // EXERCISE
   r = a.getRadians();
   
   // VERIFY
   assertEquals(r, 0.0);
   assertEquals(a.radians, 0.0);
   
   // TEARDOWN
}

/*********************************************
 * name:    GET RADIANS - 270
 * input:   270 degrees
 * output:  270 degrees
 *********************************************/
void TestAngle::getRadians_270()
{
   // SETUP
   Angle a;
   a.radians = M_PI + M_PI_2;
   double r = -99.9;
   
   // EXERCISE
   r = a.getRadians();
   
   // VERIFY
   assertEquals(r, M_PI + M_PI_2);
   assertEquals(a.radians, M_PI + M_PI_2);
   
   // TEARDOWN
}

/*****************************************************************
 *****************************************************************
 * ADD
 *****************************************************************
 *****************************************************************/

/*********************************************
 * name:    ADD ZERO
 * input:   45 degrees + 0
 * output:  45 degrees
 *********************************************/
void TestAngle::add_0()
{
   // SETUP
   Angle a;
   a.radians = 0.785398;
   double r = 0.0;
   
   // EXERCISE
   a.add(r);
   
   // VERIFY
   assertEquals(a.radians, 0.785398);
   assertEquals(r, 0.0);
   
   // TEARDOWN
}

/*********************************************
 * name:    ADD VALUE
 * input:   45 degrees + 90 degrees
 * output:  135 degrees
 *********************************************/
void TestAngle::add_value()
{
   // SETUP
   Angle a;
   a.radians = 0.785398;
   double r = M_PI_2;
   
   // EXERCISE
   a.add(r);
   
   // VERIFY
   assertEquals(a.radians, 2.35619);
   assertEquals(r, M_PI_2);
   
   // TEARDOWN
}

/*****************************************************************
 *****************************************************************
 * NORMALIZATION TESTS
 *****************************************************************
 *****************************************************************/

/*********************************************
 * name:    SET RADIANS - NEGATIVE
 * input:   -90
 * output:  270 degrees
 *********************************************/
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

/*********************************************
 * name:    SET RADIANS - ONE LAP
 * input:   45 + 360 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setRadians_oneLap()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(0.785398 + (2.0 * M_PI));
   
   // VERIFY
   assertEquals(a.radians, 0.785398);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET RADIANS - SIX LAPS
 * input:   45 + (6 x 360) degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::setRadians_sixLaps()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(0.785398 + (2.0 * M_PI * 6.0));
   
   // VERIFY
   assertEquals(a.radians, 0.785398);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET RADIANS - NEGATIVE 3/4
 * input:   -270 degrees
 * output:  90 degrees
 *********************************************/
void TestAngle::setRadians_negativeThreeQuarters()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(-(M_PI + M_PI_2));
   
   // VERIFY
   assertEquals(a.radians, M_PI_2);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET RADIANS - NEGATIVE ONE LAP
 * input:   -45 - 360 degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::setRadians_negativeOneLap()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(-0.785398 - (2.0 * M_PI));
   
   // VERIFY
   assertEquals(a.radians, 5.49779);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET RADIANS - NEGATIVE SIX LAPS
 * input:   -45 - (6 x 360) degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::setRadians_negativeSixLaps()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setRadians(-0.785398 - (2.0 * M_PI * 6.0));
   
   // VERIFY
   assertEquals(a.radians, 5.49779);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET DEGREES - NEGATIVE
 * input:   -90
 * output:  270 degrees
 *********************************************/
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

/*********************************************
 * name:    SET DEGREES - ONE LAP
 * input:   45 + 360 degrees
 * output:  45 degrees
 *********************************************/
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

/*********************************************
 * name:    SET DEGREES - SIX LAP
 * input:   45 + (6 x 360) degrees
 * output:  45 degrees
 *********************************************/
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

/*********************************************
 * name:    SET DEGREES - NEGATIVE 3/4
 * input:   -270 degrees
 * output:  90 degrees
 *********************************************/
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

/*********************************************
 * name:    SET DEGREES - NEGATIVE ONE LAP
 * input:   -45 - 360 degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::setDegrees_negativeOneLap()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setDegrees(-45.0 - 360.0);
   
   // VERIFY
   assertEquals(a.radians, 5.49779);
   
   // TEARDOWN
}

/*********************************************
 * name:    SET DEGREES - NEGATIVE SIX LAPS
 * input:   -45 - (6 x 360) degrees
 * output:  315 degrees
 *********************************************/
void TestAngle::setDegrees_negativeSixLaps()
{
   // SETUP
   Angle a;
   a.radians = -99.9;
   
   // EXERCISE
   a.setDegrees(-45.0 - 360.0 * 6.0);
   
   // VERIFY
   assertEquals(a.radians, 5.49779);
   
   // TEARDOWN
}

/*********************************************
 * name:    ADD POSITIVE LAP
 * input:   45 degrees + 360 degrees
 * output:  45 degrees
 *********************************************/
void TestAngle::add_positiveLap()
{
   // SETUP
   Angle a;
   a.radians = 0.785398;
   double r = 2.0 * M_PI;
   
   // EXERCISE
   a.add(r);
   
   // VERIFY
   assertEquals(a.radians, 0.785398);
   assertEquals(r, 2.0 * M_PI);
   
   // TEARDOWN
}

/*********************************************
 * name:    ADD NEGATIVE LAP
 * input:   45 degrees + (-90 degrees)
 * output:  315 degrees
 *********************************************/
void TestAngle::add_negativeLap()
{
   // SETUP
   Angle a;
   a.radians = 0.785398;
   double r = -M_PI_2;
   
   // EXERCISE
   a.add(r);
   
   // VERIFY
   assertEquals(a.radians, 5.49779);
   assertEquals(r, -M_PI_2);
   
   // TEARDOWN
}
