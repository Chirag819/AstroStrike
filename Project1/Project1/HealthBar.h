#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

using namespace std;
using namespace sf;

class HealthBar
{
private:
	vector<Sprite> lives;
	Sprite singleLife;
	Texture texture;

public:
	HealthBar(int x);
	void setLife();
	int getLife();
	void draw(RenderWindow& window);


};

