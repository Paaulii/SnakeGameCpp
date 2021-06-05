#pragma once
#include <SFML/Audio.hpp>

class MySoundBuffer : public sf::SoundBuffer
{
public:
	// Typy SoundBuffer'�w
	enum class Type
	{
		Coin,
		PowerUp,
		Defeat
	};

private:
	Type type;

public:
	// Konstruktor domy�lny
	MySoundBuffer(Type type);

	// Zwraca typ SoundBuffera
	const Type GetType() const;
};