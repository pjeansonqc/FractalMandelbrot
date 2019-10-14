#ifndef _FM_RGB_H_
#define _FM_RGB_H_

#include <cstdint>
namespace FractalMandelbrot
{
   struct FM_RGB
   {
      double r{ 0 };
      double g{ 0 };
      double b{ 0 };

      FM_RGB(double r, double g, double b);
      ~FM_RGB();
      FM_RGB operator+(const FM_RGB & inOther);
      FM_RGB operator-(const FM_RGB & inOther);
   };
}// namespace FractalMandelbrot


#endif //_FM_RGB_H_