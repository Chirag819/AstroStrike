#include "EnemyBullet.h"


EnemyBullet::EnemyBullet() {
	if (texture.loadFromFile("Assets/EnemyBullet.png")) {
		sprite.setTexture(texture);
		sprite.setScale(0.1f, 0.1f);
	}
}


void EnemyBullet::setBullets(vector<Sprite> newBullets) {
	bullets = newBullets;
}
vector<Sprite> EnemyBullet::getBullets() {
	return bullets;
}


void EnemyBullet::draw(RenderWindow& window) {
	for (int i = 0; i < bullets.size(); i++)window.draw(bullets[i]);
}

void EnemyBullet::accumulator(Vector2f Pposition, Vector2f Psize) {
	if (fireTimer < 25) fireTimer++;


	if (fireTimer >= 25) {
		sprite.setPosition(Pposition.x , Pposition.y + (Psize.y/2) - 20.0f);
		bullets.push_back(Sprite(sprite));
		fireTimer = 0;
	}
}

void EnemyBullet::fire() {

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].move(-15.0f, 0.0f);
		if (bullets[i].getPosition().x <= 0) {
			bullets.erase(bullets.begin() + i);
		}
	}
}

