#pragma once

#include <cstdint>
using namespace std;


namespace FractalMandelbrot
{
#pragma pack(push, 2)
   struct BitmapFileHeader
   {
      char header[2]{ 'B', 'M' };
      int32_t fileSize{ 0 };
      int32_t reserved{ 0 };
      int32_t dataOffset{ 0 };
   };
#pragma pack(pop)
}


