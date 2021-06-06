#pragma once
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "IDrawable.h"
#include "MyTexture.h"

// G��wna klasa przedmiot�w, kt�re w�� mo�e podnosi�
class MapItem : public IDrawable
{
protected:
	float posX;
	float posY;
	std::shared_ptr<MyTexture> texturePtr;
	sf::Sprite sprite;

public:
	// Konstruktor domy�lny
	MapItem();

	// Konstuktor parametryczny
	MapItem(float x, float y, std::shared_ptr<MyTexture> texturePtr);

	// Rysuje sprite'a
	void Draw(sf::RenderWindow* window);

	// Zwraca warto��, czy snake znajduje si� na przedmiocie, czy nie
	bool IsColliding(Snake* snake);

	// Zwraca rozmiar sprite'a
	const sf::Vector2u GetSize() const;

	// Zwraca wska�nik do tekstury 
	const std::shared_ptr<MyTexture> GetTexture() const;

protected:
	// Ustawia wszystkie parametry sprite'a
	void SetSpriteProperties();
};