#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "MyTexture.h"
#include "IDrawable.h"

class Snake : public IDrawable
{
public:
	enum class Direction{Top,Right,Bottom,Left};

private:
	float posX;
	float posY;
	float speed;
	unsigned int size;
	unsigned int increasingSize;
	std::shared_ptr<MyTexture> headTexture;
	std::shared_ptr<MyTexture> bodyTexture;
	sf::Sprite sprite;
	Direction direction;
	std::vector<sf::Vector2f>positions;
	bool immunited;
	bool isEatable;
	int numberOfDecresedParts;

public:
	// Konstruktor domy�lny, ustawia odpowiednie warto�ci dla zmiennych
	Snake();

	// Ustawia tekstury snake'a
	void SetTextures(std::shared_ptr<MyTexture> headTexture, std::shared_ptr<MyTexture> bodyTexture);
	
	// Rysuje snake'a na ekranie
	void Draw(sf::RenderWindow* window);

	// Ustawia pr�dko�� snake'a
	void SetSpeed(float speed);

	// Zmiana kierunku poruszania si� snake'a
	void SetDirection(Direction direction);

	// Ustawia rotacje sprite'a znale�nego od kierunku snake'a
	void SetSpriteRotation();

	// Ustawia pozycje snake'a
	void SetPosition(float x, float y);

	// Ustawia niewra�liwo��
	void SetImmunization(bool val);

	// Ustawia mo�liwo�� zjadania siebie
	void SetEatablility(bool val);

	// Zwraca true, je�li snake jest niewra�liwy
	bool const IsImmunited() const;
	
	// Zwraca true, je�li snake mo�e siebie je��
	bool const IsEatable() const;

	// Zmienia pozycje snake'a 
	void Move();

	// Zwi�ksza wielko�� snake'a i jego pr�dko��
	void Grow();

	// Resetuje wszystkie ustawienia snake'a
	void Reset();

	// Zwraca pozycje g�owy snake'a
	const sf::Vector2f& GetPosition() const;

	// Zwraca rozmiar spritu snake'a
	const sf::Vector2u GetSize() const;
	
	// Zwraca liczb� zjedzon� przez siebie
	const int GetNumberOfDecreasedParts() const;

	// Zwraca kierunek snake'a
	const Direction GetDirection() const;

	// Zwraca sprite'a snake'a
	const sf::Sprite& GetSprite() const;

	// Zwraca pr�dko�� snake'a
	const float GetSpeed() const;

	// Funkcja sprawdza, czy Snake znajduje si� w polu gry
	bool IsInArena(Background* background);

	// Sprawdza, czy dosz�o do kolizji snake'a (czy zjad� siebie)
	bool IsCollision();

	// Sprawdza, czy potencjalny PickUp jest na snake'u
	bool IsObjectOnSnake(float posX, float posY, sf::Vector2u pickUpSize, float additionalDistance = 0);
private:
	// Ustawia w�a�ciwo�ci snake'a
	void SetSpriteProperties();
};