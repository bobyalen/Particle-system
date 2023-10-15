#include "Particle.h"
#include <iostream>
#include <random>
#include <cmath>
class ParticleSystem
{
    Texture texture;
    const static int numParticles = 1000;
    Particle particles[numParticles];
    Particle POI;

public:
    bool exploded = true;

    ParticleSystem(const string& textureFile)
    {
        if (!texture.loadFromFile(textureFile))
            cerr << "Failed to load texture " << textureFile << endl;
    }

    void Spawn(Vector2f pos)
    {
        for (int i = 0; i < numParticles; i++)
        {
            particles[i].setPos(pos);
            float angle = (float)rand() / RAND_MAX * 360;
            sf::Vector2f velocity = sf::Vector2f(100 * cos(angle), 100 * sin(angle));
            particles[i].setVel(velocity);
        }
    }

    void fix(Vector2f vel)
    {
        POI.setVel(vel);
    }

    bool Expand(Vector2f pos)
    {
        if (pos.y <=350)
        {
            return true;
        }
        return false;
    }

    void Update(float deltaTime)
    {
        for (int i = 0; i < numParticles; i++)
        {
            particles[i].Update(deltaTime);
            if (range(i))
            {
                sf::Vector2f pos = POI.getPos();
                particles[i].Reset(pos);
            }
        }
    }

    bool range(int i)
    {
        random_device rng;
        uniform_real_distribution<float> dist(0.0f, 1.0f);
        float radius = 100.0f + 400.0f * dist(rng);;
        float dx = POI.getPos().x - particles[i].getPos().x;
        float dy = POI.getPos().y - particles[i].getPos().y;
        float distance = sqrt(dx * dx + dy * dy);
        if (distance > radius)
        {
            return true;
        }
        return false;
    }


    void Set(Vector2f pos, Vector2f vel)
    {
        POI.setPos(pos);
        POI.setVel(vel);

    }

    void shoot(float deltaTime, RenderWindow& window)
    {
        POI.Update(deltaTime);
        Sprite sprite(texture);
        sprite.setScale(Vector2f(0.1f, 0.1f));
        sprite.setColor(Color(255, 64, 64));
        sprite.setPosition(POI.getPos());
        window.draw(sprite, BlendAdd);

    }

    Vector2f POIpos()
    {
        return POI.getPos();
    }

    void Draw(RenderWindow& window)
    {
        Sprite sprite(texture);
        sprite.setScale(Vector2f(0.1f, 0.1f));
        sprite.setColor(particles->colour);
        for (int i = 0; i < numParticles; i++)
        {
            sprite.setPosition(particles[i].getPos());
            window.draw(sprite, BlendAdd);
        }
    }
};