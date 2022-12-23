#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "Scene.h"
#include "Button.h"
#include "Player.h"
#include "WorldScene.h"
#include "Units.h"
#include "Shop.h"

class GameScene :
	public Scene
{

private:
	Player* player;
	Units* units;
	Inventory* inventory;
	Shop* shop;

	sf::Font font;
	sf::Sprite background;
	sf::Texture textureBackground;
	sf::Texture heroesT[3];
	sf::Texture unitsT[3];
	sf::Texture equipedT[6];
	sf::Texture inventoryT[12];
	sf::Text texts[4];
	sf::Text textInfoMenu;
	sf::Text textInfoPlayerTeam;
	std::vector <Button*> buttons;
	std::vector <Button*> buttonsUnits;
	std::vector <Button*> buttonsItems;
	std::vector <Button*> buttonStages;
	std::vector <Button*> buttonsShop;

	void init();
	void initButtons();
	void initFont();
	void initTexts();
	void listUnits();
	void listInventory();
	void listShop();
	void Stages();
	void EquipHero(Hero* hero);
	void RemoveHero(Hero* hero);
	void EquipItem(Item* inventoryItem);
	void RemoveEquipedItem(Item* equipedItem);
	void SellItem(Item* inventoryItem);
	void updateTexts();
	void buy();
	void sellHero();
	void showMenuInfo(sf::Text * text, Entity* entity, sf::Vector2f pos, sf::RenderTarget* target);
public:
	GameScene();
	GameScene(sf::RenderWindow* window, std::stack<Scene*>* scenes);
	virtual ~GameScene();

	void renderButtons(sf::RenderTarget* target = NULL);
	void updateButtons();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
	void renderTexts(sf::RenderTarget* target = NULL);
};

#endif