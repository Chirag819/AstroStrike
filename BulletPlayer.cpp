#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"BulletPlayer.h"
using namespace sf;
using namespace std;


//initializing the outlook of the bullet
BulletPlayer::BulletPlayer() {
	if (bulletTex.loadFromFile("Textures/bullet.png")) {
		singleBullet.setTexture(bulletTex);
		singleBullet.setScale(0.2f, 0.2f);
	}
	fire_Timer = 0;
}
//making a container of the bullets
void BulletPlayer::accumulatebullets(Vector2f Pposition, Vector2f PSize) {
	if (fire_Timer < 10) {
		fire_Timer++;
	}
	if (Mouse::isButtonPressed(Mouse::Left) && fire_Timer >= 10) {
		fire_Timer = 0;
		Vector2f player_top = { Pposition.x + PSize.x / 2, Pposition.y };
		singleBullet.setPosition(player_top);
		bullets.push_back(Sprite(singleBullet));
	}
}
//firing movement of the bullets
void BulletPlayer::update() {
	for (size_t i = 0; i < bullets.size(); i++) {
		bullets[i].move(0.f, -10.f);

		if (bullets[i].getPosition().y <= 10) {
			bullets.erase(bullets.begin() + i);
		}
	}
}
vector<Sprite> BulletPlayer::fetchBullets(BulletPlayer& currBullet) {
	return currBullet.bullets;
}
//updating the bullets array after used
void BulletPlayer::updatebullets(vector<Sprite>& dummybullets) {
	bullets = dummybullets;
}
void BulletPlayer::draw(RenderWindow& window) {
	for (size_t i = 0; i < bullets.size(); i++) {
		window.draw(bullets[i]);
	}
}
