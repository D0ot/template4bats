cmake_minimum_required(VERSION 3.0.0)
project(myagent VERSION 0.1.0)

### Library Configuration Start ###

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

INCLUDE(FindPkgConfig)
find_package(Eigen3 REQUIRED)
find_package(LibXml2 REQUIRED)
PKG_CHECK_MODULES(SigC++ sigc++-2.0)
find_package(SigC++ REQUIRED)
PKG_CHECK_MODULES(GTKMM gtkmm-2.4)


set(CXXOPTS_INCLUDE_DIR 3rd/cxxopts/include)

### Library Configuration End ###

set(LIBS_INCLUDE_DIRS 
  ${EIGEN3_INCLUDE_DIR} 
  ${LIBXML2_INCLUDE_DIRS} 
  ${LIBXMLXX_INCLUDE_DIRS} 
  ${SigC++_INCLUDE_DIRS} 
  ${CXXOPTS_INCLUDE_DIR}
  )

if(GTKMM_FOUND)
  message(STATUS "GTKMM_FOUND TRUE")
  list(APPEND LIBS_INCLUDE_DIRS ${GTKMM_INCLUDE_DIRS})
else(GTKMM_FOUND)
  message(STATUS "GTKMM_FOUND FALSE")
endif(GTKMM_FOUND)




set(INCLUDE_DIRS inc ${LIBS_INCLUDE_DIRS})

set(SOURCES 
src/main.cc
src/MyAgent/think.cc
src/MyAgent/init.cc
src/CommandLine/commandline.cc
)

add_executable(main ${SOURCES})
target_include_directories(main PUBLIC ${INCLUDE_DIRS})
target_link_libraries(main bats ${LIBXML2_LIBRARIES})

if (GTKMM_FOUND)
  target_link_libraries(main ${GTKMM_LIBRARIES})
endif (GTKMM_FOUND)

set(XML_FILES_DIR config/xml)

configure_file(${XML_FILES_DIR}/conf.dtd . COPYONLY)
configure_file(${XML_FILES_DIR}/conf.xml . COPYONLY)
configure_file(${XML_FILES_DIR}/nao_mdl.xml . COPYONLY)



# Configurations for gtk glade file. see "debugger.glade"
set(GTK_DEBUGGER_CONFIG_DIR config/gtkdebugger)
set(GTK_DEBUGGER_GLADE Debugger/debugger.glade)

configure_file(${GTK_DEBUGGER_CONFIG_DIR}/${GTK_DEBUGGER_GLADE} ./${GTK_DEBUGGER_GLADE} COPYONLY)

