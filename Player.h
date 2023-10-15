#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace sf;
class Player
{
public:
	Player(float x, float y);
	Vector2f getPos();
	void move(float x);
	void draw(RenderWindow& window);
private:
	RectangleShape player;
	RenderWindow window;
	Vector2f pos;
	float ypos;
};

