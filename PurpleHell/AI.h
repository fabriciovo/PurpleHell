#ifndef AI_H
#define AI_H


#include "Enemy.h"

#include <fstream>
#include <sstream>

class AI
{
private:
	static const int maxUnits = 5;;
	sf::Texture* texture;
	sf::Sprite* sprite;
	Enemy* team[maxUnits];
	//Arquivos
	void ArquivoEnemies(std::ifstream &, int);
	


public:
	AI();
	AI(int i);
	virtual ~AI();
	void renderEnemies(sf::RenderTarget* target);
	void updateEnemies(sf::Vector2f mousePos, const float &dt);
	void battlePosition();
	bool selectedEnemy();
	Enemy* getEnemy();	

	Enemy* getTeam(int i);
	bool checkDeads();
	int NumberOfEnemies();

};
#endif // !AI_H
