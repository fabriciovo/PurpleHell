#ifndef SCENE_H
#define SCENE_H


#include "Entity.h"

class Scene
{
protected:

	sf::RenderWindow *window;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::RectangleShape fadeShape;

	std::vector<sf::Texture> textures;
	std::stack<Scene*> *scenes;
	std::string fontFile;
	

	bool quit;
	bool fade;
	int timerFade;
public:
	Scene();
	Scene(sf::RenderWindow *window, std::stack<Scene*> *scenes);
	virtual ~Scene();

	const bool &getEnd() const;
	bool buttonPressed;

	void endScene();
	virtual void updateInput(const float &dt) = 0;
	virtual void updateMousePosition();
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget *target = NULL) = 0;
	void updateFade(const float& dt);
	void renderFade(sf::RenderTarget *target);
	void Exit();
};
#endif