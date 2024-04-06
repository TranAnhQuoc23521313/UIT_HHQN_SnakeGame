#pragma once

typedef enum {
	SMALL,
	MEDIUM,
	LARGE
} GridSize;

class GamePlay
{
private:
	int x;
	int y;
	int size;
	bool ChooseModePlay;
public:
	// Cụm các hàm dùng để thiết kế nút lệnh chọn chế độ trò chơi
	void Choose_Mode_GamePlay();
	static void DrawChooseButtonMode();


	void Start(int,int);
	void DrawGrid(int,int,int);
};

