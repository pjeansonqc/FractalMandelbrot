#include "pch.h"
#include "RGB.h"

namespace FractalMandelbrot
{
   RGB::RGB(double r, double g, double b):r(r), g(g), b(b)
   {
   }


   RGB::~RGB()
   {
   }

   RGB RGB::operator+(const RGB & inOther)
   {
      r += inOther.r;
      g += inOther.g;
      b += inOther.b;
      return *this;
   }
   RGB RGB::operator-(const RGB & inOther)
   {
      r -= inOther.r;
      g -= inOther.g;
      b -= inOther.b;
      return *this;
   }
}