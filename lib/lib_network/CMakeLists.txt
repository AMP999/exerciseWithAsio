cmake_minimum_required(VERSION 3.21.0)

project(
  lib_network
  VERSION 0.0.1
  DESCRIPTION "A simple library to handle basic networking using ASIO"
  LANGUAGES CXX
)

set(lib_network_INCLUDE "${lib_network_DIR}/include")

add_library(lib_network INTERFACE)
target_compile_features(lib_network INTERFACE cxx_std_17)
target_include_directories(
  lib_network INTERFACE
  ${lib_network_INCLUDE}
  ${asio_INCLUDE}
)

