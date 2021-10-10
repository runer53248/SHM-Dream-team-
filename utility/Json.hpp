#pragma once
#include <nlohmann/json.hpp>

class JsonSerializer;

class Json {
public:
    Json() = default;
    Json(nlohmann::json::initializer_list_t init);
    Json(const nlohmann::json& json);

    size_t getBlockArraySize(const std::string& blockName) const;
    size_t getArraySize(size_t index) const;

    template<typename T>
    T getValue(const std::string& name) const {
        return json[name].get<T>();
    }

    template<typename T>
    T getArrayValue(size_t index, const std::string& name) const {
        return json[index][name].get<T>();
    }

    template<typename T>
    T getBlockValue(const std::string& blockName, const std::string& name) const {
        return json[blockName][name].get<T>();
    }

    template<typename T>
    T getBlockArrayValue(const std::string& blockName, size_t index, const std::string& name) const {
        return json[blockName][index][name].get<T>();
    }

    template<typename T>
    void putValue(const std::string& name, const T& value) {
        json[name] = value;
    }

    template<typename T>
    void putArrayValue(size_t index, const std::string& name,const T& value) {
        json[index][name] = value;
    }

    template<typename T>
    void putBlockValue(const std::string& blockName, const std::string& name, const T& value) {
        json[blockName][name] = value;
    }

    template<typename T>
    void putBlockArrayValue(const std::string& blockName, size_t index, const std::string& name,const T& value) {
        json[blockName][index][name] = value;
    }

    friend JsonSerializer;

private:
    nlohmann::json json{};
};
