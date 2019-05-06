#include "pch.h"
#include "MandelBrot.h"
#include <complex>

using namespace std;

namespace FractalMandelbrot
{

   MandelBrot::MandelBrot(int inMaxIteration) : mMaxIteration(inMaxIteration)
   {
   }


   MandelBrot::~MandelBrot()
   {
   }

   int MandelBrot::getIteration(double x, double y, int inMaxiterations)
   {
      complex<double> z = 0;
      complex<double> c(x,y);

      int iterations = 0;

      while(iterations < inMaxiterations)
      {
         z = z * z + c;
         if (abs(z) > 2)
         {
            break;
         }
         ++iterations;
      }

      return iterations;
   }

}