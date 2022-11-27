#include "GameScene.h"

//Inits

void GameScene::initFont()
{
	if (!this->font.loadFromFile(this->fontFile)) {
		throw("COULD NOT LOAD FONT");
	}
}

void GameScene::initPlayers()
{
	this->player = new Player();
	this->units = new Units();
	this->inventory = new Inventory();

}

void GameScene::initButtons()
{
	sf::Texture texture1;
	texture1.loadFromFile("res/hud/button1.png");

	sf::Texture texture3;
	texture3.loadFromFile("res/hud/button3.png");
	this->buttons.push_back(new Button(5, 18, 75,20, &this->font, "CHASE", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture1));
	this->buttons.push_back(new Button(5, 48, 75,20, &this->font, "SHOP",  sf::Color::White, sf::Color::Black, sf::Color::Blue, texture1));
	this->buttons.push_back(new Button(5, 78, 75,20, &this->font, "INVENTORY", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture1));
	this->buttons.push_back(new Button(5, 108,75,20, &this->font, "UNITS", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture1));
	this->buttons.push_back(new Button(5, 138,75,20, &this->font, "QUIT", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture1));

	this->buttonsSlots.push_back(new Button(95, 84, 20,20, &this->font, "SLOT 1", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture3));
	this->buttonsSlots.push_back(new Button(145, 84, 20,20, &this->font,"SLOT 2", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture3));
	this->buttonsSlots.push_back(new Button(195, 84, 20,20, &this->font,"SLOT 3", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture3));

	this->buttonsItems.push_back(new Button(91, 84,  2,5, &this->font, "Equip", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture3));
	this->buttonsItems.push_back(new Button(134, 84, 2,5, &this->font, "Remove", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture3));


	this->buttonStages.push_back(new Button(91, 20, 2, 5, &this->font, "STAGE 1", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture3));
	/*this->buttonStages.push_back(new Button(134, 20, 2, 5, &this->font, "STAGE 2", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture3));
	this->buttonStages.push_back(new Button(177, 20, 2, 5, &this->font, "STAGE 3", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture3));
	this->buttonStages.push_back(new Button(220, 20, 2, 5, &this->font, "STAGE 4", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture3));
	this->buttonStages.push_back(new Button(263, 20, 2, 5, &this->font, "STAGE 5", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture3));
	this->buttonStages.push_back(new Button(298, 20, 2, 5, &this->font, "STAGE 6", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture3));*/

}

void GameScene::initTexts()
{
	sf::Text goldText;
	sf::Text unitText;
	sf::Text panelText;
	sf::Text shopText;
	sf::Text equipText;

	goldText.setFont(this->font);
	goldText.setString("Gold: ");
	goldText.setCharacterSize(8);
	goldText.setPosition(5, 175);

	unitText.setFont(this->font);
	unitText.setString("YOUR UNITS");
	unitText.setCharacterSize(52);
	unitText.setPosition(550, 10);

	shopText.setFont(this->font);
	shopText.setString(" ");
	shopText.setCharacterSize(52);
	shopText.setPosition(75, 75);

	equipText.setFont(this->font);
	equipText.setString("EQUIPED ITEMS");
	equipText.setCharacterSize(32);
	equipText.setPosition(300, 300);

	panelText.setFont(this->font);
	panelText.setCharacterSize(16);
	panelText.setPosition(175,0);

	this->texts[0] = goldText;
	this->texts[1] = unitText;
	this->texts[2] = panelText;
	this->texts[3] = equipText;

}
//Constructors

GameScene::GameScene()
{
}

GameScene::GameScene(sf::RenderWindow *window, std::stack<Scene*> *scenes) : Scene(window, scenes)
{

	this->initFont();
	this->initPlayers();
	this->initButtons();
	this->initTexts();
	this->textureBackground.loadFromFile("res/backgrounds/game.png");
	this->background.setTexture(textureBackground);
}


GameScene::~GameScene()
{

}

//Updates

void GameScene::update(const float & dt)
{
	this->updateMousePosition();
	this->updateFade(dt);
	this->updateInput(dt);
	this->updateButtons();
	this->player->update(this->mousePosView, dt);
	this->units->updateUnits(this->mousePosView, dt);
	this->inventory->updateInventory(this->mousePosView, dt);
	this->player->getEquipedItems()->updateEquipedItems(this->mousePosView,dt);

}

