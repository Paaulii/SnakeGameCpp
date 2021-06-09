#pragma once
#include <SFML/Graphics.hpp>

class MyFont : public sf::Font
{
public:
	// Typy czcionek za�adowanych w pami�� programu
	enum class Type
	{
		Arial,
		Snake,
		LostIsland
	};

private:
	Type type;

public:
	// Konstruktor parametryczny
	// Ustawia typ czcionki
	MyFont(Type type);

	// Zwraca typ czcionki
	const Type GetType() const;
};