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
#include "PowerUp.h"

class GameManager
{
private:
	bool isPickUpCollected;
	bool isGameOver;
	bool isInSnakeSelect;
	bool isPowerUpCollected;
	bool isReversed;

	float snakeSpeedMultiplier;
	float timeBetweenPowerUps;
	float powerUpDuration;

	sf::Clock clock;
	sf::Clock durationTime;

	Snake snake;
	PickUp pickUp;
	PowerUp powerUp;
	

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

	// Rysuje obiekty znajduj�cie si� na obrazie, kt�ry jest widoczny
	// podczas sko�czenia gry
	void DrawEndGameObjects(sf::RenderWindow* window);

	// Rysuje menu wyboru snake'a
	void DrawSnakeSelectMenu(sf::RenderWindow* window);

	// Porusza Snake'iem
	void MoveSnake();

	// Ustawia kierunek Snake'a
	void SetSnakeDirection(Snake::Direction direction);

	// Sprawdza obecne po�o�enie snake'a : 
	// czy znajduje si� w arenie lub czy dosz�o do kolizji (czy zjad� siebie)
	void CheckWhereIsSnake();

	// Sprawdza, czy PickUp lub PowerUp zosta� zebrany, je�li tak (PickUp): dodaje punkt
	// do score'a, zwi�ksza w�a, generuje kolejny PickUp
	// Je�eli PowerUp jest zebrany i min�� okre�lony czas to generuje kolejny PowerUp
	void CheckIfPickupOrPowerUpIsCollected();

	void CheckPowerUpDuration();

	bool const IsReversed() const;

	void TurnOffPowerUp();

	void SetReversion();

	void TurnOffReversion();

	void FlickerBorder();

	// Daje Snake'owi okre�lony PowerUp
	void GiveSnakePower(PowerUp::UpgradeType upgradeType);

	// Od�wie�a Highscora
	void UpdateHighScores();

	// Resetuje wszystkie parametry gry, aby mo�na by�o j� zacz�� od nowa
	void ResetGame();

	// Sprawdza czy gra si� sko�czy�a
	bool IsGameOver();

	// Zwraca warto�� logiczn�, czy gracz dalej znajduje si� w menu wyboru snejka
	bool IsInSnakeSelectMenu();

	// Sprawdza czy snejk zosta� wybrany przez gracza, je�li tak
	// to ustawia go na domy�lnego w aktualnej grze
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

	// Generuje Powerup'a je�li up�yn�� odpowiedni czas
	void GeneratePowerUp();

	// Generowanie pocz�tkowej pozycji snake'a
	void GenerateSnakePosition();
};