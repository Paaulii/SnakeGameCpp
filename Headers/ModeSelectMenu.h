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
		sf::Text text;
		std::shared_ptr<MyTexture> texturePtr;
		std::shared_ptr<MyFont> fontPtr;

		// Konstruktor parametryczny, ustawia odpowiedni� tekstur� oraz
		// Czcionk� tekstu pod sprite'm
		GameMode(std::shared_ptr<MyTexture> texturePtr, std::shared_ptr<MyFont> fontPtr);

		// Ustawia pozycje sprite'a
		void SetPosition(sf::Vector2f position);

		// Sprawdza czy sprite zosta� klikni�ty
		const bool IsMouseOnGameMode(sf::Vector2i& position) const;

		// Rysuje sprite'a
		void Draw(sf::RenderWindow* window);

		void SetUpText(const std::string& str);
	};

	std::vector<GameMode> modes;
	sf::Text text;
	std::shared_ptr<MyFont> fontTitle;
	std::shared_ptr<MyFont> fontDescription;

public:
	// Konstruktor domy�lny
	ModeSelectMenu();

	// Konstruktor parametryczny
	// Ustawia czcionk� tytu�u oraz czcionk� pod teksturami tryb�w
	ModeSelectMenu(std::shared_ptr<MyFont> fontPtr, std::shared_ptr<MyFont> descFontPtr);

	// Dodaje teksture oraz tworzy nowy obiekt GameMode'a
	// i dodaje go do wektora
	void AddTexture(std::shared_ptr<MyTexture> texturePtr);

	// Sprawdza, czy kt�ry� z GameMod�w zawartych w wektorze
	// zosta� klikni�ty
	const MyTexture::Type GetClickedMode(sf::Vector2i position) const;

	// Zmienia kolor mode'u, je�li jest nad nim myszka
	void HighlightHoveredMode(sf::Vector2i position);

	// Rysuje tekst oraz wszystkie elementy w wektorze GameM�de'�w
	void Draw(sf::RenderWindow* window);

private:
	// Ustawia wszystkie pozycje GameMode'�w w wektorze
	void SetUpGameModes();

	// Ustawia wszystkie propercje tekstu
	void SetUpText();
};
