#pragma once

#include "HeaderFiles.h"
#include "State.h"

class VisualizationState : public State
{
private:
	short m_numberOfPillars;
	std::vector<sf::RectangleShape*> m_pillarsToSort;
	sf::Clock m_sortingSpeed;

	sf::Text m_clikToSortText;

	bool m_arePillarsSorting;



	void initPillars(sf::RenderWindow* window);
public:
	VisualizationState(sf::RenderWindow* viewPoint, std::stack<State*>* statesPtr,
		short numberOfPillars);
	virtual ~VisualizationState();

	static sf::Text timerText;
	static sf::Clock timer;

	void endState() override;

	void startVisualization(sf::RenderWindow* okno);

	void update(const float& timePerFrame , sf::RenderWindow* okno) override;
	void updateKeybinds(const float& timePerFrame) override;

	void render(sf::RenderTarget* target = nullptr) override;

};

