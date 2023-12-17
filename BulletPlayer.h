#include<iostream>
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
using namespace sf;
using namespace std;


class BulletPlayer {
    Sprite singleBullet;
    vector<Sprite> bullets;
    Texture bulletTex;
    int fire_Timer;

public:
    //initializing the outlook of the bullet
    BulletPlayer();
    //making a container of the bullets
    void accumulatebullets(Vector2f Pposition, Vector2f PSize);
    //firing movement of the bullets
    void update();
    vector<Sprite> fetchBullets(BulletPlayer& currBullet);
    //updating the bullets array after used
    void updatebullets(vector<Sprite>& dummybullets);
    void draw(RenderWindow& window);

};