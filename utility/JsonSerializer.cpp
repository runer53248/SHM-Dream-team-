#include "JsonSerializer.hpp"

nlohmann::json JsonSerializer::baseJson{};

size_t JsonSerializer::getSize(const std::string& blockName) {
    try {
        return baseJson.at(blockName).size();
    } catch (const nlohmann::json::exception& err) {
        std::cout << "\nError: getSize(" << std::quoted(blockName) << ") couldn't throw - return 0.\n\n";
    }
    return 0;
}

void JsonSerializer::save(const std::string& filename){
    std::ofstream file(filename);
    file << baseJson.dump(2);
}

void JsonSerializer::load(const std::string& filename){
    std::ifstream file(filename);
    file >> baseJson;
}

void JsonSerializer::clear() {
    baseJson.clear();
}