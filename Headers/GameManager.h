#pragma once
#include "Snake.h"
#include "PickUp.h"
#include "Background.h"
#include "TexturesManager.h"
#include "FontsManager.h"
#include "ScoreManager.h"
#include "LoseScreen.h"
#include "TypeInArea.h"
#include "HighScoreManager.h"
#include "Title.h"
#include "AudioManager.h"
#include "SnakeSelectMenu.h"

class GameManager
{
private:
	bool isPickUpCollected;
	bool isGameOver;
	bool isInSnakeSelect;

	Snake snake;
	PickUp pickUp;
	Background background;
	Title title;

	LoseScreen loseScreen;
	TypeInArea typeInArea;

	SnakeSelectMenu snakeSelectMenu;

	HighScoreManager highScoreManager;
	TexturesManager texturesManager;
	AudioManager audioManager;
	FontsManager fontsManager;
	ScoreManager scoreManager;

	std::vector<IDrawable*> drawableInGameObjects;
	std::vector<IDrawable*> drawableEndGameObjects;

public:
	// Podczas tworzenia obiektu ustawia wszystkie parametry swoich atrybut�w
	GameManager();

	// Rysuje wszystkie rysowalne obiekty, kt�re znajduj� si� w oknie podczas trwania gry
	// �eby narysowa� obiekt, musi by� zawarty w wektorze "drawableInGameObjects"
	void DrawInGameObjects(sf::RenderWindow* window);

	void DrawEndGameObjects(sf::RenderWindow* window);

	void DrawSnakeSelectMenu(sf::RenderWindow* window);

	// Porusza Snake'iem
	void MoveSnake();

	// Ustawia kierunek Snake'a
	void SetSnakeDirection(Snake::Direction direction);

	// Sprawdza obecne po�o�enie snake'a : 
	// czy znajduje si� w arenie lub czy dosz�o do kolizji (czy zjad� siebie)
	void CheckWhereIsSnake();

	// Sprawdza, czy PickUp zosta� zebrany, je�li tak: dodaje punkt
	// do score'a, zwi�ksza w�a, generuje kolejny PickUp
	void CheckIfPickupIsCollected();

	void UpdateHighScores();

	void ResetGame();

	// Sprawdza czy gra si� sko�czy�a
	bool IsGameOver();

	bool IsInSnakeSelectMenu();

	void CheckIfSnakeWasSelected(sf::Vector2i position);

	// Zwraca obiekt klasy TextureManager
	const TexturesManager& GetTextureManager() const;

	// Zwraca obiekt klasy FontsManager
	const FontsManager& GetFontsManager() const;

	// Zwraca obiekt klasy ScoreManager
	const ScoreManager& GetScoreManager() const;

	// Zwraca obiekt klasy HighScoreManager
	const HighScoreManager& GetHighScoreManager() const;
	
	// Zwraca obiekt klasy AudiManager
	const AudioManager& GetAudioManager() const;

	// Zwraca obiekt kalsy TypeInAreaManager
	TypeInArea& GetTypeInAreaManager();

private:
	// Generuje PickUp'a 
	void GeneratePickUp();

	// Generowanie pocz�tkowej pozycji snake'a
	void GenerateSnakePosition();
};