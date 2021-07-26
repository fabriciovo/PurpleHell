#ifndef WORLDSCENE_H
#define WORLDSCENE_H


#include "Scene.h"
#include "Button.h"
#include "BattleScene.h"
#include "GameScene.h"

class WorldScene :
	public Scene
{

private:
	sf::Font font;
	sf::Sprite background;
	sf::Texture textureBackground;
	void initButtons();
	void initFont();
	void initTexts();


	std::vector <Button*> buttons;
	sf::Text texts[3];
public:
	WorldScene();
	WorldScene(sf::RenderWindow* window, std::stack<Scene*>* scenes);
	virtual ~WorldScene();

	void renderButtons(sf::RenderTarget* target = NULL);
	void updateButtons();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
	void renderTexts(sf::RenderTarget* target = NULL);




};

#endif