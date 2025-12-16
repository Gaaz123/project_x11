#include "raylib.h"
#include "fighters.h"
#include <string>

int main() {
    InitWindow(800, 600, "Fight Game");
    SetTargetFPS(60);
    
    Warrior warrior("Warrior", 200, 300);
    Mage mage("Mage", 600, 300);
    
    Fighter* player1 = &warrior;
    Fighter* player2 = &mage;
    
    bool gameOver = false;
    std::string winner = "";
    int turn = 1; 
    
    while (!WindowShouldClose()) {
        if (!gameOver) {
            if (IsKeyPressed(KEY_SPACE)) {
                if (turn == 1) {
                    player1->attackTarget(*player2);
                    if (!player2->isAlive()) {
                        gameOver = true;
                        winner = player1->getName();
                    }
                    turn = 2;
                } else {
                    player2->attackTarget(*player1);
                    if (!player1->isAlive()) {
                        gameOver = true;
                        winner = player2->getName();
                    }
                    turn = 1;
                }
            }
            
            if (IsKeyPressed(KEY_Q) && turn == 1) {
                player1->specialMove();
            }
            if (IsKeyPressed(KEY_P) && turn == 2) {
                player2->specialMove();
            }
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawRectangle(0, 0, 800, 600, Color{230, 230, 250, 255});
        
        DrawRectangle(100, 400, 600, 50, GRAY);
        
        DrawRectangle(player1->getX(), player1->getY(), 50, 100, BLUE);
        DrawText(player1->getName().c_str(), player1->getX(), player1->getY() - 30, 20, DARKBLUE);
        
        DrawRectangle(player1->getX(), player1->getY() - 20, 50, 10, RED);
        int healthWidth1 = (player1->getHealth() * 50) / 100;
        DrawRectangle(player1->getX(), player1->getY() - 20, healthWidth1, 10, GREEN);
        
        DrawRectangle(player2->getX(), player2->getY(), 50, 100, RED);
        DrawText(player2->getName().c_str(), player2->getX(), player2->getY() - 30, 20, MAROON);
        
        DrawRectangle(player2->getX(), player2->getY() - 20, 50, 10, RED);
        int healthWidth2 = (player2->getHealth() * 50) / 100;
        DrawRectangle(player2->getX(), player2->getY() - 20, healthWidth2, 10, GREEN);
        
        DrawText("Controls:", 10, 10, 20, DARKGRAY);
        DrawText("SPACE - attack", 10, 40, 20, DARKGRAY);
        DrawText("Q - Warrior special", 10, 70, 20, DARKGRAY);
        DrawText("P - Mage special", 10, 100, 20, DARKGRAY);
        
        DrawText(TextFormat("Turn: %s", (turn == 1) ? player1->getName().c_str() : player2->getName().c_str()), 
                300, 10, 30, DARKGRAY);
        
        DrawText(TextFormat("%s: %d HP", player1->getName().c_str(), player1->getHealth()), 
                150, 500, 20, BLUE);
        DrawText(TextFormat("%s: %d HP", player2->getName().c_str(), player2->getHealth()), 
                550, 500, 20, RED);
        
        if (gameOver) {
            DrawRectangle(0, 0, 800, 600, Color{0, 0, 0, 200});
            DrawText("GAME OVER!", 200, 200, 50, YELLOW);
            DrawText(TextFormat("Winner: %s", winner.c_str()), 250, 280, 40, GREEN);
            DrawText("Press ESC to exit", 250, 350, 30, WHITE);
        }
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}