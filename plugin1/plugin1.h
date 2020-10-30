#include <iostream>
#include <boost/config.hpp> // for BOOST_SYMBOL_EXPORT
#include "../pluginInterface.h"
namespace plugin
{
class Plugin1:public pluginInterface
{
  public:
  virtual void executePlugin();
};

// Exporting `plugin::plugin` variable with alias name `plugin`
// (Has the same effect as `BOOST_DLL_ALIAS(plugin::plugin, plugin)`)
extern "C" BOOST_SYMBOL_EXPORT Plugin1 plugin;
Plugin1 plugin;

} // namespace my_namespace