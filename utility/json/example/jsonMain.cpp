#include "../JsonSerializer.hpp"

struct Span {
    int min = 0;
    int current = 1;
    int max = 10;
};

class Ship {
public:
    std::string name = "Default";
    int speed = 0;
    int durability = 0;
    int hp = 100;
    struct Crew {
        Span number;
    };

    Crew crew;
};

template <>
Json JsonConvert::to_json(const std::unique_ptr<Ship>& object) {
    Json json;
    json.putValue("name", object->name);
    json.putValue("speed", object->speed);
    json.putValue("durability", object->durability);
    json.putValue("hp", object->hp);

    json.putBlockValue("Crew", "min", object->crew.number.min);
    json.putBlockValue("Crew", "current", object->crew.number.current);
    json.putBlockValue("Crew", "max", object->crew.number.max);

    return json;
}

template <>
std::unique_ptr<Ship> JsonConvert::from_json(const Json& json) {
    const auto name = json.getValue<std::string>("name");
    const auto speed = json.getValue<int>("speed");
    const auto durability = json.getValue<int>("durability");
    const auto hp = json.getValue<int>("hp");

    const auto min = json.getBlockValue<int>("Crew", "min");
    const auto current = json.getBlockValue<int>("Crew", "current");
    const auto max = json.getBlockValue<int>("Crew", "max");

    return std::make_unique<Ship>(Ship{
        .name = name,
        .speed = speed,
        .durability = durability,
        .hp = hp,
        .crew = {min, current, max}});
}

int main() {
    auto ship = std::make_unique<Ship>();

    JsonSerializer::put("ships", ship);

    auto isSaved = JsonSerializer::save("Ship.json");
    if(isSaved){
        std::cout << "Save success.\n";
    }

    JsonSerializer::clear();

    auto isLoaded = JsonSerializer::load("Ship.json");
    if(isLoaded){
        std::cout << "Load success.\n";
    }

    auto size = JsonSerializer::getSize("ships");

    if (size) {
        std::cout << "Number of ships in file : " << size << '\n';
        auto isShip = JsonSerializer::get<std::unique_ptr<Ship>>("ships", 0);
        if (auto ship = std::move(isShip.value())) {
            std::cout << "ship name = " << ship->name << '\n';
        }
    }

    return 0;
}
