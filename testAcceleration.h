/***********************************************************************
 * Header File:
 *    Test Acceleration : Test the Acceleration class
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    All the unit tests for Acceleration
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "acceleration.h"
#include "angle.h"

/*******************************
 * TEST ACCELERATION
 * A friend class for Acceleration which contains the Acceleration unit tests
 ********************************/
class TestAcceleration : public UnitTest
{
public:
   void run()
   {
      // Without Add
      constructor_default();
      constructor_nonDefault();
      getDDX();
      getDDY();
      setDDX();
      setDDY();
      set_up();
      set_down();
      set_left();
      set_right();
      set_diagonal();
      
      // Add
      addDDX_zero();
      addDDX_value();
      addDDY_zero();
      addDDY_value();
      add_zeroZero();
      add_valueZero();
      add_zeroValue();
      add_valueValue();
      
      report("Acceleration");
   }
   
private:
   // Constructor Tests
   void constructor_default();
   void constructor_nonDefault();
   
   // Getter Tests
   void getDDX();
   void getDDY();
   
   // Setter Tests
   void setDDX();
   void setDDY();
   void set_up();
   void set_down();
   void set_left();
   void set_right();
   void set_diagonal();
   
   // Add Tests
   void addDDX_zero();
   void addDDX_value();
   void addDDY_zero();
   void addDDY_value();
   void add_zeroZero();
   void add_valueZero();
   void add_zeroValue();
   void add_valueValue();
};
