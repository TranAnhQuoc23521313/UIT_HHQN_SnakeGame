#pragma once
#include <raylib.h>
#include <vector>

#define GRID_SIZE 30    // Kích thước 1 ô

class meat
{
private:
    Vector2 position;   // Vị trí miếng thịt
    int existenceTime;  // Thời gian tồn tại
    Color color;    // Màu của miếng thịt
public:
    meat(int, int, std::vector<Vector2>);   // Constructor

    // Hàm tạo ra 1 vị trí ngẫu nhiên cho miếng thịt
    Vector2 GenerateRandomPosition(int, int);   

    // Hàm cho phép miếng thịt xuất hiện tại vị trí đã có
    void SetRandomPosition(int, int, std::vector<Vector2>); 
    // Hàm vẽ miếng thịt
    void Draw();    

    // Hàm Lấy vị trị miếng thịt hiện tại
    Vector2 GetPosition();  

    // Hàm lấy ra thời gian tồn tại miếng thịt
    int GetExistenceTime();
    // Hàm tăng thời gian tồn tại
    void IncrementExistenceTime();  

    // Hàm đưa thời gian tồn tại về 0
    void ResetExistenceTime()   
    { 
        existenceTime = 0;
    }

    // Hàm kiểm tra xem miếng thịt có xuất hiện trên thân con rắn hay không
    bool ElementInSnake(Vector2 Pos_meat, std::vector<Vector2> snake);  
};

