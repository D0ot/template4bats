cmake_minimum_required(VERSION 3.0.0)
project(myagent VERSION 0.1.0)

### Library Configuration ###

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

INCLUDE(FindPkgConfig)
find_package(Eigen3 REQUIRED)
find_package(LibXml2 REQUIRED)
PKG_CHECK_MODULES(SigC++ sigc++-2.0)
find_package(SigC++ REQUIRED)
PKG_CHECK_MODULES(GTKMM gtkmm-2.4)

set(CXXOPTS_INCLUDE_DIRS 3rd/cxxopts/include)

###

set(LIBS_INCLUDE_DIRS 
  ${EIGEN3_INCLUDE_DIR} 
  ${LIBXML2_INCLUDE_DIR} 
  ${SigC++_INCLUDE_DIRS} 
  ${LIBXMLXX_INCLUDE_DIRS} 
  ${GTKMM_INCLUDE_DIR}
  ${CXXOPTS_INCLUDE_DIRS}
  )



set(INCLUDE_DIRS inc ${LIBS_INCLUDE_DIRS})

set(SOURCES 
src/main.cc
src/MyAgent/think.cc
src/MyAgent/init.cc
src/CommandLine/commandline.cc
)

add_executable(main ${SOURCES})
target_include_directories(main PUBLIC ${INCLUDE_DIRS})
target_link_libraries(main bats)

if (GTKMM_FOUND)
  target_link_libraries(main ${GTKMM_LIBRARIES} ${LIBXML2_LIBRARIES})
endif (GTKMM_FOUND)


configure_file(xml/conf.dtd . COPYONLY)
configure_file(xml/conf.xml . COPYONLY)
configure_file(xml/nao_mdl.xml . COPYONLY)

