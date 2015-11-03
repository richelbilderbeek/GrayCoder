//---------------------------------------------------------------------------
/*
GrayCoder, tool to convert integers to and from Gray code
Copyright (C) 2009-2015 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
// From http://www.richelbilderbeek.nl/ToolGrayCoder.htm
//---------------------------------------------------------------------------
#ifndef GRAYCODERMENUDIALOG_H
#define GRAYCODERMENUDIALOG_H

#include <string>
#include <vector>

#include "about.h"
#include "help.h"
#include "richelbilderbeekprogram.h"
#include "menudialog.h"

namespace ribi {
namespace grco {

///GUI independent GrayCoder menu dialog
struct menu_dialog final : public MenuDialog
{
  explicit menu_dialog() noexcept;

  private:
  int ExecuteSpecific(const std::vector<std::string>& argv) noexcept override;
  About GetAbout() const noexcept override;
  Help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override;
  std::vector<std::string> GetVersionHistory() const noexcept override;

  #ifndef NDEBUG
  static void test() noexcept;
  #endif

};

} //~namespace grco

using GrayCoderMenuDialog = grco::menu_dialog;

} //~namespace ribi

#endif // GRAYCODERMENUDIALOG_H
