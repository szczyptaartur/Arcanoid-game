#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class Block : public Drawable
{
public:
	Block() = delete;
	Block(float t_X, float t_Y, float width, float height);
	~Block() = default;

	void setPosition();

	float right();
	float left();
	float bottom();
	float top();

	Vector2f getPosition();

private:
	RectangleShape shape;
	void draw(RenderTarget & target, RenderStates state) const override; //ta metoda jest odziedziczona 

};

