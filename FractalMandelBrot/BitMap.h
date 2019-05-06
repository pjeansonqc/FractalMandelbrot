#pragma once
#include <string>
#include <vector>
#include <cstdint>
using namespace std;
class BitMap
{
private:
   int mWidth{0};
   int mHeight{0};
   vector<uint8_t> mPixels;
public:
   BitMap(int inWidth, int inHeight);
   bool write(const string &inFileName);
   void setPixel(int inX, int inY, uint8_t inRed, uint8_t inGreen, uint8_t inBlue);
   virtual ~BitMap();
};

