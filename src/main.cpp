#include "reaper_plugin.h"

#ifdef _WIN32
#include <windows.h>
#else
#include "../WDL/swell/swell.h"
#endif

REAPER_PLUGIN_HINSTANCE g_hInst = 0;

// global variable that holds the handle to the Reaper main window, useful for various win32 API calls
HWND g_parent;

extern "C"
{

// Reaper entry point function. Every Reaper plugin needs this.
REAPER_PLUGIN_DLL_EXPORT int REAPER_PLUGIN_ENTRYPOINT(REAPER_PLUGIN_HINSTANCE hInstance, reaper_plugin_info_t *rec)
{
  g_hInst = hInstance;
  if (rec)
  { 
    // Check caller is OK
    if (rec->caller_version != REAPER_PLUGIN_VERSION || !rec->GetFunc)
    {
      return 0;
    }
  
    g_parent = rec->hwnd_main;

    // Pop up a message box with "Hello World!"
    MessageBox(g_parent, "Hello World!", "Reaper Hello World", MB_OK);
   
    return 1;
  }
  else
  {
    return 0;
  }
}

};

