#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

using namespace std;
using namespace sf;


class EndPage
{
private:
	Texture texture;
	Sprite sprite;

public:
	EndPage(int x, int y);
	void draw(RenderWindow& window);
};

