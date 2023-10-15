#include "Player.h"
Player::Player(float x, float y)
{
	player.setFillColor(sf::Color::Red);
	ypos = y - 20;
	pos = Vector2f(x/2, ypos);
	player.setSize(Vector2f(10.0f,15.0f));
}

void Player::draw(RenderWindow& window)
{
	player.setPosition(getPos());
	window.draw(player);
}

void Player::move(float x)
{
	pos = Vector2f(x, ypos);
}

Vector2f Player::getPos()
{
	return pos;
}