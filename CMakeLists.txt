# This file is part of Turtle Demo
# Copyright (C) 2014 Jeremy Carter
#
# This project as a whole is licensed under the wxWindows Library Licence,
# Version 3.1. See the file called LICENSE found in the project root folder
# for the text of the license.
#
# CMakeLists.txt
#
# Created on: Jun 19, 2014
#     Author: Jeremy Carter
#      Email: Jeremy [at] JeremyCarter [dot] ca

project (turtle-demo-project C CXX)

cmake_minimum_required (VERSION 2.8.10)
set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_BUILD_TYPE Debug)
#set (CMAKE_BUILD_TYPE Release)
list (APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")	# This project uses C++11.
file (TO_NATIVE_PATH "${PROJECT_SOURCE_DIR}/src" src_dir)	# Path to project source code.
file (TO_NATIVE_PATH "${src_dir}/cmake_modules" CMAKE_MODULE_PATH)	# Path to custom cmake modules.

#set (wxWidgets_CONFIGURATION mswud)

# --- Find dependencies ---
find_package (wxWidgets REQUIRED net gl core base)
# ------

include(${wxWidgets_USE_FILE})

add_library (wxmainframe SHARED ${src_dir}/wxMainFrame.cpp)
set_property (TARGET wxmainframe PROPERTY INCLUDE_DIRECTORIES ${wxWidgets_INCLUDE_DIRS})
target_link_libraries (wxmainframe ${wxWidgets_LIBRARIES})

add_library (wxturtle SHARED ${src_dir}/wxTurtle.cpp)
set_property (TARGET wxturtle PROPERTY INCLUDE_DIRECTORIES ${wxWidgets_INCLUDE_DIRS})
target_link_libraries (wxturtle ${wxWidgets_LIBRARIES})

add_library (wxdrawpanel SHARED ${src_dir}/wxDrawPanel.cpp)
set_property (TARGET wxdrawpanel PROPERTY INCLUDE_DIRECTORIES ${wxWidgets_INCLUDE_DIRS})
target_link_libraries (wxdrawpanel ${wxWidgets_LIBRARIES} wxturtle)

add_executable (turtle-demo ${src_dir}/wxMainApp.cpp)
set_property (TARGET turtle-demo PROPERTY INCLUDE_DIRECTORIES ${wxWidgets_INCLUDE_DIRS})
target_link_libraries (turtle-demo ${wxWidgets_LIBRARIES} wxmainframe wxdrawpanel)
