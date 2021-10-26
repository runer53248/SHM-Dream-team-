#pragma once

#include <memory>

//example implementation to show load from json
class Player {
public:
    //will load data from global json
    static std::unique_ptr<Player> create();

    ~Player();

    size_t getMoney() const;
    std::string getName() const;

    void setMoney( size_t money );
    void setName( std::string name );

private:
    Player();

    size_t money_;
    std::string name_;
};
