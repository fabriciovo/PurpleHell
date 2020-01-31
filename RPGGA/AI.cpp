#include "AI.h"

AI::AI()
{
	std::ifstream ifsEnemies("res/AI/0.txt");
	ArquivoEnemies(ifsEnemies, 0);
}

AI::AI(int i)
{
	std::ifstream ifsEnemies("res/AI/"+std::to_string(i)+".txt");
	ArquivoEnemies(ifsEnemies, 0);


}


AI::~AI()
{
	for (int i = 0; i < this->maxUnits; i++) {
		delete this->team[i];
		delete this->texture;
		delete this->sprite;
	}
}

//Update
void AI::updateEnemies(sf::Vector2f mousePos, const float &dt)
{
	for (int i = 0; i < this->maxUnits; i++) {
		if (this->team[i]){
				this->team[i]->update(mousePos);
				this->team[i]->updateAnimation(dt);
			}
		}
}

//Render
void AI::renderEnemies(sf::RenderTarget * target)
{
	for (int i = 0; i < this->maxUnits; i++) {
		if (this->team[i]) {
			this->team[i]->render(target);
		}
	}

}

//Stuff
void AI::battlePosition()
{
	for (int i = 0; i < this->maxUnits; i++) {
			if (this->team[i]) {
				this->team[i]->SetPosition(55 + (35 * i), 152);
			}
		}

	
}

bool AI::selectedEnemy()
{
	for (int i = 0; i < this->maxUnits; i++) {
		if (this->team[i])
			if (team[i]->getSelected()) {
				return true;
			}
	}
	return false;
}

Enemy* AI::getEnemy()
{
	for (int i = 0; i < this->maxUnits; i++) {
		if (team[i]->getSelected()) {
			return team[i];
		}
	}

}

Enemy* AI::getTeam(int i)
{
	return this->team[i];
}

bool AI::checkDeads(){
		for (int i = 0; i < this->maxUnits; i++) {
			if (this->team[i])
				if (this->team[i]->getHp() > 0) {
					return false;
					break;
				}
		}
		return true;
}

int AI::NumberOfEnemies()
{
	int temp = 0;
	for (int i = 0; i < this->maxUnits; i++) {
		if (this->team[i])
			if (this->team[i]->getHp() > 0) {
				temp++;
			}
	}
	return temp;
}

//Arquivos
void AI::ArquivoEnemies(std::ifstream &ifsEnemies, int i)
{
	std::string name = " ";
	int hp = 0, power = 0;

	if (ifsEnemies.is_open())
	{

		if (!ifsEnemies.eof())
		{

			ifsEnemies >> name >> hp >> power;
			std::cout << name << hp << power << std::endl;
			if (name != "slot") {
				sf::Texture *tex;
				tex = new sf::Texture();
				tex->loadFromFile("res/img/AI/" + name + ".png");
				this->team[i] = (new Enemy(0, 0, name, hp, power, tex));
				i++;
			}
			ArquivoEnemies(ifsEnemies, i);
		}
		else {
			ifsEnemies.close();
		}
	}

}