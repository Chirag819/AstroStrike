
#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
using namespace sf;
class Player {

    Sprite player;
    Texture playerTex;
public:
    Player(float x, float y);

    //how the player will move
    void movement(float x);

    Vector2f playerPosition();

    Vector2f playerSize();
    //returns the all four vertices of the Sprite
    FloatRect globalBound();

    void draw(RenderWindow& window);

};