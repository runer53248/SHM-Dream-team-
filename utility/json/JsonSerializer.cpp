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

bool JsonSerializer::save(const std::string& filename) {
    try {
        std::ofstream file(filename);
        file << baseJson.dump(2);
        return true;
    } catch (const nlohmann::json::exception& err){
        std::cout << "\nError: json throw when dump.\n\n";
    } catch (const std::ios_base::failure& e){
        std::cout << "\nError: JsonSerializer::save caught an ios_base::failure.\n"
                  << "Explanatory string: " << e.what() << ".\n\n";
    }

    return false;
}

bool JsonSerializer::load(const std::string& filename) {
    try{
        std::ifstream file(filename);
        file >> baseJson;
        return true;
    } catch (const nlohmann::json::exception& err){
        std::cout << "\nError: couldn't load json from file: " << filename << ".\n\n";
    } catch (const std::ios_base::failure& e){
        std::cout << "\nError: JsonSerializer::load caught an ios_base::failure.\n"
                  << "Explanatory string: " << e.what() << ".\n\n";
    }

    return false;
}

void JsonSerializer::clear() {
    baseJson.clear();
}
