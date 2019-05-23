using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SharpMandelbrot
{
    class Pixel
    {
        public sbyte red;
        public sbyte green;
        public sbyte blue;
        public Pixel()
        {
            red = 0;
            green = 0;
            blue = 0;
        }
        public Pixel(sbyte r, sbyte g, sbyte b)
        {
            red = r;
            green = g;
            blue = b;
        }
    }
}
