#include "..\Headers\GameManager.h"
#include <random>
#include <algorithm>

GameManager::GameManager()
{
	snake = Snake(texturesManager.GetTexture(MyTexture::Type::SnakeHeadYellow), texturesManager.GetTexture(MyTexture::Type::SnakeBodyYellow));
	scoreManager.SetFont(fontsManager.GetFont(MyFont::Type::Arial));

	drawableInGameObjects.push_back(&snake);
	drawableInGameObjects.push_back(&background);
	drawableInGameObjects.push_back(&scoreManager);

	isGameOver = false;
	isPickUpCollected = true;
	GenerateSnakePosition();
	GeneratePickUp();
}

void GameManager::GeneratePickUp()
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<float> posX(150.0f, 850.0f); //x e [100,900] y e [250,750]
	std::uniform_real_distribution<float> posY(300.0f, 700.0f);

	if (isPickUpCollected)
	{
		isPickUpCollected = false;

		float x = posX(generator);
		float y = posY(generator);

		pickUp = PickUp(x, y);
		drawableInGameObjects.push_back(&pickUp);
	}
}

void GameManager::DrawInGameObjects(sf::RenderWindow* window)
{
	for (const auto obj : drawableInGameObjects)
	{
		printf("1\n");
		obj->Draw(window);
	}
}

void GameManager::GenerateSnakePosition()
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_real_distribution<float> posX(150.0f, 850.0f); //x e [100,900] y e [250,750]
	std::uniform_real_distribution<float> posY(300.0f, 700.0f);
	std::uniform_int_distribution<int>direction(0,3); // kierunek

	float x = posX(generator);
	float y = posY(generator);
	int index = direction(generator);

	snake.SetDirection(Snake::Direction(index));
	snake.SetPosition(x, y);
}

void GameManager::MoveSnake()
{
	snake.Move();
}

void GameManager::SetSnakeDirection(Snake::Direction direction)
{
	snake.SetDirection(direction);
}

void GameManager::CheckWhereIsSnake()
{
	if (!snake.IsInArena(&background) || snake.IsCollision())
	{
		isGameOver = true;
	}
}

bool GameManager::IsGameOver()
{
	if (isGameOver)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameManager::CheckPickUp()
{
	if (pickUp.IsCollected(&snake))
	{
		scoreManager.AddScore();
		isPickUpCollected = true;
		snake.Grow();
		drawableInGameObjects.erase(std::remove(drawableInGameObjects.begin(), drawableInGameObjects.end(), &pickUp), drawableInGameObjects.end());
		GeneratePickUp();
	}
}