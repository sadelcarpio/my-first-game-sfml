#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include "resource_identifiers.hpp"
#include "scene_node.hpp"
#include "resource_holder.hpp"
#include "sprite_node.hpp"
#include "aircraft.hpp"

/**
 * Class that contains the whole SceneGraph (first parent node and all children) and separates them by layers
 */
class World : private sf::NonCopyable {
public:
    /**
     * Constructor. Defines the world with the window it's goinng to be shown on
     * @param window
     */
    explicit World(sf::RenderWindow &window);

    /**
     * Updates all of its attributes, including the Scene Graph
     * @param dt The constant time per frame
     */
    void update(sf::Time dt);

    /**
     * Draws the Scene Graph on a given WorldView
     */
    void draw();

private:
    void loadTextures();

    void buildScene();

private:
    enum Layer {  // In an enum, it's default value is an autoincrement from 0
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
