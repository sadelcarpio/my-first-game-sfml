#pragma once

#include "entity.hpp"
#include "resource_identifiers.hpp"

/**
 * Inherits from Entity. Aircraft that will move around the screen.
 */
class Aircraft : public Entity {
public:
    enum Type {
        Eagle,
        Raptor,
    };

public:
    /**
     * Construct an Aircraft with the following type and its sprite (texture)
     * @param type
     * @param texture
     */
    explicit Aircraft(Type type, const TextureHolder &texture);

    void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::Sprite mSprite;
};
