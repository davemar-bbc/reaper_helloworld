## Hello World Reaper Plugin

This is a very simple Reaper Pluging that pops up a message box with "Hello World!" displayed in it. It's basically the simplest example Reaper plugin code that does something.

### Installation

This uses cmake to build the code, so make sure you've got cmake installed. You will also need:
 * WDL (save this in reaper_helloworld/ directory)
 * reaper_plugin.h from http://www.reaper.fm/sdk/plugin/reaper_plugin.h (save this in reaper_helloworld/src)
 * reaper_plugin_functions.h from Reaper itself (save this in reaper_helloworld/src)
 
To build the code, follow this process:
```
> cd reaper_helloworld
> mkdir build
> cd build
> cmake ..
> make
```

Expect to see quite a few warnings on when doing the make, these are just from the WDL library. 

If it all works it should copy the reaper_hellworld.dylib file to ~/Library/Application Support/REAPER/UserPlugins/ and Reaper should automatically pick it up from there when it is run.


