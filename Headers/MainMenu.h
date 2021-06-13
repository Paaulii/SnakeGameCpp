#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "IDrawable.h"
#include "Title.h"
#include "HighScoreManager.h"
#include "MyTexture.h"
#include "Help.h"
#include "Credits.h"

class MainMenu 
{
public:
	enum class Mode
	{
		Default,
		HighScores,
		Credits,
		Help,
	};

private:

	Button start, highscore, help, credits, quit;
	Title snake;

	sf::RenderWindow* window;

	std::shared_ptr<MyFont> fontPtrTitle;
	std::shared_ptr<MyFont> fontPtrButtons;

	std::shared_ptr<MyTexture> texture;
	sf::Sprite sprite;

	bool isInMainMenu;

	Mode currentMode;

	Credits creditsScreen;
	Help helpScreen;
	HighScoreManager* highScoreManagerPtr;

public:
	// Konstruktor domy�lny, ustawia wszystkie zmienne, tekstury oraz czcionki
	// Tworzy odpowiednie Button'y
	MainMenu(sf::RenderWindow& win, std::shared_ptr<MyFont> fontPtrTitle,
		std::shared_ptr<MyFont> fontPtrButtons, std::shared_ptr<MyTexture> menuTexture,
		std::shared_ptr<MyTexture> creditsTexture, std::shared_ptr<MyTexture> helpTexture, std::shared_ptr<MyTexture> help2Texture,
		HighScoreManager* highScoreManagerPtr);

	// Rysuje odpowiednie obiekty na ekranie w zale�no�ci
	// Od tego w kt�rym oknie menu gracz si� znajduje
	void Draw();

	// Sprawdza czy przycisk zosta� klikni�ty
	// Je�eli tak wykonuje odpowiedni� akcj�
	void CheckIfButtonWasClicked(sf::Vector2i vec);

	// Zwraca true, je�li gracz jest w menu g��wnym
	bool IsInMainMenu();

	// Ustawia zmienn� IsInMainMenu
	void SetIsInMainMenu(bool value);

	// Zwraca aktualny mode
	Mode GetCurrentMode();

	// Zwraca referencje do obiektu Credits
	Credits& GetCreditsScreen();

	// Zwraca referencje do obiektu Help
	Help& GetHelpScreen();

	// Zwraca pointer do obiektu HighScoreManager
	HighScoreManager* GetHighScoreManagerPtr();

	// Ustawia aktualny mode
	void SetCurrentMode(Mode mode);

	// Pod�wietla przycisk je�li jest nad nim myszka
	void HighlightHoveredButton(sf::Vector2i vec);

private:
	// Ustawia wszystkie w�asno�ci sprite'a
	void SetSprite();
};
