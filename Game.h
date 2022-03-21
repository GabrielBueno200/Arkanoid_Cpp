#pragma once
#include "SDL/SDL.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include "Paddle.h"
#include "Ball.h"
#include "Block.h"
#include "Utils.h"

using namespace std;

enum class GameState { StartScreen, Playing };
enum class GameMode { SinglePlayer, MultiPlayer, None };

class Game
{
public:
	Game();
	bool Initialize();
	void LoadBackground();
	void RunLoop();
	~Game();
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	bool LoadBitmap(
		std::string bitmapFileName,
		SDL_Surface* surface,
		SDL_Texture* texture,
		SDL_Rect* screenDest,
		SDL_Renderer* renderer
	);
	void ProcessMenuInput(const Uint8* keyboardState);
	void ProcessBotInput(const Uint8* keyboardState);
	void ProcessMultiplayerInput(const Uint8* keyboardState);
	void ProcessSingleplayerInput(const Uint8* keyboardState);
	void UpdateScoreBoard(int firstPlayerScore, int secondPlayerScore = -1);
	void ResetGame();
	void InitializeVariables();

	SDL_Window* window;

	SDL_Surface* screenSurface = NULL;
	SDL_Surface* menuSurface = NULL;
	SDL_Texture* menuTexture = NULL;

	SDL_Surface* fieldSurface = NULL;
	SDL_Texture* fieldTexture = NULL;

	SDL_Renderer* renderer = NULL;
	
	Uint32 ticksCount;
	
	bool isRunning;

	GameState gameState;
	GameMode gameMode;

	Paddle firstPaddle;
	Paddle secondPaddle;
	vector<Ball> balls;
	vector<vector<Block>> blocks;
	int firstPlayerScore, secondPlayerScore;

	std::string menuBitmapName;
	std::string fieldBitmapName;
};
