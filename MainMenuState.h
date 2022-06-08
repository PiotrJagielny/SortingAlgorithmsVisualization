#pragma once

#include "State.h"
#include "VisualizationState.h"


class MainMenuState : public State
{
private:
	std::map<std::string, sf::Text*> m_texts;

	sf::RectangleShape m_SelectionSortButton;

	sf::RectangleShape m_BubbleSortButton;

	sf::RectangleShape m_InsertionSortButton;

	sf::RectangleShape m_QuickSortButton;

	sf::RectangleShape m_MergeSortButton;


	bool m_goToVisualization;

	sf::RectangleShape m_elementsNumberSlider;
	sf::RectangleShape m_movableElementsNumberSlider;
	bool m_isNumberOfElementsPressed;
	short m_numberOfPillarsMin;
	short m_numberOfPillarsMax;

	sf::RectangleShape m_delaySlider;
	sf::RectangleShape m_movableDelaySlider;
	bool m_isDelayPressed;
	short m_delayMin;
	short m_delayMax;
	

	void initText(sf::RenderWindow* window);
	void initButtons();
	void initSliders();
	void initVariables();
public:
	MainMenuState(sf::RenderWindow* viewPoint , std::stack<State*>* statesPtr);
	virtual ~MainMenuState();

	const bool goToVisualization() const;

	void endState() override;

	void moveSlider(sf::RectangleShape& movableItemBounds,
		sf::RectangleShape& sliderBounds,const sf::RenderWindow* okno);

	void setValueBySlider(short& valueToSet,float valueRatio,short minValue,short maxValue,
		const sf::RectangleShape& movableItem,const sf::RectangleShape& slider);

	bool buttonHoverAndClickLogic(sf::RectangleShape& button, sf::RenderWindow* okno,
		bool& selectSortingAlgorithm);

	void goToVisualization(sf::RenderWindow* okno);

	void update(const float& timePerFrame , sf::RenderWindow* okno) override;
	void updateKeybinds(const float& timePerFrame) override;
	void updateButtons(sf::RenderWindow* okno);
	void updateSliders(sf::RenderWindow* okno);
	void updateText(sf::RenderWindow* okno);

	void render(sf::RenderTarget* target = nullptr) override;
	void renderText(sf::RenderTarget* target);
	void renderButtons(sf::RenderTarget* target);
	void renderSliders(sf::RenderTarget* target);

};

