#ifndef _H_ZOOM_H
#define _H_ZOOM_H

namespace FractalMandelbrot
{

   struct Zoom
   {
      int x{ 0 };
      int y{ 0 };
      double scale{ 0.0 };
      Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {}
      
   };



} //namespace FractalMandelbrot

#endif //_H_ZOOM_H