cmake_minimum_required(VERSION 3.20.0)

project(exerciseWithAsio VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(lib_DIR "${CMAKE_SOURCE_DIR}/lib") 
set(lib_third_party_DIR "${lib_DIR}/third_party")
set(lib_network_DIR "${lib_DIR}/lib_network") 
set(source_DIR "${CMAKE_SOURCE_DIR}/src")

set(CMAKE_MODULE_PATH $ {CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake") 
find_package(asio REQUIRED)

add_subdirectory(${lib_network_DIR})

add_executable(playWithAsio) 
target_sources(playWithAsio PRIVATE ${source_DIR}/playWithAsio.cpp)
target_include_directories(playWithAsio PRIVATE ${asio_INCLUDE})
target_link_libraries(playWithAsio PRIVATE lib_network)
add_executable(server)
target_sources(server PRIVATE ${source_DIR}/server.cpp)
target_link_libraries(server PRIVATE lib_network)