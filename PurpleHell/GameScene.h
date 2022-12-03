#ifndef GAMESCENE_H
#define GAMESCENE_H



#include "Scene.h"
#include "Button.h"
#include "Player.h"
#include "WorldScene.h"
#include "Units.h"

class GameScene :
	public Scene
{

private:
	Player *player;
	Units*units;
	Inventory *inventory;

	sf::Font font;
	sf::Sprite background;
	sf::Texture textureBackground;
	sf::Texture heroesT[3];
	sf::Texture unitsT[3];
	sf::Texture equipedT[6];
	sf::Texture inventoryT[12];
	sf::Text texts[4];

	std::vector <Button*> buttons;
	std::vector <Button*> buttonsSlots;
	std::vector <Button*> buttonsItems;
	std::vector <Button*> buttonStages;

	void initPlayers();
	void initButtons();
	void initFont();
	void initTexts();
	void listUnits();
	void listInventory();
	void Shop();
	void Stages();
	void ChangeHero(Entity *unit, Entity * hero);
	void ChangeItems(Entity *unit, Entity * hero);
	void RemoveEquipedItem(Item* equipedItem);

public:
	GameScene();
	GameScene(sf::RenderWindow *window, std::stack<Scene*> *scenes);
	virtual ~GameScene();

	void renderButtons(sf::RenderTarget* target = NULL);	
	void updateButtons();
	void updateInput(const float &dt);
	void update(const float& dt);
	void render(sf::RenderTarget *target = NULL);
	void renderTexts(sf::RenderTarget* target = NULL);
};

#endif