#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "graycodermenudialog.h"

#include <cassert>
#include <iostream>

#include <boost/lexical_cast.hpp>

#include "graycodermaindialog.h"
#pragma GCC diagnostic pop

ribi::grco::menu_dialog::menu_dialog() noexcept
{

}

int ribi::grco::menu_dialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc == 1)
  {
    std::cout << GetHelp() << '\n';
    return 0;
  }
  //User supplied binary or decimal value?
  for (int i=0; i!=argc-1; ++i) //-1 as the next argument is used
  {
    const std::string s = argv[i];
    if (s == "-d" || s == "--dec")
    {
      try
      {
        const int x = boost::lexical_cast<int>( argv[i + 1] );
        main_dialog d;
        d.SetNormalInt(x);
        std::cout << d << '\n';
        return 0;
      }
      catch(boost::bad_lexical_cast&)
      {
        std::cout << "Please supply a number as decimal value\n";
        return 1;
      }
    }
    if (s == "-b" || s == "--bin")
    {
      try
      {

        const int x = main_dialog::BitStringToInt( argv[i + 1] );
        main_dialog d;
        d.SetNormalInt(x);
        std::cout << d << '\n';
        return 0;
      }
      catch(std::logic_error&)
      {
        std::cout << "Please supply a binary number\n";
        return 1;
      }
    }
  }

  std::cout << GetHelp() << '\n';
  return 1;
}

ribi::About ribi::grco::menu_dialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "GrayCoder",
    "tool to convert integers to and from Gray code",
    "the 30th of September 2013",
    "2009-2015",
    "http://www.richelbilderbeek.nl/ToolGrayCoder.htm",
    GetVersion(),
    GetVersionHistory()
  );
  return a;
}

ribi::Help ribi::grco::menu_dialog::GetHelp() const noexcept
{
  return ribi::Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {
      Help::Option('b',"bin","decimal number to be converted to/from Gray code"),
      Help::Option('d',"dec","decimal number to be converted to/from Gray code")
    },
    {
      "GrayCoder -d 123456",
      "GrayCoder -b 010101"
    }
  );
}

std::string ribi::grco::menu_dialog::GetVersion() const noexcept
{
  return "2.2";
}

std::vector<std::string> ribi::grco::menu_dialog::GetVersionHistory() const noexcept
{
  return {
    "2009-05-02: version 1.0: initial version in C++ Builder",
    "2013-08-26: version 2.0: port to Qt Creator console application",
    "2013-09-30: version 2.1: added desktop application",
    "2013-11-01: version 2.2: added console application",
  };
}
