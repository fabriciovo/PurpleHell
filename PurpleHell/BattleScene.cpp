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
	this->buttons.push_back(new Button(280, 70, 75, 40, &this->font, "RUN", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture));
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
	turnText.setString(" - TURN - \n- PLAYER -");
	turnText.setString(" - TURN - \n- PLAYER -");
	turnText.setCharacterSize(18);
	turnText.setPosition(135, 60);

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
	nameSelectedHero.setPosition(280, 10);

	nameSelectedEnemy.setFont(this->font);
	nameSelectedEnemy.setCharacterSize(16);
	nameSelectedEnemy.setPosition(20, 10);

	//HP
	heroHP.setFont(this->font);
	heroHP.setCharacterSize(18);
	heroHP.setPosition(275, 20);

	//POWER
	heroPower.setFont(this->font);
	heroPower.setCharacterSize(18);
	heroPower.setPosition(275, 30);

	enemyHP.setFont(this->font);
	enemyHP.setCharacterSize(18);
	enemyHP.setPosition(20, 30);


	//BattleInfo
	sf::Text genericBattleTextSetting;
	genericBattleTextSetting.setFont(this->font);
	genericBattleTextSetting.setCharacterSize(16);

	this->battleInfo.push_back(genericBattleTextSetting);
	this->battleInfo.push_back(genericBattleTextSetting);
	this->battleInfo.push_back(genericBattleTextSetting);
	this->battleInfo.push_back(genericBattleTextSetting);
	this->battleInfo.push_back(genericBattleTextSetting);
	this->battleInfo.push_back(genericBattleTextSetting);
	this->battleInfo.push_back(genericBattleTextSetting);
	this->battleInfo.push_back(genericBattleTextSetting);

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
	this->battleTexts.push_back(heroPower);
}

