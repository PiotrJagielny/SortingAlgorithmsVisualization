#include "HeaderFiles.h"
#include "FunctionsAndVariables.h"

bool Variables::isSelectionSortSelected = false;
bool Variables::isBubbleSortSelected = false;

float Variables::timePerFrame = 0.0f;
short Variables::numberOfPillars = 0;
short Variables::delayInMilisecounds = 0;



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

		window->display();
	}

	void setGreenColorAfterSort(std::vector<sf::RectangleShape*>& pillarsToSort,
		sf::Clock& sortSpeed, sf::RenderWindow* window)
	{
		for (int iii{ 0 }; iii < pillarsToSort.size(); ++iii)
		{

			
			pillarsToSort[iii]->setFillColor(sf::Color::Green);
			window->draw(*pillarsToSort[iii]);

			float normalizeRimeRatio{1.0f / Variables::numberOfPillars};

			delay(sortSpeed, normalizeRimeRatio * 1000.0f);

			window->display();

		}
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

	void selectionSort(std::vector<sf::RectangleShape*>& pillarsToSort, sf::Clock& sortSpeed,
		sf::RenderWindow* window)
	{
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
			float pillarPositionXtemp{ pillarsToSort[iii]->getPosition().x };

			pillarsToSort[iii]->setPosition(
				pillarsToSort[smallestPillarIndex]->getPosition().x,
				pillarsToSort[iii]->getPosition().y
			);

			pillarsToSort[smallestPillarIndex]->setPosition(
				pillarPositionXtemp,
				pillarsToSort[smallestPillarIndex]->getPosition().y
			);

			std::swap(pillarsToSort[iii], pillarsToSort[smallestPillarIndex]);

			drawPillars(pillarsToSort, window);
			delay(sortSpeed, Variables::delayInMilisecounds);
		}
		setGreenColorAfterSort(pillarsToSort, sortSpeed, window);

	}

	void bubbleSort(std::vector<sf::RectangleShape*>& pillarsToSort, sf::Clock& sortSpeed, sf::RenderWindow* window)
	{
		for (int iii{ 0 }; iii < pillarsToSort.size(); ++iii)
		{


			for (int kkk{ 0 }; kkk < pillarsToSort.size() - iii - 1; ++kkk)
			{
				if (pillarsToSort[kkk]->getGlobalBounds().height >
					pillarsToSort[kkk + 1]->getGlobalBounds().height)
				{
					
					float pillarPositionXtemp{ pillarsToSort[kkk]->getPosition().x };

					pillarsToSort[kkk]->setPosition(
						pillarsToSort[kkk+1]->getPosition().x,
						pillarsToSort[kkk]->getPosition().y
					);

					pillarsToSort[kkk+1]->setPosition(
						pillarPositionXtemp,
						pillarsToSort[kkk+1]->getPosition().y
					);

					

					std::swap(pillarsToSort[kkk], pillarsToSort[kkk+1]);
				}
			}
			drawPillars(pillarsToSort, window);
			delay(sortSpeed, Variables::delayInMilisecounds);
			
		}
		setGreenColorAfterSort(pillarsToSort, sortSpeed, window);

	}
}
