#include "Json.hpp"

Json::Json(nlohmann::json::initializer_list_t init)
    : json(init) {}
Json::Json(const nlohmann::json& json)
    : json(json) {}

size_t Json::getBlockArraySize(const std::string& blockName) const {
    return json.at(blockName).size();
}

size_t Json::getArraySize() const {
    return json.size();
}