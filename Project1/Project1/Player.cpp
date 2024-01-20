#include "Player.h"

Player:: Player() {
	if (texture.loadFromFile("Assets/Player.png")) {
		player.setTexture(texture);
		player.setScale(0.2f, 0.2f);
		player.setPosition(0.0f,50.0f);
		
	}

}

FloatRect Player::getPlayerGlobalBound() {
	return player.getGlobalBounds();
}

Vector2f Player::getPlayerPosition() {
	return player.getPosition();
}


void Player::draw(RenderWindow& window) {
	window.draw(player);
}

void Player::movement(float x, float y) {
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		if (player.getPosition().y > 0) {
			player.move(0.0f, -5.0f);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		if (player.getPosition().y + player.getGlobalBounds().height < y) {
			player.move(0.0f, 5.0f);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (player.getPosition().x + player.getGlobalBounds().width < x) {
			player.move(5.0f, 0.0f);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		if (player.getPosition().x > 0) {
			player.move(-5.0f, 0.0f);
		}
	}
}