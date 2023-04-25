#include "include/game.hpp"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
        : mWindow(sf::VideoMode(640, 480), "World"),
          mWorld(mWindow) {  // initializer list, parentheses means the value you are initializing to
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);  // handler user input
        }
        render();  // render graphic objects
    }
}

void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {  // iteration of the Game loop (frame or tick)
        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
}

void Game::update(sf::Time elapsedTime) {
    mWorld.update(elapsedTime);
}

void Game::render() {
    mWindow.clear();
    mWorld.draw();

    mWindow.setView(mWindow.getDefaultView());
    mWindow.display();
}
