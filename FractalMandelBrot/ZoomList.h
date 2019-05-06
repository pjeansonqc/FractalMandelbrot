#ifndef _H_ZOOMLIST_H
#define _H_ZOOMLIST_H
#include "Zoom.h"
#include <vector>
#include <utility>

namespace FractalMandelbrot
{
   class ZoomList
   {
   public:
      ZoomList(int pWidth = 0, int pHeight = 0) : mWidth(pWidth), mHeight(pHeight)
      {

      }
      ~ZoomList();
      void Add(const Zoom & inZoom);
      //***************************************************************************
      std::pair <double, double> doZoom(int x, int y)
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
   private:
      double mXCenter{ 0.0 };
      double mYCenter{ 0.0 };
      double mScale{ 1.0 };
      int mWidth{ 0 };
      int mHeight{ 0 };
      std::vector<Zoom> mZoomList;
   };



   
} // namespace FractalMandelbrot


#endif // _H_ZOOMLIST_H