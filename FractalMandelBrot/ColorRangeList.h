#pragma once
#include <vector>
#include "ColorRange.h"
#include "RGB.h"

using namespace std;

namespace FractalMandelbrot
{
   class ColorRangeList
   {
   private:
      vector<ColorRange> mColorRanges;
      int mMaxIterations{ 0 };
   public:
      ColorRangeList(int inMaxIterations);
      ~ColorRangeList();
      void AddColorRange(double inBegin, double inEnd, const FM_RGB & inColor);
      FM_RGB GetColor(int inIterations);

   };

}