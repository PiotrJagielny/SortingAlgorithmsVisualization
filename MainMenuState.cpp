#include "HeaderFiles.h"
#include "MainMenuState.h"
#include "FunctionsAndVariables.h"


void MainMenuState::initText()
{
	m_texts["SelectAlgo"] = new sf::Text;
	m_texts["SelectAlgo"]->setFont(*m_font);
	m_texts["SelectAlgo"]->setPosition(3.0f , 50.0f);
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

	m_texts["goToVisualization"] = new sf::Text;
	m_texts["goToVisualization"]->setFont(*m_font);
	m_texts["goToVisualization"]->setPosition(3.0f, 700.0f);
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
	m_SelectionSortButton.setPosition(190.0f , 205.0f);

	m_BubbleSortButton.setSize(sf::Vector2f(30.0f, 30.0f));
	m_BubbleSortButton.setOutlineThickness(2.0f);
	m_BubbleSortButton.setFillColor(sf::Color{ 255 , 255 , 255 , 100 });
	m_BubbleSortButton.setPosition(190.0f, 285.0f);


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
	this->initText();
	this->initVariables();

}

MainMenuState::~MainMenuState()
{
	delete m_texts["SelectAlgo"];
	delete m_texts["SelectionSort"];
	delete m_texts["goToVisualization"];
	delete m_texts["numberOfPillars"];
	delete m_texts["delay"];
	delete m_texts["BubbleSort"];
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
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	//{//Go to visualization state if Enter Pressed
	//	m_goToVisualization = true;
	//	m_statesPtr->push(new VisualizationState{ okno, m_statesPtr, Variables::numberOfPillars });
	//}
	
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
	}
	else if (buttonHoverAndClickLogic(m_BubbleSortButton, okno, Variables::isBubbleSortSelected))
	{
		Variables::isSelectionSortSelected = false;
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

	target->draw(*m_texts["SelectAlgo"]);
	target->draw(*m_texts["SelectionSort"]);
	target->draw(*m_texts["goToVisualization"]);
	target->draw(*m_texts["numberOfPillars"]);
	target->draw(*m_texts["delay"]);
	target->draw(*m_texts["BubbleSort"]);
	
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	target->draw(m_SelectionSortButton);
	target->draw(m_BubbleSortButton);
}

void MainMenuState::renderSliders(sf::RenderTarget* target)
{
	target->draw(m_elementsNumberSlider);
	target->draw(m_movableElementsNumberSlider);

	target->draw(m_delaySlider);
	target->draw(m_movableDelaySlider);
}
