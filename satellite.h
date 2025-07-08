/***********************************************************************
 * Header File:
 *    Satellite
 * Author:
 *    Roger Galan & Jessen Forbush 
 * Summary:
 *    All the information about the satellite base class
 ************************************************************************/

#pragma once

#include "position.h"  // for POINT
#include "velocity.h"  // for VELOCITY
#include "uiDraw.h"    // for DRAW* and RANDOM
#include "angle.h"     // for ANGLE

#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>  // for ASSERT
#include <iostream>
#include <vector>

# define TIME 48.0
# define RADIUS_EARTH 6378000.0
# define GRAVITY_EARTH 9.80665
# define POS_HORIZON_EARTH 0.0
# define POS_VERTICAL_EARTH 0.0

class TestSatellite;
class TestGps;
class TestSputnik;
class TestStarlink;
class TestDragon;
class TestHubble;

class Satellite
{
   friend TestSatellite;
   friend TestGps;
   friend TestSputnik;
   friend TestStarlink;
   friend TestDragon;
   friend TestHubble;
   
public:
   Satellite() : position(200.0, 200.0), velocity(0.0, 0.0), dead(false), angularVelocity(1.0), radius(0.0) {}
   Satellite(Satellite& s, Angle a);
   
   virtual ~Satellite() = default;  // Virtual destructor

   double getRadius() const { return radius;  }
   bool isDead() const { return dead; }
   const Position& getPosition() const { return position; }
   void kill() { dead = true; }
   virtual void draw(ogstream* pgout)                       const = 0;
   virtual void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) = 0;
   virtual void move(double time);
   virtual void input() {}

   inline double getGravity(double heightAboveEarth)
   {
      return GRAVITY_EARTH * (RADIUS_EARTH / (RADIUS_EARTH + heightAboveEarth)) * (RADIUS_EARTH / (RADIUS_EARTH + heightAboveEarth));
   }

   inline double computeHeightAboveEarth(Position& pos)
   {
      return sqrt((pos.getMetersX() * pos.getMetersX()) + (pos.getMetersY() * pos.getMetersY())) - RADIUS_EARTH;
   }

   inline double directionOfGravityPull(Position& pos)
   {
      return atan2(POS_HORIZON_EARTH - pos.getMetersX(), POS_VERTICAL_EARTH - pos.getMetersY());
   }

protected:
   Velocity velocity;
   Position position;
   Angle direction;
   double angularVelocity;
   bool dead;
   double radius;

};

/***************************************************
 * SATELLITE DERIVED
 * A simple derived class so we can test Satellite
 ***************************************************/
class SatelliteDerived : public Satellite
{
public:
   SatelliteDerived() : Satellite() {}
   SatelliteDerived(SatelliteDerived& s, Angle a) : Satellite(s, a) {};
   ~SatelliteDerived() {}
   
   // Implement pure virtual functions so this class is concrete
   virtual void draw(ogstream* pgout) const override { assert(false); }
   virtual void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override { assert(false); }
};

/***************************************************
 * SATELLITE DUMMY
 * The dummy double! - Everything returns FALSE
 ***************************************************/
class SatelliteDummy : public Satellite
{
public:
   SatelliteDummy() : Satellite() {}
   SatelliteDummy(SatelliteDummy& s, Angle a) : Satellite(s, a) {};
   ~SatelliteDummy() {}

   double getRadius()            const { assert(false); return true; }
   bool isDead()                 const { assert(false); return true; }
   const Position& getPosition() const { assert(false); return position; }
   void kill()                         { assert(false); }
   virtual void draw(ogstream* pgout) const override { assert(false); }
   virtual void destroy(std::vector<std::unique_ptr<Satellite>>* satellites) override { assert(false); }
   virtual void move(double time) override { assert(false); }
};
