// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include <vector>
#include <conio.h>
#include <iostream>

using namespace sf;
using namespace std;

template <class T1, class T2> bool isIntersecting(T1&A, T2&B) 
{
	return A.right() >= B.left() && A.left() <= B.right()
		&& A.top() <= B.bottom() && A.bottom() >= B.top();
}


bool collisionTest(Paddle&paddle, Ball&ball)
{
	if (!isIntersecting(paddle, ball)) return false;

	ball.moveUp(1/2);

	float distance = abs(ball.getPosition().x - paddle.getPosition().x)/(abs(ball.ballRadius-paddle.width));
	cout << distance << endl;

	if (ball.getPosition().x < paddle.getPosition().x)
	{
		ball.moveLeft(distance);
	}
	else
	{
		ball.moveRight(distance);
	}
}


bool collistionTest(Block&block, Ball&ball)
{
	if (!isIntersecting(block, ball)) return false;

	float widthPosition = block.getPosition().x - ball.getPosition().x;
	float heightPosition = ball.getPosition().y - block.getPosition().y;
	cout << widthPosition << endl;
	getchar();
	if (heightPosition > 0 && widthPosition < 0) {
		if (abs(widthPosition) > 42) ball.moveLeft();
		else ball.moveDown();
	}

	else if (heightPosition > 0 && widthPosition > 0) {
		if (abs(widthPosition) > 42) ball.moveRight();
		else ball.moveDown();
	}

	else if (heightPosition < 0 && widthPosition < 0) {
		if (abs(widthPosition) > 42) ball.moveLeft();
		else ball.moveUp();
	}

	else if (heightPosition < 0 && widthPosition > 0) {
		if (abs(widthPosition) > 42) ball.moveRight();
		else ball.moveUp();
	}

	block.setPosition();

}



int main()
{
	float height = 600, width = 800;
	Ball ball(width / 2, height/2);
	Paddle paddle(width/2 , height - 100);
	vector <Block> blocks;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			blocks.emplace_back(115+j*95,40+35*i, 90, 30);
		}
	}


	Event event;
	RenderWindow window( VideoMode(width,height),"Arcanoid" );
	window.setFramerateLimit(60);
	while (1) {
		window.clear(Color::Red);
		window.pollEvent(event);
		if (event.type == event.Closed)
		{
			window.close();
			break;
		}


		collisionTest(paddle,ball);
		for (int i = 0; i < 28; i++) {
			collistionTest(blocks[i], ball);
		}

		ball.update();
		paddle.update();

		window.draw(paddle);
		window.draw(ball);

		for (auto& block : blocks)
			window.draw(block);

		window.display();
	}
	
    return 0;
}

