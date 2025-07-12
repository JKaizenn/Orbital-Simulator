/**********************************************
 * Header File:
 *    STAR / STARS
 * Author:
 *    Roger Galan & Jessen Forbush 2/8/2025
 * Summary:
 *    Stars that twinkle in the sky
 ************************************************************************/

#pragma once

#include "position.h"  // For Position
#include "uiDraw.h"    // For ogstream, drawStar, and random()

/************************************************************
 * STAR
 *
 * A single twinkling star in the simulation.
 ************************************************************/
class Star {
public:
   // Default Constructor
   Star()
   {
      phase = random(0, 255);
   }
   
   // Reset the star using the upper-right corner.
   void reset(const Position& posUpperRight) {
      // Get screen dimensions in pixels
      double screenWidthPixels = posUpperRight.getPixelsX();
      double screenHeightPixels = posUpperRight.getPixelsY();
      
      // Convert to world coordinates
      double worldWidth = screenWidthPixels * posUpperRight.getZoom();
      double worldHeight = screenHeightPixels * posUpperRight.getZoom();
      
      // Randomize x anywhere from left to right edge
      double randomX = random(-worldWidth / 2.0, worldWidth / 2.0);
      
      // Randomize y anywhere from bottom to top edge
      double randomY = random(-worldHeight / 2.0, worldHeight / 2.0);
      
      // Set position in world coordinates
      position.setMetersX(randomX);
      position.setMetersY(randomY);
   }
   
   // Draw the star.
   void draw(ogstream& gout)
   {
      // Increment the phase for twinkling
      phase++;
      
      // Draw the star using the current phase
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
