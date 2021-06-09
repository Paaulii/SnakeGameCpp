#pragma once
#include "MapItem.h"

class PickUp : public MapItem
{
public:
	// Konstruktor domy�lny
	PickUp();

	// Konstruktor parametryczny PickUp'a
	// Wywo�uje konstruktor parametryczny dla MapItem
	PickUp(float x, float y, std::shared_ptr<MyTexture> texturePtr);
};