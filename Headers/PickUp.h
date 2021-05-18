#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"

class PickUp
{
private:
	int posX;
	int posY;
	sf::RectangleShape shape;

	// Ustawia w�a�ciwo�ci PickUp'a
	void SetPickUpProperties();
public:
	// Konstruktor domy�lny
	PickUp();

	// Konstruktor parametryczny PickUp'a
	PickUp(int x, int y);

	// Rysuje PickUp'a w oknie gry
	void Draw(sf::RenderWindow* window);

	// Sprawdza, czy PickUp zosta� zebrany
	bool IsCollected(Snake* snake);
};