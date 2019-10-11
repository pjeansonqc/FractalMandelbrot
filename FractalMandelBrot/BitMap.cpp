#include "pch.h"
#include "BitMap.h"
#include "BitmapInfoHeader.h"
#include"BitmapFileHeader.h"
#include <fstream>
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
bool BitMap::write(const string &inFileName)
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
      lFile.write((char*)mPixels.data(), mWidth *  mHeight * 3);
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
void BitMap::setPixel(int inX, int inY, uint8_t inRed, uint8_t inGreen, uint8_t inBlue)
{
   uint8_t * lPixel = &mPixels[inY * 3 * mWidth + inX * 3];

   lPixel[0] = inBlue;
   lPixel[1] = inGreen;
   lPixel[2] = inRed;
   return;
}