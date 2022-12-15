#include "Shop.h"

Shop::Shop()
{
	for (int i = 0; i < this->maxArrayValues; i++) {
		std::srand(time(NULL));
		int randomLife = rand() % 100;
		int randomPower = rand() % 100;
		int randomJob = rand() % 3;

		sf::Texture* tex;
		tex = new sf::Texture();
		tex->loadFromFile("res/img/Player/mage.png");

		this->heroes[i] = new Hero(0.0, 0.0 , names[80],"mage", randomLife, randomPower, randomJob, tex);
		
		this->items[i] = new Item();
		
	}
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
			this->heroes[i]->UpdateAnimation(dt);
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
