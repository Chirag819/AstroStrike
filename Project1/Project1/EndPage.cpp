#include "EndPage.h"

EndPage::EndPage(int x , int y)
{
	if (texture.loadFromFile("Assets/GameOver.png")) {
		sprite.setTexture(texture);
		sprite.setScale(1.2f, 1.2f);
		sprite.setPosition((x - sprite.getGlobalBounds().width) / 2, (y - sprite.getGlobalBounds().height) / 2);
	}
}

void EndPage::draw(RenderWindow& window)
{
	window.draw(sprite);
}
