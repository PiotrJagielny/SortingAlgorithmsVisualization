#pragma once
class Variables
{
public:
	static bool isSelectionSortSelected;
	static bool isBubbleSortSelected;

	static float timePerFrame;
	static short numberOfPillars;
	static short delayInMilisecounds;

};

namespace Functions
{
	int getRandomInt(int min, int max);

	void drawPillars(std::vector<sf::RectangleShape*>& pillarsToSort, sf::RenderWindow* window);

	void setGreenColorAfterSort(std::vector<sf::RectangleShape*>& pillarsToSort,
		sf::Clock& sortSpeed, sf::RenderWindow* window);

	void delay(sf::Clock& sortSpeed, float time);


	//Sorting algorithms
	void selectionSort(std::vector<sf::RectangleShape*>& pillarsToSort,
		sf::Clock& sortSpeed, sf::RenderWindow* window);

	void bubbleSort(std::vector<sf::RectangleShape*>& pillarsToSort,
		sf::Clock& sortSpeed, sf::RenderWindow* window);

}

