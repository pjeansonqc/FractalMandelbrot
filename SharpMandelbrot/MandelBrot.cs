using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace SharpMandelbrot
{
    class MandelBrot
    {
        //private:
        int mMaxIteration = 100;
        //public:
        public MandelBrot(int inMaxIteration)
        {
            mMaxIteration = inMaxIteration;
        }



        public static int getIteration(double x, double y, int inMaxiterations)
        {
            Complex z = new Complex(0,0);
            Complex c = new Complex(x, y);

            int iterations = 0;

            while (iterations < inMaxiterations)
            {
                z = z * z + c;
                double lMag = Complex.Abs(z);
                if (lMag > 2)
                {
                    break;
                }
                ++iterations;
            }

            return iterations;
        }
    }
}
