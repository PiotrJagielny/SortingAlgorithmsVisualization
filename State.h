#pragma once

#include "HeaderFiles.h"


class State
{
private:
	sf::RenderWindow* m_viewPoint;

	

	std::vector<sf::Texture*> m_textures;
	std::vector<sf::RectangleShape*> m_RectagnelShapes;

	bool m_quit;

public:
	State(sf::RenderWindow* viewPoint, std::stack<State*>* statesPtr);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();
	virtual void endState() = 0;


	virtual void updateKeybinds(const float& timePerFrame) = 0;
	virtual void update(const float& timePerFrame , sf::RenderWindow* okno) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

protected:
	sf::Font* m_font;
	std::stack<State*>* m_statesPtr;
};

