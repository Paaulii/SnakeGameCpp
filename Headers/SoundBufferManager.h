#pragma once
#include "MySoundBuffer.h"

class SoundBufferManager
{
private:
	// Struktura wspomagaj�ca �adowanie danych z plik�w
	struct SoundBufferInfo
	{
		std::string filePath;
		MySoundBuffer::Type type;
	};

	std::vector<std::shared_ptr<MySoundBuffer>> soundBuffersPointers;

	// Przechowuje wszystkie SoundBuffery do za�adowania
	std::vector<SoundBufferInfo> filesPaths
	{
		{".\\Sounds\\Coin.wav", MySoundBuffer::Type::Coin},
		{".\\Sounds\\Defeat.wav", MySoundBuffer::Type::Defeat},
		{".\\Sounds\\PowerUp.wav", MySoundBuffer::Type::PowerUp},
		{".\\Sounds\\MusicMenu.wav", MySoundBuffer::Type::MenuMusic},
		{".\\Sounds\\MusicGame.wav", MySoundBuffer::Type::GameMusic}
	};

public:
	// Konstruktor domy�lny
	SoundBufferManager();

	// �aduje wszystkie podane SoundBuffer'y
	void LoadAllSoundBuffers();

	// Zwraca dany SoundBuffer
	const std::shared_ptr<MySoundBuffer> GetSoundBuffer(MySoundBuffer::Type type) const;

	// Zwraca wektor wszystkich SoundBuffer'�w
	const std::vector<std::shared_ptr<MySoundBuffer>>& GetVector() const;

private:
	// Dodaje nowy podany SoundBuffer
	void AddSoundBuffer(std::string fileName, MySoundBuffer::Type type);
};