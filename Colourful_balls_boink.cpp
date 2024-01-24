#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

class Shape
{
    std::string s_name = "";
    std::string sn = "";
    float x = 0.0f;
    float y = 0.0f;
    float sx = 0.0f;
    float sy = 0.0f;
    int r = 0;
    int g = 0;
    int b = 0;
    float w = 0.0f;
    float h = 0.0f;
    float radius = 0.0f;

public:
    Shape() {}

    Shape(const std::string& name, const std::string& sN, float xPos, float yPos, float scaleX, float scaleY,
        int red, int green, int blue, float width, float height, float circleRadius)
        : s_name(name), sn(sN), x(xPos), y(yPos), sx(scaleX), sy(scaleY),
        r(red), g(green), b(blue), w(width), h(height), radius(circleRadius)
    {}

    static std::vector<Shape> loadFromFile(const std::string& filename)
    {
        std::vector<Shape> shapes;

        std::ifstream fin(filename);

        if (!fin.is_open())
        {
            std::cerr << "Error opening file: " << filename << "\n";
            return shapes;
        }

        Shape tempShape;
        while (fin >> tempShape.s_name >> tempShape.sn >> tempShape.x >> tempShape.y >> tempShape.sx >> tempShape.sy
            >> tempShape.r >> tempShape.g >> tempShape.b >> tempShape.w >> tempShape.h >> tempShape.radius)
        {
            shapes.push_back(tempShape);
        }

        fin.close();
        return shapes;
    }

    void createAndDisplayShape(sf::RenderWindow& window)
    {
        std::unique_ptr<sf::Shape> shape;

        if (s_name == "Circle")
        {
            shape = std::make_unique<sf::CircleShape>(radius);
        }
        else if (s_name == "Rectangle")
        {
            shape = std::make_unique<sf::RectangleShape>(sf::Vector2f(w, h));
        }

        if (shape)
        {
            shape->setFillColor(sf::Color(r, g, b));
            shape->setPosition(x, y);
            shape->setOutlineColor(sf::Color::White);
            shape->setOutlineThickness(2.0f);
            shape->setPosition(x, y);


            std::cout << "Displaying shape: " << s_name << " at (" << x << ", " << y << ")\n";

            // Display shape name in the center of shape
            sf::Font font;
            if (font.loadFromFile("MondayFeelings-7BD2l.ttf"))
            {
                sf::Text text(sn, font, 20);
                text.setFillColor(sf::Color::Black);
                text.setPosition(x + (shape->getGlobalBounds().width - text.getGlobalBounds().width) / 2,
                    y + (shape->getGlobalBounds().height - text.getGlobalBounds().height) / 2);
                window.draw(*shape);
                window.draw(text);
            }
            else
            {
                std::cerr << "Could not load font!!\n";
            }

        }
    }

    std::string getName() const
    {
        return s_name;
    }

    float getX() const
    {
        return x;
    }

    float getY() const
    {
        return y;
    }

    float getSpeedX() const
    {
        return sx;
    }

    float getWidth() const
    {
        return w;
    }

    float getHeight() const
    {
        return h;
    }

    float getSpeedY() const
    {
        return sy;
    }

    void setX(float newX)
    {
        x = newX;
    }

    void setY(float newY)
    {
        y = newY;
    }

    void setSpeedX(float newSpeedX)
    {
        sx = newSpeedX;
    }

    void setSpeedY(float newSpeedY)
    {
        sy = newSpeedY;
    }
};

int main(int argc, char* argv[])
{
    const int wWidth = 800;
    const int wHeight = 600;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Boink!\n");
    window.setFramerateLimit(60);

    std::vector<Shape> shapes = Shape::loadFromFile("config.txt");
    std::cout << "Number of shapes loaded: " << shapes.size() << "\n";

    sf::Font myFont;
    if (!myFont.loadFromFile("BabyPlums-6Y0AD.ttf"))
    {
        std::cerr << "Could not load font!\n";
        return -1;
    }

    sf::Text text("Shapes Bouncing Game", myFont, 24);

    // main loop - main window is open
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                std::cout << "Key pressed with code = " << event.key.code << "\n";

                if (event.key.code == sf::Keyboard::X)
                {
                    //circleMoveSpeed *= -1.0f;
                }
            }
        }

        for (auto& shape : shapes)
        {
            // Move each shape in the x and y directions
            float newX = shape.getX() - shape.getSpeedX();
            float newY = shape.getY() - shape.getSpeedY();

            // Check for collisions with window boundaries
            if (newX < 0 || newX + shape.getWidth() > window.getSize().x - 40)
            {
                // Reverse X direction to bounce back
                shape.setSpeedX(-shape.getSpeedX());
            }

            if (newY < 0 || newY + shape.getHeight() > window.getSize().y - 40)
            {
                // Reverse Y direction to bounce back
                shape.setSpeedY(-shape.getSpeedY());
            }

            // Update positions
            shape.setX(newX);
            shape.setY(newY);

            std::cout << "Create and display shape: " << shape.getName() << "\n";
            shape.createAndDisplayShape(window);
        }

        window.draw(text);
        window.display();
    }
    return 0;
}