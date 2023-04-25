#pragma once

#include "scene_node.hpp"

class Entity : public SceneNode {
public:
    void setVelocity(sf::Vector2f velocity);

    void setVelocity(float vx, float vy);

    sf::Vector2f getVelocity() const;

private:
    void updateCurrent(sf::Time dt) override {
        move(mVelocity * dt.asSeconds());
    }

private:
    sf::Vector2f mVelocity;
};
