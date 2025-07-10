/***********************************************************************
 * Source File:
 *    TEST DRAGON
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for Dragon
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "dragon.h"
#include "testDragon.h"
#include <math.h>

/*************************************
 * DEFAULT CONSTRUCTOR
 * input: nothing
 * output: position (0.0, 8000000.0), velocity (-7900.0, 0.0), dead(false), angularVelocity(0.05), radius(7.0)
 **************************************/
void TestDragon::defaultConstructor()
{
   // SETUP
   
   // EXERCISE
   Dragon d;
   
   // VERIFY
   assertEquals(d.position.x, 0.0);
   assertEquals(d.position.y, 8000000.0);
   assertEquals(d.velocity.dx, -7900.0);
   assertEquals(d.velocity.dy, 0.0);
   assertEquals(d.dead, false);
   assertEquals(d.angularVelocity, 0.05);
   assertEquals(d.radius, 7.0);
   assertEquals(d.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * WHOLE DRAGON DESTROY
 * input: satellite vector
 * output: 3 Parts, 2 Fragments
 **************************************/
void TestDragon::destroyDragon_3Parts_2Fragments()
{
   // SETUP
   Dragon dragon;
   dragon.direction.radians = M_PI;
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   dragon.destroy(&satellites);
   
   // VERIFY
   assertUnit(satellites.size() == 5); // 3 parts, 2 fragments
   DragonCenter* dc = dynamic_cast<DragonCenter*>(satellites[0].get());
   DragonLeft* dl = dynamic_cast<DragonLeft*>(satellites[1].get());
   DragonRight* dr = dynamic_cast<DragonRight*>(satellites[2].get());
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[3].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[4].get());
   assertUnit(dc != nullptr);
   assertUnit(dl != nullptr);
   assertUnit(dr != nullptr);
   assertUnit(f0 != nullptr);
   assertUnit(f1 != nullptr);
   assertUnit(dc->direction.radians == M_PI);
   assertUnit(dl->direction.radians == M_PI);
   assertUnit(dr->direction.radians == M_PI);
   assertUnit(f0->direction.radians == M_PI);
   assertUnit(f1->direction.radians == M_PI);
   assertUnit(dc->radius == 6.0);
   assertUnit(dl->radius == 6.0);
   assertUnit(dr->radius == 6.0);
   assertUnit(f0->radius == 2.0);
   assertUnit(f1->radius == 2.0);
   
   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * PART DRAGON CENTER DESTROY
 * input: satellite vector
 * output: 4 Fragments
 **************************************/
void TestDragon::destroyDragonCenter_4Fragments()
{
   // SETUP
   Dragon dragon;
   dragon.direction.radians = M_PI;
   DragonCenter dragonCenter(dragon, Angle(0.0), 6.0);
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   dragonCenter.destroy(&satellites);
   
   // VERIFY
   assertUnit(satellites.size() == 4); // 4 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   Fragment* f2 = dynamic_cast<Fragment*>(satellites[2].get());
   Fragment* f3 = dynamic_cast<Fragment*>(satellites[3].get());
   assertUnit(f0 != nullptr);
   assertUnit(f1 != nullptr);
   assertUnit(f2 != nullptr);
   assertUnit(f3 != nullptr);
   assertUnit(f0->direction.radians == M_PI);
   assertUnit(f1->direction.radians == M_PI);
   assertUnit(f2->direction.radians == M_PI);
   assertUnit(f3->direction.radians == M_PI);
   assertUnit(f0->radius == 2.0);
   assertUnit(f1->radius == 2.0);
   assertUnit(f2->radius == 2.0);
   assertUnit(f3->radius == 2.0);
   
   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * PART DRAGON LEFT DESTROY
 * input: satellite vector
 * output: 2 Fragments
 **************************************/
void TestDragon::destroyDragonLeft_2Fragments()
{
   // SETUP
   Dragon dragon;
   dragon.direction.radians = M_PI;
   DragonLeft dragonLeft(dragon, Angle(0.0), 6.0);
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   dragonLeft.destroy(&satellites);
   
   // VERIFY
   assertUnit(satellites.size() == 2); // 2 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   assertUnit(f0 != nullptr);
   assertUnit(f1 != nullptr);
   assertUnit(f0->direction.radians == M_PI);
   assertUnit(f1->direction.radians == M_PI);
   assertUnit(f0->radius == 2.0);
   assertUnit(f1->radius == 2.0);
   
   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * PART DRAGON RIGHT DESTROY
 * input: satellite vector
 * output: 2 Fragments
 **************************************/
void TestDragon::destroyDragonRight_2Fragments()
{
   // SETUP
   Dragon dragon;
   dragon.direction.radians = M_PI;
   DragonRight dragonRight(dragon, Angle(0.0), 6.0);
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   dragonRight.destroy(&satellites);
   
   // VERIFY
   assertUnit(satellites.size() == 2); // 2 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   assertUnit(f0 != nullptr);
   assertUnit(f1 != nullptr);
   assertUnit(f0->direction.radians == M_PI);
   assertUnit(f1->direction.radians == M_PI);
   assertUnit(f0->radius == 2.0);
   assertUnit(f1->radius == 2.0);
   
   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}
