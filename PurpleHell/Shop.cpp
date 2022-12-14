#include "Shop.h"

Shop::Shop()
{
}

void Shop::ShopRender(sf::RenderTarget* target)
{
	for (int i = 0; i < this->maxArrayValues; i++) {
		if (this->heroes[i]) {
			this->heroes[i]->render(target);
		}
		if (this->items[i]) {
			this->items[i]->render(target);
		}
	}
}

void Shop::ShopUpdate(sf::Vector2f mousePos, const float& dt)
{
	for (int i = 0; i < this->maxArrayValues; i++) {
		if (this->heroes[i]) {
			this->heroes[i]->updateAnimation(dt);
			this->heroes[i]->update(mousePos, dt);
		}
		if (this->items[i]) {
			this->items[i]->update(mousePos, dt);
		}
	}
}


Shop::~Shop()
{
}
