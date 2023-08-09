#pragma once


#include "scene_node.hpp"

/**
 * Child of SceneNode, represents an element that has a fixed Sprite that doesn't move (could be a background image)
 */
class SpriteNode : public SceneNode {
public:
    /**
     * Construct SpriteNode with a texture
     * @param texture
     */
    explicit SpriteNode(const sf::Texture &texture);

    /**
     * Construct SpriteNode with texture and textureRect which is the space the texture is going to fill.
     * @param texture
     * @param textureRect
     */
    SpriteNode(const sf::Texture &texture,
               const sf::IntRect &textureRect);

private:
    void drawCurrent(sf::RenderTarget &target,
                     sf::RenderStates states) const override;

private:
    sf::Sprite mSprite;
};
