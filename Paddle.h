#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class Paddle : public sf::Drawable
{
public:
	Paddle() = delete;
	Paddle(float t_X, float t_Y);
	~Paddle() = default;
	void update();

	Vector2f getPosition();

	float right();
	float left();
	float bottom();
	float top();

	const float width{ 80.0f };
	const float height{ 20.0f };


private:
	RectangleShape shape;
	const float paddleVelocity{ 6.0f };
	Vector2f velocity{ paddleVelocity,0.f };
	void draw(RenderTarget & target, RenderStates state) const override; //ta metoda jest odziedziczona 
};


