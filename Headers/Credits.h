#pragma once
#include "IDrawable.h"
#include "MyTexture.h"
#include "Button.h"
#include "MyFont.h"

class Credits : public IDrawable 
{
	sf::Sprite sprite;
	std::shared_ptr<MyTexture> texture;
	Button back;
	std::shared_ptr<MyFont> fontTitleText;

public:
	// Konstruktor domy�lny
	Credits();

	// Rysuje ekran z autorami
	void Draw(sf::RenderWindow* window);

	// Sprawdza, czy zosta� klikni�ty przycisk powrotu
	bool IsReturnButtonClicked(sf::Vector2i vec);

	// Ustawia czcionk� przycisku
	void SetFont(std::shared_ptr<MyFont> font);

	// Ustawia tekstur� z autorami
	void SetTexture(std::shared_ptr<MyTexture> texture);

	// Pod�wietla przycisk je�li jest nad nim myszka
	void HiglightHoveredButton(sf::Vector2i vec);
};