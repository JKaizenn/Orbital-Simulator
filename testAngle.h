/***********************************************************************
 * Header File:
 *    Test Angle : Test the Angle class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Angle
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "angle.h"

/*******************************
 * TEST ANGLE
 * A friend class for Angle which contains the Angle unit tests
 ********************************/
class TestAngle : public UnitTest
{
public:
   void run()
   {
      // Angle Without Normalize
      defaultConstructor();
      setUp();
      setDown();
      setRight();
      setLeft();
      reverse();
      setRadians_noNormalize();
      setDegrees_noNormalize();
      getDegrees_0();
      getDegrees_270();
      getRadians_0();
      getRadians_270();
      add_0();
      add_value();
      
      // Angle Normalize
      setRadians_negative();
      setRadians_oneLap();
      setRadians_sixLaps();
      setRadians_negativeThreeQuarters();
      setRadians_negativeOneLap();
      setRadians_negativeSixLaps();
      setDegrees_negative();
      setDegrees_oneLap();
      setDegrees_sixLaps();
      setDegrees_negativeThreeQuarters();
      setDegrees_negativeOneLap();
      setDegrees_negativeSixLaps();
      add_positiveLap();
      add_negativeLap();
      
      report("Angle");
   }
   
private:
   // Constructor Tests
   void defaultConstructor();
   
   // Setter Tests
   void setUp();
   void setDown();
   void setRight();
   void setLeft();
   void reverse();
   void setRadians_noNormalize();
   void setDegrees_noNormalize();
   
   // Getter Tests
   void getDegrees_0();
   void getDegrees_270();
   void getRadians_0();
   void getRadians_270();
   
   // Add Tests - No Normalize
   void add_0();
   void add_value();
   
   // Setter Tests - With Normalize
   void setRadians_negative();
   void setRadians_oneLap();
   void setRadians_sixLaps();
   void setRadians_negativeThreeQuarters();
   void setRadians_negativeOneLap();
   void setRadians_negativeSixLaps();
   void setDegrees_negative();
   void setDegrees_oneLap();
   void setDegrees_sixLaps();
   void setDegrees_negativeThreeQuarters();
   void setDegrees_negativeOneLap();
   void setDegrees_negativeSixLaps();
   
   // Add Tests - With Normalize
   void add_positiveLap();
   void add_negativeLap();
};
