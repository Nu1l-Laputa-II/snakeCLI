#include "game.h"
#include "utils.h"

Snake snake;
Position food;
int score = 0;
int gameOver = 0;

void initGame() {
    // Initialize snake
    snake.length = 1;
    snake.body[0].x = WIDTH / 2;
    snake.body[0].y = HEIGHT / 2;
    snake.direction = 1;

    // Generate first food
    generateFood();
    score = 0;
    gameOver = 0;
}

void generateFood() {
    int valid;
    do {
        valid = 1;
        food.x = rand() % (WIDTH - 2) + 1;
        food.y = rand() % (HEIGHT - 2) + 1;
        
        for (int i = 0; i < snake.length; i++) {
            if (food.x == snake.body[i].x && food.y == snake.body[i].y) {
                valid = 0;
                break;
            }
        }
    } while (!valid);
}

void updateGame() {
    Position newHead = snake.body[0];

    // Update head position based on direction
    switch (snake.direction) {
        case 0: newHead.y--; break;
        case 1: newHead.x++; break;
        case 2: newHead.y++; break;
        case 3: newHead.x--; break;
    }

    // Check if food is eaten
    if (newHead.x == food.x && newHead.y == food.y) {
        score += 10;
        snake.length++;
        generateFood();
    }

    // Move snake body
    for (int i = snake.length - 1; i > 0; i--) {
        snake.body[i] = snake.body[i-1];
    }
    snake.body[0] = newHead;
}

void drawGame() {
    clearScreen();
    
    // Draw border and game area (scan)
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == 0 || y == HEIGHT-1 || x == 0 || x == WIDTH-1)
                printf("#");
            else {
                int isSnake = 0;
                for (int i = 0; i < snake.length; i++) {
                    if (snake.body[i].x == x && snake.body[i].y == y) {
                        printf("O");
                        isSnake = 1;
                        break;
                    }
                }
                if (!isSnake) {
                    if (food.x == x && food.y == y)
                        printf("*");
                    else
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\nScore: %d\n", score);
}

int isGameOver() {
    Position head = snake.body[0];
    
    // Check wall collision
    if (head.x <= 0 || head.x >= WIDTH-1 || head.y <= 0 || head.y >= HEIGHT-1)
        return 1;
        
    // Check self collision
    for (int i = 1; i < snake.length; i++) {
        if (head.x == snake.body[i].x && head.y == snake.body[i].y)
            return 1;
    }
    
    return 0;
}

void handleInput() {
    if (_kbhit()) { // Check if a key is pressed
        char key = _getch();  // Get the pressed key
        switch(key) {
            case 'w': if (snake.direction != 2) snake.direction = 0; break;
            case 'd': if (snake.direction != 3) snake.direction = 1; break;
            case 's': if (snake.direction != 0) snake.direction = 2; break;
            case 'a': if (snake.direction != 1) snake.direction = 3; break;
        }
    }
}
