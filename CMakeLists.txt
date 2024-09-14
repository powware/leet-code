cmake_minimum_required(VERSION 3.10)

project(leet-code VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(leet_code ${SRCS})

if(MSVC)
  target_compile_options(leet_code ${TARGET_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(leet_code ${TARGET_NAME} PRIVATE -Wall -Wextra
                                                          -Wpedantic -Werror)
endif()

target_link_libraries(leet_code GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(leet_code)
