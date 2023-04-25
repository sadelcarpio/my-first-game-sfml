#include <iostream>
#include "include/resource_holder.hpp"
#include "include/texture_identifiers.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application", sf::Style::Close);
    window.setFramerateLimit(20);

    // Try to load resources
    ResourceHolder<sf::Texture, Textures::ID> textures;
    try {
        textures.load(Textures::Desert, "../Media/Textures/Desert.png");
        textures.load(Textures::Eagle, "../Media/Textures/Eagle.png");
    }
    catch (std::runtime_error &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return 1;
    }

    // Access resources
    sf::Sprite landscape(textures.get(Textures::Desert));
    sf::Sprite airplane(textures.get(Textures::Eagle));
    airplane.setPosition(200.f, 200.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::Closed)
                return 0;
        }

        window.clear();
        window.draw(landscape);
        window.draw(airplane);
        window.display();
    }
}
