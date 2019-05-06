#include "pch.h"
#include "FractalCreator.h"

namespace FractalMandelbrot
{
   FractalCreator::FractalCreator(int inWidth, int inHeight, int inMaxiterations) :
      mWidth(inWidth), 
      mHeight(inHeight),
      mMaxiterations(inMaxiterations),
      lHistogram(inMaxiterations),
      lIterationsVector(mWidth * mHeight, 0),
      lZoomList(mWidth, mHeight),
      lbm(inWidth, inHeight)
   {
      lHistogram.resize(mMaxiterations, 0);
      //lIterationsVector.resize(mWidth * mHeight, 0);
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
            auto location = lZoomList.doZoom(x, y);
            int lIterations = MandelBrot::getIteration(location.first, location.second, mMaxiterations);
            lIterationsVector[y*mWidth + x] = lIterations;
            if (lIterations != MandelBrot::MAX_ITERATIONS)
            {
               lHistogram[lIterations]++;
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
         lTotal += lHistogram[i];
      }

      for (int x = 0; x < mWidth; ++x)
      {
#pragma omp parallel for
         for (int y = 0; y < mHeight; ++y)
         {
            int iterations = lIterationsVector[y*mWidth + x];
            double hue = 0.0;


            if (iterations < mMaxiterations)
            {
#pragma omp parallel for
               for (int i = 0; i < iterations; i++)
               {
                  hue += ((double)lHistogram[i]) / lTotal;
               }
            }
            else
            {
               hue = 0;
            }
            uint8_t lRed = 0;
            uint8_t lGreen = 255*hue;
            uint8_t lBlue = 0;
            lbm.setPixel(x, y, lRed, lGreen, lBlue);
         }
      }
   }
   void FractalCreator::addZoom()
   {
      lZoomList.Add(Zoom(mWidth / 2, mHeight / 2, 4.0 / mWidth));
      lZoomList.Add(Zoom(295, mHeight - 202, 0.1));
      lZoomList.Add(Zoom(288, mHeight - 304, 0.01));
   }
   void FractalCreator::writeBitmap(std::string name)
   {
   
      lbm.write(name);
   }



} // namespace FractalMandelbrot