#pragma once
#include "MapItem.h"

class Block : public MapItem
{
private:
	bool isFlickering;
	float timeBetweenFlickers;
	sf::Clock flickerClock;

public:
	// Konstruktor domy�lny
	Block();

	// Konstruktor parametryczny Block'a
	// Wywo�uje konstruktor parametryczny dla MapItem
	Block(float x, float y, std::shared_ptr<MyTexture> texturePtr);

	// Zwraca pozycje bloku
	const sf::Vector2f& GetPosition() const;

	// Sprawia,�e alfa koloru sprite si� zmienia, 
	// gdy zmienna isFlickering jest ustawiona na true
	void Flicker();

	// Zwraca warto�� logiczn�, czy Block miga
	const bool GetFlickerStatus() const;

	// Ustawia zmienn� isFlickering
	void SetFlickerStatus(bool val);
};