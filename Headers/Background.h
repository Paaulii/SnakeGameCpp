#pragma once
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "MyTexture.h"

class Background : public IDrawable
{
private:
	float width;
	float height;
	sf::RectangleShape border;
	std::shared_ptr<MyTexture> texturePtr;
	sf::Sprite sprite;

public:
	// W momencie tworzenia obiektu zostaj� ustawione w�a�ciwo�ci areny
	Background();

	void SetTextureAndSprite(std::shared_ptr<MyTexture> texturePtr);

	// Funkcja rysuje w oknie gry aren�
	void Draw(sf::RenderWindow* window);

	// Zwraca kszta�t areny
	const sf::RectangleShape& GetShape() const;

private:
	// Ustawienie w�a�ciwo�ci areny
	void SetArenasProperties();
};
