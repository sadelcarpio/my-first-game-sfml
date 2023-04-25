#include <iostream>
#include "include/resource_holder.hpp"
#include "include/resource_identifiers.hpp"
#include "include/game.hpp"

int main() {
    try {
        Game game;
        game.run();
    } catch (std::exception& e) {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
}
