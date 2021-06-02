#pragma once
#include "PickableItem.h"

class PickUp : public PickableItem
{
public:
	// Konstruktor domy�lny
	PickUp();

	// Konstruktor parametryczny PickUp'a
	PickUp(float x, float y, std::shared_ptr<MyTexture> texturePtr);
};