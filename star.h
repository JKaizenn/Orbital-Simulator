/**********************************************
 * Header File:
 *    STAR / STARS
 * Author:
 *    Br. Helfrich
 * Edited By:
 *    Roger Galan & Jessen Forbush 2/8/2025
 * Summary:
 *    A single star that twinkles individually at random, along with a
 *    Stars container that holds many such stars. Each star updates its
 *    twinkle phase by randomizing it on each draw so that the stars
 *    twinkle out of phase with one another. Stars are positioned only
 *    in the sky (using the upper-right corner for screen dimensions).
 ************************************************************************/

#pragma once

#include "position.h"  // For Position
#include "uiDraw.h"    // For ogstream, drawStar, and random()

/************************************************************
 * STAR
 *
 * Represents a single twinkling star in the simulation.
 * This class encapsulates the star's position and twinkle phase,
 * and it updates its appearance each time it is drawn.
 * The star is designed to be displayed only in the sky.
 ************************************************************/
class Star {
public:
   // Default Constructor
   Star()
   {
      // Set the phase to be a random value between 0 and 255.
      phase = random(0, 255);
   }
   
   // Reset the star using the upper-right corner.
   void reset(const Position& posUpperRight) {
      double width = posUpperRight.getPixelsX();
      double height = posUpperRight.getPixelsY();
      
      // Randomize x anywhere from 0 to width.
      position.setPixelsX(random(0.0, width));
      
      // Randomize y anywhere from height/2 to height (sky area only).
      position.setPixelsY(random(height / 2.0, height));
   }
   
   // Draw the star.
   void draw(ogstream& gout)
   {
      // Increment the phase for twinkling
      phase++;
      
      // Draw the star using the current phase.
      gout.drawStar(position, phase);
   }
   
private:
   Position position;      // The star's position.
   unsigned char phase;    // Current twinkle phase.
};

/************************************************************
 * STARS
 *
 * A container class for managing multiple Star objects.
 * This class handles the allocation, resetting, and
 * drawing of a collection of stars. Each star twinkles individually,
 * creating a dynamic star field that appears only in the sky.
 ************************************************************/
class Stars {
public:
   // Constructor: create 'count' stars (default is 50).
   Stars(int count = 50)
   {
      this->count = count;
      stars = new Star[count];
   }
   
   // Destructor: free the allocated array.
   ~Stars()
   {
      delete[] stars;
   }
   
   // Reset all stars using the upper-right corner (screen dimensions).
   void resetAll(const Position& posUpperRight)
   {
      for (int i = 0; i < count; i++)
      {
         stars[i].reset(posUpperRight);
      }
   }
   
   // Draw all stars.
   void drawAll(ogstream& gout)
   {
      for (int i = 0; i < count; i++)
      {
         stars[i].draw(gout);
      }
   }
   
private:
   Star* stars;         // Dynamically allocated array of Star objects.
   unsigned int count;  // Number of stars.
};
