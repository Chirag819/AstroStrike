#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"

using namespace sf;
using namespace std;


//about the movement of the bullet and its projection
class BulletEnemy {
    Sprite singleBullet;
    vector<Sprite> bullets;
    Texture bulletTex;
    int fire_Timer;
public:
    //initializing the outlook of the bullet
    BulletEnemy();

    //making a container of the bullets
    void accumulatebullets(Vector2f ESize, Vector2f EPosition);
    //firing movement of the bullets
    void update(float y);
    vector<Sprite> fetchBullets(BulletEnemy& currBullet);
    void draw(RenderWindow& window);
    //updating the bullets array after used
    void updatebullets(vector<Sprite>& dummybullets);
};