#include "Bullet.h"


Bullet::Bullet() {
	if (texture.loadFromFile("Assets/Bullet.png")) {
		sprite.setTexture(texture);
		sprite.setScale(0.03f, 0.03f);
	}
}


void Bullet::setBullets(vector<Sprite> newBullets) {
	bullets = newBullets;
}
vector<Sprite> Bullet::getBullets() {
	return bullets;
}


void Bullet::draw(RenderWindow& window) {
	for(int i = 0; i < bullets.size(); i++)window.draw(bullets[i]);
}

void Bullet::accumulator(Vector2f Pposition, Vector2f Psize) {
	if (fireTimer < 25) fireTimer++;


	if (Mouse::isButtonPressed(Mouse::Left) && (fireTimer >= 25) ){
		sprite.setPosition(Pposition.x + Psize.x, Pposition.y + (Psize.y / 2));
		bullets.push_back(Sprite(sprite));
		fireTimer = 0;

	}
}

void Bullet::fire(int x) {
	
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].move(10.0f, 0.0f);
		if (bullets[i].getPosition().x > x) {
			bullets.erase(bullets.begin() + i);
		}
	}
}

