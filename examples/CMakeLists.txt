cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project(EasyDSP-Examples VERSION 0.0.0 LANGUAGES CXX)

add_executable(edsp-library-info library_info.cpp)
target_link_libraries(edsp-library-info pthread ${EDSP_LIBRARIES} )
