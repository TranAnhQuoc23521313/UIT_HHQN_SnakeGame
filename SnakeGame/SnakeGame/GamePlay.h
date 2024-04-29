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
	int size;	// Kích thước sân đấu
	bool ChooseModePlay;	// Kiểm tra xem đã chọn chế độ game chưa
	int SCR_WIDTH;	// Độ rộng sân đấu
	bool buttonsVisible = true;	// Kiểm tra xem có hiển thị nút chọn chế độ khi chơi lại
	bool FirstGame = true;	// Kiểm tra xem có phải game này là game đầu tiên ?
	std::string ModeGame;	// Hàm lấy ra chế độ game hiện tại
public:
	static int score;	// Lưu trữ điểm số
	// Cụm các hàm dùng để thiết kế nút lệnh chọn chế độ trò chơi
	void Choose_Mode_GamePlay();	// Hàm thể hiện giao diện chọn chế độ chơi
	int getSCR_WIDTH()	// Hàm lấy chiều rộng màn hình
	{
		return this->SCR_WIDTH;
	}
	void setSCR_WIDTH(int);	// Hàm điều chỉnh chiều rộng màn hình
	void Start(int,int);	// Hàm chơi game chính	
	void DrawScore(int);	// Hàm vẽ điểm khi GameOver
	void GameOver(int,int,int);	// Hàm thể hiện giao diện khi GameOver
	std::string GetModeGame()	// hàm lấy ra chế độ chơi
	{
		return this->ModeGame;
	}
};

