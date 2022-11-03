#ifndef  ENTITY_H
#define ENTITY_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <map>
#include <stack>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"


#include "AnimationComponent.h"
class Job;

class Entity
{
private:
	void initVariables();
protected:

	sf::Texture* texture;
	sf::Sprite* sprite;
	bool selected;
	bool played;
	int hp;
	int power;
	int type;
	bool canUseSpecial = true;
	std::string name;

	AnimationComponent *animationComponent;

public:
	Entity();
	virtual ~Entity();

	//Component
	void CreateSprite(sf::Texture*);
	void createAnimationComponent(sf::Texture& texture_sheet);

	virtual void SetPosition(const float x, const float y);
	virtual void SetScale(const float x, const float y);
	virtual void action(Entity* entity) = 0;
	virtual void special(Entity *entity) = 0;

	virtual void update(sf::Vector2f mousePos, const float &dt);


	//virtual void equip(Item item,Inventory inventory);
	//virtual void useItem(Item item,Inventory inventory);

	virtual void render(sf::RenderTarget* target);

	const bool &getSelected() const;
	const bool &getPlayed() const;
	sf::Sprite *getSprite();

	void setDamage(int hp);

	std::string getName();
	int getHp();
	int getPower();
	bool getEspecial();
	void setEspecial(bool value);
	sf::Vector2f getPosition();
	void setPlayed(bool value);
	void setSelected(bool value);
	void setHp(int hp);
	void setPower(int power);
	int getType();


};

#endif // ! ENTITY_H