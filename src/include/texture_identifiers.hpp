#pragma once

/**
 * Enum for dealing with Texture Resources
 */
namespace Textures {
    enum ID {
        Eagle,
        Raptor,
        Desert,
    };
}

template<typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;  // abreviates the first arg to the second arg
