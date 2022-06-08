#include "HeaderFiles.h"
#include "FunctionsAndVariables.h"
#include "VisualizationState.h"

bool Variables::isSelectionSortSelected = false;
bool Variables::isBubbleSortSelected = false;
bool Variables::isInsertionSortClicked = false;
bool Variables::isQuickSortClicked = false;
bool Variables::isMergeSortClicked = false;

float Variables::timePerFrame = 0.0f;
short Variables::numberOfPillars = 0;
short Variables::delayInMilisecounds = 0;

bool Variables::assignArrayOnce = true;
std::vector<sf::RectangleShape*> Variables::pillarsDuplicate;

int Variables::windowHeight = 950;
int Variables::windowWidth = 1400;


namespace Functions
{

	int getRandomInt(int min, int max)
	{
		static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

		return std::uniform_int_distribution<>{ min, max }(mt);
	}


	void drawPillars(std::vector<sf::RectangleShape*>& pillarsToSort, sf::RenderWindow* window)
	{
		window->clear();

		for (auto* pillar : pillarsToSort)
		{
			window->draw(*pillar);

		}
		window->draw(VisualizationState::timerText);
		window->display();
	}

	void setGreenColorAfterSort(std::vector<sf::RectangleShape*>& pillarsToSort,
		 sf::RenderWindow* window)
	{
		for (int iii{ 0 }; iii < pillarsToSort.size(); ++iii)
		{
			pillarsToSort[iii]->setFillColor(sf::Color::Green);
		}
		drawPillars(pillarsToSort, window);
	}

	void delay(sf::Clock& sortSpeed, float time)
	{

		while (true)
		{

			if (sortSpeed.getElapsedTime().asMilliseconds() >= time )
			{
				sortSpeed.restart();
				return;
			}
				
		}
	}



	void updateTimer(const sf::Clock& timer)
	{
		std::stringstream getTimeString;

		getTimeString << "Timer: " << timer.getElapsedTime().asSeconds() << 's';

		VisualizationState::timerText.setString(getTimeString.str());
	}

	void swapPillars(int firstPillarIndex, int secoundPillarIndex, std::vector<sf::RectangleShape*>& allPillars)
	{
		float pillarPositionXtemp{ allPillars[firstPillarIndex]->getPosition().x };

		allPillars[firstPillarIndex]->setPosition(
			allPillars[secoundPillarIndex]->getPosition().x,
			allPillars[firstPillarIndex]->getPosition().y
		);

		allPillars[secoundPillarIndex]->setPosition(
			pillarPositionXtemp,
			allPillars[secoundPillarIndex]->getPosition().y
		);

		std::swap(allPillars[firstPillarIndex], allPillars[secoundPillarIndex]);

	}

	int caluculateNextGap(int gap)
	{
		if (gap <= 1)
			return 0;

		return (int)ceil(gap/2.0);
	}


	//Sorting algorithms

	void selectionSort(std::vector<sf::RectangleShape*>& pillarsToSort, sf::Clock& sortSpeed,
		sf::RenderWindow* window)
	{
		VisualizationState::timer.restart();
		for (int iii{ 0 }; iii < pillarsToSort.size(); ++iii)
		{


			int smallestPillarIndex{ iii };
			for (int kkk{ iii + 1 }; kkk < pillarsToSort.size(); ++kkk)
			{

				if (pillarsToSort[kkk]->getGlobalBounds().height <
					pillarsToSort[smallestPillarIndex]->getGlobalBounds().height)
				{
					smallestPillarIndex = kkk;
				}

			}
		
			swapPillars(iii, smallestPillarIndex, pillarsToSort);
			drawPillars(pillarsToSort, window);
			delay(sortSpeed, Variables::delayInMilisecounds);
			updateTimer(VisualizationState::timer);
		}

		setGreenColorAfterSort(pillarsToSort, window);

	}

	void bubbleSort(std::vector<sf::RectangleShape*>& pillarsToSort, sf::Clock& sortSpeed, sf::RenderWindow* window)
	{
		VisualizationState::timer.restart();
		for (int iii{ 0 }; iii < pillarsToSort.size(); ++iii)
		{


			for (int kkk{ 0 }; kkk < pillarsToSort.size() - iii - 1; ++kkk)
			{
				if (pillarsToSort[kkk]->getGlobalBounds().height >
					pillarsToSort[kkk + 1]->getGlobalBounds().height)
				{
					swapPillars(kkk, kkk + 1, pillarsToSort);
					
				}
			}
			drawPillars(pillarsToSort, window);
			delay(sortSpeed, Variables::delayInMilisecounds);
			updateTimer(VisualizationState::timer);
		}
		setGreenColorAfterSort(pillarsToSort, window);
		
	}


