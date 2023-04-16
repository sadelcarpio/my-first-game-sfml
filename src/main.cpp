#include "game.hpp"
#include "texture_holder.hpp"

int main() {
    TextureHolder textures;
    textures.load(Textures::Airplane, "../Media/Textures/Eagle.png");
    sf::Sprite playerPlane;
    playerPlane.setTexture(textures.get(Textures::Airplane));
    Game game;
    game.run();
}
