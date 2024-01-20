#include "EnemyHealthBar.h"

EnemyHealthBar::EnemyHealthBar()
{
	//bar.setPosition(x, y);
	outerBar.setFillColor(Color::Transparent);
	outerBar.setOutlineColor(Color::White);
	outerBar.setSize({ 175.f, 10.f});
	outerBar.setOutlineThickness(1.0f);
	Vector2f v(health * 7.f, 10.f);
	bar.setSize( v );
	bar.setFillColor(Color::Red);
}

void EnemyHealthBar::setPos(int x, int y)
{
	bar.setPosition(x, y);
	outerBar.setPosition(x, y);
}

void EnemyHealthBar::draw(RenderWindow& window)
{
	window.draw(outerBar);
	window.draw(bar);
}

int EnemyHealthBar::getHealth()
{
	return health;
}

void EnemyHealthBar::setHealth(int health)
{
	this->health = health;
	bar.setSize({ health * 7.f, 10.f });
}