	void insertionSort(std::vector<sf::RectangleShape*>& pillarsToSort, sf::Clock& sortSpeed, sf::RenderWindow* window)
	{
		VisualizationState::timer.restart();
		for (int iii{ 1 }; iii < pillarsToSort.size(); ++iii)
		{
			bool isBiggestInSortedArray{ false };

			for (int kkk{ iii }; kkk >= 1 && isBiggestInSortedArray == false; --kkk)
			{
				if (pillarsToSort[kkk]->getGlobalBounds().height <
					pillarsToSort[kkk - 1]->getGlobalBounds().height)
				{
					swapPillars(kkk, kkk - 1, pillarsToSort);
					
				}
				else
				{
					isBiggestInSortedArray = true;
				}
			}
			drawPillars(pillarsToSort, window);
			delay(sortSpeed, Variables::delayInMilisecounds);
			updateTimer(VisualizationState::timer);
		}

		setGreenColorAfterSort(pillarsToSort, window);
	}


	int partitionRelativeToPivot(std::vector<sf::RectangleShape*>& pillarsToSort, int startIndex, int endIndex,
		sf::RenderWindow* window, sf::Clock& sortSpeed)
	{
		int pivot{ static_cast<int>(pillarsToSort[endIndex]->getGlobalBounds().height) };
		int partitionIndex{ startIndex };

		for (int iii{ startIndex }; iii < endIndex; ++iii)
		{
			if (pillarsToSort[iii]->getGlobalBounds().height <= pivot)
			{
				swapPillars(iii, partitionIndex, pillarsToSort);
				++partitionIndex;
			}
			if (iii % 4 == 0)
			{
				drawPillars(pillarsToSort, window);
				delay(sortSpeed, Variables::delayInMilisecounds);
				updateTimer(VisualizationState::timer);
			}
		}
		swapPillars(endIndex, partitionIndex, pillarsToSort);

		

		return partitionIndex;
	}

	void quickSort(std::vector<sf::RectangleShape*>& pillarsToSort, int startIndex, int endIndex,
		sf::RenderWindow* window, sf::Clock& sortSpeed)
	{
		if (startIndex >= endIndex)
			return;

		

		int pivotIndex{ partitionRelativeToPivot(pillarsToSort, startIndex, endIndex,window, sortSpeed) };

		quickSort(pillarsToSort, startIndex, pivotIndex - 1, window, sortSpeed);
		quickSort(pillarsToSort, pivotIndex + 1, endIndex, window, sortSpeed);
		
	}

	
	void merge(std::vector<sf::RectangleShape*>& pillarsToSort, int startIndex, int endIndex,
		sf::RenderWindow* window, sf::Clock& sortSpeed)
	{
		int gap{ endIndex - startIndex + 1 };

		for (gap = caluculateNextGap(gap); gap > 0; gap = caluculateNextGap(gap))
		{
			for (int iii{ startIndex }; iii + gap <= endIndex; ++iii)
			{
				if (pillarsToSort[iii]->getGlobalBounds().height >
					pillarsToSort[iii + gap]->getGlobalBounds().height)
				{
					swapPillars(iii, iii + gap, pillarsToSort);
				}
			}
			drawPillars(pillarsToSort, window);
			delay(sortSpeed, Variables::delayInMilisecounds);
			updateTimer(VisualizationState::timer);
		}

	}

	void mergeSort(std::vector<sf::RectangleShape*>& pillarsToSort, int startIndex, int endIndex,
		sf::RenderWindow* window, sf::Clock& sortSpeed)
	{
		if (startIndex == endIndex)
			return;
		
		int middleIndex{ (startIndex + endIndex) / 2 };

		mergeSort(pillarsToSort, startIndex, middleIndex, window, sortSpeed);
		mergeSort(pillarsToSort, middleIndex + 1, endIndex, window, sortSpeed);

		merge(pillarsToSort,startIndex,endIndex, window, sortSpeed);
		

	}
	
}
