cmake_minimum_required(VERSION 3.10)
project(SAP C)

if (use_GTK)
find_package (PkgConfig REQUIRED)
pkg_check_modules (GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
message(status "GTK3_INCLUDE_IDRS = ${GTK3_INCLUDE_DIRS}")

link_directories(${GTK3_LIBRARY_DIRS})
message(status "GTK3_LIBRARY_IDRS = ${GTK3_LIBRARY_DIRS}")

add_definitions(${GTK3_CFLAGS_OTHER})
message(satus "GTK3_CFLAGS_OTHER = ${GTK3_CFLAGS_OTHER}")



set(CMAKE_C_STANDARD 99)

add_executable(SAP sap.c)

target_link_libraries(SAP ${GTK3_LIBRARIES})
endif ()

add_definitions("-Wall -g")


add_executable(SAP 
                sap.c 
                player.c 
                player.h 
                playlist.c 
                playlist.h 
                song.c 
                song.h 
                manager.c 
                manager.h 
                SAPDefine.h 
                log.h 
                log.c 
                filetools.c 
                filetools.h 
                tools.c 
                tools.h 
                list.c
                main.c)

target_link_libraries(SAP
       # SDL2
        )
