#include <cassert>
#include "texture_holder.hpp"

void TextureHolder::load(Textures::ID id, const std::string &filename) {
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    if (!texture->loadFromFile(filename))
        throw std::runtime_error("TextureHolder::load - Failed to load " + filename);
    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);  // assert that second element is true (element was successfully inserted. only works in debug
}

sf::Texture& TextureHolder::get(Textures::ID id) {
    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end());
    return *found->second;
}

const sf::Texture &TextureHolder::get(Textures::ID id) const {
    auto found = mTextureMap.find(id);
    assert(found != mTextureMap.end());
    return *found->second;
}
