#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "graycodermaindialog.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

#pragma GCC diagnostic pop

void ribi_grco_main_dialog_test() noexcept
{
  ///BitStringToInt
  {
    assert(BitStringToInt(   "0") == 0);
    assert(BitStringToInt(   "1") == 1);
    assert(BitStringToInt(  "10") == 2);
    assert(BitStringToInt(  "11") == 3);
    assert(BitStringToInt( "100") == 4);
    assert(BitStringToInt( "101") == 5);
    assert(BitStringToInt( "110") == 6);
    assert(BitStringToInt( "111") == 7);
    assert(BitStringToInt("1000") == 8);
    assert(BitStringToInt("1001") == 9);
    assert(BitStringToInt("10000") ==  16);
    assert(BitStringToInt("100000") ==  32);
    assert(BitStringToInt("1000000") ==  64);
    assert(BitStringToInt("10000000") == 128);
    assert(BitStringToInt("100000000") == 256);
    assert(BitStringToInt("1000000000") == 512);
  }
  ///IntToBitString
  {
    assert(IntToBitString(  0) ==    "0");
    assert(IntToBitString(  1) ==    "1");
    assert(IntToBitString(  2) ==   "10");
    assert(IntToBitString(  3) ==   "11");
    assert(IntToBitString(  4) ==  "100");
    assert(IntToBitString(  5) ==  "101");
    assert(IntToBitString(  6) ==  "110");
    assert(IntToBitString(  7) ==  "111");
    assert(IntToBitString(  8) == "1000");
    assert(IntToBitString(  9) == "1001");
    assert(IntToBitString( 16) == "10000");
    assert(IntToBitString( 32) == "100000");
    assert(IntToBitString( 64) == "1000000");
    assert(IntToBitString(128) == "10000000");
    assert(IntToBitString(256) == "100000000");
    assert(IntToBitString(512) == "1000000000");
  }
  //IntToGray
  {
    assert(IntToGray( 0)== 0);
    assert(IntToGray( 1)== 1);
    assert(IntToGray( 2)== 3);
    assert(IntToGray( 3)== 2);
    assert(IntToGray( 4)== 6);
    assert(IntToGray( 5)== 7);
    assert(IntToGray( 6)== 5);
    assert(IntToGray( 7)== 4);
    assert(IntToGray( 8)==12);
    assert(IntToGray( 9)==13);
    assert(IntToGray(10)==15);
    assert(IntToGray(11)==14);
    assert(IntToGray(12)==10);
    assert(IntToGray(13)==11);
    assert(IntToGray(14)== 9);
    assert(IntToGray(15)== 8);
  }
  //GrayToInt
  {
    assert(GrayToInt( 0)== 0);
    assert(GrayToInt( 1)== 1);
    assert(GrayToInt( 3)== 2);
    assert(GrayToInt( 2)== 3);
    assert(GrayToInt( 6)== 4);
    assert(GrayToInt( 7)== 5);
    assert(GrayToInt( 5)== 6);
    assert(GrayToInt( 4)== 7);
    assert(GrayToInt(12)== 8);
    assert(GrayToInt(13)== 9);
    assert(GrayToInt(15)==10);
    assert(GrayToInt(14)==11);
    assert(GrayToInt(10)==12);
    assert(GrayToInt(11)==13);
    assert(GrayToInt( 9)==14);
    assert(GrayToInt( 8)==15);
  }
}

std::ostream& ribi::grco::operator<<(std::ostream& os, const main_dialog& dialog)
{
  os
    << "Normal value   : " << dialog.GetNormalInt() << " (" << dialog.GetNormalIntAsBitStr() << ")\n"
    << "Gray code value: " << dialog.GetGrayInt() << " (" << dialog.GetGrayIntAsBitStr() << ")\n";

  return os;
}
