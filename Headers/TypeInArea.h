#pragma once
#include <SFML/Graphics.hpp>
#include "MyFont.h"

class TypeInArea
{
private:
	sf::String playerInput;
	sf::Text displayText;
	sf::Text topText;
	std::shared_ptr<MyFont> fontDisplayText;
	std::shared_ptr<MyFont> fontTopText;
	sf::RectangleShape rectangle;

public:
	// Konstruktor domy�lny
	TypeInArea();

	// Konstruktor parametryczny
	TypeInArea(std::shared_ptr<MyFont> fontDisplayText, std::shared_ptr<MyFont> fontTopText);

	// Aktualizuje aktualn� nazw� gracza
	void UpdateText(sf::String str);

	// Usuwa ostatni znak z nazwy gracza
	void EreseLastCharacter();

	// Rysuje ca�e pole do wpisywania
	void Draw(sf::RenderWindow* window);

	// Zwraca nazwe gracza
	std::string GetPlayerName();

private:
	// �aduje czcionk� i ustawia wszystkie parametry obu tekst�w
	void SetUpTextes();

	// Ustawia wszystkie paramertry prostok�ta
	void SetUpRectangle();
};