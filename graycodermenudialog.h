#ifndef GRAYCODERMENUDIALOG_H
#define GRAYCODERMENUDIALOG_H

#include <string>
#include <vector>

#include "about.h"
#include "help.h"
#include "menudialog.h"

namespace ribi {
namespace grco {

///GUI independent GrayCoder menu dialog
struct menu_dialog final : public MenuDialog
{
  explicit menu_dialog() noexcept;
  About GetAbout() const noexcept override;

  private:
  int ExecuteSpecific(const std::vector<std::string>& argv) noexcept override;
  Help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override;
  std::vector<std::string> GetVersionHistory() const noexcept override;
};

} //~namespace grco

using GrayCoderMenuDialog = grco::menu_dialog;

} //~namespace ribi

#endif // GRAYCODERMENUDIALOG_H
