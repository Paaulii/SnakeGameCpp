#pragma once
#include <SFML/Audio.hpp>
#include "SoundBufferManager.h"

class AudioManager
{
private:
	// Struktura przechowuj�ca d�wi�k i jego buffer
	struct MySound
	{
		sf::Sound sound;
		std::shared_ptr<MySoundBuffer> soundBuffer;

		// konstruktor parametryczny dodaj�cy SoundBuffer do Sound'a
		MySound(std::shared_ptr<MySoundBuffer> soundBuffer);

		// Gra d�wi�k, kt�ry zawiera
		void Play();

		// Zwraca typ SoundBuffer'a
		const MySoundBuffer::Type GetType() const;
	};

	SoundBufferManager soundBufferManager;
	std::vector<MySound> sounds;

public:
	// Konstruktor domy�lny
	// Tworzy obiekt MySound dla ka�dego sound buffera
	// Zawartego w SoundBufferManager'ze
	AudioManager();

	// Gra podany typ d�wieku
	const void PlaySound(MySoundBuffer::Type type);

	// Przestaje gra� podany typ d�wi�ku
	const void StopSound(MySoundBuffer::Type type);

private:
	// Ustawia odpowiednie g�o�no�ci wszystkim d�wi�kom
	void SetSoundDetails();
};
