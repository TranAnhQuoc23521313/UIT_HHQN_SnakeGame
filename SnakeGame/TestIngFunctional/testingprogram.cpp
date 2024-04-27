#include "raylib.h"
#include <iostream>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Khởi tạo cửa sổ và tạo một màn hình với kích thước cụ thể
    InitWindow(screenWidth, screenHeight, "TESTING INSERT PICTURE");

    // Load ảnh từ đường dẫn cụ thể
    Image image = LoadImage("C:/Users/quoc9/Downloads/1695388601323.png");

    // Thu nhỏ hoặc phóng to ảnh để phù hợp với kích thước của cửa sổ
    ImageResize(&image, screenWidth, screenHeight);

    // Chuyển đổi ảnh thành Texture2D
    Texture2D background = LoadTextureFromImage(image);

    // Giải phóng bộ nhớ của image sau khi đã sử dụng
    UnloadImage(image);

    // Load ảnh icon từ tệp ảnh
    Image icon = LoadImage("snake-icon-png-4.png");

    // Thiết lập icon cho cửa sổ của ứng dụng
    SetWindowIcon(icon);

    // Giải phóng bộ nhớ của icon sau khi đã sử dụng
    UnloadImage(icon);

    SetTargetFPS(60);
    InitAudioDevice();
    Music theme = LoadMusicStream("C:/Users/ABC/OneDrive/Desktop/NewStuff.mp3");
    Sound fx = LoadSound("C:/Users/ABC/Downloads/AK47.mp3");
    Sound th = LoadSound("C:/Users/ABC/Downloads/368476734_1479871569512143_8106116662697456924_n (online-video-cutter.com).mp3");
    SetTargetFPS(60);
    PlaySound(th);

    while (!WindowShouldClose()) {
        UpdateMusicStream(theme);
        if (IsKeyPressed(KEY_SPACE)) {
            // Phát âm thanh
            std::cout << "OK" << std::endl;
            PlaySound(fx);
        }
        if (IsSoundPlaying(th) == false)
            PlaySound(th);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);
        EndDrawing();
    }

    // Giải phóng bộ nhớ của âm thanh sau khi sử dụng
    CloseAudioDevice();
    // Giải phóng texture và đóng cửa sổ
    UnloadTexture(background);
    CloseWindow();

    return 0;
}
