#include "WorldScene.h"

//Inits
void WorldScene::initButtons()
{

	sf::Texture texture1;
	texture1.loadFromFile("res/hud/button1.png");
	this->buttons.push_back(new Button(25, 25, 75, 20, &this->font, "Start Game", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture1));
	this->buttons.push_back(new Button(25, 50, 75, 20, &this->font, "QUIT", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture1));
	this->buttons.push_back(new Button(25, 75, 75, 20, &this->font, "Credits", sf::Color::White, sf::Color::Black, sf::Color::Blue, texture1));

}

void WorldScene::initFont()
{
	if (!this->font.loadFromFile(this->fontFile)) {
		throw("COULD NOT LOAD FONT");
	}
}

void WorldScene::initTexts()
{
	sf::Text worldText;

	worldText.setFont(this->font);
	worldText.setString("WORLD");
	worldText.setCharacterSize(32);
	worldText.setPosition(350 , 10);

	this->texts[0] = worldText;
}

//Constructors

WorldScene::WorldScene()
{
}

WorldScene::WorldScene(sf::RenderWindow* window, std::stack<Scene*>* scenes) : Scene(window, scenes)
{
	this->initFont();
	this->initButtons();
	this->initTexts();
	this->textureBackground.loadFromFile("res/backgrounds/World.png");
	this->background.setTexture(textureBackground);
}


WorldScene::~WorldScene()
{

}

//Updates
void WorldScene::updateButtons()
{
	for (auto& it : this->buttons) {
		it->update(this->mousePosView);
	}
	if (this->buttons[0]->isPressed()) {
		this->scenes->push(new BattleScene(this->window, this->scenes, 0));
	}
	if (this->buttons[1]->isPressed()) {
		this->scenes->push(new GameScene(this->window, this->scenes));
	}

}

void WorldScene::updateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		//this->scenes->push(new BattleState(this->window, this->scenes));
	}
}

void WorldScene::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateButtons();
}

//Renders

void WorldScene::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->renderButtons(target);
	this->renderTexts(target);

}

void WorldScene::renderTexts(sf::RenderTarget* target)
{
	for (int i = 0; i < 3; i++) {
		target->draw(texts[i]);
	}
}

void WorldScene::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons) {

		it->render(target);
	}
}