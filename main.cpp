#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "graycodermenudialog.h"

#pragma GCC diagnostic pop

int main(int argc, char * argv[])
{
  const std::vector<std::string> args { ribi::grco::menu_dialog::ConvertArguments(argc,argv) };
  ribi::grco::menu_dialog d;
  return d.Execute(args);
}
