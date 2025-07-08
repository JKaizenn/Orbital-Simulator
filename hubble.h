/***********************************************************************
 * Header File:
 *    HUBBLE
 * Author:
 *    Roger Galan & Jessen Forbush
 * Summary:
 *    The Hubble Satellite class
 ************************************************************************/

#pragma once
#include "satellite.h"

class TestHubble;

/***************************************************
 * HUBBLE
 * a Hubble telescope satellite
 ***************************************************/
class Hubble : public Satellite
{
   friend TestHubble;
public:
   Hubble();
   ~Hubble() {}
   void draw(ogstream* pgout)  const override;
   void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override;
};
