using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SharpMandelbrot
{
    public struct Zoom
    {
        public int x;// { 0 };
        public int y;// { 0 };
        public double scale;// { 0.0 };
        public Zoom(int inX, int inY, double inScale) 
        {
            x = inX;
            y = inY;
            scale = inScale;
        }

    };
}
