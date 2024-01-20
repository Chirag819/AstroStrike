#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include <cstdlib> 

using namespace std;
using namespace sf;

class Enemy
{
private:
//public:
	Sprite sprite;
	Texture texture;
	vector<Sprite> enemies;
	int timer = 35;
	int preY = -10;

public:
	Enemy();
	void setEnemies(vector<Sprite> newEnemies);
	vector<Sprite> getEnemies();
	void draw(RenderWindow& window);
	void accumulator(int x,int y);
	int getY(int y);
	void mover();

};

