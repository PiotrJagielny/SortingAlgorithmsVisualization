#include "HeaderFiles.h"
#include "MainMenuState.h"
#include "FunctionsAndVariables.h"


void MainMenuState::initText(sf::RenderWindow* window)
{
	m_texts["whatProgramDoes"] = new sf::Text;
	m_texts["whatProgramDoes"]->setFont(*m_font);
	m_texts["whatProgramDoes"]->setPosition(300.0f , 0.0f);
	m_texts["whatProgramDoes"]->setCharacterSize(70.0f);
	m_texts["whatProgramDoes"]->setString("Sorting Algorithms Visualization");

	m_texts["SelectAlgo"] = new sf::Text;
	m_texts["SelectAlgo"]->setFont(*m_font);
	m_texts["SelectAlgo"]->setPosition(3.0f , 110.0f);
	m_texts["SelectAlgo"]->setCharacterSize(50.0f);
	m_texts["SelectAlgo"]->setString("Select sorting algorithm:");

	
	m_texts["SelectionSort"] = new sf::Text;
	m_texts["SelectionSort"]->setFont(*m_font);
	m_texts["SelectionSort"]->setPosition(3.0f, 200.0f);
	m_texts["SelectionSort"]->setCharacterSize(30.0f);
	m_texts["SelectionSort"]->setString("- Selection Sort");

	m_texts["BubbleSort"] = new sf::Text;
	m_texts["BubbleSort"]->setFont(*m_font);
	m_texts["BubbleSort"]->setPosition(3.0f, 280.0f);
	m_texts["BubbleSort"]->setCharacterSize(30.0f);
	m_texts["BubbleSort"]->setString("- Bubble Sort");

	m_texts["InsertionSort"] = new sf::Text;
	m_texts["InsertionSort"]->setFont(*m_font);
	m_texts["InsertionSort"]->setPosition(3.0f, 360.0f);
	m_texts["InsertionSort"]->setCharacterSize(30.0f);
	m_texts["InsertionSort"]->setString("- Insertion Sort");

	m_texts["QuickSort"] = new sf::Text;
	m_texts["QuickSort"]->setFont(*m_font);
	m_texts["QuickSort"]->setPosition(280.0f, 200.0f);
	m_texts["QuickSort"]->setCharacterSize(30.0f);
	m_texts["QuickSort"]->setString("- Quick Sort");

	m_texts["MergeSort"] = new sf::Text;
	m_texts["MergeSort"]->setFont(*m_font);
	m_texts["MergeSort"]->setPosition(280.0f, 280.0f);
	m_texts["MergeSort"]->setCharacterSize(30.0f);
	m_texts["MergeSort"]->setString("- Merge Sort");

	m_texts["goToVisualization"] = new sf::Text;
	m_texts["goToVisualization"]->setFont(*m_font);
	m_texts["goToVisualization"]->setPosition(3.0f,window->getSize().y - 50.0f );
	m_texts["goToVisualization"]->setCharacterSize(30.0f);
	m_texts["goToVisualization"]->setString("Press Enter to confirm");

	m_texts["numberOfPillars"] = new sf::Text;
	m_texts["numberOfPillars"]->setFont(*m_font);
	m_texts["numberOfPillars"]->setPosition(m_elementsNumberSlider.getPosition().x, 600.0f);
	m_texts["numberOfPillars"]->setCharacterSize(20.0f);
	m_texts["numberOfPillars"]->setString("Number of pillars: ");

	m_texts["delay"] = new sf::Text;
	m_texts["delay"]->setFont(*m_font);
	m_texts["delay"]->setPosition(m_delaySlider.getPosition().x, 600.0f);
	m_texts["delay"]->setCharacterSize(20.0f);
	m_texts["delay"]->setString("Delay: ");
}

