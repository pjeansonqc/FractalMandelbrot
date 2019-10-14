#include "stdafx.h"
#include "BitMap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"
#include <fstream>
#include <thread>

using namespace std;
using namespace FractalMandelbrot;

//***************************************************************************
BitMap::BitMap(int inWidth, int inHeight) : 
   mWidth(inWidth), 
   mHeight(inHeight),
   mPixels(inWidth*inHeight * 3, 0)
{
}

//***************************************************************************
BitMap::~BitMap()
{
}

//***************************************************************************
bool BitMap::writeAsync(const string &inFileName)
{
   bool lReturnValue = false;
   BitmapFileHeader lFileHeader;
   BitmapInfoHeader lInfoHeader;
   
   lFileHeader.fileSize = sizeof(lFileHeader) + sizeof(lInfoHeader) + mWidth *  mHeight * 3;
   lFileHeader.dataOffset = sizeof(lFileHeader) + sizeof(lInfoHeader);

   lInfoHeader.width = mWidth;
   lInfoHeader.height = mHeight;

   ofstream lFile;
   lFile.open(inFileName, ios::out | ios::binary);
   if (lFile)
   {
      lFile.write((char*)&lFileHeader, sizeof(lFileHeader));
      lFile.write((char*)&lInfoHeader, sizeof(lInfoHeader));
      long long lSizeToWrite = mWidth * mHeight * 3;
      lFile.write((char*)mPixels.data(), lSizeToWrite);
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

//***************************************************************************
bool BitMap::write(const string& inFileName)
{
    auto lWrite = [&](const string& rFileName)
    {
        writeAsync(rFileName);
    };
    std::thread writeThread(lWrite, inFileName);
    writeThread.join();
    return true;
}

//***************************************************************************
void BitMap::setPixel(int inX, int inY, uint8_t inRed, uint8_t inGreen, uint8_t inBlue)
{
   uint8_t * lPixel = &mPixels[inY * 3 * mWidth + inX * 3];

   lPixel[0] = inRed;
   lPixel[1] = inGreen;
   lPixel[2] = inBlue;
   return;
}