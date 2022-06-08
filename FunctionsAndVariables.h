#pragma once
class Variables
{
public:
	static bool isSelectionSortSelected;
	static bool isBubbleSortSelected;
	static bool isInsertionSortClicked;
	static bool isQuickSortClicked;
	static bool isMergeSortClicked;

	static float timePerFrame;
	static short numberOfPillars;
	static short delayInMilisecounds;

	static bool assignArrayOnce;
	static std::vector<sf::RectangleShape*> pillarsDuplicate;

	static int windowWidth;
	static int windowHeight;
	

};

namespace Functions
{


	int getRandomInt(int min, int max);

	void drawPillars(std::vector<sf::RectangleShape*>& pillarsToSort, sf::RenderWindow* window);

	void setGreenColorAfterSort(std::vector<sf::RectangleShape*>& pillarsToSort,
		sf::RenderWindow* window);

	void delay(sf::Clock& sortSpeed, float time);

	void updateTimer(const sf::Clock& timer);

	void swapPillars(int firstPillarIndex, int secoundPillarIndex,
		std::vector<sf::RectangleShape*>& allPillars);

	int caluculateNextGap(int gap);

	//Sorting algorithms
	void selectionSort(std::vector<sf::RectangleShape*>& pillarsToSort,
		sf::Clock& sortSpeed, sf::RenderWindow* window);

	void bubbleSort(std::vector<sf::RectangleShape*>& pillarsToSort,
		sf::Clock& sortSpeed, sf::RenderWindow* window);

	void insertionSort(std::vector<sf::RectangleShape*>& pillarsToSort,
		sf::Clock& sortSpeed, sf::RenderWindow* window);

	int partitionRelativeToPivot(std::vector<sf::RectangleShape*>& pillarsToSort,
		int startIndex, int endIndex, sf::RenderWindow* window, sf::Clock& sortSpeed);

	void quickSort(std::vector<sf::RectangleShape*>& pillarsToSort,
		int startIndex, int endIndex, sf::RenderWindow* window, sf::Clock& sortSpeed);

	void merge(std::vector<sf::RectangleShape*>& pillarsToSort,
		int startIndex, int endIndex,
		sf::RenderWindow* window, sf::Clock& sortSpeed);

	void mergeSort(std::vector<sf::RectangleShape*>& pillarsToSort,
		int startIndex, int endIndex,
		sf::RenderWindow* window, sf::Clock& sortSpeed);

	

}

