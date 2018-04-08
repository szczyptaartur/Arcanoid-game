#include "stdafx.h"
#include "Paddle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

Paddle::Paddle(float t_X,float t_Y)
{
	shape.setPosition(t_X, t_Y); //pozycja kulki
	shape.setSize(sf::Vector2f(width,height)); //wielkosc (promien) kulki
	shape.setFillColor(Color::White); //ustawiamy kolor paletki
	shape.setOrigin(this->width/2, this->height/2); //przesuniecie tak jakby w miejsce naszego srodka
}

void Paddle::draw(RenderTarget& target, RenderStates state) const //state to jakies dodatkowe wartosci (malo wazne)
{
	target.draw(this->shape, state);
}

float Paddle::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

float Paddle::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

float Paddle::left()
{
	return shape.getPosition().x - shape.getSize().x / 2.f;
}

float Paddle::right()
{
	return shape.getPosition().x + shape.getSize().x / 2.f;
}

void Paddle::update()
{
	shape.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0) {
		velocity.x = -paddleVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800) {
		velocity.x = paddleVelocity;
	}
	else {
		velocity.x = 0;
	}
}

Vector2f Paddle::getPosition()
{
	return shape.getPosition();
}