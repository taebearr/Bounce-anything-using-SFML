#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bouncing Cat");
    window.setFramerateLimit(60);

    sf::Texture catTexture;
    if (!catTexture.loadFromFile("cat5.PNG"))
    {
        std::cerr << "Error loading cat image.\n";
        return -1;
    }

    sf::Sprite catSprite(catTexture);
    catSprite.setPosition(100.0f, 100.0f);
    float catSpeedX = 3.0f;
    float catSpeedY = 2.0f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Move the cat
        catSprite.move(catSpeedX, catSpeedY);

        // Check for collisions with window boundaries
        if (catSprite.getPosition().x < 0 || catSprite.getPosition().x + catSprite.getGlobalBounds().width > window.getSize().x)
        {
            // Reverse X direction to bounce back
            catSpeedX = -catSpeedX;
        }

        if (catSprite.getPosition().y < 0 || catSprite.getPosition().y + catSprite.getGlobalBounds().height > window.getSize().y)
        {
            // Reverse Y direction to bounce back
            catSpeedY = -catSpeedY;
        }

        window.clear();
        window.draw(catSprite);
        window.display();
    }

    return 0;
}