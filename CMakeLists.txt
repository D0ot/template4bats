cmake_minimum_required(VERSION 3.0.0)
project(myagent VERSION 0.1.0)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

INCLUDE(FindPkgConfig)
find_package(Eigen3 REQUIRED)
find_package(LibXml2 REQUIRED)
PKG_CHECK_MODULES(SigC++ sigc++-2.0)
find_package(SigC++ REQUIRED)
PKG_CHECK_MODULES(GTKMM gtkmm-2.4)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/inc)

set(INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR} ${LIBXML2_INCLUDE_DIR} ${SigC++_INCLUDE_DIRS} ${LIBXMLXX_INCLUDE_DIRS} ${MY_INCLUDE_DIR})

set(SOURCES 
src/MyAgent/think.cc
src/MyAgent/init.cc
)

add_executable(main ${SOURCES})
target_include_directories(main PUBLIC ${INCLUDE_DIRS})


