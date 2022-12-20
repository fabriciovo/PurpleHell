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

enum ENUM_STATUS {
	normal,
	poison,
	fire,
	stun,
	shield
};


#include "AnimationComponent.h"
class Job;

class Entity
{
private:
	void initVariables();
protected:

	sf::Texture* texture;
	sf::Sprite* sprite;

	std::string name;
	std::string job;

	int hp;
	int power;
	int special;

	ENUM_STATUS battleStatus;

	bool selected = false;
	bool played = false;
	bool canUseSpecial = true;

	AnimationComponent *animationComponent;

public:


	Entity();
	virtual ~Entity();

	//Component
	void CreateSprite(sf::Texture*);
	void createAnimationComponent(sf::Texture& texture_sheet);

	virtual void SetPosition(const float x, const float y);
	virtual void SetScale(const float x, const float y);
	virtual void Action(Entity* entity) = 0;
	virtual void Special(Entity *entity) = 0;
	virtual void update(sf::Vector2f mousePos, const float &dt);
	virtual void render(sf::RenderTarget* target);

	sf::Sprite *getSprite();
	sf::Vector2f getPosition();
	
	std::string getName();
	std::string GetJob();

	int getType();
	int getHp();
	int getPower();

	const bool &getSelected() const;
	const bool &getPlayed() const;		
	bool getEspecial();



	void setDamage(int hp);	 
	void setEspecial(bool value);
	void setPlayed(bool value);
	void setSelected(bool value);
	void setHp(int hp);
	void setPower(int power);
	void ApplyEffect();
	void SetEffect(ENUM_STATUS effect);
	ENUM_STATUS GetEffect();
};

#endif // ! ENTITY_H