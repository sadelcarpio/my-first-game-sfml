#include <SFML/Graphics.hpp>

class Game {
public:
    Game();

    void run();

private:
    void processEvents();

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    void update(sf::Time deltaTime);

    void render();

private:
    sf::RenderWindow mWindow;
    sf::Texture mTexture;
    sf::Sprite mPlayer;
    bool mIsMovingUp = false, mIsMovingDown = false, mIsMovingRight = false, mIsMovingLeft = false;
    const float PlayerSpeed = 150.f;  // pixels / second
    sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};
