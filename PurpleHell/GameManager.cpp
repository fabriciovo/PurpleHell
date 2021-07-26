#include "GameManager.h"

//Static Functions


//init
void GameManager::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(350,197), "GAME");
	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(true);
	this->mousePressed = false;
}

void GameManager::initScenes()
{
	this->scenes.push(new MainMenuScene(this->window,&this->scenes));
	
}

//GameManager
GameManager::GameManager()
{
	this->initWindow();
	this->initScenes();
}


GameManager::~GameManager()
{
	delete this->window;

	while (!this->scenes.empty()) {
		delete this->scenes.top();
		this->scenes.pop();
	}

}



//Functions
void GameManager::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void GameManager::updateSFMLEvents()
{

	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();

		if (this->sfEvent.type == sf::Event::MouseButtonReleased){
			this->scenes.top()->buttonPressed = false;
			//std::cout << "MOUSE FALSE" << std::endl;

		}
	}
}

void GameManager::update()
{
	this->updateSFMLEvents();

	if (!this->scenes.empty()) {

		this->scenes.top()->update(this->dt);

		if (this->scenes.top()->getEnd()) {
			this->scenes.top()->endScene();
			delete this->scenes.top();
			this->scenes.pop();
		}

	}
	else
	{
		//this->endApplication();
		this->window->close();
	}
}

void GameManager::render()
{

	this->window->clear();

	//render stuff
	if (!this->scenes.empty()) {
		this->scenes.top()->render(this->window);
	}
	this->window->display();
}

void GameManager::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}

}

void GameManager::endApplication()
{
}

bool GameManager::Pressed()
{
	return this->mousePressed;
}

void GameManager::SetPressed(bool value)
{
	this->mousePressed = value;
}