void MainMenuState::initButtons()
{

	m_SelectionSortButton.setSize(sf::Vector2f(30.0f , 30.0f));
	m_SelectionSortButton.setOutlineThickness(2.0f);
	m_SelectionSortButton.setFillColor(sf::Color{255 , 255 , 255 , 100});
	m_SelectionSortButton.setPosition(200.0f , 205.0f);

	m_BubbleSortButton.setSize(sf::Vector2f(30.0f, 30.0f));
	m_BubbleSortButton.setOutlineThickness(2.0f);
	m_BubbleSortButton.setFillColor(sf::Color{ 255 , 255 , 255 , 100 });
	m_BubbleSortButton.setPosition(200.0f, 285.0f);

	m_InsertionSortButton.setSize(sf::Vector2f(30.0f, 30.0f));
	m_InsertionSortButton.setOutlineThickness(2.0f);
	m_InsertionSortButton.setFillColor(sf::Color{ 255 , 255 , 255 , 100 });
	m_InsertionSortButton.setPosition(200.0f, 365.0f);

	m_QuickSortButton.setSize(sf::Vector2f(30.0f, 30.0f));
	m_QuickSortButton.setOutlineThickness(2.0f);
	m_QuickSortButton.setFillColor(sf::Color{ 255 , 255 , 255 , 100 });
	m_QuickSortButton.setPosition(440.0f, 205.0f);

	m_MergeSortButton.setSize(sf::Vector2f(30.0f, 30.0f));
	m_MergeSortButton.setOutlineThickness(2.0f);
	m_MergeSortButton.setFillColor(sf::Color{ 255 , 255 , 255 , 100 });
	m_MergeSortButton.setPosition(440.0f, 285.0f);


}

void MainMenuState::initSliders()
{
	//number of elements slider initialization
	m_elementsNumberSlider.setSize(sf::Vector2f{200.0f , 20.0f});
	m_elementsNumberSlider.setPosition(3.0f , 550.0f);

	m_movableElementsNumberSlider.setSize(sf::Vector2f{ 10.0f , 50.0f });
	m_movableElementsNumberSlider.setPosition(
		m_elementsNumberSlider.getPosition().x + m_elementsNumberSlider.getGlobalBounds().width/2,
		m_elementsNumberSlider.getPosition().y - m_elementsNumberSlider.getGlobalBounds().height/2 - 3.0f
	);
	m_movableElementsNumberSlider.setOutlineThickness(2.0f);
	m_movableElementsNumberSlider.setOutlineColor(sf::Color::Green);

	//Delay slider initialization
	m_delaySlider.setSize(sf::Vector2f{ 200.0f , 20.0f });
	m_delaySlider.setPosition(350.0f, 550.0f);

	m_movableDelaySlider.setSize(sf::Vector2f{ 10.0f , 50.0f });
	m_movableDelaySlider.setPosition(
		m_delaySlider.getPosition().x + m_delaySlider.getGlobalBounds().width / 2,
		m_delaySlider.getPosition().y - m_delaySlider.getGlobalBounds().height / 2 - 3.0f
	);
	m_movableDelaySlider.setOutlineThickness(2.0f);
	m_movableDelaySlider.setOutlineColor(sf::Color::Green);

}

void MainMenuState::initVariables()
{

	m_goToVisualization = false;
	m_isNumberOfElementsPressed = false;
	m_isDelayPressed = false;

	m_numberOfPillarsMin = 20;
	m_numberOfPillarsMax = 2000;
	Variables::numberOfPillars = m_numberOfPillarsMax / 2;

	m_delayMin = 1;
	m_delayMax = 80;
	Variables::delayInMilisecounds = m_delayMax / 2;
}

MainMenuState::MainMenuState(sf::RenderWindow* viewPoint , std::stack<State*>* statesPtr)
	: State(viewPoint , statesPtr)
{
	this->initButtons();
	this->initSliders();
	this->initText(viewPoint);
	this->initVariables();

}

