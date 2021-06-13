#pragma once
#include <SFML/Graphics.hpp>
#include "MyTexture.h"
#include "IDrawable.h"
#include "MyFont.h"

class SnakeSelectMenu : public IDrawable
{
private:
	// Struktura trzymaj�ca spirite'y g��w Snake'a
	struct SnakeHead : public IDrawable
	{
		sf::Sprite sprite;
		std::shared_ptr<MyTexture> texturePtr;

		// Konstruktor parametryczny
		SnakeHead(std::shared_ptr<MyTexture> texturePtr);

		// Ustawia pozycje sprite'a
		void SetPosition(sf::Vector2f position);

		// Sprawdza czy sprite zosta� klikni�ty
		const bool IsMouseOnSprite(sf::Vector2i& position) const;

		// Rysuje sprite'a
		void Draw(sf::RenderWindow* window);
	};

	std::vector<SnakeHead> snakes;
	sf::Text text;
	std::shared_ptr<MyFont> fontPtr;

public:
	// Konstruktor domy�lny
	SnakeSelectMenu();

	// Konstruktor parametryczny
	// Ustawia czcionk�
	SnakeSelectMenu(std::shared_ptr<MyFont> fontPtr);

	// Dodaje teksture oraz tworzy nowy obiekt SnakeHead
	// i dodaje go do wektora
	void AddTexture(std::shared_ptr<MyTexture> texturePtr);

	// Sprawdza, czy kt�ry� z SnakeHead'�w zawartych w wektorze
	// zosta� klikni�ty
	const MyTexture::Type GetClickedSnake(sf::Vector2i position) const;

	// Zmienia kolor snejka, je�li jest nad nim myszka
	void HighlightHoveredSnake(sf::Vector2i position);

	// Rysuje tekst oraz wszystkie elementy w wektorze SnakeHead'�w
	void Draw(sf::RenderWindow* window);

private:
	// Ustawia wszystkie pozycje SnakeHead'�w w wektorze
	void SetUpSnakes();

	// Ustawia wszystkie propercje tekstu
	void SetUpText();
};