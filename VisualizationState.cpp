#include "HeaderFiles.h"
#include "VisualizationState.h"
#include "FunctionsAndVariables.h"


void VisualizationState::initPillars(sf::RenderWindow* window)
{
	
	float pillarWidth{ static_cast<float>(window->getSize().x) / static_cast<float>(m_numberOfPillars) };
	float pillarPositionX{ 0.0f };
	for (int iii{ 0 }; iii < m_numberOfPillars; ++iii, pillarPositionX += pillarWidth)
	{

		m_pillarsToSort.push_back(new sf::RectangleShape{});
		m_pillarsToSort[iii]->setSize(
			sf::Vector2f{pillarWidth ,
			static_cast<float>(Functions::getRandomInt(1,window->getSize().y - 100))}
		);

		m_pillarsToSort[iii]->setPosition(
			pillarPositionX,
			window->getSize().y - m_pillarsToSort[iii]->getGlobalBounds().height
		);

		//m_pillarsToSort[iii]->setOutlineThickness(1.0f);
		//m_pillarsToSort[iii]->setOutlineColor(sf::Color::Green);

		//m_pillarsToSort[iii]->setFillColor(sf::Color::White);

	}
}

VisualizationState::VisualizationState(sf::RenderWindow* viewPoint, std::stack<State*>* statesPtr, short numberOfPillars)
	: State(viewPoint, statesPtr)
{

	m_numberOfPillars = numberOfPillars;
	this->initPillars(viewPoint);
	m_arePillarsSorting = false;

	//Init text
	m_clikToSortText.setFont(*m_font);
	m_clikToSortText.setString("Press 'G' to sort (or ESC to back)");
	m_clikToSortText.setPosition(0.0f , 0.0f);
}

VisualizationState::~VisualizationState()
{

}

void VisualizationState::endState()
{

}

void VisualizationState::startVisualization(sf::RenderWindow* okno)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		m_arePillarsSorting = true;

		if (Variables::isSelectionSortSelected == true)
			Functions::selectionSort(m_pillarsToSort, m_sortingSpeed, okno);
		else if (Variables::isBubbleSortSelected == true)
			Functions::bubbleSort(m_pillarsToSort, m_sortingSpeed, okno);
	}
}

void VisualizationState::update(const float& timePerFrame , sf::RenderWindow* okno)
{
	this->updateKeybinds(timePerFrame);
	//std::cout << "You are in the Visualization State\n";

	this->startVisualization(okno);
}

void VisualizationState::updateKeybinds(const float& timePerFrame)
{
	this->checkForQuit();
}

void VisualizationState::render(sf::RenderTarget* target)
{
	for (auto* pillar : m_pillarsToSort)
		target->draw(*pillar);


	if(m_arePillarsSorting == false)
		target->draw(m_clikToSortText);
}
