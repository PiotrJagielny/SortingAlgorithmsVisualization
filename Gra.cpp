#include "HeaderFiles.h"
#include "Gra.h"
#include "FunctionsAndVariables.h"

bool Gra::m_singleClickEscapeDetection = false;

void Gra::InitWindow()
{
	m_okno = new sf::RenderWindow{ sf::VideoMode{1400,950} , "Sorting Algorithms Visualization" ,
		sf::Style::Close | sf::Style::Titlebar};


}

void Gra::InitStates()
{
	m_states.push(new MainMenuState{m_okno, &m_states});
}

Gra::Gra()
{
	this->InitWindow();
	this->InitStates();

	m_frameTimer.restart();
	//m_singleClickEscapeDetection = false;
}

Gra::~Gra()
{
	delete m_okno;

	while (!m_states.empty())
	{
		delete m_states.top();
		m_states.pop();
	}
}

void Gra::gameLoop()
{
	while (m_okno->isOpen())
	{
		Variables::timePerFrame = m_frameTimer.getElapsedTime().asSeconds();
		this->update();
		this->render();
	}
}

void Gra::pollEvents()
{
	while (m_okno->pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_okno->close();
		else if (m_event.type == sf::Event::KeyReleased && m_event.key.code == sf::Keyboard::Escape)
			m_singleClickEscapeDetection = false;
	}

}

void Gra::update()
{
	this->pollEvents();

	if (!m_states.empty())
	{
		m_states.top()->update(Variables::timePerFrame , m_okno);

		if (m_states.top()->getQuit() && !m_singleClickEscapeDetection)
		{
			m_states.top()->endState();
			delete m_states.top();
			m_states.pop();
			m_singleClickEscapeDetection = true;
		}

		
	}
	else
	{
		m_okno->close();
	}

	//std::cout << m_states.size() << '\n';

	
}

void Gra::render()
{
	m_okno->clear();

	if (!m_states.empty())
	{
		m_states.top()->render(m_okno);
	}

	m_okno->display();
}
