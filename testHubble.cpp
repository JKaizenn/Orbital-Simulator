/***********************************************************************
 * Source File:
 *    TEST HUBBLE
 * Author:
 *    Jessen Forbush & Roger Galan
 * Summary:
 *    The unit tests for HUbble
 ************************************************************************/
#define _USE_MATH_DEFINES
#include "hubble.h"
#include "testHubble.h"
#include <math.h>

/*************************************
 * DEFAULT CONSTRUCTOR
 * input: nothing
 * output: position(-4216400.0, 0.0), velocity(0.0, 3100.0), dead(false), angularVelocity(0.02), radius(0.0)
 **************************************/
void TestHubble::defaultConstructor()
{
   // SETUP
   
   // EXERCISE
   Hubble h;
   
   // VERIFY
   assertEquals(h.position.x, 0.0);
   assertEquals(h.position.y, -42164000.0);
   assertEquals(h.velocity.dx, 3100.0);
   assertEquals(h.velocity.dy, 0.0);
   assertEquals(h.dead, false);
   assertEquals(h.angularVelocity, 0.02);
   assertEquals(h.radius, 10.0);
   assertEquals(h.direction.radians, 0.0);
   
   // TEARDOWN
}

/*************************************
 * WHOLE STARLINK DESTROY
 * input: satellite vector
 * output: 2 Parts, 2 Fragments
 **************************************/
void TestHubble::destroyHubble_4Parts()
{
   // SETUP
   Hubble hub;
   hub.direction.radians = M_PI;
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   hub.destroy(&satellites);
   
   // VERIFY
   assertUnit(satellites.size() == 4); // 4 fragments
   HubbleTelescope* ht = dynamic_cast<HubbleTelescope*>(satellites[0].get());
   HubbleComputer* hc = dynamic_cast<HubbleComputer*>(satellites[1].get());
   HubbleLeft* hl = dynamic_cast<HubbleLeft*>(satellites[2].get());
   HubbleRight* hr = dynamic_cast<HubbleRight*>(satellites[3].get());
   assertUnit(ht != nullptr);
   assertUnit(hc != nullptr);
   assertUnit(hl != nullptr);
   assertUnit(hr != nullptr);
   assertUnit(ht->direction.radians == M_PI);
   assertUnit(hc->direction.radians == M_PI);
   assertUnit(hl->direction.radians == M_PI);
   assertUnit(hr->direction.radians == M_PI);
   assertUnit(ht->radius == 10.0);
   assertUnit(hc->radius == 7.0);
   assertUnit(hl->radius == 8.0);
   assertUnit(hr->radius == 8.0);
   
   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}

/*************************************
 * PART HUBBLE TELESCOPE DESTROY
 * input: satellite vector
 * output: 3 Fragments
 **************************************/
void TestHubble::destroyHubbleTelescope_3Fragments()
{
   // SETUP
   Hubble hub;
   hub.direction.radians = M_PI;
   HubbleTelescope hubTelescope(hub, Angle(0.0), 10.0);
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   hubTelescope.destroy(&satellites);
   
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
 * PART HUBBLE COMPUTER DESTROY
 * input: satellite vector
 * output: 2 Fragments
 **************************************/
void TestHubble::destroyHubbleComputer_2Fragments()
{
   // SETUP
   Hubble hub;
   hub.direction.radians = M_PI;
   HubbleComputer hubComputer(hub, Angle(0.0), 7.0);
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   hubComputer.destroy(&satellites);
   
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
 * PART HUBBLE LEFT DESTROY
 * input: satellite vector
 * output: 2 Fragments
 **************************************/
void TestHubble::destroyHubbleLeft_2Fragments()
{
   // SETUP
   Hubble hub;
   hub.direction.radians = M_PI;
   HubbleLeft hubLeft(hub, Angle(0.0), 8.0);
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   hubLeft.destroy(&satellites);
   
   // VERIFY
   assertUnit(satellites.size() == 2); // 3 fragments
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
 * PART HUBBLE RIGHT DESTROY
 * input: satellite vector
 * output: 2 Fragments
 **************************************/
void TestHubble::destroyHubbleRight_2Fragments()
{
   // SETUP
   Hubble hub;
   hub.direction.radians = M_PI;
   HubbleRight hubRight(hub, Angle(0.0), 8.0);
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   hubRight.destroy(&satellites);
   
   // VERIFY
   assertUnit(satellites.size() == 2); // 3 fragments
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
