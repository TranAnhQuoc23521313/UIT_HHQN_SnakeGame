#pragma once
#include <raylib.h>
#include <vector>
#include "meat.h"
#include <string>
//#include "GamePlay.h"

#define GRID_SIZE 30
//#define GRID_ROWS 20
//#define GRID_COLS 20

class Snake {
private:
    int dx; // Hướng di chuyển theo trục X
    int dy; // Hướng di chuyển theo trục Y
    int SCC_WIDTH;  // Lấy chiều ngang của chế độ chơi
    int score;  // Điểm của con rắn 
    int Speed = 8;  // Tốc độ di chuyển ban đầu
    std::string MG; // Chế độ chơi
    bool Lose;  // Kiểm tra có thua không
    bool Eat;   // Kiểm tra có ăn chưa
public:

    std::vector<Vector2> body;  // Vector chứa vị trí thân con rắn
    Snake(int, int, int, int);  // Constructor 
    void Move(int, int,meat&);  // Hàm thiết lập di chuyển
    void Draw();    // Hàm vẽ con rắn
    void ChangeDirection(int, int);   // Hàm thay đổi hướng di chuyển khi dùng phím
    bool CheckSelfCollision() const;    // Hàm kiểm tra xem nó có cắn chính mình không
    void Set_SCR_WIDTH(int SCR_WIDTH)   // Hàm điều chỉnh giá trị kích thước sân đấu
    {
        this->SCC_WIDTH = SCR_WIDTH;
    }

    int GetScore()  // Hàm lấy điểm của con rắn
    {
        return this->score;
    }

    int GetSpeed()  // Hàm lấy tốc độ
    {
        return this->Speed;
    }

    void DrawScore();   // Hàm vẽ điểm trên màn hình
    void SetModeGame(std::string new_mode)
    {
        this->MG = new_mode;
    }
    bool GetLose()
    {
        return this->Lose;
    }
    bool GetEat()
    {
        return this->Eat;
    }
    void SetEat(bool Status)
    {
        this->Eat = Status;
    }
};