#pragma once
#include "Snake.h"
#include "PickUp.h"
#include "Background.h"
#include "TexturesManager.h"

class GameManager
{
private:
	int scores;
	bool isPickUpCollected;
	bool isGameOver;
	Snake snake;
	PickUp pickUp;
	Background background;
	TexturesManager texturesManager;

public:
	// Podczas tworzenia obiektu wygeneruje pocz�tkowe po�o�enie snake'a
	GameManager();

	// Generowanie pocz�tkowej pozycji snake'a
	void GenerateSnakePosition();

	//DO ROBOTY
	void DrawSnake(sf::RenderWindow* window);

	//DO ROBOTY
	void DrawBackground(sf::RenderWindow* window);

	//DO ROBOTY
	void MoveSnake();

	//DO ROBOTY
	void SetDirection(Snake::Direction direction);

	// Sprawdza obecne po�o�enie snake'a : 
	// czy znajduje si� w arenie lub czy dosz�o do kolizji (czy zjad� siebie)
	void CheckWhereIsSnake();

	// Generuje PickUp'a 
	void GeneratePickUp();

	// Sprawdza czy gra si� sko�czy�a
	bool IsGameOver();

	//DO ROBOTY
	void DrawPickUp(sf::RenderWindow* window);

	// Sprawdza, czy PickUp zosta� zebrany, je�li tak: dodaje punkt
	// do score'a, zwi�ksza w�a, generuje kolejny PickUp
	void CheckPickUp();
};