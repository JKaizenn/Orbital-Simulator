/***********************************************************************
 * Header File:
 *    Test GPS : Test the GPS class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for GPS
 ************************************************************************/

#pragma once
#include "gps.h"
#include "unitTest.h"

/***************************************************
 * GPS TEST
 * Test the GPS class
 ***************************************************/
class TestGps : public UnitTest
{
public:
   
   void run()
   {
      // Constructor Tests
      defaultConstructor0();
      defaultConstructor1();
      defaultConstructor2();
      defaultConstructor3();
      defaultConstructor4();
      defaultConstructor5();
      
      // Collision
      
      // Fragment
      
      // Parts
      
      report("GPS");
   }
   
private:
   // Constructor Tests for all 6 GPS satellites
   void defaultConstructor0();
   void defaultConstructor1();
   void defaultConstructor2();
   void defaultConstructor3();
   void defaultConstructor4();
   void defaultConstructor5();
   
};
