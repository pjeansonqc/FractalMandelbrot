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

   FractalCreator lfrac(800, 600, 100);
   lfrac.addZoom();
   lfrac.calculateIteration();
   lfrac.drawFractal();
   lfrac.writeBitmap("test.bmp");

}

