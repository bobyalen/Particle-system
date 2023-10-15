#include "ParticleSystem.h"
#include "Particle.h"


Particle::Particle()
{
}
void Particle::Update(float deltaTime)
{
    pos += vel * deltaTime;
}

void Particle::setPos(Vector2f& newPos)
{
    pos.x = newPos.x + 5;
    pos.y = newPos.y;
}

void Particle::setVel(Vector2f& newVel)
{
    vel = newVel;
}

void Particle::Reset(Vector2f newPos)
{
    random_device rng;
    uniform_real_distribution<float> dist(0.0f, 1.0f);
    pos = newPos;

    float angle = (float)rand() / RAND_MAX * 360;
    sf::Vector2f velocity = sf::Vector2f(100 * cos(angle), 100 * sin(angle));
    vel = velocity;
    colour = sf::Color(rand() % 255, rand() % 255, rand() % 255);
}

void Particle::fly()
{
    pos = Vector2f(pos.x, pos.y - 25);
}



Vector2f Particle::getPos()
{
    return pos;
}


Vector2f Particle::getVel()
{
    return vel;
}
