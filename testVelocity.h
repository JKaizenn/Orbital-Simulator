/***********************************************************************
 * Header File:
 *    TEST VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Unit tests for the Velocity class.
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "velocity.h"

/*********************************************
 * TEST VELOCITY
 * Unit tests for Velocity
 *********************************************/
class TestVelocity : public UnitTest
{
public:
   void run()
   {
      // Constructor Tests
      constructor_default();
      constructor_nonDefault();
      
      // Getter Tests
      getDX();
      getDY();
      getSpeed_zero();
      getSpeed_up();
      getSpeed_down();
      getSpeed_left();
      getSpeed_right();
      getSpeed_diagonal();
      
      // Setter Tests
      setDX();
      setDY();
      set_up();
      set_down();
      set_left();
      set_right();
      set_diagonal();
      
      // Add Tests
      addDX_zero();
      addDX_value();
      addDY_zero();
      addDY_value();
      add_stationary();
      add_noTime();
      add_moving1Second();
      add_moving4Seconds();
      
      report("Velocity");
   }
   
private:
   // Constructor Tests
   void constructor_default();
   void constructor_nonDefault();
   
   // Getter Tests
   void getDX();
   void getDY();
   void getSpeed_zero();
   void getSpeed_right();
   void getSpeed_up();
   void getSpeed_left();
   void getSpeed_down();
   void getSpeed_diagonal();
   
   // Setter Tests
   void setDX();
   void setDY();
   void set_up();
   void set_down();
   void set_left();
   void set_right();
   void set_diagonal();
   
   // Add Tests
   void addDX_zero();
   void addDX_value();
   void addDY_zero();
   void addDY_value();
   void add_stationary();
   void add_noTime();
   void add_moving1Second();
   void add_moving4Seconds();
};
