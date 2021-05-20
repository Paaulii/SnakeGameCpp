#pragma once
#include "IDrawable.h"
#include "MyFont.h"

class Title : public IDrawable
{
private:
	sf::Text text;
	std::shared_ptr<MyFont> fontPtr;
public:
	// Konstruktor domy�lny
	Title();
	
	// Rysuje tekst
	void Draw(sf::RenderWindow* window);

	// Ustawia czcionk�
	void SetFont(std::shared_ptr<MyFont> fontPtr);
private:
	// Ustawia wszystkie parametry tekstu
	void SetUpText();
};