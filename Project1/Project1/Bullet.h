#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"


using namespace std;
using namespace sf;

class Bullet
{
private:
//public:
	int fireTimer = 25;
	Texture texture;
	Sprite sprite;
	vector<Sprite> bullets;
public:
	Bullet();
	void setBullets(vector<Sprite> newBullets);
	vector<Sprite> getBullets();
	void accumulator(Vector2f Ppos, Vector2f Psize);
	void draw(RenderWindow& window);
	void fire(int x);

};

