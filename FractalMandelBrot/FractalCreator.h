#ifndef _H_FRACTALCREATOR_H_
#define _H_FRACTALCREATOR_H_
#include <iostream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "BitMap.h"
#include <ppl.h>
#include "MandelBrot.h"
#include "ZoomList.h"
#include "ColorRangeList.h"
#include <string>
#include "RGB.h"

namespace FractalMandelbrot
{
   class FractalCreator
   {
   private:
      int mWidth{ 800 };
      int mHeight{ 600 };
      BitMap mBitMap{mWidth, mHeight};
      int mMaxiterations{100};
      ColorRangeList mColorRangeList;
      vector<int> mHistogram{ 100, 0 };
      vector<int> mIterationsVector{ mWidth * mHeight, 0 };
      ZoomList mZoomList{ mWidth, mHeight };
      int mRangeTotal;
      bool mGotFirstRange{false};

   public:
      FractalCreator(int inWidth, int inHeight, int inMaxiterations);
      virtual ~FractalCreator();
      void run(std::string name);
      void addZoom(const Zoom & inZoom);
      void addColorRange(double rangeBegin, double rangeEnd, const RGB & rgb);

   private:
      void calculateIteration();
      void drawFractal();
      void writeBitmap(std::string name);
      void calculateRangeTotals();
   };
}

#endif//#ifndef _H_FRACTALCREATOR_H_