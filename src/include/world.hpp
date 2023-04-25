#pragma once

#include <SFML/Graphics.hpp>
#include "resource_identifiers.hpp"
#include "scene_node.hpp"
#include "resource_holder.hpp"
#include "sprite_node.hpp"
#include "aircraft.hpp"

class World : private sf::NonCopyable {
public:
    explicit World(sf::RenderWindow &window);

    void update(sf::Time dt);

    void draw();

private:
    void loadTextures();

    void buildScene();

private:
    enum Layer {
        Background,
        Air,
        LayerCount,
    };

private:
    sf::RenderWindow &mWindow;
    sf::View mWorldView;
    TextureHolder mTextures;
    SceneNode mSceneGraph;
    std::array<SceneNode *, LayerCount> mSceneLayers;

    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;
    Aircraft *mPlayerAircraft;
};
