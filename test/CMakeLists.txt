include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG release-1.11.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(sample_test sample-ut.cpp)
target_link_libraries(sample_test gtest_main)
set_target_properties(sample_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test")

include(GoogleTest)
gtest_discover_tests(sample_test)
