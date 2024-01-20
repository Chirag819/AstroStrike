#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

using namespace std;
using namespace sf;

class EnemyHealthBar
{
private:
	int health = 25;
	RectangleShape bar;
	RectangleShape outerBar;


public:
	EnemyHealthBar();
	void setPos(int x, int y);
	void draw(RenderWindow& window);
	int getHealth();
	void setHealth(int health);
};

