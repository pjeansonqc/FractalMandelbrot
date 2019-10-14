#pragma once
#include <vector>
#include "RGB.h"
using namespace std;

namespace FractalMandelbrot
{
   class ColorRange
   {
   public:
      int mBegin{ 0 };
      int mEnd{ 0 };
      FM_RGB mColor{ 0, 0, 0 };

   public:
      ColorRange(int inBegin, int inEnd, const FM_RGB & inColor) : 
         mBegin(inBegin), 
         mEnd(inEnd), 
         mColor(inColor)  
      {}
      ~ColorRange()
      {
      }
      bool IsInRange(int inValue)
      {
         bool lInRange = false;
         if (inValue >= mBegin && inValue <= mEnd)
         {
            lInRange = true;
         }
         return lInRange;
      }
   };


} // namespace 
