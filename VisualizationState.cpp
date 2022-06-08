#include "HeaderFiles.h"
#include "VisualizationState.h"
#include "FunctionsAndVariables.h"

sf::Text VisualizationState::timerText = sf::Text{};
sf::Clock VisualizationState::timer = sf::Clock{};

void VisualizationState::initPillars(sf::RenderWindow* window)
{
	
	float pillarWidth{ static_cast<float>(window->getSize().x) / static_cast<float>(m_numberOfPillars) };
	float pillarHeightDifference{ static_cast<float>(window->getSize().y - 100.0f) / static_cast<float>(m_numberOfPillars) };
	float pillarPositionX{ 0.0f };
	float setSamePillarHeightDifference{ pillarHeightDifference };

	for (int iii{ 0 }; iii < m_numberOfPillars; pillarPositionX += pillarWidth, ++iii)
	{

		m_pillarsToSort.push_back(new sf::RectangleShape{});


		m_pillarsToSort[iii]->setSize(
			sf::Vector2f{ pillarWidth ,
			setSamePillarHeightDifference }
		);


		m_pillarsToSort[iii]->setPosition(
			pillarPositionX,
			window->getSize().y - m_pillarsToSort[iii]->getGlobalBounds().height
		);

		setSamePillarHeightDifference += pillarHeightDifference;
	}
	//shuffle pillars
	for (int iii{ 0 }; iii < m_pillarsToSort.size(); ++iii)
	{
		int randomPillarPosition{ Functions::getRandomInt(iii, m_pillarsToSort.size() - 1) };
	

		Functions::swapPillars(iii, randomPillarPosition, m_pillarsToSort);
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

	VisualizationState::timerText.setFont(*m_font);
	VisualizationState::timerText.setPosition(viewPoint->getSize().x - 200.0f, 0.0f);
	VisualizationState::timerText.setCharacterSize(24);
	VisualizationState::timerText.setString("Timer: 0s");
}

VisualizationState::~VisualizationState()
{

}

void VisualizationState::endState()
{

}

void VisualizationState::startVisualization(sf::RenderWindow* okno)
{
	if (m_arePillarsSorting == false)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
		{
			m_arePillarsSorting = true;

			if (Variables::isSelectionSortSelected == true)
				Functions::selectionSort(m_pillarsToSort, m_sortingSpeed, okno);
			else if (Variables::isBubbleSortSelected == true)
				Functions::bubbleSort(m_pillarsToSort, m_sortingSpeed, okno);
			else if (Variables::isInsertionSortClicked == true)
				Functions::insertionSort(m_pillarsToSort, m_sortingSpeed, okno);
			else if (Variables::isQuickSortClicked == true)
			{
				VisualizationState::timer.restart();
				Functions::quickSort(m_pillarsToSort, 0, m_pillarsToSort.size() - 1, okno, m_sortingSpeed);
				Functions::setGreenColorAfterSort(m_pillarsToSort, okno);
			}
			else if (Variables::isMergeSortClicked == true)
			{
				VisualizationState::timer.restart();
				Functions::mergeSort(m_pillarsToSort,0,m_pillarsToSort.size()-1,okno ,m_sortingSpeed);
				Functions::setGreenColorAfterSort(m_pillarsToSort, okno);
				
			}
		}
	}
}

void VisualizationState::update(const float& timePerFrame , sf::RenderWindow* okno)
{
	this->updateKeybinds(timePerFrame);

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

	target->draw(VisualizationState::timerText);
}