MainMenuState::~MainMenuState()
{
	delete m_texts["whatProgramDoes"];
	delete m_texts["SelectAlgo"];
	delete m_texts["SelectionSort"];
	delete m_texts["InsertionSort"];
	delete m_texts["goToVisualization"];
	delete m_texts["numberOfPillars"];
	delete m_texts["delay"];
	delete m_texts["BubbleSort"];
	delete m_texts["QuickSort"];
	delete m_texts["MergeSort"];
}

const bool MainMenuState::goToVisualization() const
{
	return m_goToVisualization;
}

void MainMenuState::endState()
{

}

void MainMenuState::moveSlider(sf::RectangleShape& movableItem, sf::RectangleShape& slider,
	const sf::RenderWindow* okno)
{
	movableItem.setPosition(
		sf::Mouse::getPosition(*okno).x - 5.0f,
		movableItem.getPosition().y
	);

	//dont allow movable element get out of Slider
	if (movableItem.getPosition().x <= slider.getPosition().x)
	{//Left
		movableItem.setPosition(
			slider.getPosition().x,
			movableItem.getPosition().y
		);

	}
	else if (movableItem.getPosition().x + movableItem.getGlobalBounds().width >
		slider.getPosition().x + slider.getGlobalBounds().width)
	{//Right
		movableItem.setPosition(
			slider.getPosition().x + slider.getGlobalBounds().width -
			movableItem.getGlobalBounds().width + 2.0f,
			movableItem.getPosition().y
		);

	}


}

void MainMenuState::setValueBySlider(short& valueToSet, const float valueRatio, short minValue, short maxValue,
	const sf::RectangleShape& movableItem, const sf::RectangleShape& slider)
{
	//Set number of pillars in relation to mouse position to slider
	valueToSet = (movableItem.getPosition().x - slider.getPosition().x) * valueRatio;


	//If smaller than minimum number of pillars set minimum value
	if (valueToSet < minValue)
		valueToSet = minValue;
	//If bigger than maxinum number of pillars ser maximum value
	else if (valueToSet > maxValue)
		valueToSet = maxValue;
}

bool MainMenuState::buttonHoverAndClickLogic(sf::RectangleShape& button, sf::RenderWindow* okno,
	bool& selectSortingAlgorithm)
{

	if (button.getGlobalBounds().contains(sf::Mouse::getPosition(*okno).x, sf::Mouse::getPosition(*okno).y))
	{
		button.setFillColor(sf::Color{ 0 , 255 , 0 , 200 });

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			selectSortingAlgorithm = true;
			return true;
		}
	}
	else if (selectSortingAlgorithm == false)
	{
		button.setFillColor(sf::Color{ 255 , 255 , 255 , 100 });
	}

	return false;
}

void MainMenuState::goToVisualization(sf::RenderWindow* okno)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{//Go to visualization state if Enter Pressed
		m_goToVisualization = true;
		m_statesPtr->push(new VisualizationState{ okno, m_statesPtr, Variables::numberOfPillars });
	}
}

void MainMenuState::update(const float& timePerFrame , sf::RenderWindow* okno)
{
	this->updateKeybinds(timePerFrame);
	this->updateButtons(okno);
	this->updateSliders(okno);
	this->updateText(okno);


	this->goToVisualization(okno);

	
}

void MainMenuState::updateKeybinds(const float& timePerFrame)
{
	this->checkForQuit();

}

