#include "HeaderFiles.h"
#include "State.h"
#include "Gra.h"

State::State(sf::RenderWindow* viewPoint , std::stack<State*>* statesPtr)
{
	m_statesPtr = statesPtr;

	m_viewPoint = viewPoint;
	m_quit = false;

	//Init font
	m_font = new sf::Font;
	if (!m_font->loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "ERROR::STATE::Font could not load";
	}

}

State::~State()
{
	delete m_font;

}

const bool& State::getQuit() const
{
	return m_quit;
}

void State::checkForQuit()
{
	if (Gra::m_singleClickEscapeDetection == false)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{

			m_quit = true;
		}
	}

}
