#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"Enemy.h"
using namespace sf;
using namespace std;



Enemy::Enemy(float x, float y) { //initializing the outlook of the player
	if (enemyTex.loadFromFile("Textures/enemy.png")) {
		enemy.setTexture(enemyTex);
		enemy.setScale(0.6f, 0.6f);
	}
	enemy.setPosition(x / 2 - enemy.getGlobalBounds().width / 2, 5.f);
	moveDir = { 3.f, 0.f };
}

void Enemy:: movement(float x) { //how the player will move
	enemy.move(moveDir);
	if (enemy.getPosition().x < 0 || enemy.getPosition().x > x - enemy.getGlobalBounds().width - 4.f) {
		moveDir.x = -moveDir.x;
	}
}
Vector2f Enemy:: EnemySize() {
	return { enemy.getGlobalBounds().width, enemy.getGlobalBounds().height };
}
Vector2f Enemy:: EnemyPosition() {
	return enemy.getPosition();
}
FloatRect Enemy:: globalBound() {
	return enemy.getGlobalBounds();
}
void Enemy:: draw(RenderWindow& window) {
	window.draw(enemy);
}
