#pragma once
#include <SFML/Graphics.hpp>
#include "MyFont.h"
#include "TypeInArea.h"
#include "IDrawable.h"

class LoseScreen : public IDrawable
{
private:
	sf::Text titleText;
	std::shared_ptr<MyFont> fontTitle;
	sf::Text scoreText;
	std::shared_ptr<MyFont> fontScore;
	sf::Text infoText;
	std::shared_ptr<MyFont> fontInfo;

public:
	// Konstruktor domy�lny
	LoseScreen();

	// Konstruktor parametryczny
	// ustawia wska�niki do czcionek, podane w parametrach
	LoseScreen(std::shared_ptr<MyFont> fontTitle, std::shared_ptr<MyFont> fontScore);

	// Rysuje teksty
	void Draw(sf::RenderWindow* window);

	// Ustawia score do wy�wietlenia
	void SetScore(int score);

private:
	// Ustawia wszystkie parametry tekstu
	void SetUpTextes();
};