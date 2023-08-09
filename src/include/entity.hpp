#pragma once

#include "scene_node.hpp"

/**
 * Element of the game that can be drawn and moved on the screen.
 */
class Entity : public SceneNode {
public:
    /**
     * Set velocity of Entity by providing a velocity vector
     * @param velocity
     */
    void setVelocity(sf::Vector2f velocity);

    /**
     * Set velocity by providing vx and vy components
     * @param vx
     * @param vy
     */
    void setVelocity(float vx, float vy);

    /**
     * Get current Entity velocity
     * @return Entity's velocity
     */
    sf::Vector2f getVelocity() const;

private:
    void updateCurrent(sf::Time dt) override;

private:
    sf::Vector2f mVelocity;
};
