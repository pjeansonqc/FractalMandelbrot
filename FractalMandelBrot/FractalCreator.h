#ifndef _H_FRACTALCREATOR_H_
#define _H_FRACTALCREATOR_H_
#include <iostream>
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "BitMap.h"
#include <ppl.h>
#include "MandelBrot.h"
#include "ZoomList.h"
#include <string>


namespace FractalMandelbrot
{
   class FractalCreator
   {
   private:
      int mWidth{ 800 };
      int mHeight{ 600 };
      BitMap mBitMap{mWidth, mHeight};
      int mMaxiterations{100};
      vector<int> mHistogram{ 100, 0 };
      vector<int> mIterationsVector{ mWidth * mHeight, 0 };
      ZoomList mZoomList{ mWidth, mHeight };

   public:
      FractalCreator(int inWidth, int inHeight, int inMaxiterations);
      virtual ~FractalCreator();

      void calculateIteration();
      void drawFractal();
      void addZoom();
      void writeBitmap(std::string name);
   };
}

#endif//#ifndef _H_FRACTALCREATOR_H_