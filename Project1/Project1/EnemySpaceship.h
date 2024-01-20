#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <cstdlib> 

using namespace std;
using namespace sf;

class EnemySpaceship
{
private:
	//public:
	Sprite sprite;
	Texture texture;
	int timer = 65;

public:
	EnemySpaceship();
	Vector2f getEnemyPosition();
	FloatRect getEnemyGlobalBound();
	void draw(RenderWindow& window);
	int getY(int y);
	void position(int x, int y);
};


