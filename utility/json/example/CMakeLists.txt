project(jsonExample)

add_executable(json-example jsonMain.cpp)
target_link_libraries(json-example PRIVATE json-lib)
set_target_properties(json-example PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/utility/json/example")