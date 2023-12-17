#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"Player.h"
#include"BulletPlayer.h"
#include"Enemy.h"
#include"BulletEnemy.h"
using namespace sf;
using namespace std;


class HealthBarPlayer {
public:
    RectangleShape healthBar;
    float playerLive;

    HealthBarPlayer(float x, float y) {
        playerLive = 10.f;
        healthBar.setSize(Vector2f(10.f * 20.f, 20.f));
        healthBar.setFillColor(Color::Red);
        healthBar.setPosition(x - healthBar.getSize().x - 2.f, y / 2 + 22.f);
    }
    float getLives() {
        return playerLive;
    }
    void setlives(float &lives) {
        playerLive = lives;
    }
    void setHealthBar(float &lives) {
        healthBar.setSize(Vector2f{ 20.f * lives, 20.f });

    }
    void draw(RenderWindow& window) {
        window.draw(healthBar);
    }
};




// Function for collision 
void collision(vector<Sprite>& bPlayer, vector<Sprite>& bEnemy, FloatRect &PlayerGlobalBound, FloatRect &EnemyGlobalBound, 
    float &pLive, float &eLive) {
    for (size_t i = 0; i < bPlayer.size(); i++) {
        if (EnemyGlobalBound.intersects(bPlayer[i].getGlobalBounds())) {
            eLive-=0.5;
            bPlayer.erase(bPlayer.begin() + i);
        }
    }
    for (size_t i = 0; i < bEnemy.size(); i++) {
        if (PlayerGlobalBound.intersects(bEnemy[i].getGlobalBounds())) {
            pLive -= 0.5;
            bEnemy.erase(bEnemy.begin() + i);
        }
    }
}

//for the health aaaaa
void setAttributes(RectangleShape& currElement, int what) {
    if (what == 0) {
        currElement.setFillColor(Color::Red);
    }
    else {
        currElement.setFillColor(Color:: Color(255, 165, 0));
        currElement.setSize(Vector2f(10.f * 20.f, 20.f));
    }
    
}


int main()
{
    //in renderWindow we can even select the style, size..
    RenderWindow window(VideoMode(800, 600), "SFML works!", Style::Default);


    //to avoid the frame rate to shoot up extremely we can set the frame rate to an extend
    window.setFramerateLimit(60);

    //Player
    Player player(window.getSize().x, window.getSize().y);

    //Enemy
    Enemy enemy(window.getSize().x, window.getSize().y);

    //Player Bullets
    BulletPlayer bulletPlayer;

    //Enemy bullet
    BulletEnemy bulletEnemy;


    //healthBar
    HealthBarPlayer hpBarPlayer(window.getSize().x, window.getSize().y);

    float playerLive = hpBarPlayer.getLives();
    float enemyLive = 10;
    RectangleShape hpBarEnemy;
    setAttributes(hpBarEnemy, 1);
    hpBarEnemy.setPosition(window.getSize().x - hpBarEnemy.getSize().x - 2.f, window.getSize().y / 2); 

    window.draw(hpBarPlayer.healthBar);
    while (window.isOpen() && playerLive >0 && enemyLive > 0)
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //Update
        player.movement(window.getSize().x);
        enemy.movement(window.getSize().x);

        bulletPlayer.accumulatebullets(player.playerPosition(), player.playerSize());
        bulletPlayer.update();

        bulletEnemy.accumulatebullets(enemy.EnemySize(), enemy.EnemyPosition());
        bulletEnemy.update(window.getSize().y);

        //Collision
        vector<Sprite>bPlayer = bulletPlayer.fetchBullets(bulletPlayer);
        vector<Sprite>bEnemy = bulletEnemy.fetchBullets(bulletEnemy);

        FloatRect EnemyGlobalBound = enemy.globalBound();
        FloatRect PlayerGlobalBound = player.globalBound();
        collision(bPlayer, bEnemy, PlayerGlobalBound, EnemyGlobalBound, playerLive, enemyLive);
        bulletPlayer.updatebullets(bPlayer);
        bulletEnemy.updatebullets(bEnemy);
        hpBarPlayer.setlives(playerLive);
        hpBarPlayer.setHealthBar(playerLive);
        hpBarEnemy.setSize(Vector2f{ 20.f * enemyLive, 20.f });


        // clear
        window.clear();

        // to draw
        player.draw(window);
        bulletPlayer.draw(window);
        bulletEnemy.draw(window);
        enemy.draw(window);
        hpBarPlayer.draw(window);
        window.draw(hpBarEnemy);

        window.display();
    }

    return 0;
}