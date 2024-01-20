#include "EnemySpaceship.h"

EnemySpaceship::EnemySpaceship()
{
	if (texture.loadFromFile("Assets/EnemySpaceship.png")) {
		sprite.setTexture(texture);
		sprite.setScale(.7f, .7f);
	}
}

Vector2f EnemySpaceship::getEnemyPosition()
{
	return sprite.getPosition();
}

FloatRect EnemySpaceship::getEnemyGlobalBound()
{
	return sprite.getGlobalBounds();
}


void EnemySpaceship::draw(RenderWindow& window) {
	window.draw(sprite);
}

int EnemySpaceship::getY(int y) {
	int Random = rand() % (y - int(sprite.getGlobalBounds().height));
	return Random;
}

void EnemySpaceship::position(int x,int y)
{
	if (timer < 65) {
		timer++;
	}
	else {
		sprite.setPosition(x - sprite.getGlobalBounds().width, getY(y));
		timer = 0;
	}
}

