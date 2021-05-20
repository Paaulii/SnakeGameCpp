#pragma once
#include <SFML/Graphics.hpp>

class MyFont : public sf::Font
{
public:
	enum class Type
	{
		Arial,
		Snake,
		LostIsland
	};

private:
	Type type;

public:
	// Konstruktor domy�lny
	MyFont(Type type);

	// Zwraca typ czcionki
	const Type GetType() const;
};