// FractalMandelBrot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"
#include <iostream>

#include "FractalCreator.h"
#include "RGB.h"

using namespace FractalMandelbrot;
#if(0)
int main()
{
   

   FractalCreator lfrac(800, 600, 10000);
   lfrac.addColorRange(0.0, 0.10, FM_RGB(0, 0, 255));
   lfrac.addColorRange(0.10, 0.25, FM_RGB(0,128,255));
   lfrac.addColorRange(0.25, 0.75, FM_RGB(0, 255, 255));
   lfrac.addColorRange(0.75, 1.0,  FM_RGB(255, 255, 255));
   lfrac.addZoom(Zoom(295, 600 - 202, 0.1));
   lfrac.addZoom(Zoom(288, 600 - 304, 0.01));
   lfrac.run("test.bmp");

}

#endif