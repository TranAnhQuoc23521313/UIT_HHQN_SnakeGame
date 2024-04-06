#pragma once

#define SCREEN_WIDTH 1820
#define SCREEN_HEIGHT 980
#define GRID_SIZE 30
#define GRID_ROWS (SCREEN_HEIGHT / GRID_SIZE)
#define GRID_COLS (SCREEN_WIDTH / GRID_SIZE)

class GamePlay
{
private:
	int x;
	int y;
	int size;
public:
	int Choose_Mode_GamePlay();
	void Start();
	void DrawGrid(int,int,int);
};

