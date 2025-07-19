/***********************************************************************
 * Header File:
 *    TEST ACCELERATION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Unit tests for the Acceleration class.
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "acceleration.h"
#include "angle.h"

/*********************************************
 * TEST ACCELERATION
 * Unit tests for Acceleration
 *********************************************/
class TestAcceleration : public UnitTest
{
public:
   void run()
   {
      // Constructor Tests
      constructor_default();
      constructor_nonDefault();
      
      // Getter Tests
      getDDX();
      getDDY();
      
      // Setter Tests
      setDDX();
      setDDY();
      set_up();
      set_down();
      set_left();
      set_right();
      set_diagonal();
      
      // Add Tests
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
