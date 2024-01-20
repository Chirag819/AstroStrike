#include "StartPage.h"

StartPage::StartPage(int x, int y)
{
	if (texture.loadFromFile("Assets/Start.png")) {
		sprite.setTexture(texture);
		sprite.setScale(1.2f, 1.2f);
		sprite.setPosition((x - sprite.getGlobalBounds().width)/2, (y - sprite.getGlobalBounds().height)/ 2);
	}
}


void StartPage::draw(RenderWindow& window)
{
	window.draw(sprite);
}

bool StartPage::isClick(RenderWindow& window)
{
	int sizeX = (window.getSize().x - sprite.getGlobalBounds().width) / 2, sizeY =  (window.getSize().y - sprite.getGlobalBounds().height)/ 2;
	int endX = sprite.getGlobalBounds().width + sizeX, endY = sprite.getGlobalBounds().height + sizeY;
	if( (Mouse::getPosition(window).x >= sizeX) && (Mouse::getPosition(window).x <= endX ) && 
		(Mouse::getPosition(window).y >= sizeY) && (Mouse::getPosition(window).y <= endY) &&
		(Mouse::isButtonPressed(Mouse::Left))) {
		return true;
	}
	return false;
}


