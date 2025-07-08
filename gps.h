/***********************************************************************
 * Header File:
 *    Gps
 * Author:
*    Roger Galan & Jessen Forbush
 * Summary:
 *    The Gps class
 ************************************************************************/

#pragma once
#include "satellite.h"

/***************************************************
 * Gps
 * a GPS satellite, there will be 6 in the program
 ***************************************************/
class Gps : public Satellite
{
public:
   Gps() : Satellite(){}
   Gps(int index);
   ~Gps() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};
