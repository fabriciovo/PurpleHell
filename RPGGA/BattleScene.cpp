#include "BattleScene.h"


void BattleScene::initTextures()
{
	this->textureBackground.loadFromFile("res/backgrounds/battle.png");
	this->background.setTexture(textureBackground);
}


void BattleScene::initButtons()
{
	sf::Texture texture;
	texture.loadFromFile("res/hud/button2.png");
	this->buttons.push_back(new Button(280, 70, 75, 40,	&this->font, "RUN", sf::Color::White, sf::Color::Black, sf::Color::Blue,texture));
	this->buttons.push_back(new Button(100, 5, 75, 40, &this->font, "ATTACK", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture));
	this->buttons.push_back(new Button(150, 5, 75, 40, &this->font, "MAGIC", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture));
	this->buttons.push_back(new Button(200, 5, 75, 40, &this->font, "ITEM", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture));
}

void BattleScene::initFont()
{
	if (!this->font.loadFromFile(this->fontFile)) {
		throw("COULD NOT LOAD FONT");
	}
}

void BattleScene::initTexts()
{
	sf::Text turnText;

	turnText.setFont(this->font);
	turnText.setString("- TURN -");
	turnText.setCharacterSize(18);
	turnText.setPosition(this->window->getSize().x / 2-32, this->window->getSize().y / 2- 64);

	this->infoText = turnText;

	//Player/Enemy
	sf::Text nameSelectedHero;
	sf::Text nameSelectedEnemy;
	sf::Text heroHP;
	sf::Text heroPower;
	sf::Text enemyHP;
	sf::Text enemyTitle;
	sf::Text played;

	//TItle
	enemyTitle.setFont(this->font);
	enemyTitle.setString("- ENEMY -");
	enemyTitle.setCharacterSize(16);
	enemyTitle.setPosition(20, 3);


	//Names
	nameSelectedHero.setFont(this->font);
	nameSelectedHero.setCharacterSize(16);
	nameSelectedHero.setPosition(280,  10);

	nameSelectedEnemy.setFont(this->font);
	nameSelectedEnemy.setCharacterSize(16);
	nameSelectedEnemy.setPosition(20,  10);

	//HP
	heroHP.setFont(this->font);
	heroHP.setCharacterSize(18);
	heroHP.setPosition(275, 20);

	//POWER
	heroPower.setFont(this->font);
	heroPower.setCharacterSize(18);
	heroPower.setPosition(275,30);


	enemyHP.setFont(this->font);
	enemyHP.setCharacterSize(18);
	enemyHP.setPosition(20, 30);

	//player played
	played.setFont(this->font);
	played.setCharacterSize(18);
	played.setPosition(325, 525);


	this->battleTexts.push_back(nameSelectedHero);
	this->battleTexts.push_back(nameSelectedEnemy);
	this->battleTexts.push_back(heroHP);
	this->battleTexts.push_back(enemyHP);
	this->battleTexts.push_back(enemyTitle);
	this->battleTexts.push_back(played);
	this->battleTexts.push_back(heroPower);;
}

void BattleScene::initPlayer()
{
	this->player = new Player(true);
	this->player->battlePosition();
}

void BattleScene::initAI() {

	ais.push(new AI(0));
	ais.push(new AI(1));
	ais.push(new AI(2));
	ais.push(new AI(3));

	ais.front()->battlePosition();
}



//Constructors

BattleScene::BattleScene()
{
}

BattleScene::BattleScene(sf::RenderWindow* window, std::stack<Scene*>* scenes, int wave) : Scene(window, scenes)
{

	this->wave = wave;
	this->maxWave = wave*2;
	this->initPlayer();
	this->initAI();
	this->initFont();
	this->initTextures();
	this->initButtons();
	this->initTexts();
	this->turn = true;
	this->win = false;
	this->winEnemy = false;
}


BattleScene::~BattleScene()
{

}

