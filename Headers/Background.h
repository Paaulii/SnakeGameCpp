#pragma once
#include <SFML/Graphics.hpp>
#include "IDrawable.h"

class Background : public IDrawable
{
private:
	float width;
	float height;
	sf::RectangleShape arena;
public:
	// W momencie tworzenia obiektu zostaj� ustawione w�a�ciwo�ci areny
	Background();

	// Ustawienie w�a�ciwo�ci areny
	void SetArenasProperties();

	// Funkcja rysuje w oknie gry aren�
	void Draw(sf::RenderWindow* window);

	// Zwraca kszta�t areny
	const sf::RectangleShape& GetShape() const;
};
