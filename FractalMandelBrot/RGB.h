#pragma once

#include <cstdint>
namespace FractalMandelbrot
{
   struct RGB
   {
      double r{ 0 };
      double g{ 0 };
      double b{ 0 };

      RGB(double r, double g, double b);
      ~RGB();
      RGB operator+(const RGB & inOther);
      RGB operator-(const RGB & inOther);
   };
}// namespace FractalMandelbrot
