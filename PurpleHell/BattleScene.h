#ifndef BATTLESCENE_H
#define BATTLESCENE_H


#include "Scene.h"
#include "Button.h"
#include "GameScene.h"
#include "AI.h"

#include <string>
#include <xstring>
#include <cstdlib>
#include <ctime>
#include <stdlib.h> 
#include <time.h>
#include <queue>
class BattleScene :
	public Scene
{
protected:

	Player * player;
	AI* ai;

	sf::Font font;
	sf::Text infoText;
	sf::Text battleInfo;
	sf::Sprite background;
	sf::Texture textureBackground;
	sf::Texture hudTexture;
	sf::Sprite hudSprite;

	std::vector <Button*> buttons;
	std::vector <sf::Text> battleTexts;
	std::queue<AI*> ais;

	bool turn;
	bool win;
	bool winEnemy;

	int wave;
	int maxWave;
	int timer = 100;
	int timerToStart = 100;
	int enemyTurnIndex = 0;
	int enemyIndex = 0;
	int timerDamageText = 20;
	int playerIndex = 0;
	void initTextures();
	void initButtons();
	void initFont();
	void initTexts();
	void initPlayer();
	void initAI();
	void battleSystem(const float& dt);
	void playerReward();


public:
	BattleScene();
	BattleScene(sf::RenderWindow * window, std::stack<Scene*>* scenes, int wave);
	virtual ~BattleScene();

	void renderButtons(sf::RenderTarget* target = NULL);
	void updateButtons();
	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
	void renderTexts(sf::RenderTarget* target = NULL);
	void updateTexts();
	void enemyTurn();
	void damageTexts(Entity * hero, Enemy * enemy, bool isPlayer, bool miss = false);
	void updateDamageText(const float& dt);
};

#endif // !BATTLESTATE_H
