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
private:

	Button start, highscore, help, credits, quit;
	Title snake;

	sf::RenderWindow* window;

	std::shared_ptr<MyFont> fontPtrTitle;
	std::shared_ptr<MyFont> fontPtrButtons;

	std::shared_ptr<MyTexture> texture;
	sf::Sprite sprite;

	bool isInMainMenu;

public:
	HighScoreManager* highScoreManagerPtr;
	Help helpScreen;
	Credits creditsScreen;
	enum class Mode
	{
		Default,
		HighScores,
		Credits,
		Help,
	};
	Mode currentMode;
	MainMenu(sf::RenderWindow& win, std::shared_ptr<MyFont> fontPtrTitle,
		std::shared_ptr<MyFont> fontPtrButtons, std::shared_ptr<MyTexture> menuTexture,
		std::shared_ptr<MyTexture> creditsTexture, std::shared_ptr<MyTexture> helpTexture, std::shared_ptr<MyTexture> help2Texture,
		HighScoreManager* highScoreManagerPtr);
	void DrawButtonsAndTitle();
	void CheckIfButtonWasClicked(sf::Vector2i vec);
	bool IsInMainMenu();
	void SetIsInMainMenu(bool value);

	// Pod�wietla przycisk je�li jest nad nim myszka
	void HighlightHoveredButton(sf::Vector2i vec);

private:
	void SetSprite();
};
