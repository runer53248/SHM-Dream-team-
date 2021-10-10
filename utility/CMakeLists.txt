# Utils
project(jsonWork)
set(CXX_STANDARD 17)

find_package(nlohmann_json 3.2.0 REQUIRED)

add_library(json-lib json/JsonSerializer.cpp json/Json.cpp)
target_link_libraries(json-lib PRIVATE nlohmann_json::nlohmann_json)
set_target_properties(json-lib PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/utility/json")
