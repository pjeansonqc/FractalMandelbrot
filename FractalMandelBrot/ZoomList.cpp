#include "pch.h"
#include "ZoomList.h"


namespace FractalMandelbrot
{

   ZoomList::~ZoomList()
   {
   }

   void ZoomList::Add(const Zoom & inZoom)
   {
      mZoomList.push_back(inZoom);
      mXCenter += (inZoom.x - mWidth / 2.0) * mScale;
      mYCenter += (inZoom.y - mHeight / 2.0) * mScale;
      mScale *= inZoom.scale;
   }
   std::pair <double, double> ZoomList::doZoom(int x, int y)
   {
      std::pair <double, double> lCoordinates(0.0, 0.0);
      //for (auto lZoom : mZoomList)
      {
         //lCoordinates.first = (2.0 / mWidth * (x+lZoom.x) * lZoom.scale) - 1.0 * lZoom.scale;
         //lCoordinates.second = (2.0 / mHeight * (y+lZoom.y) * lZoom.scale) - 1.0 * lZoom.scale;

         lCoordinates.first = (x - mWidth / 2)*mScale + mXCenter;
         lCoordinates.second = (y - mHeight / 2)*mScale + mYCenter;
      }
      return lCoordinates;
   }
}