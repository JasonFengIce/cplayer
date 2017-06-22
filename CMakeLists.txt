cmake_minimum_required(VERSION 3.7)
project(cplayer)

set(CMAKE_C_STANDARD 99)

#
#find_package(PkgConfig REQUIRED)
#pkg_check_modules(SDL sdl)
#
#set(LIBSDL_DEFINITIONS ${PC_LIBSDL_CFLAGS_OTHER})

#find_path(LIBSDL_INCLUDE_DIR SDL/SDL.h
#        HINTS ${PC_LIBSDL_INCLUDEDIR} ${PC_LIBSDL_INCLUDE_DIRS}
#        PATH_SUFFIXES libsdl)
#
##find_library(LIBSDL_LIBRARY NAMES sdl libsdl
##        HINTS ${PC_LIBSDL_LIBDIR} ${PC_LIBSDL_LIBRARY_DIRS})
#
#find_library(LIBSDLMAIN_LIBRARY NAMES sdlmain libsdlmain
#        HINTS ${PC_LIBSDLMAIN_LIBDIR} ${PC_LIBSDLMAIN_LIBRARY_DIRS})
#
#include(FindPackageHandleStandardArgs)
## handle the QUIETLY and REQUIRED arguments and set LIBSDL_FOUND to TRUE
## if all listed variables are TRUE
#find_package_handle_standard_args(LibSDL DEFAULT_MSG
#        LIBSDL_LIBRARY LIBSDL_INCLUDE_DIR)
#
#mark_as_advanced(LIBSDL_INCLUDE_DIR LIBSDL_LIBRARY)
#
#set(LIBSDL_LIBRARIES ${LIBSDL_LIBRARY})
#set(LIBSDL_INCLUDE_DIRS ${LIBSDL_INCLUDE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES src/main.c src/m3u8.c src/m3u8.h src/httpserver.c src/httpserver.c src/httpserver.h)


add_executable(cplayer ${SOURCE_FILES})

target_link_libraries(
        cplayer
        ${PROJECT_SOURCE_DIR}/lib/libavcodec.dylib
        ${PROJECT_SOURCE_DIR}/lib/libavdevice.dylib
        ${PROJECT_SOURCE_DIR}/lib/libavfilter.dylib
        ${PROJECT_SOURCE_DIR}/lib/libavformat.dylib
        ${PROJECT_SOURCE_DIR}/lib/libavutil.dylib
        ${PROJECT_SOURCE_DIR}/lib/libpostproc.dylib
        ${PROJECT_SOURCE_DIR}/lib/libSDL2.dylib
        ${PROJECT_SOURCE_DIR}/lib/libswresample.dylib
        ${PROJECT_SOURCE_DIR}/lib/libswscale.dylib
        ${PROJECT_SOURCE_DIR}/lib/libcurl.dylib
        ${PROJECT_SOURCE_DIR}/lib/libmicrohttpd.dylib
)

#${PROJECT_SOURCE_DIR}/lib/libavcodec.a
#${PROJECT_SOURCE_DIR}/lib/libavdevice.a
#${PROJECT_SOURCE_DIR}/lib/libavfilter.a
#${PROJECT_SOURCE_DIR}/lib/libavformat.a
#${PROJECT_SOURCE_DIR}/lib/libavutil.a
#${PROJECT_SOURCE_DIR}/lib/libSDL.a
#${PROJECT_SOURCE_DIR}/lib/libSDLmain.a
#${PROJECT_SOURCE_DIR}/lib/libswresample.a
#${PROJECT_SOURCE_DIR}/lib/libswscale.a
