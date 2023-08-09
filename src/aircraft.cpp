#include "include/aircraft.hpp"
#include "include/resource_holder.hpp"

/**
 * Function that maps aircraft ids to texture ids.
 * @param type type of the aircraft
 * @return id from the texture id
 */
Textures::ID toTextureID(Aircraft::Type type) {
    switch (type) {
        case Aircraft::Eagle:
            return Textures::Eagle;

        case Aircraft::Raptor:
            return Textures::Raptor;
    }
    return Textures::Eagle;
}


Aircraft::Aircraft(Aircraft::Type type, const TextureHolder &texture) :
        mSprite(texture.get(toTextureID(type))) {
    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}
