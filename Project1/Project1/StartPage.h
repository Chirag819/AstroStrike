#pragma once
#include<iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

using namespace std;
using namespace sf;


class StartPage
{
private:
	Texture texture;
	Sprite sprite;

public:
	StartPage(int x, int y);
	void draw(RenderWindow &window);
	bool isClick(RenderWindow &window);
};

