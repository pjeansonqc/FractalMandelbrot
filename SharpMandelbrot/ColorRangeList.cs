using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace SharpMandelbrot
{
    class ColorRangeList
    {
        //private:
        List<ColorRange> mColorRanges;
        int mMaxIterations = 0;
        //public:
        public ColorRangeList(int inMaxIterations)
        {
            mMaxIterations = inMaxIterations;
            mColorRanges = new List<ColorRange>();
        }
        public void AddColorRange(double inBegin, double inEnd, Color inColor)
        {
            int lBegin = (int)Math.Round( inBegin * mMaxIterations);
            int lEnd = (int)Math.Round(inEnd * mMaxIterations);
            ColorRange lColorRange = new ColorRange(lBegin, lEnd, inColor);
            mColorRanges.Add(lColorRange);
        }
        public Color GetColor(int inIterations)
        {
            Color lColor = new Color();
            bool lFound = false;
            foreach (ColorRange range in mColorRanges)
            {
                if (range.IsInRange(inIterations))
                {
                    lColor = range.mColor;
                    lFound = true;
                    break;
                }
            }
            if (!lFound)
            {
                Console.WriteLine("Color range Not found!");
            }
            return lColor;
        }

    };
}

