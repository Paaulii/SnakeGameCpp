#pragma once
#include "Snake.h"
#include "PickUp.h"
#include "Background.h"
#include "TexturesManager.h"
#include "FontsManager.h"
#include "ScoreManager.h"

class GameManager
{
private:
	bool isPickUpCollected;
	bool isGameOver;

	Snake snake;
	PickUp pickUp;
	Background background;
	TexturesManager texturesManager;
	FontsManager fontsManager;
	ScoreManager scoreManager;

	std::vector<IDrawable*> drawableInGameObjects;

public:
	// Podczas tworzenia obiektu ustawia wszystkie parametry swoich atrybut�w
	GameManager();

	// Rysuje wszystkie rysowalne obiekty, kt�re znajduj� si� w oknie podczas trwania gry
	// �eby narysowa� obiekt, musi by� zawarty w wektorze "drawableInGameObjects"
	void DrawInGameObjects(sf::RenderWindow* window);

	// Porusza Snake'iem
	void MoveSnake();

	// Ustawia kierunek Snake'a
	void SetSnakeDirection(Snake::Direction direction);

	// Sprawdza obecne po�o�enie snake'a : 
	// czy znajduje si� w arenie lub czy dosz�o do kolizji (czy zjad� siebie)
	void CheckWhereIsSnake();

	// Sprawdza, czy PickUp zosta� zebrany, je�li tak: dodaje punkt
	// do score'a, zwi�ksza w�a, generuje kolejny PickUp
	void CheckPickUp();

	// Sprawdza czy gra si� sko�czy�a
	bool IsGameOver();

	// Zwraca obiekt klasy TextureManager
	const TexturesManager& GetTextureManager() const;

	// Zwraca obiekt klasy FontsManager
	const FontsManager& GetFontsManager() const;

	// Zwraca obiekt klasy ScoreManager
	const ScoreManager& GetScoreManager() const;

private:
	// Generuje PickUp'a 
	void GeneratePickUp();

	// Generowanie pocz�tkowej pozycji snake'a
	void GenerateSnakePosition();
};