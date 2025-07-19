/***********************************************************************
 * Source File:
 *    TEST STARLINK
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for Starlink
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "starlink.h"
#include "testStarlink.h"
#include <math.h>

/*************************************
 * DEFAULT CONSTRUCTOR
 * input: nothing
 * output: position (0.0, -13020000.0), velocity (5800.0, 0.0), dead(false), angularVelocity(0.05), radius(6.0)
 **************************************/
void TestStarlink::defaultConstructor()
{
   // SETUP
   
   // EXERCISE
   Starlink s;
   
   // VERIFY
   assertEquals(s.position.x, 0.0);
   assertEquals(s.position.y, -13020000.0);
   assertEquals(s.velocity.dx, 5800.0);
   assertEquals(s.velocity.dy, 0.0);
   assertEquals(s.dead, false);
   assertEquals(s.angularVelocity, 0.05);
   assertEquals(s.radius, 6.0);
   assertEquals(s.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * WHOLE STARLINK DESTROY
 * input: satellite vector
 * output: 2 Parts, 2 Fragments
 **************************************/
void TestStarlink::destroyStarlink_2Part_2Fragments()
{
   // SETUP
   Starlink starlink;
   // Explicit attribute setting
   starlink.position.x = 0.0;
   starlink.position.y = -13020000.0;
   starlink.velocity.dx = 5800.0;
   starlink.velocity.dy = 0.0;
   starlink.direction.radians = M_PI;
   starlink.angularVelocity = 0.05;
   starlink.radius = 6.0;
   starlink.dead = false;
   
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   starlink.destroy(&satellites);
   
   // VERIFY
   assertEquals(satellites.size(), 4); // 2 parts, 2 fragments
   StarlinkBody* sb = dynamic_cast<StarlinkBody*>(satellites[0].get());
   StarlinkArray* sa = dynamic_cast<StarlinkArray*>(satellites[1].get());
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[2].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[3].get());
   assertEquals(sb != nullptr, true);
   assertEquals(sa != nullptr, true);
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(sb->direction.radians, M_PI);
   assertEquals(sa->direction.radians, M_PI);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(sb->radius, 2.0);
   assertEquals(sa->radius, 4.0);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);
   
   // Verify parts and fragments received velocity kick
   assertEquals(sb->velocity.dx != 5800.0 || sb->velocity.dy != 0.0, true);
   assertEquals(sa->velocity.dx != 5800.0 || sa->velocity.dy != 0.0, true);
   assertEquals(f0->velocity.dx != 5800.0 || f0->velocity.dy != 0.0, true);
   assertEquals(f1->velocity.dx != 5800.0 || f1->velocity.dy != 0.0, true);
   
   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * STARLINK BODY DESTROY
 * input: satellite vector
 * output: 3 Fragments
 **************************************/
void TestStarlink::destroyStarlinkBody_3Fragments()
{
   // SETUP
   Starlink starlink;
   // Explicit attribute setting
   starlink.position.x = 0.0;
   starlink.position.y = -13020000.0;
   starlink.velocity.dx = 5800.0;
   starlink.velocity.dy = 0.0;
   starlink.direction.radians = M_PI;
   starlink.angularVelocity = 0.05;
   starlink.radius = 6.0;
   starlink.dead = false;
   
   StarlinkBody starlinkBody(starlink, Angle(0.0), 2.0);
   // Explicit attribute setting for part
   starlinkBody.position = starlink.position;
   starlinkBody.velocity = starlink.velocity;
   starlinkBody.direction = starlink.direction;
   starlinkBody.angularVelocity = starlink.angularVelocity;
   starlinkBody.radius = 2.0;
   starlinkBody.dead = false;
   
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   starlinkBody.destroy(&satellites);
   
   // VERIFY
   assertEquals(satellites.size(), 3); // 3 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   Fragment* f2 = dynamic_cast<Fragment*>(satellites[2].get());
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(f2 != nullptr, true);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(f2->direction.radians, M_PI);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);
   assertEquals(f2->radius, 2.0);
   
   // Verify fragments received velocity kick
   assertEquals(f0->velocity.dx != 5800.0 || f0->velocity.dy != 0.0, true);
   assertEquals(f1->velocity.dx != 5800.0 || f1->velocity.dy != 0.0, true);
   assertEquals(f2->velocity.dx != 5800.0 || f2->velocity.dy != 0.0, true);
   
   // Verify fragments have different velocities from each other
   assertEquals(f0->velocity.dx != f1->velocity.dx || f0->velocity.dy != f1->velocity.dy, true);
   assertEquals(f1->velocity.dx != f2->velocity.dx || f1->velocity.dy != f2->velocity.dy, true);
   
   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * STARLINK ARRAY DESTROY
 * input: satellite vector
 * output: 3 Fragments
 **************************************/
void TestStarlink::destroyStarlinkArray_3Fragments()
{
   // SETUP
   Starlink starlink;
   // Explicit attribute setting
   starlink.position.x = 0.0;
   starlink.position.y = -13020000.0;
   starlink.velocity.dx = 5800.0;
   starlink.velocity.dy = 0.0;
   starlink.direction.radians = M_PI;
   starlink.angularVelocity = 0.05;
   starlink.radius = 6.0;
   starlink.dead = false;
   
   StarlinkArray starlinkArray(starlink, Angle(0.0), 4.0);
   // Explicit attribute setting for part
   starlinkArray.position = starlink.position;
   starlinkArray.velocity = starlink.velocity;
   starlinkArray.direction = starlink.direction;
   starlinkArray.angularVelocity = starlink.angularVelocity;
   starlinkArray.radius = 4.0;
   starlinkArray.dead = false;
   
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   starlinkArray.destroy(&satellites);
   
   // VERIFY
   assertEquals(satellites.size(), 3); // 3 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   Fragment* f2 = dynamic_cast<Fragment*>(satellites[2].get());
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(f2 != nullptr, true);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(f2->direction.radians, M_PI);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);
   assertEquals(f2->radius, 2.0);
   
   // Verify fragments received velocity kick
   assertEquals(f0->velocity.dx != 5800.0 || f0->velocity.dy != 0.0, true);
   assertEquals(f1->velocity.dx != 5800.0 || f1->velocity.dy != 0.0, true);
   assertEquals(f2->velocity.dx != 5800.0 || f2->velocity.dy != 0.0, true);
   
   // Verify fragments have different velocities from each other
   assertEquals(f0->velocity.dx != f1->velocity.dx || f0->velocity.dy != f1->velocity.dy, true);
   assertEquals(f1->velocity.dx != f2->velocity.dx || f1->velocity.dy != f2->velocity.dy, true);
   
   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}
