#include<iostream>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "HealthBar.h"
#include "EndPage.h"
#include "StartPage.h"
#include "EnemySpaceship.h"
#include "EnemyBullet.h"
#include "EnemyHealthBar.h"

using namespace std;
using namespace sf;


void Collision(vector<Sprite>& dummyB, vector<Sprite>& dummyE, FloatRect& playerGlobalBound, bool& isHit) {
    // Collision between enemy and bullets
    for (size_t i = 0; i < dummyB.size(); i++)
    {
        for (size_t j = 0; j < dummyE.size(); j++)
        {
            if (dummyB[i].getGlobalBounds().intersects(dummyE[j].getGlobalBounds())) {
                dummyB.erase(dummyB.begin() + i);
                dummyE.erase(dummyE.begin() + j);
                break;
            }
        }
    }

    // Collision between player and enemy
    for (size_t i = 0; i < dummyE.size(); i++)
    {
        if (playerGlobalBound.intersects(dummyE[i].getGlobalBounds())) {
            dummyE.erase(dummyE.begin() + i);
            isHit = true;
            break;
        }
    }
}

int main() {

    float initialGameTimer = 10.0f;
    int screenX = 1800;
    int screenY = 900;
    float backgroundScale = 2.0f;

    RenderWindow window(VideoMode(screenX, screenY),"Window", Style::Default);
    window.setFramerateLimit(60);

    Texture backgroundTexture;
    backgroundTexture.loadFromFile("Assets/b1.jpg");
    Sprite background(backgroundTexture);
    background.setScale(backgroundScale, backgroundScale);

    Clock clock;
    Time gameTimer = clock.getElapsedTime();
    clock.restart();

    StartPage startPage(window.getSize().x, window.getSize().y);
    EndPage endPage(window.getSize().x, window.getSize().y);
    Player player;
    Bullet playerBullets;
    Enemy enemy;
    EnemySpaceship enemySpaceship;
    EnemyBullet enemyBullet;
    FloatRect enemyGlobalBound;
    
    HealthBar healthBar(window.getSize().x);
    vector<Sprite>dummyPlayerBullet, dummyEnemyBullet;
    FloatRect playerGlobalBound;
    bool isHit = false;
    bool isGameStarted = false;
    bool isGameOver = false;
    int timer = 0;

    EnemyHealthBar enemyHealthBar;

    while (window.isOpen() )
    {
        gameTimer = clock.getElapsedTime();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(isGameStarted == false) isGameStarted = startPage.isClick(window);
        if (isGameStarted && (!isGameOver)) {

            isGameStarted = true;
            player.movement(window.getSize().x, window.getSize().y);
            playerBullets.accumulator(player.getPlayerPosition(), playerGlobalBound.getSize());
            playerBullets.fire(window.getSize().x);
            if(gameTimer.asSeconds() <= initialGameTimer) enemy.accumulator(window.getSize().x, window.getSize().y);
            if (gameTimer.asSeconds() >= initialGameTimer + 2.0f) {
                enemyBullet.accumulator(enemySpaceship.getEnemyPosition(), enemySpaceship.getEnemyGlobalBound().getSize());
                enemySpaceship.position(window.getSize().x, window.getSize().y);
            }            
            enemy.mover();
            enemyBullet.fire();

            dummyEnemyBullet = enemy.getEnemies();
            dummyPlayerBullet = playerBullets.getBullets();
            playerGlobalBound = player.getPlayerGlobalBound();
            Collision(dummyPlayerBullet, dummyEnemyBullet, playerGlobalBound, isHit);
            
            if (isHit) {
                healthBar.setLife();
                isHit = 0;
            }

            enemy.setEnemies(dummyEnemyBullet);
            playerBullets.setBullets(dummyPlayerBullet);
            
            if ((gameTimer.asSeconds()>= initialGameTimer + 2.0f )) {
                enemyGlobalBound = enemySpaceship.getEnemyGlobalBound();
                dummyEnemyBullet.clear();
                Collision(dummyEnemyBullet, dummyPlayerBullet, enemyGlobalBound,  isHit);
                playerBullets.setBullets(dummyPlayerBullet);
                if (isHit) {
                    isHit = 0;
                    enemyHealthBar.setHealth(enemyHealthBar.getHealth() - 1);
                }
            }
            enemyHealthBar.setPos(enemySpaceship.getEnemyPosition().x, enemySpaceship.getEnemyPosition().y);
            dummyEnemyBullet = enemyBullet.getBullets();
            dummyPlayerBullet.clear();
            Collision(dummyPlayerBullet, dummyEnemyBullet, playerGlobalBound, isHit);
            enemyBullet.setBullets(dummyEnemyBullet);

            window.clear(Color::Black);
            window.draw(background);
            
            if (healthBar.getLife() <= 0 || (enemyHealthBar.getHealth() <= 0)) {
                endPage.draw(window);
                isGameOver = 1;
            }
            else {
                
                player.draw(window);
                playerBullets.draw(window);
                enemy.draw(window);
                if (gameTimer.asSeconds() >= initialGameTimer + 2) {
                    enemySpaceship.draw(window);
                    enemyHealthBar.draw(window);
                }
                enemyBullet.draw(window);
                healthBar.draw(window);
            }
                      
        }
        else{
            window.clear(Color::Black);
            window.draw(background);
            if (isGameOver) {

                endPage.draw(window);
            }
            else startPage.draw(window);
        }
        
        window.display();
    }
    return 0;
}