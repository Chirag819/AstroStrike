#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

using namespace std;
using namespace sf;

class Player {
private:
	Texture texture;
	Sprite player;
	int score = 0;

public:
	Player();
	Vector2f getPlayerPosition();
	FloatRect getPlayerGlobalBound();
	void draw(RenderWindow &window);
	void movement(float x, float y);
};