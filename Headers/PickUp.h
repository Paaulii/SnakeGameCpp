#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "IDrawable.h"
#include "MyTexture.h"

class PickUp : public IDrawable
{
private:
	float posX;
	float posY;
	std::shared_ptr<MyTexture> texturePtr;
	sf::Sprite sprite;

public:
	// Konstruktor domy�lny
	PickUp();

	// Konstruktor parametryczny PickUp'a
	PickUp(float x, float y, std::shared_ptr<MyTexture> texturePtr);

	// Rysuje PickUp'a w oknie gry
	void Draw(sf::RenderWindow* window);

	// Sprawdza, czy PickUp zosta� zebrany
	bool IsCollected(Snake* snake);

	// Zwraca rozmiar sprite'a
	const sf::Vector2u GetSize() const;
	
	// Zwraca wska�nik do tekstury 
	const std::shared_ptr<MyTexture> GetTexture() const;

private:
	// Ustawia w�a�ciwo�ci PickUp'a
	void SetSpriteProperties();
};