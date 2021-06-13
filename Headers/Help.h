#pragma once

#include "MyTexture.h"
#include "Button.h"
#include "MyFont.h"

class Help 
{
	sf::Sprite help;
	std::shared_ptr<MyTexture> helpTexture;
	Button back, prev_page, next_page;
	std::shared_ptr<MyFont> fontTitleText;

public:
	Help(); //konstruktor domy�lny
	void Draw(sf::RenderWindow* window, const std::string& which_page); //rysuje ekran pomocy
	bool CheckIfReturnButtonWasClicked(sf::Vector2i vec); //sprawdza, czy zosta� klikni�ty przycisk powrotu do menu 
	bool CheckIfNextPageButtonWasClicked(sf::Vector2i vec); //sprawdza, czy zosta� klikni�ty przycisk nast�pnej strony
	bool CheckIfPrevPageButtonWasClicked(sf::Vector2i vec); //sprawdza, czy zosta� klikni�ty przycisk pierwszej strony
	void SetFont(std::shared_ptr<MyFont> font); //ustawia czcionk�
	void SetTexture(std::shared_ptr<MyTexture> texture); //ustawia tekstur� z ekranem pomocy
};