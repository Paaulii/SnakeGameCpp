#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "IDrawable.h"

class PickUp : public IDrawable
{
private:
	float posX;
	float posY;
	sf::RectangleShape shape;

public:
	// Konstruktor domy�lny
	PickUp();

	// Konstruktor parametryczny PickUp'a
	PickUp(float x, float y);

	// Rysuje PickUp'a w oknie gry
	void Draw(sf::RenderWindow* window);

	// Sprawdza, czy PickUp zosta� zebrany
	bool IsCollected(Snake* snake);

private:
	// Ustawia w�a�ciwo�ci PickUp'a
	void SetPickUpProperties();
};