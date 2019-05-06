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
      std::pair <double, double> doZoom(int x, int y);
         
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