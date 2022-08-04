cmake_minimum_required (VERSION 3.12)

project(reflection VERSION 0.0.1 LANGUAGES CXX)

set(version 0.0.1)

find_program(CLANG_TIDY clang-tidy REQUIRED)
if(CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=google-*,bugprone-*,performance-*,portability-*,readability-*,-readability-identifier-length")
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CMAKE_SOURCE_DIR}/vs/include)

find_package(Boost 1.79.0 REQUIRED)

add_library(
   ${PROJECT_NAME} SHARED ${CMAKE_CURRENT_LIST_DIR}/vs/src/reflection/member_info.cpp
                          ${CMAKE_CURRENT_LIST_DIR}/vs/src/object.cpp
                          ${CMAKE_CURRENT_LIST_DIR}/vs/src/type.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${CONAN_LIBS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

#install(FILES ${CMAKE_CURRENT_LIST_DIR}/vs/ DESTINATION include/${PROJECT_NAME}-${version})
install(DIRECTORY vs/include/ DESTINATION include/${PROJECT_NAME} FILES_MATCHING PATTERN "*.h*")
install(TARGETS ${PROJECT_NAME}
        DESTINATION lib/${PROJECT_NAME}-${version}
        EXPORT ${PROJECT_NAME}-targets)
install(EXPORT ${PROJECT_NAME}-targets
        DESTINATION lib/${PROJECT_NAME}-${version})

configure_file(
   ${reflection_SOURCE_DIR}/pkg/${PROJECT_NAME}-config.cmake.in
   ${reflection_BINARY_DIR}/pkg/${PROJECT_NAME}-config.cmake @ONLY)

configure_file(
   ${reflection_SOURCE_DIR}/${PROJECT_NAME}-config-version.cmake.in
   ${reflection_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake @ONLY)

install(FILES ${reflection_BINARY_DIR}/pkg/${PROJECT_NAME}-config.cmake
         ${reflection_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
         DESTINATION lib/${PROJECT_NAME}-${version})