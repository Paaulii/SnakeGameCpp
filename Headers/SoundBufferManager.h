#pragma once
#include "MySoundBuffer.h"

class SoundBufferManager
{
private:
	struct SoundBufferInfo
	{
		std::string filePath;
		MySoundBuffer::Type type;
	};

	std::vector<std::shared_ptr<MySoundBuffer>> soundBuffersPointers;

	// Przechowuje wszystkie tekstury do za�adowania
	std::vector<SoundBufferInfo> filesPaths
	{
		{"coin.wav", MySoundBuffer::Type::Coin}
	};

public:
	// Konstruktor domy�lny
	SoundBufferManager();

	// �aduje wszystkie podane tekstury
	void LoadAllSoundBuffers();

	// Zwraca dan� tekstur�
	const std::shared_ptr<MySoundBuffer> GetSoundBuffer(MySoundBuffer::Type type) const;

	const std::vector<std::shared_ptr<MySoundBuffer>>& GetVector() const;

private:
	// Dodaje podan� tekstur�
	void AddSoundBuffer(std::string fileName, MySoundBuffer::Type type);
};