#include "graycodermenudialog.h"

int main(int argc, char * argv[])
{
  const std::vector<std::string> args = { ribi::grco::menu_dialog::ConvertArguments(argc,argv) };
  ribi::grco::menu_dialog d;
  return d.Execute(args);
}
