cmake_minimum_required(VERSION 2.6)
project(MScThesisBenchmarks)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# dependencies
find_package(Armadillo REQUIRED)
if (UNIX)
	if (NOT APPLE)
		find_library(RT_LIBRARY rt)
		if (NOT RT_LIBRARY)
			message(FATAL_ERROR "Could not find librt")
		endif()
	endif()
endif()


include_directories(include ${ARMADILLO_INCLUDE_DIRS})

add_subdirectory(src)
