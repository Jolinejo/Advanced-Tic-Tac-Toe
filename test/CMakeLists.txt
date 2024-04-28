cmake_minimum_required(VERSION 3.5)

project(case LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if ($ENV{GOOGLETEST_DIR})
    get_filename_component(_GTEST_BASE $ENV{GOOGLETEST_DIR} REALPATH)
elseif (EXISTS "C:/Users/clt/Downloads/googletest-main (1)/googletest-main") # set by QC
    get_filename_component(_GTEST_BASE "C:/Users/clt/Downloads/googletest-main (1)/googletest-main" REALPATH) # set by QC
endif()

if (NOT GTEST_ROOT)
    if (_GTEST_BASE)
        message("Setting GTEST_ROOT to ${_GTEST_BASE}")
        set(GTEST_ROOT ${_GTEST_BASE})
    else()
        message("No GTEST_ROOT specified - using system defaults.")
    endif()
endif()

find_package(GTest REQUIRED)
if (NOT GTest_FOUND)
    message (FATAL_ERROR "No GTest Found")
endif()

add_executable(case main.cpp tst_case.cpp)
add_test(NAME case COMMAND case)

target_link_libraries(case PRIVATE GTest::GTest)
if (GMock_FOUND)
    target_link_libraries(case INTERFACE GTest::GMock)
endif()
