#pragma once

#include "MyTexture.h"
#include "Button.h"
#include "MyFont.h"

class Help 
{
private:
	enum class ScreenType
	{
		First,
		Second
	};

	sf::Sprite help;
	std::shared_ptr<MyTexture> helpFirstPageTexture;
	std::shared_ptr<MyTexture> helpSecondPageTexture;
	Button backButton;
	Button anotherPageButton;
	std::shared_ptr<MyFont> fontTitleText;
	ScreenType screenType;

public:
	// Konstruktor domy�lny
	Help();

	// Rysuje ekran pomocy
	void Draw(sf::RenderWindow* window);

	// Sprawdza, czy zosta� klikni�ty przycisk powrotu do menu 
	bool IsReturnButtonClicked(sf::Vector2i vec);

	// Sprawdza, czy zosta� klikni�ty przycisk nast�pnej strony
	void CheckIfAnotherPageButtonWasClicked(sf::Vector2i vec);

	// Ustawia czcionk�
	void SetFont(std::shared_ptr<MyFont> font);

	// Ustawia tekstur� z ekranem pomocy
	void SetTextures(std::shared_ptr<MyTexture> textureFirst, std::shared_ptr<MyTexture> textureSecond);

	// Pod�wietla przycisk je�li jest nad nim myszka
	void HiglightHoveredButton(sf::Vector2i vec);
};