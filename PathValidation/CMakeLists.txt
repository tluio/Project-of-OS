cmake_minimum_required(VERSION 3.1)
add_library(PathValidation
	PathValidation.cpp
	)

if(USE_ASAN)
	SET(CMAKE_CXX_FLAGS "-std=c++11 -fno-rtti -Wall -lz3 -g -fsanitize=address")
	target_link_libraries(AliasAnalyzer asan)
elseif(USE_DEBUG)
	SET(CMAKE_CXX_FLAGS "-std=c++11 -fno-rtti -g -Wall -lz3")
else()
	SET(CMAKE_CXX_FLAGS "-std=c++11 -fno-rtti -Wall -lz3")
endif()
