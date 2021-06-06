#pragma once
#include <SFML/Graphics.hpp>
#include "IDrawable.h"
#include "MyTexture.h"
#include "MyFont.h"

class ModeSelectMenu : public IDrawable
{
private:
	// Struktura trzymaj�ca spirite'y g��w Snake'a
	struct GameMode : public IDrawable
	{
		sf::Sprite sprite;
		std::shared_ptr<MyTexture> texturePtr;

		// Konstruktor parametryczny
		GameMode(std::shared_ptr<MyTexture> texturePtr);

		// Ustawia pozycje sprite'a
		void SetPosition(sf::Vector2f position);

		// Sprawdza czy sprite zosta� klikni�ty
		const bool IsClicked(sf::Vector2i& position) const;

		// Rysuje sprite'a
		void Draw(sf::RenderWindow* window);
	};

	std::vector<GameMode> modes;
	sf::Text text;
	std::shared_ptr<MyFont> fontPtr;

public:
	// Konstruktor domy�lny
	ModeSelectMenu();

	// Konstruktor parametryczny
	ModeSelectMenu(std::shared_ptr<MyFont> fontPtr);

	// Dodaje teksture oraz tworzy nowy obiekt GameMode'a
	// i dodaje go do wektora
	void AddTexture(std::shared_ptr<MyTexture> texturePtr);

	// Sprawdza, czy kt�ry� z GameMod�w zawartych w wektorze
	// zosta� klikni�ty
	const MyTexture::Type GetClickedMode(sf::Vector2i position) const;

	// Rysuje tekst oraz wszystkie elementy w wektorze GameM�de'�w
	void Draw(sf::RenderWindow* window);

private:
	// Ustawia wszystkie pozycje GameMode'�w w wektorze
	void SetUpGameModes();

	// Ustawia wszystkie propercje tekstu
	void SetUpText();
};
