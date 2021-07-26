#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "GameScene.h"
#include "Button.h"
#include <iostream>
#include <map>
#include <string>

#include <map>

class MainMenuScene :
	public Scene
{
private:
	sf::Font font;

	sf::Sprite background;
	sf::Texture textureBackground;
	sf::Text texts[3];

	std::vector <Button*> buttons;

	std::map<std::string, Button*> buttonsMap;

	void initFonts();
	void initButtons();
	void initTexts();
	bool showCredits;



public:
	MainMenuScene();
	MainMenuScene(sf::RenderWindow *window, std::stack<Scene*> *scenes);
	virtual ~MainMenuScene();

	
	void updateButtons();
	void updateInput(const float &dt);
	void update(const float& dt);
	void render(sf::RenderTarget *target = NULL);
	void renderButtons(sf::RenderTarget*target=NULL);
	void renderTexts(sf::RenderTarget* target);




};

#endif


