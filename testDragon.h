/***********************************************************************
 * Header File:
 *    Test Dragon : Test the Dragon class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Dragon
 ************************************************************************/

#pragma once
#include "dragon.h"
#include "unitTest.h"

/***************************************************
 * DRAGON TEST
 * Test the Dragon class
 ***************************************************/
class TestDragon : public UnitTest
{
public:
   
   void run()
   {
      // Constructor Tests
      defaultConstructor();
      
      report("Dragon");
   }
   
private:
   // Constructor Tests
   void defaultConstructor();
   
};
