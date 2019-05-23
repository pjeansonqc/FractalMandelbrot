using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SharpMandelbrot
{
    class ZoomList
    {
        // private:
        double mXCenter;
        double mYCenter;
        double mScale;
        int mWidth;
        int mHeight;
        List<Zoom> mZoomList;

        //public:
        public ZoomList(int pWidth = 0, int pHeight = 0)
        {
            mXCenter = 0f;
            mYCenter = 0f;
            mScale = 1.0f;
            mWidth = pWidth;
            mHeight = pHeight;
            mZoomList = new List<Zoom>();
        }

        public void Add(Zoom inZoom)
        {
            mZoomList.Add(inZoom);
            mXCenter += (inZoom.x - mWidth / 2.0) * mScale;
            mYCenter += (inZoom.y - mHeight / 2.0) * mScale;
            mScale *= inZoom.scale;
        }
        //***************************************************************************
        public Tuple<double, double> DoZoom(int x, int y)
        {
            double lX = (x - mWidth / 2) * mScale + mXCenter;
            double lY = (y - mHeight / 2) * mScale + mYCenter;
            Tuple<double, double> lCoordinates = new Tuple<double, double>(lX, lY);

            return lCoordinates;
        }

       
    };

}
