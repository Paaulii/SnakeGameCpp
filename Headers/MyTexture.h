#pragma once
#include <SFML/Graphics.hpp>

class MyTexture : public sf::Texture
{
public:
	// Typy tekstur za�adowanych w pami�� programu
	enum class Type
	{
		SnakeHeadGreen,
		SnakeBodyGreen,
		SnakeBigGreen,
		SnakeHeadPink,
		SnakeBodyPink,
		SnakeBigPink,
		SnakeHeadBlue,
		SnakeBodyBlue,
		SnakeBigBlue,
		SnakeHeadYellow,
		SnakeBodyYellow,
		SnakeBigYellow,
		Apple,
		Arena,
		Menu,
		HelpScreen,
		CreditsScreen,
		PowerUpSpeed,
		PowerUpImmunity,
		PowerUpEatableSnake,
		PowerUpReverseSides,
		PowerUpSlow,
		Block,
		ClassicArena,
		None
	};

private:
	Type type;

public:
	// Konstruktor domy�lny
	MyTexture(Type type);

	// Zwraca typ tekstury
	const Type GetType() const;
};