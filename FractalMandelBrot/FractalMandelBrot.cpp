// FractalMandelBrot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "BitMap.h"
#include <ppl.h>
#include "MandelBrot.h"
#include "ZoomList.h"
#include "FractalCreator.h"

using namespace FractalMandelbrot;

int main()
{
#if(1)
   FractalCreator lfrac(800, 600, 100);
   lfrac.addZoom();
   lfrac.calculateIteration();
   lfrac.drawFractal();
   lfrac.writeBitmap("test.bmp");
#else

   std::cout << "Hello World!\n";
   int const WIDTH = 800;
   int const HEIGHT = 600;
   BitMap lbm(WIDTH, HEIGHT);
   
   vector<int> lHistogram(MandelBrot::MAX_ITERATIONS, 0);
   vector<int> lIterationsVector(WIDTH * HEIGHT, 0);
   ZoomList lZoomList(WIDTH, HEIGHT);
   lZoomList.Add(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
   lZoomList.Add(Zoom(295, HEIGHT - 202, 0.1));
   lZoomList.Add(Zoom(288, HEIGHT - 304, 0.01));

#pragma omp parallel for
   for (int x = 0; x < WIDTH; ++x)
   {
#pragma omp parallel for
      for (int y = 0; y < HEIGHT; ++y)
      {
         auto location = lZoomList.doZoom(x, y);
         int lIterations = MandelBrot::getIteration(location.first, location.second, 100);
         lIterationsVector[y*WIDTH+x] = lIterations;
         if (lIterations != MandelBrot::MAX_ITERATIONS)
         {
            lHistogram[lIterations]++;
         }
      }
   }
   int lTotal = 0;
#pragma omp parallel for
   for (int i=0; i < MandelBrot::MAX_ITERATIONS;i++)
   {
      lTotal += lHistogram[i];
   }

   for (int x = 0; x < WIDTH; ++x)
   {
#pragma omp parallel for
      for (int y = 0; y < HEIGHT; ++y)
      {
         int iterations = lIterationsVector[y*WIDTH + x];
         double hue = 0.0;
         

         if (iterations < MandelBrot::MAX_ITERATIONS)
         {
#pragma omp parallel for
            for (int i = 0; i < iterations; i++)
            {
               hue += ((double)lHistogram[i]) / lTotal;
            }
         }
         else
         {
            hue = 0;
         }
         uint8_t lRed = 0;
         uint8_t lGreen = (uint8_t)pow(255, hue) ;
         uint8_t lBlue = 0;
         lbm.setPixel(x, y, lRed, lGreen, lBlue);
      }
   }

   lbm.write("test.bmp");
#endif
}

