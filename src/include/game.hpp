#pragma once

#include <SFML/Graphics.hpp>

/**
 * Defines the game engine, the setup previous to the execution of the game, and the game loop
 */
class Game {
public:
    /**
     * Constructor. mWindow and mPlayer are passed as initialization list.
     */
    Game();

    /**
     * runs the game loop, namely, while window is open: process input/events, update game logic, and
     * render the sprites and graphic elements
     */
    void run();

private:
    /**
     * Looks for specific types of events (key pressed/released, window closed). In the case of
     * player input, delegates to Game::handlePlayerInput
     */
    void processEvents();

    /**
     * Based on the key that was pressed/released as input, updates variables to manipulate movement of player
     * @param key key code of the pressed/released key
     * @param isPressed Whether the key was pressed or released
     */
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    /**
     * updates the state of the game acording to the member variables mIsMoving...
     * @param deltaTime The constant timestep at which the game runs (1 / FPS)
     */
    void update(sf::Time deltaTime);

    /**
     * Clears the previous frame and draws and display the updated scene
     */
    void render();

private:
    sf::RenderWindow mWindow;
    sf::Texture mTexture;
    sf::Sprite mPlayer;
    bool mIsMovingUp = false, mIsMovingDown = false, mIsMovingRight = false, mIsMovingLeft = false;
    const float PlayerSpeed = 150.f;  // pixels / second
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};
