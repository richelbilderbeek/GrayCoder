#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "graycodermaindialog.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

#pragma GCC diagnostic pop

ribi::grco::main_dialog::main_dialog(const int normal_int) noexcept
  : m_i(normal_int)
{

}

int ribi::grco::main_dialog::BitStringToInt(const std::string& s)
{
  int power = 1;
  int result = 0;
  const auto j = s.rend();
  for (auto i = s.rbegin(); i!=j; ++i)
  {
    const char c = *i;
    if (c == '0')
    {
      //OK
    }
    else if (c == '1')
    {
      result += power;
    }
    else
    {
      throw std::logic_error("A bitstring must consist of zeroes and ones only");
    }
    power *= 2;
  }
  return result;
}

int ribi::grco::main_dialog::GrayToInt(int i)
{
  int power = 1;
  while (1)
  {
    const int j = i >> power;
    i ^= j;
    if (j == 0 || power == 16) return i;
    power <<= 1;
  }
}

std::string ribi::grco::main_dialog::IntToBitString(int i)
{
  assert( i >= 0 && "Did not bother to supply this yet");
  std::string s =(i%2 ? "1" : "0" );
  i>>=1;
  while (i > 0)
  {
    s = (i%2 ? "1" : "0") + s;
    i>>=1;
  }
  return s;
}

int ribi::grco::main_dialog::IntToGray(const int i)
{
  assert( i >= 0 && "Did not bother to supply this yet");
  return (i ^ (i>>1));
}

std::ostream& ribi::grco::operator<<(std::ostream& os, const main_dialog& dialog)
{
  os
    << "Normal value   : " << dialog.GetNormalInt() << " (" << dialog.GetNormalIntAsBitStr() << ")\n"
    << "Gray code value: " << dialog.GetGrayInt() << " (" << dialog.GetGrayIntAsBitStr() << ")\n";

  return os;
}
