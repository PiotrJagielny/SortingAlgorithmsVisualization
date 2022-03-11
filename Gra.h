#pragma once

#include "HeaderFiles.h"
#include "VisualizationState.h"
#include "MainMenuState.h"


class Gra
{
private:
	sf::RenderWindow* m_okno;
	sf::Event m_event;

	sf::Clock m_frameTimer;;

	

	std::stack<State*> m_states;

	void InitWindow();
	void InitStates();
public:
	//Constructors / Descructors
	Gra();
	~Gra();

	void gameLoop();

	void pollEvents();

	void update();

	void render();


	static bool m_singleClickEscapeDetection;
};

