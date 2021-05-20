#pragma once
#include <SFML/Audio.hpp>
#include "SoundBufferManager.h"

class AudioManager
{
private:
	// Struktura przechowuj�ca d�wi�k i jego buffer
	struct Sound
	{
		sf::Sound sound;
		std::shared_ptr<MySoundBuffer> soundBuffer;

		// konstruktor parametryczny dodaj�cy SoundBuffer do Sound'a
		Sound(std::shared_ptr<MySoundBuffer> soundBuffer);

		// Gra d�wi�k, kt�ry zawiera
		void Play();

		// Zwraca typ SoundBuffer'a
		const MySoundBuffer::Type GetType() const;
	};

	SoundBufferManager soundBufferManager;
	std::vector<Sound> sounds;

public:
	// Konstruktor domy�lny
	AudioManager();

	// Gra podany typ d�wieku
	const void PlaySound(MySoundBuffer::Type type);
};
