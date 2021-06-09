#pragma once
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "MyTexture.h"
#include "MyFont.h"

class PowerUpDisplayer : public IDrawable
{
private:
	std::shared_ptr<MyTexture> texturePtr;
	sf::Sprite sprite;

	std::shared_ptr<MyFont> fontPtr;
	sf::Text text;

	sf::Clock clock;

	bool shouldBeDrawn;

public:
	// Konstrutkor domy�lny
	PowerUpDisplayer();

	// Konstruktor parametryczny, ustawia czionk� tekstu
	PowerUpDisplayer(std::shared_ptr<MyFont> fontPtr);

	// Ustawia tekstur�, kt�ra ma si� wy�wietla�
	void SetTextureAndStartDrawing(std::shared_ptr<MyTexture> texturePtr);

	// Przestaje rysowa�
	void StopDrawing();

	// Rysuje obiekt w oknie
	void Draw(sf::RenderWindow* window);

	// Sprawia, �e gdy zostanie ma�o czasu, alfa koloru si� zmienia na ni�sz�
	void Flicker();

private:
	// Ustawia wszystkie parametry tekstu
	void SetUpText();
};