#pragma once

namespace FractalMandelbrot
{
   class MandelBrot
   {
   private:
      int mMaxIteration{100};
   public:
      MandelBrot(int inMaxIteration);
      virtual ~MandelBrot();


      static int getIteration(double x, double y, int inMaxiterations);
   };

}