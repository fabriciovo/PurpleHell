#ifndef SHOP_H
#define SHOP_H
#include "Hero.h"
#include "Item.h"
class Shop
{
public:
	Shop();
	
	void ShopRender(sf::RenderTarget* target);
	void ShopUpdate(sf::Vector2f mousePos, const float& dt);

	~Shop();
private:
	static const int maxArrayValues = 9;
	Hero* heroes[maxArrayValues];
	Item* items[maxArrayValues];
};
#endif