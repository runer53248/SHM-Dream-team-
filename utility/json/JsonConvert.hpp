#pragma once
#include <nlohmann/json.hpp>

class JsonSerializer;
class Json;

class JsonConvert {
    friend JsonSerializer;

private:
    template <typename T>
    static T from_json(const Json& j) {
        throw nlohmann::json::exception("Error: try to use from_json to unimplemmented type.");
    }

    template <typename T>
    static Json to_json(const T& object) {
        throw nlohmann::json::exception("Error: try to use to_json to unimplemmented type.");
    }
};