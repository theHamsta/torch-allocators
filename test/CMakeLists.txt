project(test)

cmake_minimum_required(VERSION 3.17)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

add_executable(test
    main.cpp
    )

target_include_directories(
    test
PRIVATE
    ${CMAKE_SOURCE_DIR}
	)
target_link_libraries(
    test
PRIVATE
    c10_c_api
	)

set_target_properties(test PROPERTIES
            CXX_STANDARD 17
            CXX_EXTENSIONS OFF
            )
