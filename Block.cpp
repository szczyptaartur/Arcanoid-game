#include "stdafx.h"
#include "Block.h"


Block::Block(float t_X, float t_Y, float width, float height)
{
	shape.setPosition(t_X, t_Y); //pozycja bloczka
	shape.setSize(sf::Vector2f(width, height)); //wielkosc bloczka
	shape.setFillColor(Color::Blue); //ustawiamy kolor bloczka
	shape.setOrigin(width / 2, height / 2); //przesuniecie tak jakby w miejsce naszego srodka
}

void Block::draw(RenderTarget& target, RenderStates state) const //state to jakies dodatkowe wartosci (malo wazne)
{
	target.draw(this->shape, state);
}



float Block::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

float Block::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

Vector2f Block::getPosition()
{
	return shape.getPosition();
}

float Block::left()
{
	return shape.getPosition().x - shape.getSize().x / 2.f;
}

float Block::right()
{
	return shape.getPosition().x + shape.getSize().x / 2.f;
}

void Block::setPosition() 
{
	shape.setPosition(-100, -100); //pozycja bloczka
}