void BattleScene::initPlayer()
{
	this->player = new Player();
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
	this->maxWave = wave * 2;
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
	//delete this->player;
	delete this->ai;
	for (auto& it : this->buttons) {
		delete it;
	}

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

	if (!this->ais.empty()) {
		if (turn && this->player->getHero() && this->ais.front()->selectedEnemy()) {
			if (this->player->getHero()->getSelected()) {
				if (this->buttons[1]->isPressed()) {
					if (!this->buttonPressed) {
						this->buttonPressed = true;
						this->playerAttack();
					}
				}
			}
		}


		if (turn && this->player->getHero() && this->ais.front()->selectedEnemy() && this->player->getHero()->getEspecial()) {
			if (this->player->getHero()->getSelected()) {
				if (this->buttons[2]->isPressed()) {
					if (!this->buttonPressed) {
						this->player->getHero()->Special(this->ais.front()->getEnemy());
						this->buttonPressed = true;
						this->playerIndex++;
					}
				}
			}
		}


		if (turn && this->player->getEquipedItems()->getItem() && this->player->getHero(playerIndex)) {
			if (this->buttons[3]->isPressed()) {
				if (!this->buttonPressed) {
					this->buttonPressed = true;
					this->useItem();
				}
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
	this->updateFade(dt);
	this->updateMousePosition();
	this->player->getEquipedItems()->updateEquipedItems(mousePosView, dt);
	this->updateTexts();

	if (!this->ais.empty()) {
		this->ais.front()->updateEnemies(mousePosView, dt);
		this->updateInput(dt);
		this->updateButtons();
		this->player->update(mousePosView, dt);

		if (this->ais.front()->checkDeads()) {
			this->player->setTeamToTrue();
			this->player->setSpecialToTrue();
			this->playerIndex = 0;
			this->ais.pop();
		}

		if (this->player->checkDeads()) {
			//game over
		}


		if (turn) {
			//player turn
			if (this->player->checkPlayed()) {
				if (this->playerIndex < this->player->teamSize()) {
					if (this->player->getHero(this->playerIndex)->getHp() > 0) {
						this->player->getHero(this->playerIndex)->setSelected(true);
					}
					else {
						playerIndex++;
					}
				}
			}
			else {
				turn = false;
				this->timer = 200;
			}

		}
		else {
			//enemy turn
			battleSystemEnemy(dt);
		}
	}



	/*if (this->playerIndex < this->player->teamSize())
		if (this->player->getHero(this->playerIndex)->getHp() > 0) {
			this->player->getHero(playerIndex)->setSelected(true);
		}
		else {
			playerIndex++;
		}
	}
	else {
		turn = false;
	}

	if (turn == false && !this->ais.empty()) {
		battleSystem(dt);
	}

	if (this->ais.empty()) {
		std::cout << "PLAYER WIN" << std::endl;
		this->winEnemy = false;
		this->win = true;
		this->playerReward();
		this->endScene();
	}
	else
	{
		this->ais.front()->battlePosition();
	}

	if (this->player->checkDeads()) {
		this->winEnemy = true;
		this->win = false;
		std::cout << "ENEMY WIN" << std::endl;;
		this->endScene();

	}

*/
	for (int key = 0; key < 7; key++) {
		this->updateDamageText(dt, key);
	}

}

//Renders
void BattleScene::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	target->draw(this->hudSprite);
	this->player->getEquipedItems()->renderEquipedItems(target);
	this->renderTexts(target);
	this->player->render(target);
	if (!this->ais.empty()) {
		this->renderButtons(target);
		this->ais.front()->renderEnemies(target);
	}
	this->renderFade(target);

}

void BattleScene::renderTexts(sf::RenderTarget* target)
{
	target->draw(infoText);
	for (int i = 0; i < battleTexts.size(); i++) {
		target->draw(battleTexts[i]);
	}
	for (auto& it : this->battleInfo) {
		target->draw(it);
	}


}

void BattleScene::updateTexts()
{
	if (this->player->getHero(0)->getName() != "slot") {
		this->battleTexts[0].setString(this->player->getHero(0)->getName());
		this->battleTexts[2].setString("HP: " + std::to_string(this->player->getHero(0)->getHp()));
		this->battleTexts[6].setString("POWER: " + std::to_string(this->player->getHero(0)->getPower()));
	}
	if (!this->ais.empty()) {
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
	}

	if (turn && !win && !winEnemy) {
		this->infoText.setString(" - TURN - \n- PLAYER -");
	}
	else {
		this->infoText.setString(" - TURN - \n- ENEMY -");

	}


	if (win && !winEnemy) {
		this->infoText.setString("PLAYER WINS!");
	}

	if (!win && winEnemy) {
		this->infoText.setString("ENEMY WINS!");
	}

}

void BattleScene::enemyTurn()
{

	if (this->ais.front()->getTeam(this->enemyIndex)->getHp() <= 0 && !this->ais.front()->checkPlayed()) {
		this->enemyIndex++;
	}
	else {
		if (this->enemyTurnIndex == 0) {
			//enemy Turn start
			this->infoText.setString(" - TURN - \n- ENEMY -");
			this->enemyTurnIndex++;
		}
		else if (this->enemyTurnIndex == 1) {
			this->infoText.setString(" - TURN - \n- ENEMY -");
			this->enemyTurnIndex++;
		}
		else if (this->enemyTurnIndex == 2) {
			this->enemyAttack();
	
		}
	}

}

void BattleScene::damageTexts(int key, Entity* entity, std::string text)
{
	this->battleInfo[key].setString(text);
	this->battleInfo[key].setPosition(entity->getPosition().x, entity->getPosition().y - 18);
	this->timerDamageText = 50;
}

void BattleScene::updateDamageText(const float& dt, int key)
{
	if (this->battleInfo[key].getString() != "") {
		int y = this->battleInfo[key].getPosition().y;
		this->battleInfo[key].setPosition(this->battleInfo[key].getPosition().x, y -= 1);
		if (this->timerDamageText <= 0) {
			this->battleInfo[key].setString("");
		}
		this->timerDamageText -= dt;
	}
}

void BattleScene::useItem()
{
	int itemId = this->player->getEquipedItems()->getItemId();
	this->player->getEquipedItems()->getItem()->Action(this->player->getHero(playerIndex));
	this->player->getEquipedItems()->removeItem(itemId);
	this->player->getEquipedItems()->save();
	playerIndex++;
}

void BattleScene::renderButtons(sf::RenderTarget* target)
{
	this->buttons[0]->render(target);

	if (turn && this->ais.front()->selectedEnemy()) {
		this->buttons[1]->render(target);
		this->buttons[2]->render(target);
	}

	if (turn && this->player->getEquipedItems()->getItem() && !this->player->getHero()->getPlayed()) {
		this->buttons[3]->render(target);
	}
}

void BattleScene::battleSystemEnemy(const float& dt)
{
	if (this->timer <= 0 && !this->ais.front()->enemyPlayed()) {
		enemyTurn();
		this->timer = 100;
	}
	if (this->ais.front()->enemyPlayed() == true && this->timer <= 0) {
		this->enemyIndex = 0;
		this->playerIndex = 0;
		this->ais.front()->setTeamToPlay();
		this->player->setTeamToTrue();
		turn = true;
	}

	this->timer -= dt;
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
				fsUnits << "knight 25 5 2" << std::endl;
				fsUnits << "archer 35 6 2" << std::endl;
				fsUnits << "slot 0 0 0";
			}

			fsUnits.close();
		}

		if (fsInventory.is_open())
		{
			if (fsInventory.good())
			{
				fsInventory << "potion 1 5 1" << std::endl;
				fsInventory << "knife 1 5 2" << std::endl;
				fsInventory << "axe 1 10 3" << std::endl;
				fsInventory << "sword 1 15 4" << std::endl;
				fsInventory << "magicAxe 1 20 5" << std::endl;
			}
			fsInventory.close();
		}

		this->player->setClear(true);
	}
}

void BattleScene::enemyAttack()
{
	//this->ais.front()->getTeam(this->enemyIndex)->Action(player);
	Hero* player = this->player->getRandomHero();
	Enemy* enemy = this->ais.front()->getTeam(this->enemyIndex);

	std::srand(time(NULL));
	int r = rand() % 100;
	if (r < 33) {
		this->damageTexts(0, player, "MISS");
		enemy->setPlayed(true);
		enemy->setSelected(false);
		player->setSelected(false);
	}
	else {
		enemy->Action(player);
		this->damageTexts(0, player, "- " + std::to_string( enemy->getPower()));
	}
	this->enemyIndex++;
}

void BattleScene::playerAttack()
{
	Hero* player = this->player->getHero(this->playerIndex);
	Enemy* enemy = this->ais.front()->getEnemy();
	player->Action(enemy);

	this->damageTexts(0, enemy, "- " + std::to_string(player->getPower()));
	this->playerIndex++;
}



