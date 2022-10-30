// Copyright 2022 <emogenea, tannasha, tagganab>
// I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
#include <stdio.h>



void drawField();
int gameIsOver();
int keyRead();

int main() {
    int ballX = 5;
    int ballY = 19;

    int rocketRightX = 75;
    int rocketRightY1 = 5;
    int rocketRightY2 = 6;
    int rocketRightY3 = 7;

    int rocketLeftX = 4;
    int rocketLeftY1 = 18;
    int rocketLeftY2 = 19;
    int rocketLeftY3 = 20;

    int movingRight = 1;
    int movingTop = 1;

    int player1 = 0;
    int player2 = 0;

    drawField(ballX, ballY, rocketLeftX, rocketLeftY1, rocketLeftY2,
    rocketLeftY3, rocketRightX, rocketRightY1, rocketRightY2, rocketRightY3);

    while (gameIsOver(player1, player2) != 1) {
        int check = keyRead();
        if (ballY + 1 == 24 && movingRight == 1) {
            movingTop = 1;
        } else if (ballY - 1 == 0 && movingRight == 1) {
            movingTop = 0;
        } else if (ballY - 1 == 0 && movingRight == 0) {
            movingTop = 0;
        } else if (ballY + 1 == 24 && movingRight == 0) {
            movingTop = 1;
        }
        if (ballX == 74 && (ballY == rocketRightY1 ||
        ballY == rocketRightY2 || ballY == rocketRightY3)) {
            movingRight = 0;
        } else if (ballX == 5 && (ballY == rocketLeftY1 ||
        ballY == rocketLeftY2 || ballY == rocketLeftY3)) {
            movingRight = 1;
        }

        if (ballX == 0) {
            player2++;
            ballX = 74;
            ballY = 6;
            rocketRightX = 75;
            rocketRightY1 = 5;
            rocketRightY2 = 6;
            rocketRightY3 = 7;
            rocketLeftX = 4;
            rocketLeftY1 = 18;
            rocketLeftY2 = 19;
            rocketLeftY3 = 20;
        } else if (ballX == 79) {
            player1++;
            ballX = 5;
            ballY = 19;
            rocketRightX = 75;
            rocketRightY1 = 5;
            rocketRightY2 = 6;
            rocketRightY3 = 7;
            rocketLeftX = 4;
            rocketLeftY1 = 18;
            rocketLeftY2 = 19;
            rocketLeftY3 = 20;
        }
        if (check == 0) {
            printf("Invalid Input\n");
            return 0;
        } else if ((check == 2) && (rocketLeftY3 + 1) != 24) {
            rocketLeftY1++;
            rocketLeftY2++;
            rocketLeftY3++;

        } else if ((check == 1) && (rocketLeftY1 - 1) != 0) {
            rocketLeftY1--;
            rocketLeftY2--;
            rocketLeftY3--;

        } else if ((check == 4) && (rocketRightY3 + 1) != 24) {
            rocketRightY1++;
            rocketRightY2++;
            rocketRightY3++;

        } else if ((check == 3) && (rocketRightY1 - 1) != 0) {
            rocketRightY1--;
            rocketRightY2--;
            rocketRightY3--;

        } else if (check == 10) {
            continue;
        }
        if (movingRight == 1 && movingTop == 1) {
            ballX++;
            ballY--;
        } else if (movingRight == 1 && movingTop == 0) {
            ballX++;
            ballY++;
        } else if (movingRight == 0 && movingTop == 1) {
            ballX--;
            ballY--;
        } else if (movingRight == 0 && movingTop == 0) {
            ballX--;
            ballY++;
        }
        drawField(ballX, ballY, rocketLeftX, rocketLeftY1, rocketLeftY2,
        rocketLeftY3, rocketRightX, rocketRightY1,
        rocketRightY2, rocketRightY3);
        printf("P1 - %d:%d - P2\n", player1, player2);
       }
       if (player1 > player2) {
           printf("Player1 WON\n");
       } else {
           printf("Player2 WON\n");
       }
}

void drawField(int ballX, int ballY, int rocketLeftX,
int rocketLeftY1, int rocketLeftY2,
int rocketLeftY3, int rocketRightX, int rocketRightY1,
int rocketRightY2, int rocketRightY3) {
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            if ((y == 0) || (y == 24) ||
            (x == 79) || (x == 0)) {
                printf("#");
            } else if ((y == rocketLeftY1 || y == rocketLeftY2 ||
            y == rocketLeftY3) && x == rocketLeftX) {
                printf("|");
            } else if ((y == rocketRightY1 || y == rocketRightY2 ||
            y == rocketRightY3) && x == rocketRightX) {
                printf("|");
            } else if (x == ballX && ballY == y) {
                printf("o");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


int keyRead() {
    char input = getchar();
    if (input == 'a') {
        return 1;
    } else if (input == 'z') {
        return 2;
    } else if (input == 'k') {
        return 3;
    } else if (input == 'm') {
        return 4;
    } else if (input == ' ') {
        return 5;
    } else if (input == '\n') {
        return 10;
    }
    return 0;
}
int gameIsOver(int a , int b) {
    if (a == 21 || b == 21) {
        return 1;
    }
    return 0;
}
