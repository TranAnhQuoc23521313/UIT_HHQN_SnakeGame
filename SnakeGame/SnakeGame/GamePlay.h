#pragma once
#include <raylib.h>
#include "Snake.h"
#include <string>

typedef enum {
	SMALL,
	MEDIUM,
	LARGE
} GridSize;

class GamePlay
{
private:
	int size;
	bool ChooseModePlay;
	int SCR_WIDTH;
	bool buttonsVisible = true;
	bool FirstGame = true;
	std::string ModeGame;
	public:
	static int score;
	// Cụm các hàm dùng để thiết kế nút lệnh chọn chế độ trò chơi
	void Choose_Mode_GamePlay();
	int getSCR_WIDTH()
	{
		return this->SCR_WIDTH;
	}
	void setSCR_WIDTH(int);
	void Start(int,int);
	void DrawGrid(int,int,int);
	void DrawScore(int);
	void GameOver(int,int,int);
	std::string GetModeGame()
	{
		return this->ModeGame;
	}
};

