#pragma once

#include "entity.hpp"
#include "resource_identifiers.hpp"

class Aircraft : public Entity {
public:
    enum Type {
        Eagle,
        Raptor,
    };

public:
    explicit Aircraft(Type type, const TextureHolder &textures);

    void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    Type mType;
    sf::Sprite mSprite;
};
