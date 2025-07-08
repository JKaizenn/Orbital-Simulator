/***********************************************************************
 * Header File:
 *    Test Hubble : Test the Hubble class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Hubble
 ************************************************************************/

#pragma once
#include "hubble.h"
#include "unitTest.h"

/***************************************************
 * HUBBLE TEST
 * Test the Hubble class
 ***************************************************/
class TestHubble : public UnitTest
{
public:
   
   void run()
   {
      // Constructor Tests
      defaultConstructor();
      
      report("Hubble");
   }
   
private:
   // Constructor Tests
   void defaultConstructor();
   
};
