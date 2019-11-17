cmake_minimum_required(VERSION 3.0.0)
project(dribble VERSION 0.1.0)


set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

INCLUDE(FindPkgConfig)
find_package(Eigen3 REQUIRED)
find_package(LibXml2 REQUIRED)
PKG_CHECK_MODULES(SigC++ sigc++-2.0)
find_package(SigC++ REQUIRED)
PKG_CHECK_MODULES(GTKMM gtkmm-2.4)

set(INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR} ${LIBXML2_INCLUDE_DIR} ${SigC++_INCLUDE_DIRS} ${LIBXMLXX_INCLUDE_DIRS})


add_executable(dribble src/main.cc)
target_include_directories(dribble PUBLIC ${INCLUDE_DIRS})


