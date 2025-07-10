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
   starlink.direction.radians = M_PI;
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   starlink.destroy(&satellites);
   
   // VERIFY
   assertUnit(satellites.size() == 4); // 4 fragments
   StarlinkBody* sb = dynamic_cast<StarlinkBody*>(satellites[0].get());
   StarlinkArray* sa = dynamic_cast<StarlinkArray*>(satellites[1].get());
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[2].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[3].get());
   assertUnit(sb != nullptr);
   assertUnit(sa != nullptr);
   assertUnit(f0 != nullptr);
   assertUnit(f1 != nullptr);
   assertUnit(sb->direction.radians == M_PI);
   assertUnit(sa->direction.radians == M_PI);
   assertUnit(f0->direction.radians == M_PI);
   assertUnit(f1->direction.radians == M_PI);
   assertUnit(sb->radius == 2.0);
   assertUnit(sa->radius == 4.0);
   assertUnit(f0->radius == 2.0);
   assertUnit(f1->radius == 2.0);
   
   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * PART STARLINK BODY DESTROY
 * input: satellite vector
 * output: 3 Fragments
 **************************************/
void TestStarlink::destroyStarlinkBody_3Fragments()
{
   // SETUP
   Starlink starlink;
   starlink.direction.radians = M_PI;
   StarlinkBody starlinkBody(starlink, Angle(0.0), 2.0);
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   starlinkBody.destroy(&satellites);
   
   // VERIFY
   assertUnit(satellites.size() == 3); // 3 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   Fragment* f2 = dynamic_cast<Fragment*>(satellites[2].get());
   assertUnit(f0 != nullptr);
   assertUnit(f1 != nullptr);
   assertUnit(f2 != nullptr);
   assertUnit(f0->direction.radians == M_PI);
   assertUnit(f1->direction.radians == M_PI);
   assertUnit(f2->direction.radians == M_PI);
   assertUnit(f0->radius == 2.0);
   assertUnit(f1->radius == 2.0);
   assertUnit(f2->radius == 2.0);
   
   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * PART STARLINK ARRAY DESTROY
 * input: satellite vector
 * output: 3 Fragments
 **************************************/
void TestStarlink::destroyStarlinkArray_3Fragments()
{
   // SETUP
   Starlink starlink;
   starlink.direction.radians = M_PI;
   StarlinkArray starlinkArray(starlink, Angle(0.0), 4.0);
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   starlinkArray.destroy(&satellites);
   
   // VERIFY
   assertUnit(satellites.size() == 3); // 3 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   Fragment* f2 = dynamic_cast<Fragment*>(satellites[2].get());
   assertUnit(f0 != nullptr);
   assertUnit(f1 != nullptr);
   assertUnit(f2 != nullptr);
   assertUnit(f0->direction.radians == M_PI);
   assertUnit(f1->direction.radians == M_PI);
   assertUnit(f2->direction.radians == M_PI);
   assertUnit(f0->radius == 2.0);
   assertUnit(f1->radius == 2.0);
   assertUnit(f2->radius == 2.0);
   
   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}
