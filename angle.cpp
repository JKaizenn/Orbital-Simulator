/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>
#include <cassert>
using namespace std;

/**********************************************
 * ANGLE :: NORMALIZE
 * Ensures that the given angle in radians is
 * within the standard range (0, 2pi).
 **********************************************/
double Angle::normalize(double radians) const
{
   // Define a constant for 2pi (full circle in radians)
   const double TWO_PI = 2.0 * M_PI;

   // Use fmod (modulo for float/double types) to get remainder if radians are greater than 2pi
   radians = fmod(radians, TWO_PI);

   // If radians are negative, add 2pi to the negative remainder so it is in range
   if (radians < 0)
      radians += TWO_PI;

   assert(0.0 <= radians && radians <= TWO_PI);
   return radians;
}
