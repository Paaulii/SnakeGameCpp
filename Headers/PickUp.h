#pragma once
#include "MapItem.h"

class PickUp : public MapItem
{
public:
	// Konstruktor domy�lny
	PickUp();

	// Konstruktor parametryczny PickUp'a
	PickUp(float x, float y, std::shared_ptr<MyTexture> texturePtr);
};