cmake_minimum_required (VERSION 3.12)

project(reflection_test VERSION 0.0.1 LANGUAGES CXX)

find_program(CLANG_TIDY clang-tidy REQUIRED)
if(CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=google-*,bugprone-*,performance-*,portability-*,readability-*,-readability-identifier-length")
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CMAKE_SOURCE_DIR})

add_executable(
   ${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/TypeTest.cpp)

find_package(reflection REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CONAN_LIBS} reflection)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)