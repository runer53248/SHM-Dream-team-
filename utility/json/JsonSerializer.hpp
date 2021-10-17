#pragma once
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <optional>
#include "Json.hpp"
#include "JsonConvert.hpp"

class JsonSerializer {
public:
    static size_t getSize(const std::string& blockName);

    template <typename T>
    static std::optional<T> getValue(const std::string& blockName, const std::string& name) {
        try {
            return baseJson.at(blockName).at(name).get<T>();
        } catch (const nlohmann::json::exception& err) {
            std::cout << "\nError: get(" << std::quoted(blockName) << ", " << std::quoted(name) << ") couldn't get value from json - return null_opt.\n\n";
        }
        return {};
    }

    template <typename T>
    static std::optional<T> getValue(const std::string& blockName, size_t index, const std::string& name) {
        try {
            return baseJson.at(blockName).at(index).at(name).get<T>();
        } catch (const nlohmann::json::exception& err) {
            std::cout << "\nError: get(" << std::quoted(blockName) << ", " << index << ", " << std::quoted(name) << ") couldn't get value from json - return null_opt.\n\n";
        }
        return {};
    }

    template <typename T>
    static std::optional<T> get(const std::string& blockName, size_t index) {
        try {
            Json json = baseJson.at(blockName).at(index);
            return JsonConvert::from_json<T>(json);
        } catch (const nlohmann::json::exception& err) {
            std::cout << "\nError: get(" << std::quoted(blockName) << ", " << index << ") couldn't create object from json - return null_opt.\n\n";
        }
        return {};
    }

    template <typename T>
    static void putValue(const std::string& blockName, const std::string& name, const T& value) {
        baseJson[blockName][name] = value;
    }

    template <typename T>
    static void putValue(const std::string& blockName, size_t index, const std::string& name, const T& value) {
        baseJson[blockName][index][name] = value;
    }

    template <typename T>
    static void put(const std::string& blockName, const T& object) {
        if (!object) {
            std::cout << "\nError: put(" << std::quoted(blockName) << ") ignored - pointer to object is empty.\n\n";
            return;
        }
        try {
            Json jsonObject = JsonConvert::to_json(object);
            baseJson[blockName].push_back(convert(jsonObject));
        } catch (const nlohmann::json::exception& err) {
            std::cout << "\nError: put(" << std::quoted(blockName) << ") fail to push object into json - action ignored.\n\n";
        }
    }

    static bool save(const std::string& filename);
    static bool load(const std::string& filename);
    static void clear();

private:
    static const nlohmann::json convert(const Json& json) {
        return json.json;
    }

    static nlohmann::json baseJson;
};
