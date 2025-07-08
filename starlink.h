/***********************************************************************
 * Header File:
 *    STARLINK
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The Starlink Satellite class
 ************************************************************************/

#pragma once
#include "satellite.h"

class TestSatellite;

/***************************************************
 * STARLINK
 * a Space X Starlink Satellite
 ***************************************************/
class Starlink : public Satellite
{
   friend TestSatellite;
public:
   
   // Constructors
   Starlink();
   ~Starlink() {}
   
   // Satellite Virtual Functions
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};
