#pragma once

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
public:
	static int score;
	// Cụm các hàm dùng để thiết kế nút lệnh chọn chế độ trò chơi
	void Choose_Mode_GamePlay();
	static void DrawChooseButtonMode();
	int getSCR_WIDTH()
	{
		return this->SCR_WIDTH;
	}
	void setSCR_WIDTH(int);
	void Start(int,int);
	void DrawGrid(int,int,int);
	void DrawScore();
	friend class Snake;
};

