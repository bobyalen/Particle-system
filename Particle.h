#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class ParticleSystem;


class Particle
{
	class ParticleSystem;
	Vector2f pos;
	Vector2f vel;

	public:
		Particle();
		void Update(float deltaTime);
		void setPos(Vector2f& newPos);
		void setVel(Vector2f& newVel);
		void fly();
		void Reset(Vector2f pos);

		Vector2f getPos();
		Vector2f getVel();
		Color colour;
};



