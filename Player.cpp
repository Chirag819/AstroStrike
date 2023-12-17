#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"Player.h"
using namespace sf;
using namespace std;
//initializing the outlook of the player
    Player::Player(float x, float y) { 
        if (playerTex.loadFromFile("Textures/rocky.png")) {
            player.setTexture(playerTex);
            player.setScale(0.15f, 0.15f);
        }
        player.setPosition(x / 2 - player.getGlobalBounds().width / 2, y - player.getGlobalBounds().height - 5.f);

    }

    //how the player will move
    void Player::movement(float x) {
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            if (player.getPosition().x > 0) {
                player.move(-5.f, 0);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            if (player.getPosition().x + player.getGlobalBounds().width < x) {
                player.move(5.f, 0);
            }
        }
    }
    Vector2f Player::playerPosition() {
        return player.getPosition();
    }
    Vector2f Player::playerSize() {
        return { player.getGlobalBounds().width, player.getGlobalBounds().height };
    }
    //returns the all four vertices of the Sprite
    FloatRect Player::globalBound() {
        return player.getGlobalBounds();
    }
    void Player::draw(RenderWindow& window) {
        window.draw(player);
    }
