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
}