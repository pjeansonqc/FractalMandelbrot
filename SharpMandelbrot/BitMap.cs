using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace SharpMandelbrot
{
//#pragma pack(push, 2)
    struct BitmapFileHeader
    {
        char[2] header = { 'B', 'M' };
    int fileSize = 0;
    int reserved { 0 };
    int dataOffset { 0 };
};
//#pragma pack(pop)

}

class BitMap
    {
        //private:
        int mWidth = 0;
        int mHeight = 0;
        List<Pixel> mPixels;

        //public:

        public BitMap(int inWidth, int inHeight)
        {
            mWidth = inWidth;
            mHeight = inHeight;
            mPixels = new List<Pixel>(capacity: mWidth * mHeight);
        }
        public bool Write(string inFileName)
        {
            bool lReturnValue = false;
            BitmapFileHeader lFileHeader;
            BitmapInfoHeader lInfoHeader;

            lFileHeader.fileSize = sizeof(lFileHeader) + sizeof(lInfoHeader) + mWidth * mHeight * 3;
            lFileHeader.dataOffset = sizeof(lFileHeader) + sizeof(lInfoHeader);

            lInfoHeader.width = mWidth;
            lInfoHeader.height = mHeight;

            ofstream lFile;
            lFile.open(inFileName, ios::out | ios::binary);
            if (lFile)
            {
                lFile.write((char*)&lFileHeader, sizeof(lFileHeader));
                lFile.write((char*)&lInfoHeader, sizeof(lInfoHeader));
                lFile.write((char*)mPixels.data(), mWidth * mHeight * 3);
                lFile.close();
                lReturnValue = true;
            }
            else
            {
                //problem opening file
                lReturnValue = false;
            }
            return lReturnValue;
        }
        public void SetPixel(int inX, int inY, sbyte inRed, sbyte inGreen, sbyte inBlue)
        {
            Pixel lPixel = mPixels[inY * mWidth + inX * 3];
            
            lPixel.blue = inBlue;
            lPixel.green = inGreen;
            lPixel.red = inRed;
            return;
        }
        public override string ToString()
        {
            string lOut = base.ToString() + " Width:" + mWidth + ",Height:" + mHeight;
            return lOut;
        }
        ~BitMap()
        {

        }
    }
}
