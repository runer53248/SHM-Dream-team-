find_package(nlohmann_json 3.2.0 REQUIRED)

add_library(json-lib JsonSerializer.cpp Json.cpp)
target_link_libraries(json-lib PRIVATE nlohmann_json::nlohmann_json)

add_subdirectory(example)
