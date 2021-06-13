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
#include "PowerUpDisplayer.h"
#include "Block.h"
#include "ModeSelectMenu.h"

class GameManager
{
private:
	bool isPickUpCollected;
	bool isGameOver;
	bool isInSnakeSelect;
	bool isInModeSelect;
	bool isPowerUpCollected;
	bool isReversed;
	bool isPlayingClassicMode;

	int howManyBlocks;

	float snakeSpeedMultiplier;
	float timeBetweenPowerUps;
	float powerUpDuration;

	sf::Clock clock;
	sf::Clock durationTime;

	Snake snake;
	PickUp pickUp;
	PowerUp powerUp;

	std::vector<Block*> blocks;

	Background background;
	Title title;
	PowerUpDisplayer powerUpDisplayer;

	LoseScreen loseScreen;
	TypeInArea typeInArea;

	SnakeSelectMenu snakeSelectMenu;
	ModeSelectMenu modeSelectMenu;

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

	// Destruktror, usuwa wszystkie obiekty zalokowane dynamicznie
	~GameManager();

	// Rysuje wszystkie rysowalne obiekty, kt�re znajduj� si� w oknie podczas trwania gry
	// �eby narysowa� obiekt, musi by� zawarty w wektorze "drawableInGameObjects"
	void DrawInGameObjects(sf::RenderWindow* window);

	// Rysuje obiekty znajduj�cie si� na obrazie, kt�ry jest widoczny
	// podczas sko�czenia gry
	void DrawEndGameObjects(sf::RenderWindow* window);

	// Rysuje menu wyboru snake'a
	void DrawSnakeSelectMenu(sf::RenderWindow* window);

	// Rysuje menu wyboru trybu gry
	void DrawModeSelectMenu(sf::RenderWindow* window);

	// Porusza Snake'iem
	void MoveSnake();

	// Ustawia kierunek Snake'a
	void SetSnakeDirection(Snake::Direction direction);

	// Sprawdza obecne po�o�enie snake'a : 
	// czy znajduje si� w arenie lub czy dosz�o do kolizji (czy zjad� siebie)
	void CheckWhereIsSnake();

	// Sprawdza, czy PickUp lub PowerUp zosta� zebrany, je�li tak (PickUp): dodaje punkt
	// do score'a, zwi�ksza w�a, generuje kolejny PickUp
	// Je�eli PowerUp jest zebrany lub min�� okre�lony czas to generuje kolejny PowerUp
	void CheckIfPickupOrPowerUpIsCollected();

	//Sprawdza, czy czas Power Up'a si� sko�czy�, je�li tak to wy��cza Power Up'a
	void CheckPowerUpDuration();

	// Wywo�uje u obiekt�w przeszk�d metod� Flicker()
	void FlickerObjects();

	// Sprawdza, czy gra jest w trybie odwr�conym (G�ra->D� , Lewo->Prawo)
	bool const IsReversed() const;

	// Daje Snake'owi okre�lony PowerUp
	void GiveSnakePower(PowerUp::UpgradeType upgradeType);

	// Od�wie�a Highscora
	void UpdateHighScores();

	// Resetuje wszystkie parametry gry, aby mo�na by�o j� zacz�� od nowa
	void ResetGame();

	// Sprawdza czy gra si� sko�czy�a
	bool IsGameOver();

	// Zwraca warto�� logiczn�, czy gracz dalej znajduje si� w menu wyboru trybu
	bool IsInModeSelectMenu();

	// Zwraca warto�� logiczn�, czy gracz dalej znajduje si� w menu wyboru snejka
	bool IsInSnakeSelectMenu();

	// Sprawdza czy snejk zosta� wybrany przez gracza, je�li tak
	// to ustawia go na domy�lnego w aktualnej grze
	void CheckIfSnakeWasSelected(sf::Vector2i position);

	// Sprawdza czy mode zosta� wybrany przez gracza, je�li tak
	// to ustawia go na domy�lnego w aktualnej grze
	void CheckIfModeWasSelected(sf::Vector2i position);

	// Zwraca obiekt klasy TextureManager
	const TexturesManager& GetTextureManager() const;

	// Zwraca obiekt klasy FontsManager
	const FontsManager& GetFontsManager() const;

	// Zwraca obiekt klasy ScoreManager
	const ScoreManager& GetScoreManager() const;

	// Zwraca obiekt klasy HighScoreManager
	HighScoreManager& GetHighScoreManager();
	
	// Zwraca obiekt klasy AudiManager
	AudioManager& GetAudioManager();

	// Zwraca obiekt klasy TypeInAreaManager
	TypeInArea& GetTypeInAreaManager();

	// Zwraca obiekt klasy SnakeSelectMenu
	SnakeSelectMenu& GetSnakeSelectMenu();

private:
	// Generuje PickUp'a 
	void GeneratePickUp();

	// Generuje Powerup'a je�li up�yn�� odpowiedni czas
	void GeneratePowerUp();

	void GenerateBlock();

	// Generowanie pocz�tkowej pozycji snake'a
	void GenerateSnakePosition();

	bool IsObjectOnBlock(float posX, float posY, sf::Vector2u pickUpSize, float additionalValue = 0.0f);

	// Wy��cza odpowiedniego Power Up'a
	void TurnOffPowerUp();

	// Ustawia gr� w tryb odwr�cony, gdy skr�casz w prawo, jedziesz w lewo
	void SetReversion(bool val);
};