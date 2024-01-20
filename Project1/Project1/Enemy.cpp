#include "Enemy.h"

Enemy::Enemy(){
	if (texture.loadFromFile("Assets/Enemy.png")) {
		sprite.setTexture(texture);
		sprite.setScale(0.14f, 0.14f);
	}
}

void Enemy::setEnemies(vector<Sprite> newEnemies) {
	enemies = newEnemies;
}


vector<Sprite> Enemy::getEnemies() {
	return enemies;
}


int Enemy::getY(int y) {
	int Random = rand()%(y- int(sprite.getGlobalBounds().height ));
	return Random;
}

void Enemy::draw(RenderWindow &window) {
	for(size_t i = 0; i < enemies.size(); i++)window.draw(enemies[i]);
}

void Enemy::accumulator(int x,int y) {

	if (timer < 35) {
		timer++;
	}
	else{
		int currY= getY(y );
		while ( currY == preY) {
			currY = getY(y );
		}
		sprite.setPosition(x - 5.0f, getY(y));
		enemies.push_back(sprite);
		timer = 0;
		preY = currY;
	}

}

void Enemy::mover() {
	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i].move(-10.0f, 0.0f);
		if (enemies[i].getPosition().x <= 0) {
			enemies.erase(enemies.begin() + i);
		}
	}
}