void GameScene::updateButtons()
{
	for (auto& it : this->buttons) {
		it->update(this->mousePosView);
	}
	for (auto& it : this->buttonsSlots) {
		it->update(this->mousePosView);
	}

	for (auto& it : this->buttonsItems) {
		it->update(this->mousePosView);
	}

	for (auto& it : this->buttonStages) {
		it->update(this->mousePosView);
	}
	
	//Menu
	if (this->buttons[0]->isPressed()) {
		//this->scenes->push(new BattleScene(this->window, this->scenes, 0));
		this->Stages();
	}
	if (this->buttons[1]->isPressed()) {
		this->Shop();
	}
	if (this->buttons[2]->isPressed()) {
		this->listInventory();
	}
	if (this->buttons[3]->isPressed()) {
		this->listUnits();
	}
	if (this->buttons[4]->isPressed()) {
		this->Exit();
	}

	//Units

	if (this->texts[2].getString() == "UNITS" && this->units->getHero()) {
		if (this->buttonsSlots[0]->isPressed() && !this->buttonPressed) {

			this->ChangeHero(this->units->getHero(), this->player->getTeam(0));

			this->buttonPressed = true;
		}
		if (this->buttonsSlots[1]->isPressed() && !this->buttonPressed) {
			this->ChangeHero(this->units->getHero(), this->player->getTeam(1));

			this->buttonPressed = true;
		}
		if (this->buttonsSlots[2]->isPressed() && !this->buttonPressed) {
			this->ChangeHero(this->units->getHero(), this->player->getTeam(2));

			this->buttonPressed = true;
		}
	}
	//Inventory
	if (this->texts[2].getString() == "INVENTORY" && this->inventory->getItem()){
		if (this->buttonsItems[0]->isPressed() && !this->buttonPressed) {
			this->ChangeItems(this->inventory->getItem(), this->player->getEquipedItems()->getItemById(0));
			this->buttonPressed = true;
		}
	}
	//Stages
	if (this->texts[2].getString() == "STAGES") {
		if (this->buttonStages[0]->isPressed() && !this->buttonPressed) {
			this->scenes->push(new BattleScene(this->window, this->scenes, 0));
			this->buttonPressed = true;
		}
	}
}

void GameScene::updateInput(const float & dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		//this->scenes->push(new BattleState(this->window, this->scenes));
	}
}

//Renders

void GameScene::render(sf::RenderTarget * target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->renderButtons(target);
	this->renderTexts(target);
	this->player->render(target);
	this->player->getEquipedItems()->renderEquipedItems(target);

	if (this->texts[2].getString() == "UNITS") {
		this->units->renderUnits(target);
	}

	if (this->texts[2].getString() == "INVENTORY") {
		this->inventory->renderInventory(target);
	}

	renderFade(target);

}

void GameScene::renderTexts(sf::RenderTarget* target)
{
	for (int i = 0; i < 4; i++) {
		target->draw(texts[i]);
	}
}


void GameScene::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons) {
		it->render(target);
	}

	if(this->texts[2].getString() == "UNITS" && this->units->selectedHero()){
		for (auto& it : this->buttonsSlots) {
			it->render(target);
		}
	}

	if (this->texts[2].getString() == "INVENTORY" && this->inventory->getItem()) {
		for (auto& it : this->buttonsItems) {
			it->render(target);
		}
	}

	if (this->texts[2].getString() == "STAGES") {
		for (auto& it : this->buttonStages) {
			it->render(target);
		}
	}
}

//Lists

void GameScene::listUnits()
{
	this->texts[2].setString("UNITS");

}

void GameScene::listInventory()
{
	this->texts[2].setString("INVENTORY");
	
}

void GameScene::Shop()
{
	this->texts[2].setString("SHOP");
}

void GameScene::Stages()
{
	this->texts[2].setString("STAGES");
}

