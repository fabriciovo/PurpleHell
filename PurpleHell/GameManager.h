#ifndef GAMEMANAGER_H

#define GAMEMANAGER_H


#include "MainMenuScene.h"


class GameManager
{
private:
	//Var
	sf::RenderWindow *window;
	sf::Event sfEvent;
	sf::Text texts[3];
	sf::Clock dtClock;
	float dt;

	std::stack<Scene*> scenes;
	bool mousePressed;
	//Inits
	void initWindow();
	void initScenes();


public:

	//GameManager
	GameManager();
	virtual ~GameManager();

	//Functions
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
	void endApplication();
	bool Pressed();
	void SetPressed(bool value);

	//Static Functions
};

#endif