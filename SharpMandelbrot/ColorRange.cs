using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace SharpMandelbrot
{
    class ColorRange
    {
        //public:
        public int mBegin = 0;
        public int mEnd = 0;
        public Color mColor;



        public ColorRange(int inBegin, int inEnd, Color inColor)
        {
            mBegin = inBegin;
            mEnd = inEnd;
            mColor = inColor;
        }

        public bool IsInRange(int inValue)
        {
            bool lInRange = false;
            if (inValue >= mBegin && inValue <= mEnd)
            {
                lInRange = true;
            }
            return lInRange;
        }
    }
}