void MainMenuState::updateButtons(sf::RenderWindow* okno)
{

	if (buttonHoverAndClickLogic(m_SelectionSortButton, okno, Variables::isSelectionSortSelected))
	{
		Variables::isBubbleSortSelected = false;
		Variables::isInsertionSortClicked = false;
		Variables::isQuickSortClicked = false;
		Variables::isMergeSortClicked = false;
	}
	else if (buttonHoverAndClickLogic(m_BubbleSortButton, okno, Variables::isBubbleSortSelected))
	{
		Variables::isSelectionSortSelected = false;
		Variables::isInsertionSortClicked = false;
		Variables::isQuickSortClicked = false;
		Variables::isMergeSortClicked = false;
	}
	else if (buttonHoverAndClickLogic(m_InsertionSortButton, okno, Variables::isInsertionSortClicked))
	{
		Variables::isBubbleSortSelected = false;
		Variables::isSelectionSortSelected = false;
		Variables::isQuickSortClicked = false;
		Variables::isMergeSortClicked = false;
	}
	else if (buttonHoverAndClickLogic(m_QuickSortButton, okno, Variables::isQuickSortClicked))
	{
		Variables::isBubbleSortSelected = false;
		Variables::isInsertionSortClicked = false;
		Variables::isSelectionSortSelected = false;
		Variables::isMergeSortClicked = false;
	}
	else if (buttonHoverAndClickLogic(m_MergeSortButton, okno, Variables::isMergeSortClicked))
	{
		Variables::isBubbleSortSelected = false;
		Variables::isInsertionSortClicked = false;
		Variables::isSelectionSortSelected = false;
		Variables::isQuickSortClicked = false;
	}


}

void MainMenuState::updateSliders(sf::RenderWindow* okno)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{//Move slider if clicked
		if (m_movableElementsNumberSlider.getGlobalBounds().contains(
			sf::Mouse::getPosition(*okno).x, sf::Mouse::getPosition(*okno).y))
		{
			m_isNumberOfElementsPressed = true;
		}
		else if (m_movableDelaySlider.getGlobalBounds().contains(
			sf::Mouse::getPosition(*okno).x, sf::Mouse::getPosition(*okno).y))
		{
			m_isDelayPressed = true;
		}

	}
	else
	{
		m_isNumberOfElementsPressed = false;
		m_isDelayPressed = false;
	}
		

	if (m_isNumberOfElementsPressed == true)
	{
		this->moveSlider(m_movableElementsNumberSlider, m_elementsNumberSlider, okno);
		this->setValueBySlider(Variables::numberOfPillars, 10.9f, m_numberOfPillarsMin, m_numberOfPillarsMax,
			m_movableElementsNumberSlider, m_elementsNumberSlider);

	}
	else if (m_isDelayPressed == true)
	{
		this->moveSlider(m_movableDelaySlider, m_delaySlider, okno);
		this->setValueBySlider(Variables::delayInMilisecounds, 0.5f , m_delayMin, m_delayMax,
			m_movableDelaySlider, m_delaySlider);

	}
}

void MainMenuState::updateText(sf::RenderWindow* okno)
{
	std::stringstream showNumberOfPillars;
	std::stringstream showDelay;

	showNumberOfPillars << "Number of pillars: " << Variables::numberOfPillars;
	
	m_texts["numberOfPillars"]->setString(showNumberOfPillars.str());

	showDelay << "Delay in milisecounds: " << Variables::delayInMilisecounds;

	m_texts["delay"]->setString(showDelay.str());
}

void MainMenuState::render(sf::RenderTarget* target)
{
	this->renderText(target);
	this->renderButtons(target);
	this->renderSliders(target);
}

void MainMenuState::renderText(sf::RenderTarget* target)
{
	
	target->draw(*m_texts["whatProgramDoes"]);
	target->draw(*m_texts["SelectAlgo"]);
	target->draw(*m_texts["SelectionSort"]);
	target->draw(*m_texts["InsertionSort"]);
	target->draw(*m_texts["goToVisualization"]);
	target->draw(*m_texts["numberOfPillars"]);
	target->draw(*m_texts["delay"]);
	target->draw(*m_texts["BubbleSort"]);
	target->draw(*m_texts["QuickSort"]);
	target->draw(*m_texts["MergeSort"]);
	
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	target->draw(m_SelectionSortButton);
	target->draw(m_BubbleSortButton);
	target->draw(m_InsertionSortButton);
	target->draw(m_QuickSortButton);
	target->draw(m_MergeSortButton);
}

void MainMenuState::renderSliders(sf::RenderTarget* target)
{
	target->draw(m_elementsNumberSlider);
	target->draw(m_movableElementsNumberSlider);

	target->draw(m_delaySlider);
	target->draw(m_movableDelaySlider);
}
