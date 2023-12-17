#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"BulletEnemy.h"
using namespace sf;
using namespace std;

//initializing the outlook of the bullet
BulletEnemy::BulletEnemy() {
	if (bulletTex.loadFromFile("Textures/fire.png")) {
		singleBullet.setTexture(bulletTex);
		singleBullet.setScale(0.07f, 0.07f);
	}
	fire_Timer = 0;
}

//making a container of the bullets
void BulletEnemy:: accumulatebullets(Vector2f ESize, Vector2f EPosition) {
	if (fire_Timer < 45) {
		fire_Timer++;
	}
	if (fire_Timer >= 45) {
		fire_Timer = 0;
		Vector2f player_bottom = { EPosition.x + ESize.x / 2, EPosition.y + ESize.y / 2 };
		singleBullet.setPosition(player_bottom);
		bullets.push_back(Sprite(singleBullet));
	}
}
//firing movement of the bullets
void BulletEnemy:: update(float y) {
	for (size_t i = 0; i < bullets.size(); i++) {
		bullets[i].move(0.f, 6.f);

		if (bullets[i].getPosition().y > y - 5.f) {
			bullets.erase(bullets.begin() + i);
		}
	}
}
vector<Sprite> BulletEnemy:: fetchBullets(BulletEnemy& currBullet) {
	return currBullet.bullets;
}
void BulletEnemy:: draw(RenderWindow& window) {
	for (size_t i = 0; i < bullets.size(); i++) {
		window.draw(bullets[i]);
	}
}
//updating the bullets array after used
void BulletEnemy:: updatebullets(vector<Sprite>& dummybullets) {
	bullets = dummybullets;
}
