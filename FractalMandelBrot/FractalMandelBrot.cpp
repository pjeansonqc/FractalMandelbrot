// FractalMandelBrot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "FractalCreator.h"
#include "RGB.h"

using namespace FractalMandelbrot;

int main()
{
   RGB p1(10, 20, 30);
   RGB p2(255, 255, 255);

   RGB p3 = p2 - p1;

   FractalCreator lfrac(800, 600, 1000);
   lfrac.addZoom();
   lfrac.calculateIteration();
   lfrac.drawFractal();
   lfrac.writeBitmap("test.bmp");

}

