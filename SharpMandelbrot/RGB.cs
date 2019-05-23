using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SharpMandelbrot
{
    public struct RGB
    {
        double r;
        double g;
        double b;

        public RGB(double inR, double inG, double inB)
        {
            r = inR;
            g = inG;
            b = inB;
        }
        public static RGB operator +( RGB inFirst, RGB inSecond)
        {
            SharpMandelbrot.RGB lResult = new RGB(0.0, 0.0, 0.0);
            lResult.r = inFirst.r + inSecond.r;
            lResult.g = inFirst.g + inSecond.g;
            lResult.b = inFirst.b + inSecond.b;
            return lResult;
        }
        public static RGB operator -(RGB inFirst, RGB inSecond)
        {
            SharpMandelbrot.RGB lResult = new RGB(0.0, 0.0, 0.0);
            lResult.r = inFirst.r - inSecond.r;
            lResult.g = inFirst.g - inSecond.g;
            lResult.b = inFirst.b - inSecond.b;
            return lResult;
        }
    };
}
