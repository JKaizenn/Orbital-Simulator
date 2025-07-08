/***********************************************************************
 * Header File:
 *    Dragon
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The Dragon class
 ************************************************************************/

#pragma once
#include "satellite.h"

/***************************************************
 * DRAGON
 * a SpaceX Crew Dragon satellite
 ***************************************************/
class Dragon : public Satellite
{
public:
   Dragon();
   ~Dragon() {}
   void draw(ogstream* pgout) const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};
