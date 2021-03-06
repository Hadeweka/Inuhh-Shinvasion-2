﻿# Minimum cmake version
cmake_minimum_required(VERSION 3.5)

set(CMAKE_SHARED_LINKER_FLAGS
    "${CMAKE_SHARED_LINKER_FLAGS}")

set(CMAKE_EXE_LINKER_FLAGS
    "${CMAKE_EXE_LINKER_FLAGS}")

add_definitions(-DMRB_USE_FLOAT)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

# Project name
project(InuhhShinvasion2)
set(EXECUTABLE_NAME "InuhhShinvasion2")

# C++ Standard

set(CMAKE_CXX_STANDARD 17)

# Check Ruby and mRuby dependencies

find_program(RUBY_EXECUTABLE ruby) 
find_program(BISON_EXECUTABLE bison)

# Load mRuby

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

# Load SFML libraries

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory(SFML)

# If this is a debug build, copy the ruby files to the build directory
# Otherwise compile them to bytecode

include_directories(${CMAKE_BINARY_DIR})

file(GLOB RUBYSCRIPTS "${CMAKE_SOURCE_DIR}/scripts/*.rb")

set(RUBY_COMPILED_TARGETS "")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")

	install(DIRECTORY DESTINATION ${CMAKE_BINARY_DIR}/scripts)

endif()

foreach(RUBYSCRIPT ${RUBYSCRIPTS})

	get_filename_component(COMPILED_SCRIPT ${RUBYSCRIPT} NAME_WE)

	if(CMAKE_BUILD_TYPE STREQUAL "Debug")

		configure_file(
			${RUBYSCRIPT}
			${CMAKE_BINARY_DIR}/scripts/${COMPILED_SCRIPT}.rb
		COPYONLY)

	else()

		add_custom_target(Target${COMPILED_SCRIPT}
			COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/compiled_scripts
			COMMAND ${CMAKE_BINARY_DIR}/mruby/bin/mrbc -Bcompiled_ruby_${COMPILED_SCRIPT} -o ${CMAKE_BINARY_DIR}/compiled_scripts/${COMPILED_SCRIPT}.h ${RUBYSCRIPT}
			DEPENDS ${RUBYSCRIPT} mruby
			VERBATIM
		)

		set(RUBY_COMPILED_TARGETS Target${COMPILED_SCRIPT} ${RUBY_COMPILED_TARGETS})
		
	endif()

endforeach(RUBYSCRIPT)

# Source files

set(GRAPHICS_SOURCES
	Shidacea/graphics/ResourceManager.cpp
	Shidacea/graphics/Window.cpp
	Shidacea/graphics/Texture.cpp
)

set(MAP_SOURCES
)

set(CORE_SOURCES
	Shidacea/core/Coordinates.cpp
	Shidacea/core/CoreEntity.cpp
)

set(SCRIPTING_SOURCES
	Shidacea/scripting/Helper.cpp
)

include_directories(
	Shidacea/core 
	Shidacea/graphics
	Shidacea/map
	Shidacea/scripting
)

# Load source files

set(SOURCES 
	${GRAPHICS_SOURCES}
	${MAP_SOURCES}
	${CORE_SOURCES}
	${SCRIPTING_SOURCES}
	Main.cpp
)

# Create executable and link libraries

add_executable(${EXECUTABLE_NAME} ${SOURCES})
add_dependencies(${EXECUTABLE_NAME} mruby ${RUBY_COMPILED_TARGETS})
target_link_libraries(${EXECUTABLE_NAME} ${MRUBY_LIBRARIES} sfml-main sfml-system sfml-window sfml-graphics sfml-audio Ws2_32)
