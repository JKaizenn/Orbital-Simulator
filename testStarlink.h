/***********************************************************************
 * Header File:
 *    Test Starlink : Test the Starlink class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Starlink
 ************************************************************************/

#pragma once
#include "starlink.h"
#include "unitTest.h"

/***************************************************
 * STARLINK TEST
 * Test the Starlink class
 ***************************************************/
class TestStarlink : public UnitTest
{
public:
   
   void run()
   {
      // Constructor Tests
      defaultConstructor();
      
      report("Starlink");
   }
   
private:
   // Constructor Tests
   void defaultConstructor();
   
};
