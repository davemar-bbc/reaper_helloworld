cmake_minimum_required(VERSION 2.8)

project (reaper_helloworld)

SET(CMAKE_BUILD_TYPE MinSizeRel)

IF(APPLE)
  SET( CMAKE_OSX_ARCHITECTURES i386;x86_64 )
  SET( CMAKE_OSX_DEPLOYMENT_TARGET 10.5 )
  SET ( LINK_FLAGS MINSIZEREL "-dead_strip" )

	FIND_LIBRARY(CARBON_LIBRARY Carbon)
	FIND_LIBRARY(COCOA_LIBRARY Cocoa)
	
	SET(CMAKE_MACOSX_RPATH 1)
ENDIF (APPLE)

# set unique name for swell functions
ADD_DEFINITIONS(-DSWELL_APP_PREFIX=SWELL_AMBIX)

################################################
# INCLUDES
include_directories (BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/WDL)
include_directories (BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/src)

################################################
# additional cmake find packages
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set (reaper_helloworld_sources
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	)

IF(WIN32)
	# ressource file for gui
	set (win_resource_files
		${CMAKE_CURRENT_SOURCE_DIR}/src/res.rc
		)
	set(reaper_helloworld_sources ${reaper_helloworld_sources} ${win_resource_files})
ENDIF(WIN32)

IF(NOT WIN32)
	# this filelist is from the swell example: (app_main.cpp)
	set (swell_sources
		${CMAKE_CURRENT_SOURCE_DIR}/WDL/swell/swell-dlg.mm
		${CMAKE_CURRENT_SOURCE_DIR}/WDL/swell/swell-gdi.mm
		${CMAKE_CURRENT_SOURCE_DIR}/WDL/swell/swell-ini.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/WDL/swell/swell-kb.mm 
		${CMAKE_CURRENT_SOURCE_DIR}/WDL/swell/swell-menu.mm 
		${CMAKE_CURRENT_SOURCE_DIR}/WDL/swell/swell-misc.mm 
		${CMAKE_CURRENT_SOURCE_DIR}/WDL/swell/swell-miscdlg.mm 
		${CMAKE_CURRENT_SOURCE_DIR}/WDL/swell/swell-wnd.mm 
		${CMAKE_CURRENT_SOURCE_DIR}/WDL/swell/swell.cpp 
		${CMAKE_CURRENT_SOURCE_DIR}/WDL/swell/swell-appstub.mm
		)
	
	set(reaper_helloworld_sources ${reaper_helloworld_sources} ${swell_sources})
ENDIF(NOT WIN32)

IF(APPLE)
  # set the output directory to REAPER Plugin dir
  SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "~/Library/Application Support/REAPER/UserPlugins")
ENDIF(APPLE)

add_library (reaper_helloworld SHARED
	${reaper_helloworld_sources}
	)

SET_TARGET_PROPERTIES(reaper_helloworld PROPERTIES PREFIX "")

IF(APPLE)
	target_link_libraries (reaper_helloworld ${CARBON_LIBRARY} ${COCOA_LIBRARY})
ENDIF(APPLE)