//Updates
void BattleScene::updateButtons()
{
	for (auto& it : this->buttons) {
		it->update(this->mousePosView);
	}

	if (this->buttons[0]->isPressed()) {
		this->endScene();
	}
	if (turn && this->player->getHero() && this->ais.front()->selectedEnemy()) {
		if (this->player->getHero()->getSelected()) {
			if (this->buttons[1]->isPressed()) {
				if (!this->buttonPressed) {
					this->player->getHero()->action(this->ais.front()->getEnemy());
					this->buttonPressed = true;

				}
			}
		}
	}

	if (turn && this->player->getHero() && this->ais.front()->selectedEnemy()) {
		if (this->player->getHero()->getSelected()) {
			if (this->buttons[2]->isPressed()) {
				if (!this->buttonPressed) {
					this->player->getHero()->special(this->ais.front()->getEnemy());
					this->buttonPressed = true;
				}
			}
		}
	}

	if (turn && this->player->getEquipedItems()->getItem()) {
		if (this->buttons[3]->isPressed()) {
			if (!this->buttonPressed && this->player->getHero()) {
				this->player->getEquipedItems()->getItem()->action(this->player->getHero());
				this->buttonPressed = true;
			}
		}
	}

}

void BattleScene::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		//this->scenes->push(new BattleScene(this->window, this->scenes));
	}
}

void BattleScene::update(const float& dt)
{

	this->updateMousePosition();
	this->updateInput(dt);
	this->updateButtons();
	this->updateTexts();
	this->player->update(mousePosView, dt);
	this->player->getEquipedItems()->updateEquipedItems(mousePosView, dt);
	this->ais.front()->updateEnemies(mousePosView,dt);
	this->updateFade(dt);

	if (!this->player->checkPlayed()) {
		turn = false;
	}

	if (turn == false) {

		battleSystem(dt);

	}

	if (this->ais.front()->checkDeads()) {
		this->player->setTeamToTrue();
		this->ais.pop();
	}
	if (ais.empty() == true) {
		std::cout << "PLAYER WIN" << std::endl;
		this->win = true;
		this->playerReward();
		this->endScene();
	}
	else
	{
		ais.front()->battlePosition();
	}

	if (this->player->checkDeads()) {
		this->winEnemy = true;
		std::cout << "ENEMY WIN" << std::endl;
		this->endScene();

	}

}

//Renders

void BattleScene::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	target->draw(this->hudSprite);
	this->renderButtons(target);
	this->renderTexts(target);
	this->player->render(target);
	this->player->getEquipedItems()->renderEquipedItems(target);
	this->ais.front()->renderEnemies(target);
	this->renderFade(target);
}

void BattleScene::renderTexts(sf::RenderTarget* target)
{
	target->draw(infoText);

	for (int i = 0; i < battleTexts.size(); i++) {
		target->draw(battleTexts[i]);
	}
}

void BattleScene::updateTexts()
{
	if (turn && this->player->getHero()) {
		this->battleTexts[0].setString(this->player->getHero()->getName());
		this->battleTexts[2].setString("HP: " + std::to_string(this->player->getHero()->getHp()));
		this->battleTexts[6].setString("POWER: " + std::to_string(this->player->getHero()->getPower()));
	}
	else
	{
		this->battleTexts[0].setString("");
		this->battleTexts[2].setString("");
		this->battleTexts[6].setString("");
	}

	if (this->ais.front()->selectedEnemy()) {
		this->battleTexts[1].setString(this->ais.front()->getEnemy()->getName());
		this->battleTexts[3].setString("HP: " + std::to_string(this->ais.front()->getEnemy()->getHp()));
	}
	else {
		this->battleTexts[1].setString("");
		this->battleTexts[3].setString("");
	}

	if (this->player->getHero()) {
		if (this->player->getHero()->getPlayed()) {
			this->battleTexts[5].setString("Played");
		}
		else {
			this->battleTexts[5].setString("");
		}
	}
	else {
		this->battleTexts[5].setString("");
	}

	if (turn && !win && !winEnemy) {
		this->infoText.setString("PLAYER");
	}
	else {
		this->infoText.setString("ENEMY");
	}

	if (win && !winEnemy) {
		this->infoText.setString("PLAYER WINS!");
	}

	if (!win && winEnemy) {
		this->infoText.setString("ENEMY WINS!");
	}
}

