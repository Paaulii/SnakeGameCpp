#pragma once
#include "MapItem.h"

class Block : public MapItem
{
public:
	// Konstruktor domy�lny
	Block();

	// Konstruktor parametryczny Block'a
	Block(float x, float y, std::shared_ptr<MyTexture> texturePtr);

	// Zwraca pozycje bloku
	const sf::Vector2f& GetPosition() const;
};