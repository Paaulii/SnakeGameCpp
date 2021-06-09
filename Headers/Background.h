#pragma once
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "MyTexture.h"

class Background : public IDrawable
{
private:
	float width;
	float height;

	float timeBetweenFlickers;

	sf::RectangleShape border;
	std::shared_ptr<MyTexture> texturePtr;
	sf::Sprite sprite;

	bool isBorderFlickering;

	sf::Clock flickerClock;

public:
	// W momencie tworzenia obiektu zostaj� ustawione w�a�ciwo�ci areny
	Background();

	// Ustawia texture oraz sprite'a
	void SetTextureAndSprite(std::shared_ptr<MyTexture> texturePtr);

	// Funkcja rysuje w oknie gry aren�
	void Draw(sf::RenderWindow* window);

	// Sprawia,�e alfa koloru sprite si� zmienia, 
	// gdy zmienna isBorderFlickering jest ustawiona na true
	void Flicker();

	// Zwraca true, gdy granica areny ma miga�
	const bool GetFlickerStatus() const;

	// Ustawia warto�� zmiennej isBorderFlickering
	void SetFlickerStatus(bool val);

	// Zwraca kszta�t areny
	const sf::RectangleShape& GetShape() const;

private:
	// Ustawienie w�a�ciwo�ci areny
	void SetArenasProperties();
};
