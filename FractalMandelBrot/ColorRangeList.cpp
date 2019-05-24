#include "pch.h"
#include <iostream>
#include "ColorRangeList.h"

namespace FractalMandelbrot
{
   ColorRangeList::ColorRangeList(int inMaxIterations) :
      mMaxIterations(inMaxIterations)
   {
   }


   ColorRangeList::~ColorRangeList()
   {
   }
   void ColorRangeList::AddColorRange(double inBegin, double inEnd, const RGB & inColor)
   {
      int lBegin = inBegin * mMaxIterations;
      int lEnd = inEnd * mMaxIterations;
      mColorRanges.push_back(ColorRange(lBegin, lEnd, inColor) );
   }
   RGB ColorRangeList::GetColor(int inIterations)
   {
      RGB lColor(0, 0, 0);
      bool lFound = false;
      for (auto range : mColorRanges)
      {
         if (range.IsInRange(inIterations))
         {
            lColor = range.mColor;
            lFound = true;
            break;
         }
      }
      if (!lFound)
      {
         cout << "Color range Not found!" << endl;
      }
      return lColor;
   }
   
}