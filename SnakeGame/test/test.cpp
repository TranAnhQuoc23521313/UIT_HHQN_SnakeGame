#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> // Cho Windows

// ??nh ngh?a kích th??c l??i trò ch?i
const int width = 20;
const int height = 20;

// C?u trúc ?? bi?u di?n m?t ?i?m trên l??i
struct Point {
    int x, y;
};

// Li?t kê các h??ng di chuy?n
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class SnakeGame {
private:
    bool gameOver;
    Point head, fruit;
    int score;
    Direction dir;
public:
    SnakeGame() {
        gameOver = false;
        dir = STOP;
        head.x = width / 2;
        head.y = height / 2;
        fruit.x = rand() % width;
        fruit.y = rand() % height;
        score = 0;
    }

    // Hàm v? tr?ng thái hi?n t?i c?a trò ch?i
    void Draw() {
        system("cls"); // Xóa màn hình (cho Windows)
        for (int i = 0; i < width + 2; i++)
            std::cout << "#";
        std::cout << std::endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0)
                    std::cout << "#";
                if (i == head.y && j == head.x)
                    std::cout << "O";
                else if (i == fruit.y && j == fruit.x)
                    std::cout << "F";
                else
                    std::cout << " ";
                if (j == width - 1)
                    std::cout << "#";
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < width + 2; i++)
            std::cout << "#";
        std::cout << std::endl;
        std::cout << "Score:" << score << std::endl;
    }

    // Hàm x? lý ??u vào t? bàn phím
    void Input() {
        if (_kbhit()) { // Ki?m tra n?u m?t phím ???c nh?n
            switch (_getch()) { // Nh?n phím ???c nh?n
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            }
        }
    }

    // Hàm x? lý logic trò ch?i
    void Logic() {
        switch (dir) {
        case LEFT:
            head.x--;
            break;
        case RIGHT:
            head.x++;
            break;
        case UP:
            head.y--;
            break;
        case DOWN:
            head.y++;
            break;
        default:
            break;
        }

        // Ki?m tra va ch?m v?i t??ng
        if (head.x > width || head.x < 0 || head.y > height || head.y < 0)
            gameOver = true;

        // Ki?m tra va ch?m v?i th?c ?n
        if (head.x == fruit.x && head.y == fruit.y) {
            score += 10;
            fruit.x = rand() % width;
            fruit.y = rand() % height;
        }
    }

    // Hàm ch?y trò ch?i
    void Run() {
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            // Thêm delay ?? trò ch?i không ch?y quá nhanh
            for (int i = 0; i < 1000000; i++) {}
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); // Kh?i t?o seed cho hàm random
    SnakeGame game;
    game.Run();
    return 0;
}