void GameScene::ChangeHero(Entity* unit, Entity* hero)
{
	std::fstream ofsHeroes;
	std::fstream ofsUnits;
	Entity* tempHero;
	tempHero = hero;

	int unitNum = this->units->UnitNumber();
	int heroNum = this->player->UnitNumber(hero);
	//Unit
	std::string unitName = unit->getName();
	int unitHp = unit->getHp(), unitPower = unit->getPower(), unitSpell = unit->getType();

	//Hero
	std::string heroName = tempHero->getName();
	int heroHp = tempHero->getHp(), heroPower = tempHero->getPower(), heroSpell = tempHero->getType();

	//Svaing Hero to team
	this->unitsT[heroNum].loadFromFile("res/img/Player/" + unitName + ".png");
	this->player->setTeam(heroNum, new Hero(200 + (23 * heroNum), 148, unitName, unitHp, unitPower,unitSpell ,&this->unitsT[heroNum]));

	ofsHeroes.open("res/Player/Team.txt");
	for (int it = 0; it < 3; it++) {
		ofsHeroes 
			<< this->player->getTeam(it)->getName() 
			<< " " << this->player->getTeam(it)->getHp() 
			<< " " << this->player->getTeam(it)->getPower() 
			<< " " << this->player->getTeam(it)->getType()
			<< std::endl;
		std::cout << player->getTeam(it)->getName() << std::endl;
	}
	ofsHeroes.close();

	//Svaing Hero to unity
	this->heroesT[unitNum].loadFromFile("res/img/Player/" + heroName + ".png");
	this->units->setUnits(unitNum, new Hero(93 + (25 * unitNum), 23, heroName, heroHp, heroPower,heroSpell, &this->heroesT[unitNum]));
	std::cout << "HERO NAME "<< heroName << std::endl;

	ofsUnits.open("res/Player/Units.txt");
	for (int iz = 0; iz < 3; iz++) {
		ofsUnits << this->units->getTeam(iz)->getName() 
			<< " " << this->units->getTeam(iz)->getHp() 
			<< " " << this->units->getTeam(iz)->getPower() 
			<< " " << this->units->getTeam(iz)->getType() 
			<< std::endl;
		std::cout << units->getTeam(iz)->getName() << std::endl;

	}
	ofsUnits.close();
}

void GameScene::ChangeItems(Entity* inventoryItem , Entity* equipedItem)
{

	std::fstream ofsEquiped;
	std::fstream ofsInventory;
	Entity* tempEquiped;
	tempEquiped = equipedItem;

	int inventoryNum = this->inventory->inventoryNumber();
	int equipedNum = this->player->getEquipedItems()->UnitNumber(equipedItem);
	//Inventory
	std::string inventoryName = inventory->getItem()->getName();
	int inventoryHp = inventoryItem->getHp(), inventoryPower = inventoryItem->getPower(), inventorySpell = inventoryItem->getType();

	//Equiped Item
	std::string equipName = tempEquiped->getName();
	int equipHp = tempEquiped->getHp(), equipPower = tempEquiped->getPower(), equipJob = tempEquiped->getType();

	//Svaing Equiped to inventory
	this->inventoryT[equipedNum].loadFromFile("res/img/items/" + inventoryName + ".png");
	this->player->getEquipedItems()->setItem(equipedNum, new Item(93 + (25 * equipedNum), 118, inventoryName, inventoryHp, inventoryPower, inventorySpell, &this->inventoryT[equipedNum]));
	std::cout << "EQUIP NAME " << equipName << std::endl;

	ofsEquiped.open("res/Player/equiped.txt");

	for (int it = 0; it < 6; it++) {
		ofsEquiped
			<< this->player->getEquipedItems()->getItemById(it)->getName()
			<< " " << this->player->getEquipedItems()->getItemById(it)->getHp()
			<< " " << this->player->getEquipedItems()->getItemById(it)->getPower()
			<< " " << this->player->getEquipedItems()->getItemById(it)->getType()
			<< std::endl;
	}
	ofsEquiped.close();

	//Svaing Hero to unity
	this->equipedT[inventoryNum].loadFromFile("res/img/items/" + equipName + ".png");
	this->inventory->setItem(inventoryNum, new Item(10 + (40 * inventoryNum), 140, equipName, equipHp, equipPower, equipJob, &this->equipedT[inventoryNum]));
	   
	ofsInventory.open("res/Player/Inventory.txt");
	for (int t = 0; t < 6; t++) {
			ofsInventory
			<< this->inventory->getItemById(t)->getName()
			<< " " << this->inventory->getItemById(t)->getHp()
			<< " " << this->inventory->getItemById(t)->getPower()
			<< " " << this->inventory->getItemById(t)->getType()
			<< std::endl;
	}
	ofsInventory.close();





}
