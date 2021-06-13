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
	Credits(); //konstruktor domy�lny
	void Draw(sf::RenderWindow* window); //rysuje ekran z autorami
	bool IsReturnButtonClicked(sf::Vector2i vec); //sprawdza, czy zosta� klikni�ty przycisk powrotu
	void SetFont(std::shared_ptr<MyFont> font); //ustawia czcionk� przycisku
	void SetTexture(std::shared_ptr<MyTexture> texture); //Ustawia tekstur� z autorami
	void HiglightHoveredButton(sf::Vector2i vec); // Pod�wietla przycisk je�li jest nad nim myszka
};