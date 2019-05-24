using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace SharpMandelbrot
{
    public class FractalCreator : EventArgs
    {
        int mWidth = 800;
        int mHeight = 600;
        bool mFirstRange = false;
#if (true)
        Bitmap mBitmap;
        int mMaxiterations = 100;
        ColorRangeList mColorRangeList;
        List<int> mHistogram;// { 100, 0 };
        List<int> mIterationsVector;// { mWidth * mHeight, 0 };
        ZoomList mZoomList;// { mWidth, mHeight };
        int mRangeTotal;

        public Bitmap MBitmap { get => mBitmap; set => mBitmap = value; }
        public event EventHandler<ProgressEventArgs> RaiseProgressEvent;
        public delegate void ProgressEventHandler(object sender, ProgressEventArgs a);
        // Wrap event invocations inside a protected virtual method
        // to allow derived classes to override the event invocation behavior
        protected async virtual void OnRaiseProgressEvent(ProgressEventArgs e)
        {
            // Make a temporary copy of the event to avoid possibility of
            // a race condition if the last subscriber unsubscribes
            // immediately after the null check and before the event is raised.
            EventHandler<ProgressEventArgs> handler = RaiseProgressEvent;

            // Event will be null if there are no subscribers
            if (handler != null)
            {
                // Use the () operator to raise the event.
                handler(this, e);
            }
        }
        //Public
        public FractalCreator(int inWidth, int inHeight, int inMaxiterations)
        {
            OnRaiseProgressEvent(new ProgressEventArgs(0));
            mWidth = inWidth;
            mHeight = inHeight;
            mMaxiterations = inMaxiterations;
            mBitmap = new Bitmap(mWidth, mHeight);
            mColorRangeList = new ColorRangeList(mMaxiterations);
            //mHistogram = new List<int>(100);
            mHistogram = Enumerable.Repeat(0, mMaxiterations).ToList();
            mIterationsVector = Enumerable.Repeat(0, mWidth * mHeight).ToList();
            mZoomList = new ZoomList(mWidth, mHeight);
            mRangeTotal = 0;
            mZoomList.Add(new Zoom(mWidth / 2, mHeight / 2, 4.0 / mWidth));
        }
        private IProgress<int> mProgress;
        public async Task<string> run(string name, IProgress<int> progress)
        {
            mProgress = progress;
            mProgress.Report(10);
            //OnRaiseProgressEvent(new ProgressEventArgs(10));
            calculateIteration();
            mProgress.Report(20);
            //OnRaiseProgressEvent(new ProgressEventArgs(20));
            //calculateRangeTotals();
            drawFractal();
            mProgress.Report(80);
            //OnRaiseProgressEvent(new ProgressEventArgs(50));
            MBitmap = mBitmap;
            mProgress.Report(100);
            //OnRaiseProgressEvent(new ProgressEventArgs(75));
            writeBitmap(name);
            
            //OnRaiseProgressEvent(new ProgressEventArgs(100));
            return ("Finished!");
        }
       void  calculateIteration()
        {
            //#pragma omp parallel for
            for (int x = 0; x < mWidth; ++x)
            {
                //#pragma omp parallel for
                for (int y = 0; y < mHeight; ++y)
                {
                    Tuple<double, double> location = mZoomList.DoZoom(x, y);
                    int lIterations = SharpMandelbrot.MandelBrot.getIteration(location.Item1, location.Item2, mMaxiterations);
                    mIterationsVector[y * mWidth + x] = lIterations;
                    if (lIterations < mMaxiterations)
                    {
                        mHistogram[lIterations]++;
                    }
                }
            }
        }
        async void drawFractal()
        {
            int lTotal = 0;
            //#pragma omp parallel for
            for (int i = 0; i < mMaxiterations; i++)
            {
                lTotal += mHistogram[i];
            }
            mProgress.Report(25);
            for (int x = 0; x < mWidth; ++x)
            {
                int p = (int)(25 + 75 * (1.0f * x / mWidth));
                mProgress.Report(p );
                //#pragma omp parallel for
                for (int y = 0; y < mHeight; ++y)
                {
                    int iterations = mIterationsVector[y * mWidth + x];
                    double hue = 0.0;


                    if (iterations < mMaxiterations)
                    {
//#pragma omp parallel for
                        for (int i = 0; i < iterations; i++)
                        {
                            hue += ((double)mHistogram[i]) / lTotal;
                        }
                    }
                    else
                    {
                        hue = 0;
                    }
                    Color lColor = mColorRangeList.GetColor(iterations);
                    byte lRed = (byte)(lColor.R * hue);
                    byte lGreen = (byte)(lColor.G * hue);
                    byte lBlue = (byte)(lColor.B * hue);
                    Color lc = Color.FromArgb(lRed, lGreen, lBlue);
                    mBitmap.SetPixel(x, y, lc);
                }
            }
        }
        public void addZoom(Zoom inZoom)
        {
            mZoomList.Add(inZoom);
        }

        public void addColorRange(double rangeBegin, double rangeEnd, Color inColor)
        {
            mColorRangeList.AddColorRange(rangeBegin, rangeEnd, inColor);
        }
        public void writeBitmap(string name)
        {
            mBitmap.Save(name);
        }

        public void calculateRangeTotals()
        {
            /*int rangeIndex = 0;
            for(int i=0; i<mMaxiterations;++i)
            { 
               int lIndex = mColorRangeList.GetRangeIndex(i);
               if (lIndex != -1)
               {
                  mRangeTotal[rangeIndex] += pixels;
               }
               if(i>= mColorRanges[rangeIndex+1])
               { 
                  ++rangeIndex;
               }
               int pixels = mHistogram[i];
               mRangeTotal[rangeIndex] += pixels;
            }*/

        }
#endif

    }
}
