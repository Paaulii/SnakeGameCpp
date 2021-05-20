#pragma once
#include <SFML/Graphics.hpp>

class MyTexture : public sf::Texture
{
public:
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