void BattleScene::renderButtons(sf::RenderTarget * target)
{
	/*for (auto& it : this->buttons) {
	it->render(target);
	}*/
	this->buttons[0]->render(target);

	if (turn && this->player->getHero() && this->ais.front()->selectedEnemy()) {
		if (!this->player->getHero()->getPlayed()) {
			this->buttons[1]->render(target);
			this->buttons[2]->render(target);
			this->buttons[3]->render(target);
		}
	}

	if (turn && this->player->getEquipedItems()->getItem()) {
		this->buttons[3]->render(target);
	}
}


//BattleScene

void BattleScene::battleSystem(const float& dt)
{


		this->infoText.setString("- Enemy Turn -");
	
		for (int i = 0; i < this->ais.front()->NumberOfEnemies(); i++) {
			std::srand(time(NULL));
			int num = rand() % 100;
			std::cout << num << std::endl;

			if ((num > 33 && num < 66) && this->player->getTeam(0) != nullptr ) {
				if (this->player->getTeam(0)->getHp() > 0) {
					this->ais.front()->getTeam(i)->action(this->player->getTeam(0));
					std::cout << "ENEMY -> " << this->ais.front()->getTeam(i)->getName() << "ATTACK -> " << this->player->getTeam(0)->getName() << std::endl;
				}
				else {
					std::cout << "ENEMY -> MISS" << std::endl;
				}	
			}
			else if (num < 33 && this->player->getTeam(1) != nullptr ) {
				if (this->player->getTeam(1)->getHp() > 0) {
					this->ais.front()->getTeam(i)->action(this->player->getTeam(1));
					std::cout << "ENEMY -> " << this->ais.front()->getTeam(i)->getName() << "ATTACK -> " << this->player->getTeam(1)->getName() << std::endl;
				}
				else {
					std::cout << "ENEMY -> MISS" << std::endl;
				}
			}
			else if (num > 66 && this->player->getTeam(2) != nullptr) {
				if (this->player->getTeam(2)->getHp() > 0) {
					this->ais.front()->getTeam(i)->action(this->player->getTeam(2));
					std::cout << "ENEMY -> " << this->ais.front()->getTeam(i)->getName() << "ATTACK -> " << this->player->getTeam(2)->getName() << std::endl;
				}
				else {
					std::cout << "ENEMY -> MISS" << std::endl;
				}
			}
			else {
				std::cout << "ENEMY -> MISS" << std::endl;
			}
		}
		this->player->setTeamToTrue();
		turn = true;
}



void BattleScene::playerReward()
{
	std::fstream fsUnits("res/Player/Units.txt");
	std::fstream fsInventory("res/Player/Inventory.txt");

	if (!this->player->getClear()) {
		if (fsUnits.is_open())
		{
			if (fsUnits.good())
			{
				/*fsUnits << "roulf 25 5 2" << std::endl;
				fsUnits << "louis 35 6 2" << std::endl;
				fsUnits << "slot 0 0 0";*/
			}

			fsUnits.close();
		}

		if (fsInventory.is_open())
		{
			if (fsInventory.good())
			{
				/*fsInventory << "potion 1 5 1" << std::endl;
				fsInventory << "knife 1 5 2" << std::endl;
				fsInventory << "axe 1 10 3" << std::endl;
				fsInventory << "sword 1 15 4" << std::endl;
				fsInventory << "magicAxe 1 20 5" << std::endl;
				fsInventory << "slot 0 0 0";*/
			}
			fsInventory.close();
		}

		this->player->setClear(true);
	}
}



