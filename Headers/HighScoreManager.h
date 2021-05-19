#pragma once
#include <SFML/Graphics.hpp>
#include "HighScoreEntity.h"
#include "MyFont.h"

class HighScoreManager
{
private:
	const std::string pathToFile = "highscores.txt";
	std::shared_ptr<MyFont> fontTitleText;
	std::shared_ptr<MyFont> fontHighScores;
	sf::Text titleText;
	std::vector<std::unique_ptr<HighScoreEntity>> highScoreEntities;

public:
	// Konstruktor domy�lny
	HighScoreManager();

	// Konstruktor parametryczny
	HighScoreManager(std::shared_ptr<MyFont> fontTitleText, std::shared_ptr<MyFont> fontHighScores);

	// Dodaje nowy HighScore do tabeli
	void AddHighScore(int score, std::string name);

	// Rysuje ca�� tabel� najlepszych wynik�w, wraz z tytu�em
	void Draw(sf::RenderWindow* window);

	// Destruktor klay, zapisuje do pliku 5 najlepszych wynik�w
	virtual ~HighScoreManager();

private:
	// �aduje czionk� i ustawia wszystkie parametry tekstu
	void LoadFontAndSetText();

	// �aduje wszystkie wyniki z pliku
	void LoadScoresFromFile();

	// Sortuje wektor najlepszych wynik�w
	void SortHighScores();

	// Por�wnuje dwa wyniki pomi�dzy sob�
	static bool HighScoreComparator(const std::unique_ptr<HighScoreEntity>& a, const std::unique_ptr<HighScoreEntity>& b);

	// Ustawia wielko�� wektora do maksymalnie 5
	void SetToMaxFiveHighScores();
};