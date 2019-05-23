#include "pch.h"
#include "FractalCreator.h"

namespace FractalMandelbrot
{
   void FractalCreator::run(std::string name)
   {
      calculateIteration();
      calculateRangeTotals();
      drawFractal();
      writeBitmap(name);
   }
   FractalCreator::FractalCreator(int inWidth, int inHeight, int inMaxiterations) :
      mWidth(inWidth), 
      mHeight(inHeight),
      mMaxiterations(inMaxiterations),
      mHistogram(inMaxiterations),
      mIterationsVector(mWidth * mHeight, 0),
      mZoomList(mWidth, mHeight),
      mBitMap(inWidth, inHeight),
      mColorRangeList(inMaxiterations)
   {
      mHistogram.resize(mMaxiterations, 0);
      mZoomList.Add(Zoom(mWidth / 2, mHeight / 2, 4.0 / mWidth));
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
//#pragma omp parallel for
      for (int i = 0; i < mMaxiterations; i++)
      {
         lTotal += mHistogram[i];
      }

      for (int x = 0; x < mWidth; ++x)
      {
//#pragma omp parallel for
         for (int y = 0; y < mHeight; ++y)
         {
            int iterations = mIterationsVector[y*mWidth + x];
            double hue = 0.0;


            if (iterations < mMaxiterations)
            {
//#pragma omp parallel for
               for (int i = 0; i < iterations; i++)
               {
                  hue += ((double)mHistogram[i]) / lTotal;
               }
            }
            else
            {
               hue = 0;
            }
            RGB lColor =  mColorRangeList.GetColor(iterations);
            uint8_t lRed = (uint8_t)(lColor.r * hue);
            uint8_t lGreen = (uint8_t)(lColor.g * hue);
            uint8_t lBlue = (uint8_t)(lColor.b * hue);
            mBitMap.setPixel(x, y, lRed, lGreen, lBlue);
         }
      }
   }
   void FractalCreator::addZoom(const Zoom & inZoom)
   {
      mZoomList.Add(inZoom);
   }

   void FractalCreator::addColorRange(double rangeBegin,  double rangeEnd, const RGB & rgb)
   {
      mColorRangeList.AddColorRange(rangeBegin, rangeEnd, rgb);
   }

   void FractalCreator::writeBitmap(std::string name)
   {
   
      mBitMap.write(name);
   }

   void FractalCreator::calculateRangeTotals()
   {
      /*int rangeIndex = 0;
      for(int i=0; i<mMaxiterations;++i)
      { 
         int lIndex = mColorRangeList.GetRangeIndex(i);
         if (lIndex != -1)
         {
            mRangeTotal[rangeIndex] += pixels;
         }
         if(i>= mColorRanges[rangeIndex+1])
         { 
            ++rangeIndex;
         }
         int pixels = mHistogram[i];
         mRangeTotal[rangeIndex] += pixels;
      }*/
     
   }



} // namespace FractalMandelbrot