# Minimum cmake version
cmake_minimum_required(VERSION 3.5)

set(CMAKE_SHARED_LINKER_FLAGS
    "${CMAKE_SHARED_LINKER_FLAGS}")

set(CMAKE_EXE_LINKER_FLAGS
    "${CMAKE_EXE_LINKER_FLAGS}")

# Project name
project(InuhhShinvasion2)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Load SFML libraries
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS graphics audio REQUIRED)

# Check Ruby and mRuby dependencies
find_program(RUBY_EXECUTABLE ruby)
#find_package(BISON)

# Load mRuby
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

set(MRUBY_LIBRARIES "${CMAKE_BINARY_DIR}/mruby/lib/libmruby.lib" "${CMAKE_BINARY_DIR}/mruby/lib/libmruby_core.lib")

ExternalProject_Add(mruby
  PREFIX "${CMAKE_BINARY_DIR}/mruby"
  DOWNLOAD_COMMAND ""
  UPDATE_COMMAND ""
  BUILD_IN_SOURCE 1
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/mruby" 
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ${RUBY_EXECUTABLE} minirake MRUBY_BUILD_DIR=${CMAKE_BINARY_DIR}/mruby MRUBY_CONFIG=${CMAKE_SOURCE_DIR}/mruby_build_config.rb
  INSTALL_COMMAND ""
  BUILD_BYPRODUCTS "${MRUBY_LIBRARIES}")
include_directories("${CMAKE_SOURCE_DIR}/mruby/include")

# Load source files
set(SOURCES 
	Main.cpp
)

# Create executable and link libraries

add_executable(InuhhShinvasion2 ${SOURCES})
target_link_libraries(InuhhShinvasion2 PRIVATE sfml-graphics sfml-audio sfml-system sfml-window ${MRUBY_LIBRARIES} Ws2_32)
add_dependencies(InuhhShinvasion2 mruby)
