#include "stdafx.h"
#include "RGB.h"

namespace FractalMandelbrot
{
   FM_RGB::FM_RGB(double r, double g, double b):r(r), g(g), b(b)
   {
   }


   FM_RGB::~FM_RGB()
   {
   }

   FM_RGB FM_RGB::operator+(const FM_RGB & inOther)
   {
      r += inOther.r;
      g += inOther.g;
      b += inOther.b;
      return *this;
   }
   FM_RGB FM_RGB::operator-(const FM_RGB & inOther)
   {
      r -= inOther.r;
      g -= inOther.g;
      b -= inOther.b;
      return *this;
   }
}