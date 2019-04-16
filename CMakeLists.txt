cmake_minimum_required(VERSION 3.0)

project(oe-bugs C CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(Threads REQUIRED) # TODO required due to OE bug, remove with new version
find_package(openenclave REQUIRED CONFIG)

include(oeedl_file)

include_directories(shared)

set(PROPS_CC ${CMAKE_SOURCE_DIR}/shared/props.cc)

add_subdirectory(bug1)
