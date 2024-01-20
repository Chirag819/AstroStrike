#include "HealthBar.h"

HealthBar::HealthBar(int x)
{
	if (texture.loadFromFile("Assets/Hearts.png")) {
		singleLife.setTexture(texture);
		singleLife.setScale(0.06f, 0.06f);

	}

	for (size_t i = 0; i < 3; i++)
	{
		if (i == 0) {
			singleLife.setPosition(x / 2 - singleLife.getGlobalBounds().width, 1.0f);
		}
		else{
			singleLife.setPosition(lives[i-1].getPosition().x + singleLife.getGlobalBounds().width + 10.0f, 1.0f);
		}
		lives.push_back(singleLife);
	}
}


void HealthBar::setLife()
{
	lives.pop_back();
}

int HealthBar::getLife()
{
	return lives.size();
}

void HealthBar::draw(RenderWindow & window)
{
	for (size_t i = 0; i < lives.size(); i++)
	{
		window.draw(lives[i]);
	}
}



