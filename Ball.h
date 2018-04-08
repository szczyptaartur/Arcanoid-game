#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class Ball : public sf::Drawable
{
public:
	Ball(float t_X, float t_Y);
	~Ball() = default;
	Ball() = delete;
	float left();
	float right();
	float top();
	float bottom();
	
	void update();
	void moveDown(float abs=0.5);
	void moveUp(float abs=0.5);
	void moveLeft(float abs=0.5);
	void moveRight(float abs=0.5);

	Vector2f getPosition();

	const float ballRadius{ 10.0f };

private:
	CircleShape shape;
	const float ballVelocity{ 3.0f };
	Vector2f velocity{ (sqrt(2) / 2)*ballVelocity,(sqrt(2) / 2)*ballVelocity };
	void draw(RenderTarget & target, RenderStates state) const override; //ta metoda jest odziedziczona 
};

