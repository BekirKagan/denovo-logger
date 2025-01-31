cmake_minimum_required(VERSION 3.31)
project(denovo-logger C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED on)
set(CMAKE_C_EXTENSIONS off)

add_library(${CMAKE_PROJECT_NAME} STATIC)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src/dn_logger.c)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Demo executable
add_executable(${CMAKE_PROJECT_NAME}-demo)

target_sources(${CMAKE_PROJECT_NAME}-demo PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/examples/demo.c)

target_include_directories(${CMAKE_PROJECT_NAME}-demo PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_directories(${CMAKE_PROJECT_NAME}-demo PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/build)

target_link_libraries(${CMAKE_PROJECT_NAME}-demo ${CMAKE_PROJECT_NAME})
