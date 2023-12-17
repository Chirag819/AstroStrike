#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"

using namespace sf;
using namespace std;

//about the enemy outlook and position
class Enemy {
    Sprite enemy;
    Texture enemyTex;
    Vector2f moveDir;
public:
    Enemy(float x, float y);

    void movement(float x);
    Vector2f EnemySize();
    Vector2f EnemyPosition();
    FloatRect globalBound();
    void draw(RenderWindow& window);
};