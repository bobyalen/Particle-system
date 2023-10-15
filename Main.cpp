#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ParticleSystem.h"

int main()
{
    // Create the main window
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Particles");
    window.setFramerateLimit(60);
    bool draw = false();
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    Player player(window.getSize().x, window.getSize().y);
    ParticleSystem particles("assets/blob.png");

    while (window.isOpen())
    {
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        player.move(mouse.x);
        player.draw(window);
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                particles.Set(player.getPos(), sf::Vector2f(0.0f,(std::rand() % -100) - 200.0f));
                particles.exploded = false;
            }
        }
        particles.shoot(1.0f/60.0f, window);
        if (particles.exploded == false)
        {
            if (particles.Expand(particles.POIpos()))
            {
                particles.fix(Vector2f(0.0f, 0.0f));
                particles.Spawn(particles.POIpos());
                particles.exploded = true;
            }
        }

        particles.Update(1.0f/60.0f);
        particles.Draw(window);
        window.display();

        window.clear();
    }
    return EXIT_SUCCESS;
}
