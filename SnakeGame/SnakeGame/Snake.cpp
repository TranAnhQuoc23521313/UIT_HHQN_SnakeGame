#include "Snake.h"
#include <vector>

Snake::Snake(int startX, int startY, int startDirX, int startDirY) : dx(startDirX), dy(startDirY)
{
    Point head = { startX, startY };
    body.push_back(head);
}

void Snake::Move(int GRID_COLS, int GRID_ROWS, int& FrameCount)
{
    // Lấy vị trí của phần đầu của con rắn
    Point head = body[0];

    // Tạo một vị trí mới dựa trên hướng di chuyển
    Point newHead = { head.x + dx, head.y + dy };

    // Đặt lại vị trí mới nếu vượt ra khỏi biên
    if (newHead.x < 0)
    {
        newHead.x = GRID_COLS - 1;
        FrameCount++;
    }
    if (newHead.y < 0)
    {
        newHead.y = GRID_ROWS - 1;
        FrameCount++;
    }
    if (newHead.x >= GRID_COLS)
    {
        newHead.x = 0;
        FrameCount++;
    }
    if (newHead.y >= GRID_ROWS)
    {
        newHead.y = 0;
        FrameCount++;
    }

    // Thêm vị trí mới vào phần đầu của con rắn
    body.insert(body.begin(), newHead);

    // Xoá phần cuối của con rắn
    body.pop_back();
}

void Snake::Draw()
{
    for (Point part : body)
    {
        DrawRectangle(part.x * GRID_SIZE, part.y * GRID_SIZE, GRID_SIZE, GRID_SIZE, GREEN);
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
