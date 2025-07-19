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
 * WHOLE HUBBLE DESTROY
 * input: satellite vector
 * output: 4 Parts
 **************************************/
void TestHubble::destroyHubble_4Parts()
{
   // SETUP
   Hubble hub;
   // Explicit attribute setting
   hub.position.x = 0.0;
   hub.position.y = -42164000.0;
   hub.velocity.dx = 3100.0;
   hub.velocity.dy = 0.0;
   hub.direction.radians = M_PI;
   hub.angularVelocity = 0.02;
   hub.radius = 10.0;
   hub.dead = false;
   
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   hub.destroy(&satellites);
   
   // VERIFY
   assertEquals(satellites.size(), 4); // 4 parts
   HubbleTelescope* ht = dynamic_cast<HubbleTelescope*>(satellites[0].get());
   HubbleComputer* hc = dynamic_cast<HubbleComputer*>(satellites[1].get());
   HubbleLeft* hl = dynamic_cast<HubbleLeft*>(satellites[2].get());
   HubbleRight* hr = dynamic_cast<HubbleRight*>(satellites[3].get());
   assertEquals(ht != nullptr, true);
   assertEquals(hc != nullptr, true);
   assertEquals(hl != nullptr, true);
   assertEquals(hr != nullptr, true);
   assertEquals(ht->direction.radians, M_PI);
   assertEquals(hc->direction.radians, M_PI);
   assertEquals(hl->direction.radians, M_PI);
   assertEquals(hr->direction.radians, M_PI);
   assertEquals(ht->radius, 10.0);
   assertEquals(hc->radius, 7.0);
   assertEquals(hl->radius, 8.0);
   assertEquals(hr->radius, 8.0);
   
   // Verify parts received velocity kick
   assertEquals(ht->velocity.dx != 3100.0 || ht->velocity.dy != 0.0, true);
   assertEquals(hc->velocity.dx != 3100.0 || hc->velocity.dy != 0.0, true);
   assertEquals(hl->velocity.dx != 3100.0 || hl->velocity.dy != 0.0, true);
   assertEquals(hr->velocity.dx != 3100.0 || hr->velocity.dy != 0.0, true);
   
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
   // Explicit attribute setting
   hub.position.x = 0.0;
   hub.position.y = -42164000.0;
   hub.velocity.dx = 3100.0;
   hub.velocity.dy = 0.0;
   hub.direction.radians = M_PI;
   hub.angularVelocity = 0.02;
   hub.radius = 10.0;
   hub.dead = false;
   
   HubbleTelescope hubTelescope(hub, Angle(0.0), 10.0);
   // Explicit attribute setting for the part
   hubTelescope.position = hub.position;
   hubTelescope.velocity = hub.velocity;
   hubTelescope.direction = hub.direction;
   hubTelescope.angularVelocity = hub.angularVelocity;
   hubTelescope.radius = 10.0;
   hubTelescope.dead = false;
   
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   hubTelescope.destroy(&satellites);
   
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
   assertEquals(f0->velocity.dx != 3100.0 || f0->velocity.dy != 0.0, true);
   assertEquals(f1->velocity.dx != 3100.0 || f1->velocity.dy != 0.0, true);
   assertEquals(f2->velocity.dx != 3100.0 || f2->velocity.dy != 0.0, true);
   
   // Verify fragments have different velocities from each other
   assertEquals(f0->velocity.dx != f1->velocity.dx || f0->velocity.dy != f1->velocity.dy, true);
   assertEquals(f1->velocity.dx != f2->velocity.dx || f1->velocity.dy != f2->velocity.dy, true);
   
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
   // Explicit attribute setting
   hub.position.x = 0.0;
   hub.position.y = -42164000.0;
   hub.velocity.dx = 3100.0;
   hub.velocity.dy = 0.0;
   hub.direction.radians = M_PI;
   hub.angularVelocity = 0.02;
   hub.radius = 10.0;
   hub.dead = false;
   
   HubbleComputer hubComputer(hub, Angle(0.0), 7.0);
   // Explicit attribute setting for the part
   hubComputer.position = hub.position;
   hubComputer.velocity = hub.velocity;
   hubComputer.direction = hub.direction;
   hubComputer.angularVelocity = hub.angularVelocity;
   hubComputer.radius = 7.0;
   hubComputer.dead = false;
   
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   hubComputer.destroy(&satellites);
   
   // VERIFY
   assertEquals(satellites.size(), 2); // 2 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);
   
   // Verify fragments received velocity kick
   assertEquals(f0->velocity.dx != 3100.0 || f0->velocity.dy != 0.0, true);
   assertEquals(f1->velocity.dx != 3100.0 || f1->velocity.dy != 0.0, true);
   
   // Verify fragments have different velocities from each other
   assertEquals(f0->velocity.dx != f1->velocity.dx || f0->velocity.dy != f1->velocity.dy, true);
   
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
   // Explicit attribute setting
   hub.position.x = 0.0;
   hub.position.y = -42164000.0;
   hub.velocity.dx = 3100.0;
   hub.velocity.dy = 0.0;
   hub.direction.radians = M_PI;
   hub.angularVelocity = 0.02;
   hub.radius = 10.0;
   hub.dead = false;
   
   HubbleLeft hubLeft(hub, Angle(0.0), 8.0);
   // Explicit attribute setting for the part
   hubLeft.position = hub.position;
   hubLeft.velocity = hub.velocity;
   hubLeft.direction = hub.direction;
   hubLeft.angularVelocity = hub.angularVelocity;
   hubLeft.radius = 8.0;
   hubLeft.dead = false;
   
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   hubLeft.destroy(&satellites);
   
   // VERIFY
   assertEquals(satellites.size(), 2); // 2 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);
   
   // Verify fragments received velocity kick
   assertEquals(f0->velocity.dx != 3100.0 || f0->velocity.dy != 0.0, true);
   assertEquals(f1->velocity.dx != 3100.0 || f1->velocity.dy != 0.0, true);
   
   // Verify fragments have different velocities from each other
   assertEquals(f0->velocity.dx != f1->velocity.dx || f0->velocity.dy != f1->velocity.dy, true);
   
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
   // Explicit attribute setting 
   hub.position.x = 0.0;
   hub.position.y = -42164000.0;
   hub.velocity.dx = 3100.0;
   hub.velocity.dy = 0.0;
   hub.direction.radians = M_PI;
   hub.angularVelocity = 0.02;
   hub.radius = 10.0;
   hub.dead = false;
   
   HubbleRight hubRight(hub, Angle(0.0), 8.0);
   // Explicit attribute setting for the part
   hubRight.position = hub.position;
   hubRight.velocity = hub.velocity;
   hubRight.direction = hub.direction;
   hubRight.angularVelocity = hub.angularVelocity;
   hubRight.radius = 8.0;
   hubRight.dead = false;
   
   std::vector<std::unique_ptr<Satellite>> satellites;
   
   // EXERCISE
   hubRight.destroy(&satellites);
   
   // VERIFY
   assertEquals(satellites.size(), 2); // 2 fragments
   Fragment* f0 = dynamic_cast<Fragment*>(satellites[0].get());
   Fragment* f1 = dynamic_cast<Fragment*>(satellites[1].get());
   assertEquals(f0 != nullptr, true);
   assertEquals(f1 != nullptr, true);
   assertEquals(f0->direction.radians, M_PI);
   assertEquals(f1->direction.radians, M_PI);
   assertEquals(f0->radius, 2.0);
   assertEquals(f1->radius, 2.0);
   
   // Verify fragments received velocity kick
   assertEquals(f0->velocity.dx != 3100.0 || f0->velocity.dy != 0.0, true);
   assertEquals(f1->velocity.dx != 3100.0 || f1->velocity.dy != 0.0, true);
   
   // Verify fragments have different velocities from each other
   assertEquals(f0->velocity.dx != f1->velocity.dx || f0->velocity.dy != f1->velocity.dy, true);
   
   // TEARDOWN
   satellites.clear(); // unique_ptr automatically frees memory on destroy
}
