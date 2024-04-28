#include "Snake.h"
#include"meat.h"
#include"GamePlay.h"
#include <vector>
#include <string>

Snake::Snake(int startX, int startY, int startDirX, int startDirY) : dx(startDirX), dy(startDirY)
{
    Vector2 head = { startX, startY };
    this->score = 0;
    body.push_back(head);
}

void Snake::Move(int GRID_COLS, int GRID_ROWS, int& FrameCount, meat& MEAT)
{
    // Lấy vị trí của phần đầu của con rắn
    Vector2 head = body[0];

    // Tạo một vị trí mới dựa trên hướng di chuyển
    Vector2 newHead = { head.x + dx, head.y + dy };

    // Đặt lại vị trí mới nếu vượt ra khỏi biên
    if (newHead.x < 0)
    {
        newHead.x = GRID_COLS - 1;
        //FrameCount++;
    }
    if (newHead.y < 0)
    {
        newHead.y = GRID_ROWS - 1;
        // FrameCount++;
    }
    if (newHead.x >= GRID_COLS)
    {
        newHead.x = 0;
        // FrameCount++;
    }
    if (newHead.y >= GRID_ROWS)
    {
        newHead.y = 0;
        // FrameCount++;
    }

    if (newHead.x == MEAT.GetPosition().x && newHead.y == MEAT.GetPosition().y) {

        // Thêm miếng thịt vào thân của con rắn
        body.insert(body.begin(), newHead);
        // Tạo một miếng thịt mới
        MEAT.SetRandomPosition(GRID_COLS, GRID_ROWS, this->body);
        MEAT.ResetExistenceTime();
        this->score += 10;
        if (this->score % 100 == 0)
        {
            this->Speed += 1;
        }
        this->DrawScore();
    }

    else
    {   // Thêm vị trí mới vào phần đầu của con rắn
        body.insert(body.begin(), newHead);

        // Xoá phần cuối của con rắn
        body.pop_back();
    }
}

void Snake::Draw()
{
    for (unsigned int i = 0; i < body.size(); i++)
    {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle segment = Rectangle{ x * GRID_SIZE, y * GRID_SIZE, GRID_SIZE, GRID_SIZE };
        DrawRectangleRounded(segment, 0.5, 5, DARKGRAY);
    }
}


void Snake::ChangeDirection(int newDx, int newDy)
{
    // Chỉ cho phép thay đổi hướng nếu không trái chiều với hướng hiện tại
    if ((dx != 0 && newDx != -dx) || (dy != 0 && newDy != -dy))
    {
        dx = newDx;
        dy = newDy;
    }
}

bool Snake::CheckSelfCollision() const
{
    // Lặp qua toàn bộ phần thân của con rắn, bắt đầu từ index 1 (phần thân sau phần đầu)
    for (size_t i = 1; i < body.size(); ++i)
    {
        // Nếu phần đầu của con rắn trùng với một phần của thân mình
        if (body[i].x == body[0].x && body[i].y == body[0].y)
        {
            return true; // Trả về true nếu có va chạm
        }
    }
    return false; // Trả về false nếu không có va chạm
}
void Snake::DrawScore() {
    // Vẽ điểm số bên góc phải của màn hình
    std::string scoreText = "Score: " + std::to_string(this->score);
    const char* scoreChar = scoreText.c_str(); // Chuyển đổi thành một con trỏ char

    DrawText(scoreChar, this->SCC_WIDTH - 150, 20, 20, YELLOW);
}