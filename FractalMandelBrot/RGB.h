#pragma once

#include <cstdint>
namespace FractalMandelbrot
{
   struct RGB
   {
   private:
      double r{ 0 };
      double g{ 0 };
      double b{ 0 };
   public:
      RGB(double r, double g, double b);
      ~RGB();
      RGB operator+(const RGB & inOther);
      RGB operator-(const RGB & inOther);
   };
}// namespace FractalMandelbrot
