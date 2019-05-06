#include "pch.h"
#include "FractalCreator.h"

namespace FractalMandelbrot
{
   FractalCreator::FractalCreator(int inWidth, int inHeight, int inMaxiterations) :
      mWidth(inWidth), 
      mHeight(inHeight),
      mMaxiterations(inMaxiterations),
      mHistogram(inMaxiterations),
      mIterationsVector(mWidth * mHeight, 0),
      mZoomList(mWidth, mHeight),
      mBitMap(inWidth, inHeight)
   {
      mHistogram.resize(mMaxiterations, 0);
   }


   FractalCreator::~FractalCreator()
   {
   }



   void FractalCreator::calculateIteration() 
   {
#pragma omp parallel for
      for (int x = 0; x < mWidth; ++x)
      {
#pragma omp parallel for
         for (int y = 0; y < mHeight; ++y)
         {
            auto location = mZoomList.doZoom(x, y);
            int lIterations = MandelBrot::getIteration(location.first, location.second, mMaxiterations);
            mIterationsVector[y*mWidth + x] = lIterations;
            if (lIterations < mMaxiterations)
            {
               mHistogram[lIterations]++;
            }
         }
      }
   }
   void FractalCreator::drawFractal() 
   {
      int lTotal = 0;
#pragma omp parallel for
      for (int i = 0; i < mMaxiterations; i++)
      {
         lTotal += mHistogram[i];
      }

      for (int x = 0; x < mWidth; ++x)
      {
#pragma omp parallel for
         for (int y = 0; y < mHeight; ++y)
         {
            int iterations = mIterationsVector[y*mWidth + x];
            double hue = 0.0;


            if (iterations < mMaxiterations)
            {
#pragma omp parallel for
               for (int i = 0; i < iterations; i++)
               {
                  hue += ((double)mHistogram[i]) / lTotal;
               }
            }
            else
            {
               hue = 0;
            }
            uint8_t lRed = 0;
            uint8_t lGreen = (uint8_t)(255*hue);
            uint8_t lBlue = 0;
            mBitMap.setPixel(x, y, lRed, lGreen, lBlue);
         }
      }
   }
   void FractalCreator::addZoom()
   {
      mZoomList.Add(Zoom(mWidth / 2, mHeight / 2, 4.0 / mWidth));
      mZoomList.Add(Zoom(295, mHeight - 202, 0.1));
      mZoomList.Add(Zoom(288, mHeight - 304, 0.01));
   }
   void FractalCreator::writeBitmap(std::string name)
   {
   
      mBitMap.write(name);
   }



} // namespace FractalMandelbrot