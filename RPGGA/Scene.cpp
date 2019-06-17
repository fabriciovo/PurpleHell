#include "Scene.h"



Scene::Scene()
{
}

Scene::Scene(sf::RenderWindow * window, std::stack<Scene*> *scenes)
{
	this->timerFade = 255;
	this->fade = false;
	this->window = window;
	this->quit = false;
	this->scenes = scenes;
	this->buttonPressed = false;
	this->fontFile = "res/fonts/m5x7.ttf";
	this->fadeShape.setPosition(sf::Vector2f(0, 0));
	this->fadeShape.setFillColor(sf::Color(0, 0, 0, timerFade));
	this->fadeShape.setSize(sf::Vector2f(350,197));
	

}


Scene::~Scene()
{
}


const bool & Scene::getEnd() const
{
	// TODO: insert return statement here
	return this->quit;
}

void Scene::endScene()
{
	this->fade = true;
}

void Scene::Exit()
{
	this->window->close();
}

void Scene::updateMousePosition()
{

	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}

void Scene::updateFade(const float& dt)
{
	if (fade) {
		if (dt > 1.0f) {
			timerFade += 5;
			this->fadeShape.setFillColor(sf::Color(0, 0, 0, timerFade));

			if (timerFade >= 255) {
				this->quit = true;
				this->fade = false;
			}
		}
	}
	if (!fade) {
		
		if (timerFade > 0) {
			if (dt > 1.0f) {
				timerFade -= 5;
				this->fadeShape.setFillColor(sf::Color(0, 0, 0, timerFade));
			}
		}
	}
	
}

void Scene::renderFade(sf::RenderTarget *target)
{
	target->draw(fadeShape);
}
