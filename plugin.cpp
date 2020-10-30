#include <boost/dll/import.hpp>
#include <iostream>
#include "pluginInterface.h"
void printHelp()
{
    std::cout << "./pluginTest <plugin dirctory> <plugin name>" << std::endl;
    std::cout << "example:" << std::endl;
    std::cout << "  ./pluginTest plugin1/ Plugin1" << std::endl;
}


int main(int argc, char* argv[])
{
    std::string current_exec_name = argv[0]; // Name of the current exec program
  std::vector<std::string> all_args;

  if (argc > 1)
  {
    boost::filesystem::path lib_path(argv[1]);          // argv[1] contains path to directory with our plugin library
    if(!boost::filesystem::is_directory(lib_path))
    {
      std::cout << "Error: path provided is not a directory: " << argv[1] << std::endl;
      printHelp();
      return 1;
    }
    boost::shared_ptr<pluginInterface> plugin;            // variable to hold a pointer to plugin variable
    try{
      plugin = boost::dll::import<pluginInterface>(          // type of imported symbol is located between `<` and `>`
          lib_path / argv[2],                     // path to the library and library name
          "plugin",                                       // name of the symbol to import
          boost::dll::load_mode::append_decorations              // makes `libmy_plugin_sum.so` or `my_plugin_sum.dll` from `my_plugin_sum`
      );
      std::cout << "Loading the plugin: " << argv[2] << std::endl;
    }
    catch(...)
    {
      std::cout << "Error: invlaid plugin name:" << argv[2] << std::endl;
      printHelp();
      return 1;
    }
    plugin->executePlugin();
  }
  else
  {
    std::cout << "Error: no args provided" << std::endl;
    printHelp();
  }
  return 0;
}