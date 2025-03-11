#include "game.h"
#include "utils.h"
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize double buffer
    initDoubleBuffer();
    
    // Initialize game
    initGame();
    
    // Game loop
    while (!gameOver) {
        handleInput();
        updateGame();
        drawGame();
        gameOver = isGameOver();
        sleep(100);  // Control game speed
    }
    
    // Game over
    printf("\nGame Over! Final Score: %d\n", score);
    
    // Cleanup double buffer
    cleanupDoubleBuffer();
    
    return 0;
}
