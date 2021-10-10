# Utils
project(jsonWork)
set(CXX_STANDARD 17)

find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(json jsonMain.cpp JsonSerializer.cpp Json.cpp)
target_link_libraries(json PRIVATE nlohmann_json::nlohmann_json)
set_target_properties(json PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/utility")
