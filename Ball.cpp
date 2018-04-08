#include "stdafx.h"
#include "Ball.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


Ball::Ball(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y); //pozycja kulki
	shape.setRadius(this->ballRadius); //wielkosc (promien) kulki
	shape.setFillColor(Color::Yellow); //ustawiamy kolor kulki
	shape.setOrigin(this->ballRadius, this->ballRadius); //przesuniecie tak jakby w miejsce naszego srodka
}

void Ball::draw(RenderTarget& target, RenderStates state) const //state to jakies dodatkowe wartosci (malo wazne)
{
	target.draw(this->shape, state);
}


float Ball::bottom()
{
	return shape.getPosition().y + shape.getRadius();
}

float Ball::top()
{
	return shape.getPosition().y - shape.getRadius();
}

float Ball::left()
{
	return shape.getPosition().x - shape.getRadius();
}

float Ball::right()
{
	return shape.getPosition().x + shape.getRadius();
}

void Ball::update()
{

	if (this->left() < 0) {
		velocity.x = ballVelocity;
	}
	else if (this->right() > 800) {
		velocity.x = -ballVelocity;
	}
	else if (this->top() < 0) {
		velocity.y = ballVelocity;
	}
	else if (this->bottom() > 600) {
		velocity.y = -ballVelocity;
	}

	shape.move(this->velocity);

}

void Ball::moveDown(float abs)
{
	this->velocity.y = sqrt((1 - abs)) * ballVelocity;
	//this->velocity.x = -sqrt(abs) * ballVelocity;
}

void Ball::moveUp(float abs)
{
	this->velocity.y = sqrt((1 - abs)) * (-ballVelocity);
	//this->velocity.x = sqrt(abs) * ballVelocity;
}

void Ball::moveLeft(float abs)
{
	this->velocity.x = sqrt(abs) * (-ballVelocity);
	//this->velocity.y = sqrt((1 - abs)) * (-ballVelocity);
}

void Ball::moveRight(float abs)
{
	this->velocity.x = sqrt((abs)) * ballVelocity;
	//this->velocity.y = sqrt((1 - abs)) * (-ballVelocity);
}

Vector2f Ball::getPosition()
{
	return shape.getPosition();
}