cmake_minimum_required(VERSION 3.14...3.17)

project(torch-allocator VERSION "0.1")

# Define CMAKE_INSTALL_xxx: LIBDIR, INCLUDEDIR
include(GNUInstallDirs)

set( USE_CUDA ON )
set (BUILD_SHARED_LIBS ON)
add_subdirectory( c10 )

add_library(c10_c_api SHARED c10_c_api.cpp)
target_link_libraries(c10_c_api PUBLIC c10_cuda)

install(TARGETS c10_c_api 
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	INCLUDES DESTINATION include
	)
install(FILES c10_c_api.h DESTINATION include)

add_subdirectory( test EXCLUDE_FROM_ALL )
