cmake_minimum_required(VERSION 3.14...3.17)

project(torch-allocator VERSION "0.1")

# Define CMAKE_INSTALL_xxx: LIBDIR, INCLUDEDIR
include(GNUInstallDirs)

option( USE_CUDA ON )
add_subdirectory( c10 EXCLUDE_FROM_ALL )

add_library(c10_c_api SHARED c10_c_api.cpp)
target_link_libraries( c10_c_api PRIVATE c10 )

#message (WARNING ${LIBDIR})
install(TARGETS c10_c_api DESTINATION lib)
install(FILES c10_c_api.h DESTINATION include)
