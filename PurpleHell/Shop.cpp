#include "Shop.h"

Shop::Shop()
{
	for (int i = 0; i < this->maxArrayValues; i++) {
		std::srand(time(NULL));
		int randomLife = rand() % 100;
		int randomPower = rand() % 100;
		int randomSpecial = rand() % 3;

		sf::Texture* tex = new sf::Texture();
		tex->loadFromFile("res/img/Player/mage.png");
		this->heroes[i] = new Hero(0.0, 0.0 , names[80],"mage", randomLife, randomPower, randomSpecial, tex);
		
		sf::Texture * emptyTex = new sf::Texture();
		emptyTex->loadFromFile("res/img/items/slot.png");
		this->items[i] = new Item(0, 0, "slot", 0, 0, 0, emptyTex);
		
	}
}

void Shop::Render(sf::RenderTarget* target)
{
	for (int i = 0; i < this->maxArrayValues; i++) {
		if (this->heroes[i]) {
			this->heroes[i]->render(target);
			this->heroes[i]->SetPosition(92 + (25 * i), 22);
			
		}
		if (this->items[i]) {
			this->items[i]->render(target);
			this->items[i]->SetPosition(92 + (25 * i), 48);
		}
	}
}

void Shop::Update(sf::Vector2f mousePos, const float& dt)
{
	for (int i = 0; i < this->maxArrayValues; i++) {
		if (this->heroes[i]) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (this->heroes[i]->getSprite()->getGlobalBounds().contains(mousePos)) {
					this->heroes[i]->setSelected(true);
				}
				else {
					this->heroes[i]->setSelected(false);
				}
			}
			this->heroes[i]->update(mousePos, dt);
			this->heroes[i]->UpdateAnimation(dt);
		}
		if (this->items[i]) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (this->items[i]->getSprite()->getGlobalBounds().contains(mousePos)) {
					this->items[i]->setSelected(true);
				}
				else {
					this->items[i]->setSelected(false);
				}
			}
			this->items[i]->update(mousePos, dt);
		}
	}
}

Item* Shop::GetSelectedItem()
{
	for (int i = 0; i < this->maxArrayValues; i++) {
		if (this->items[i] && this->items[i]->getSelected()) {
			return this->items[i];
		}
	}
	return nullptr;
}


Hero* Shop::GetSelectedHero()
{
	for (int i = 0; i < this->maxArrayValues; i++) {
		if (this->heroes[i] && this->heroes[i]->getSelected()) {
			return this->heroes[i];
		}
	}
	return nullptr;
}

void Shop::RemoveItem()
{
	Hero* hero = this->GetSelectedHero();
	Item* item = this->GetSelectedItem();

	if (hero) {
		for (int i = 0; i < this->maxArrayValues; i++) {
			if (this->heroes[i] == hero) {
				sf::Texture* tex = new sf::Texture();
				tex->loadFromFile("res/img/Player/mage.png");
				this->heroes[i] = new Hero(0.0, 0.0, "slot", "slot", 0, 0, 0, tex);
			}
		}
	}

	if (item) {
		for (int i = 0; i < this->maxArrayValues; i++) {
			if (this->items[i] == item) {
				sf::Texture* tex = new sf::Texture();
				tex->loadFromFile("res/img/Player/mage.png");
				this->items[i] = new Item(0.0, 0.0, "slot", 0, 0, 0, tex);
			}
		}
	}

}

Shop::~Shop()
{
}
