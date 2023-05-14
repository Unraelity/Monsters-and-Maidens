#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

const int SIZE = 8;

void setBoard(int board[][SIZE]);
void printBoard(int board[][SIZE]);
void computerMove(int board[][SIZE]);
int checkBoard(int board[][SIZE]);

int main(void) {
    
    int board[SIZE][SIZE] = {0};
    int row = 0, column = 0, gameOver = 0;
    char vdirec[10], hdirec[10];
    char playAgain[] = "yes";
    char moveOrAttack[] = "move";
    char hop[] = "yes";
    bool outOfBounce;
    
    setBoard(board);
    
    while (strcmp(playAgain, "yes") == 0) {
        
        outOfBounce = false;
        
        //Player Turn
        if (outOfBounce == false) {
            printf("Player's turn!\n");
            printf("What space is the piece on that you would like to move? (Top Left to Bottom Right) (Row-Column)\n");
            scanf("%d-%d", &row, &column);
            column = column - 1;
            row = row - 1;
            
            if ((board[column][row] != 1) && (board[column][row] != -1)) {
                printf("There is not a chip there.\n");
                outOfBounce = true;
            }
            
            if (outOfBounce == false) {
                if ((row < 0) || (row > 7) || (column < 0) || (column > 7)) {
                    printf("That is out of bounce.\n");
                    outOfBounce = true;
                }
            }
        }
        
        if (outOfBounce == false) {
            printf("Would you like to move or attack?\n");
            scanf("%s", moveOrAttack);
            
            //Player Move
            if ((strcmp(moveOrAttack, "move") == 0) && (outOfBounce == false))  {
                if (outOfBounce == false) {
                    
                    printf("Where would you like to move? (directions: up, down, left, right) (ex: up and right)\n");
                    scanf("%s and %s", vdirec, hdirec);
                    
                    if ((strcmp(vdirec, "up") == 0) && (strcmp(hdirec, "right") == 0)) {
                        
                        if (((row - 1) < 0) || ((column + 1) > 7))  {
                            printf("You cannot move out of bounce.\n");
                            outOfBounce = true;
                        }
                        
                        if (outOfBounce == false) {
                            if ((board[column][row] == 1) && (board[column+1][row-1] == 0)) {
                                board[column][row] = 0;
                                board[column+1][row-1] = 1;
                                if ((row - 1) == 0) {
                                    printf("Congratulations you got a King (K). Now you can move that chip forward and backwards!\n");
                                    board[column+1][row-1] = -1;
                                }
                            }
                            else if ((board[column][row] == -1)  && (board[column+1][row-1] == 0)) {
                                board[column][row] = 0;
                                board[column+1][row-1] = -1;
                            }
                            else {
                                printf("There is already a chip there!\n");
                                outOfBounce = true;
                            }
                        }
                    }
                    
                    else if ((strcmp(vdirec, "up") == 0) && (strcmp(hdirec, "left") == 0)) {
                        
                        if (((row - 1) < 0) || ((column - 1) < 0))  {
                            printf("You cannot move out of bounce.\n");
                            outOfBounce = true;
                        }
                        
                        if (outOfBounce == false) {
                            if ((board[column][row] == 1) && (board[column-1][row-1] == 0)) {
                                board[column][row] = 0;
                                board[column-1][row-1] = 1;
                                if ((row - 1) == 0) {
                                    printf("Congratulations you got a King (K). Now you can move that chip forward and backwards!\n");
                                    board[column-1][row-1] = -1;
                                }
                            }
                            else if ((board[column][row] == -1) && (board[column-1][row-1] == 0)) {
                                board[column][row] = 0;
                                board[column-1][row-1] = -1;
                            }
                            else {
                                printf("There is already a chip there!\n");
                                outOfBounce = true;
                            }
                        }
                    }
                    
                    else if ((strcmp(vdirec, "down") == 0) && (strcmp(hdirec, "right") == 0)) {
                        
                        if (((row + 1) > 7) || ((column + 1) > 7))  {
                            printf("You cannot move out of bounce.\n");
                            outOfBounce = true;
                        }
                        
                        if (board[column][row] != -1) {
                            printf("This piece cannot move down yet.\n");
                            outOfBounce = true;
                        }
                        
                        if ((outOfBounce == false) &&  (board[column+1][row+1] == 0)){
                            board[column][row] = 0;
                            board[column+1][row+1] = -1;
                        }
                        else if (outOfBounce == false) {
                            printf("There is already a chip there!\n");
                            outOfBounce = true;
                        }
                    }
                    
                    else if ((strcmp(vdirec, "down") == 0) && (strcmp(hdirec, "left") == 0)) {
                        
                        if (((row + 1) > 7) || ((column - 1) < 0))  {
                            printf("You cannot move out of bounce.\n");
                            outOfBounce = true;
                        }
                        
                        if (board[column][row] != -1) {
                            printf("This piece cannot move down yet.\n");
                            outOfBounce = true;
                        }
                        
                        if ((outOfBounce == false) && (board[column-1][row+1] == 0)) {
                            board[column][row] = 0;
                            board[column-1][row+1] = -1;
                        }
                        else if (outOfBounce == false) {
                            printf("There is already a chip there!\n");
                            outOfBounce = true;
                        }
                    }
                    
                    else {
                        printf("That is not a valid direction.\n");
                        outOfBounce = true;
                    }
                }
            }
            
        
            
            //Player Attack
            else if ((strcmp(moveOrAttack, "attack") == 0) && (outOfBounce == false)) {
                
                if ((board[column+1][row] != 2) && (board[column-1][row] != 2) && (board[column][row+1] != 2) && (board[column][row-1] != 2) && (board[column-1][row-1] != 2) && (board[column+1][row+1] != 2) && (board[column+1][row-1] != 2) && (board[column-1][row+1] != 2) && (board[column+1][row] != -2) && (board[column-1][row] != -2) && (board[column][row+1] != -2) && (board[column][row-1] != -2) && (board[column-1][row-1] != -2) && (board[column+1][row+1] != -2) && (board[column+1][row-1] != -2) && (board[column-1][row+1] != -2)) {
                    printf("There is no where to attack.\n");
                    outOfBounce = true;
                }
                
                if (outOfBounce == false) {
                    
                    printf("Where would you like to attack? (directions: up, down, left, right) (ex: up and right)\n");
                    scanf("%s and %s", vdirec, hdirec);
                    
                    if ((strcmp(vdirec, "up") == 0) && (strcmp(hdirec, "right") == 0) && ((board[column+1][row-1] == 2) || (board[column+1][row-1] == -2))) {
                        
                        if (((row - 2) < 0) || ((column + 2) > 7))  {
                            printf("You cannot move out of bounce.\n");
                            outOfBounce = true;
                        }
                        
                        if (outOfBounce == false) {
                            if ((board[column][row] == 1) && (board[column+2][row-2] == 0)) {
                                board[column][row] = 0;
                                board[column+1][row-1] = 0;
                                board[column+2][row-2] = 1;
                                if ((row - 2) == 0) {
                                    printf("Congratulations you got a King (K). Now you can move that chip forward and backwards!\n");
                                    board[column+2][row-2] = -1;
                                }
                                
                                column += 2;
                                row -= 2;
                                
                                while ((((board[column+1][row-1] == 2) || (board[column+1][row-1] == -2)) && (board[column+2][row-2] == 0) && (((row - 2) >= 0) && ((column + 2) <= 7))) || (((board[column-1][row-1] == 2) || (board[column-1][row-1] == -2)) && (board[column-2][row-2] == 0) && (((row - 2) >= 0) && ((column - 2) >= 0))) || (((board[column+1][row+1] == 2) || (board[column+1][row+1] == -2)) && (board[column][row] == -1) && (board[column+2][row+2] == 0) && (((row + 2) <= 7) && ((column + 2) <= 7))) || (((board[column-1][row+1] == 2) || (board[column-1][row+1] == -2)) && (board[column][row] == -1) && (board[column-2][row+2] == 0) && (((row - 2) >= 0) && ((column - 2) >= 0)))) {
                                    
                                    printBoard(board);
                                    
                                    printf("Would you like to hop (yes/no)?\n");
                                    scanf("%s", hop);
                                    
                                    if (strcmp(hop, "no") == 0) {
                                        break;
                                    }
                                    
                                    if ((board[column][row] == 1) && (board[column+2][row-2] == 0)) {
                                        board[column][row] = 0;
                                        board[column+1][row-1] = 0;
                                        board[column+2][row-2] = 1;
                                        if ((row - 2) == 0) {
                                            printf("Congratulations you got a King (K). Now you can move that chip forward and backwards!\n");
                                            board[column+2][row-2] = -1;
                                        }
                                        
                                        column += 2;
                                        row -= 2;
                                    }
                                    else if ((board[column][row] == -1)  && (board[column+2][row-2] == 0)) {
                                        board[column][row] = 0;
                                        board[column+1][row-1] = 0;
                                        board[column+2][row-2] = -1;
                                        
                                        column += 2;
                                        row -= 2;
                                    }
                                    else if ((board[column][row] == 1) && (board[column-2][row-2] == 0)) {
                                        board[column][row] = 0;
                                        board[column-1][row-1] = 0;
                                        board[column-2][row-2] = 1;
                                        if ((row - 2) == 0) {
                                            printf("Congratulations you got a King (K). Now you can move that chip forward and backwards!\n");
                                            board[column-2][row-2] = -1;
                                        }
                                        
                                        column -= 2;
                                        row -= 2;
                                    }
                                    else if ((board[column][row] == -1) && (board[column-2][row-2] == 0)) {
                                        board[column][row] = 0;
                                        board[column-1][row-1] = 0;
                                        board[column-2][row-2] = -1;
                                        
                                        column -= 2;
                                        row -= 2;
                                    }
                                    else if ((board[column][row] == -1) && (board[column+2][row+2] == 0)) {
                                        board[column][row] = 0;
                                        board[column+1][row+1] = 0;
                                        board[column+2][row+2] = -1;
                                        
                                        column += 2;
                                        row += 2;
                                    }
                                    else if ((board[column][row] == -1) && (board[column-2][row+2] == 0)) {
                                        board[column][row] = 0;
                                        board[column-1][row+1] = 0;
                                        board[column-2][row+2] = -1;
                                        
                                        column += 2;
                                        row += 2;
                                    }
                                }
                            }
                            
                            else if ((board[column][row] == -1)  && (board[column+2][row-2] == 0)) {
                                board[column][row] = 0;
                                board[column+1][row-1] = 0;
                                board[column+2][row-2] = -1;
                                
                                column += 2;
                                row -= 2;
                                
                                while ((((board[column+1][row-1] == 2) || (board[column+1][row-1] == -2)) && (board[column+2][row-2] == 0) && (((row - 2) >= 0) && ((column + 2) <= 7))) || (((board[column-1][row-1] == 2) || (board[column-1][row-1] == -2)) && (board[column-2][row-2] == 0) && (((row - 2) >= 0) && ((column - 2) >= 0))) || (((board[column+1][row+1] == 2) || (board[column+1][row+1] == -2)) && (board[column][row] == -1) && (board[column+2][row+2] == 0) && (((row + 2) <= 7) && ((column + 2) <= 7))) || (((board[column-1][row+1] == 2) || (board[column-1][row+1] == -2)) && (board[column][row] == -1) && (board[column-2][row+2] == 0) && (((row - 2) >= 0) && ((column - 2) >= 0)))) {
                                    
                                    printBoard(board);
                                    
                                    printf("Would you like to hop (yes/no)?\n");
                                    scanf("%s", hop);
                                    
                                    if (strcmp(hop, "no") == 0) {
                                        break;
                                    }
                                    
                                    if ((board[column][row] == -1)  && (board[column+2][row-2] == 0)) {
                                        board[column][row] = 0;
                                        board[column+1][row-1] = 0;
                                        board[column+2][row-2] = -1;
                                        
                                        column += 2;
                                        row -= 2;
                                    }
                                    else if ((board[column][row] == -1) && (board[column-2][row-2] == 0)) {
                                        board[column][row] = 0;
                                        board[column-1][row-1] = 0;
                                        board[column-2][row-2] = -1;
                                        
                                        column -= 2;
                                        row -= 2;
                                    }
                                    else if ((board[column][row] == -1) && (board[column+2][row+2] == 0)) {
                                        board[column][row] = 0;
                                        board[column+1][row+1] = 0;
                                        board[column+2][row+2] = -1;
                                        
                                        column += 2;
                                        row += 2;
                                    }
                                    else if ((board[column][row] == -1) && (board[column-2][row+2] == 0)) {
                                        board[column][row] = 0;
                                        board[column-1][row+1] = 0;
                                        board[column-2][row+2] = -1;
                                        
                                        column += 2;
                                        row += 2;
                                    }
                                }
                            }
                            else {
                                printf("There is already a chip there!\n");
                                outOfBounce = true;
                            }
                        }
                    }
                    else if ((strcmp(vdirec, "up") == 0) && (strcmp(hdirec, "left") == 0) && ((board[column-1][row-1] == 2) || (board[column-1][row-1] == -2))) {
                        
                        if (((row - 2) < 0) || ((column - 2) < 0))  {
                            printf("You cannot move out of bounce.\n");
                            outOfBounce = true;
                        }
                        
                        if (outOfBounce == false) {
                            if ((board[column][row] == 1) && (board[column-2][row-2] == 0)) {
                                board[column][row] = 0;
                                board[column-1][row-1] = 0;
                                board[column-2][row-2] = 1;
                                if ((row - 2) == 0) {
                                    printf("Congratulations you got a King (K). Now you can move that chip forward and backwards!\n");
                                    board[column-2][row-2] = -1;
                                }
                                column -= 2;
                                row -= 2;
                                
                                while ((((board[column+1][row-1] == 2) || (board[column+1][row-1] == -2)) && (board[column+2][row-2] == 0) && (((row - 2) >= 0) && ((column + 2) <= 7))) || (((board[column-1][row-1] == 2) || (board[column-1][row-1] == -2)) && (board[column-2][row-2] == 0) && (((row - 2) >= 0) && ((column - 2) >= 0))) || (((board[column+1][row+1] == 2) || (board[column+1][row+1] == -2)) && (board[column][row] == -1) && (board[column+2][row+2] == 0) && (((row + 2) <= 7) && ((column + 2) <= 7))) || (((board[column-1][row+1] == 2) || (board[column-1][row+1] == -2)) && (board[column][row] == -1) && (board[column-2][row+2] == 0) && (((row - 2) >= 0) && ((column - 2) >= 0)))) {
                                    
                                    printBoard(board);
                                    
                                    printf("Would you like to hop (yes/no)?\n");
                                    scanf("%s", hop);
                                    
                                    if (strcmp(hop, "no") == 0) {
                                        break;
                                    }
                                    
                                    if ((board[column][row] == 1) && (board[column+2][row-2] == 0)) {
                                        board[column][row] = 0;
                                        board[column+1][row-1] = 0;
                                        board[column+2][row-2] = 1;
                                        if ((row - 2) == 0) {
                                            printf("Congratulations you got a King (K). Now you can move that chip forward and backwards!\n");
                                            board[column+2][row-2] = -1;
                                        }
                
                                        column += 2;
                                        row -= 2;
                                    }
                                    else if ((board[column][row] == -1)  && (board[column+2][row-2] == 0)) {
                                        board[column][row] = 0;
                                        board[column+1][row-1] = 0;
                                        board[column+2][row-2] = -1;
                                        
                                        column += 2;
                                        row -= 2;
                                    }
                                    else if ((board[column][row] == 1) && (board[column-2][row-2] == 0)) {
                                        board[column][row] = 0;
                                        board[column-1][row-1] = 0;
                                        board[column-2][row-2] = 1;
                                        if ((row - 2) == 0) {
                                            printf("Congratulations you got a King (K). Now you can move that chip forward and backwards!\n");
                                            board[column-2][row-2] = -1;
                                        }
                                       
                                        column -= 2;
                                        row -= 2;
                                    }
                                    else if ((board[column][row] == -1) && (board[column-2][row-2] == 0)) {
                                        board[column][row] = 0;
                                        board[column-1][row-1] = 0;
                                        board[column-2][row-2] = -1;
                                        
                                        column -= 2;
                                        row -= 2;
                                    }
                                    else if ((board[column][row] == -1) && (board[column+2][row+2] == 0)) {
                                        board[column][row] = 0;
                                        board[column+1][row+1] = 0;
                                        board[column+2][row+2] = -1;
                                        
                                        column += 2;
                                        row += 2;
                                    }
                                    else if ((board[column][row] == -1) && (board[column-2][row+2] == 0)) {
                                        board[column][row] = 0;
                                        board[column-1][row+1] = 0;
                                        board[column-2][row+2] = -1;
                                        
                                        column += 2;
                                        row += 2;
                                    }
                                }
                            }
                            
                            else if ((board[column][row] == -1) && (board[column-2][row-2] == 0)) {
                                board[column][row] = 0;
                                board[column-1][row-1] = 0;
                                board[column-2][row-2] = -1;
                                
                                column -= 2;
                                row -= 2;
                                
                                while ((((board[column+1][row-1] == 2) || (board[column+1][row-1] == -2)) && (board[column+2][row-2] == 0) && (((row - 2) >= 0) && ((column + 2) <= 7))) || (((board[column-1][row-1] == 2) || (board[column-1][row-1] == -2)) && (board[column-2][row-2] == 0) && (((row - 2) >= 0) && ((column - 2) >= 0))) || (((board[column+1][row+1] == 2) || (board[column+1][row+1] == -2)) && (board[column][row] == -1) && (board[column+2][row+2] == 0) && (((row + 2) <= 7) && ((column + 2) <= 7))) || (((board[column-1][row+1] == 2) || (board[column-1][row+1] == -2)) && (board[column][row] == -1) && (board[column-2][row+2] == 0) && (((row - 2) >= 0) && ((column - 2) >= 0)))) {
                                   
                                    printBoard(board);
                                    
                                    printf("Would you like to hop (yes/no)?\n");
                                    scanf("%s", hop);
                                    
                                    if (strcmp(hop, "no") == 0) {
                                        break;
                                    }
                                    
                                    if ((board[column][row] == -1)  && (board[column+2][row-2] == 0)) {
                                        board[column][row] = 0;
                                        board[column+1][row-1] = 0;
                                        board[column+2][row-2] = -1;
                                        
                                        column += 2;
                                        row -= 2;
                                    }
                                    else if ((board[column][row] == -1) && (board[column-2][row-2] == 0)) {
                                        board[column][row] = 0;
                                        board[column-1][row-1] = 0;
                                        board[column-2][row-2] = -1;
                                        
                                        column -= 2;
                                        row -= 2;
                                    }
                                    else if ((board[column][row] == -1) && (board[column+2][row+2] == 0)) {
                                        board[column][row] = 0;
                                        board[column+1][row+1] = 0;
                                        board[column+2][row+2] = -1;
                                        
                                        column += 2;
                                        row += 2;
                                    }
                                    else if ((board[column][row] == -1) && (board[column-2][row+2] == 0)) {
                                        board[column][row] = 0;
                                        board[column-1][row+1] = 0;
                                        board[column-2][row+2] = -1;
                                        
                                        column += 2;
                                        row += 2;
                                    }
                                }
                            }
                            else {
                                printf("There is already a chip there!\n");
                                outOfBounce = true;
                            }
                        }
                    }
                    else if ((strcmp(vdirec, "down") == 0) && (strcmp(hdirec, "right") == 0) && ((board[column+1][row+1] == 2) || (board[column+1][row+1] == -2))) {
                        
                        if (((row + 2) > 7) || ((column + 2) > 7))  {
                            printf("You cannot move out of bounce.\n");
                            outOfBounce = true;
                        }
                        
                        if (board[column][row] != -1) {
                            printf("This piece cannot move down yet.\n");
                            outOfBounce = true;
                        }
                        
                        if ((outOfBounce == false) || (board[column+2][row+2] == 0)) {
                            board[column][row] = 0;
                            board[column+1][row+1] = 0;
                            board[column+2][row+2] = -1;
                            
                            column += 2;
                            row += 2;
                            
                            while ((((board[column+1][row-1] == 2) || (board[column+1][row-1] == -2)) && (board[column+2][row-2] == 0) && (((row - 2) >= 0) && ((column + 2) <= 7))) || (((board[column-1][row-1] == 2) || (board[column-1][row-1] == -2)) && (board[column-2][row-2] == 0) && (((row - 2) >= 0) && ((column - 2) >= 0))) || (((board[column+1][row+1] == 2) || (board[column+1][row+1] == -2)) && (board[column][row] == -1) && (board[column+2][row+2] == 0) && (((row + 2) <= 7) && ((column + 2) <= 7))) || (((board[column-1][row+1] == 2) || (board[column-1][row+1] == -2)) && (board[column][row] == -1) && (board[column-2][row+2] == 0) && (((row - 2) >= 0) && ((column - 2) >= 0)))) {
                                
                                printBoard(board);
                                
                                printf("Would you like to hop (yes/no)?\n");
                                scanf("%s", hop);
                                
                                if (strcmp(hop, "no") == 0) {
                                    break;
                                }
                                
                                if ((board[column][row] == -1)  && (board[column+2][row-2] == 0)) {
                                    board[column][row] = 0;
                                    board[column+1][row-1] = 0;
                                    board[column+2][row-2] = -1;
                                    
                                    column += 2;
                                    row -= 2;
                                }
                                else if ((board[column][row] == -1) && (board[column-2][row-2] == 0)) {
                                    board[column][row] = 0;
                                    board[column-1][row-1] = 0;
                                    board[column-2][row-2] = -1;
                                    
                                    column -= 2;
                                    row -= 2;
                                }
                                else if ((board[column][row] == -1) && (board[column+2][row+2] == 0)) {
                                    board[column][row] = 0;
                                    board[column+1][row+1] = 0;
                                    board[column+2][row+2] = -1;
                                    
                                    column += 2;
                                    row += 2;
                                }
                                else if ((board[column][row] == -1) && (board[column-2][row+2] == 0)) {
                                    board[column][row] = 0;
                                    board[column-1][row+1] = 0;
                                    board[column-2][row+2] = -1;
                                    
                                    column += 2;
                                    row += 2;
                                }
                            }
                        }
                        else {
                            printf("There is already a chip there!\n");
                            outOfBounce = true;
                        }
                    }
                    else if ((strcmp(vdirec, "down") == 0) && (strcmp(hdirec, "left") == 0) && ((board[column-1][row+1] == 2) || (board[column-1][row+1] == -2))) {
                        
                        if (((row + 2) > 7) || ((column - 2) < 0))  {
                            printf("You cannot move out of bounce.\n");
                            outOfBounce = true;
                        }
                        
                        if (board[column][row] != -1) {
                            printf("This piece cannot move down yet.\n");
                            outOfBounce = true;
                        }
                        
                        if ((outOfBounce == false) && (board[column-2][row+2] == 0)) {
                            board[column][row] = 0;
                            board[column-1][row+1] = 0;
                            board[column-2][row+2] = -1;
                            
                            column += 2;
                            row += 2;
                            
                            while ((((board[column+1][row-1] == 2) || (board[column+1][row-1] == -2)) && (board[column+2][row-2] == 0) && (((row - 2) >= 0) && ((column + 2) <= 7))) || (((board[column-1][row-1] == 2) || (board[column-1][row-1] == -2)) && (board[column-2][row-2] == 0) && (((row - 2) >= 0) && ((column - 2) >= 0))) || (((board[column+1][row+1] == 2) || (board[column+1][row+1] == -2)) && (board[column][row] == -1) && (board[column+2][row+2] == 0) && (((row + 2) <= 7) && ((column + 2) <= 7))) || (((board[column-1][row+1] == 2) || (board[column-1][row+1] == -2)) && (board[column][row] == -1) && (board[column-2][row+2] == 0) && (((row - 2) >= 0) && ((column - 2) >= 0)))) {
                                
                                printBoard(board);
                                
                                printf("Would you like to hop (yes/no)?\n");
                                scanf("%s", hop);
                                
                                if (strcmp(hop, "no") == 0) {
                                    break;
                                }
                                
                                if ((board[column][row] == -1)  && (board[column+2][row-2] == 0)) {
                                    board[column][row] = 0;
                                    board[column+1][row-1] = 0;
                                    board[column+2][row-2] = -1;
                                    
                                    column += 2;
                                    row -= 2;
                                }
                                else if ((board[column][row] == -1) && (board[column-2][row-2] == 0)) {
                                    board[column][row] = 0;
                                    board[column-1][row-1] = 0;
                                    board[column-2][row-2] = -1;
                                    
                                    column -= 2;
                                    row -= 2;
                                }
                                else if ((board[column][row] == -1) && (board[column+2][row+2] == 0)) {
                                    board[column][row] = 0;
                                    board[column+1][row+1] = 0;
                                    board[column+2][row+2] = -1;
                                    
                                    column += 2;
                                    row += 2;
                                }
                                else if ((board[column][row] == -1) && (board[column-2][row+2] == 0)) {
                                    board[column][row] = 0;
                                    board[column-1][row+1] = 0;
                                    board[column-2][row+2] = -1;
                                    
                                    column += 2;
                                    row += 2;
                                }
                            }
                        }
                        else {
                            printf("There is already a chip there!\n");
                            outOfBounce = true;
                        }
                    }
                    else {
                        printf("That is not a valid direction.\n");
                        outOfBounce = true;
                    }
                }
            }
            else {
                printf("That is not an option\n");
                outOfBounce = true;
            }
            
        }
        
        if (outOfBounce == false) {
            gameOver = checkBoard(board);
        }
        
        if ((outOfBounce == false) && (gameOver == 0)) {
            printBoard(board);
        }
        
        //Computer Turn
        
        if (outOfBounce == false) {
            computerMove(board);
        }
        
        
        if (outOfBounce == false) {
            gameOver = checkBoard(board);
        }
        
        if ((outOfBounce == false) && (gameOver == 0)) {
            printBoard(board);
        }
        
        if (gameOver == 1) {
            printBoard(board);
            printf("Great job you won!\n");
            printf("Do you want to play again? (yes/no)\n");
            scanf("%s", playAgain);
            if (strcmp(playAgain, "yes") == 0) {
                setBoard(board);
            }
        }
        else if (gameOver == 2) {
            printBoard(board);
            printf("You lost try again.\n");
            printf("Do you want to play again? (yes/no)\n");
            scanf("%s", playAgain);
            if (strcmp(playAgain, "yes") == 0) {
                setBoard(board);
            }
        }
    }
    return 0;
}

void setBoard(int board[][SIZE]) {
    
    //Computer chips
    board[1][0] = 2;
    board[3][0] = 2;
    board[5][0] = 2;
    board[7][0] = 2;
    board[0][1] = 2;
    board[2][1] = 2;
    board[4][1] = 2;
    board[6][1] = 2;
    board[1][2] = 2;
    board[3][2] = 2;
    board[5][2] = 2;
    board[7][2] = 2;
    //User chips;
    board[0][7] = 1;
    board[2][7] = 1;
    board[4][7] = 1;
    board[6][7] = 1;
    board[1][6] = 1;
    board[3][6] = 1;
    board[5][6] = 1;
    board[7][6] = 1;
    board[0][5] = 1;
    board[2][5] = 1;
    board[4][5] = 1;
    board[6][5] = 1;
    
    printBoard(board);
}

void printBoard(int board[][SIZE]) {
    int i, j;
    
    printf("  1 2 3 4 5 6 7 8\n");
    printf(" -----------------\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d", i+1);
        printf("|");
        for (j = 0; j < SIZE; j++) {
            if (board[j][i] == 1) {
                printf("X");
            }
            else if (board[j][i] == 2) {
                printf("O");
            }
            else if (board[j][i] == -1) {
                printf("K");
            }
            else if (board[j][i] == -2) {
                printf("Q");
            }
            else if (board[j][i] == 0) {
                printf(" ");
            }
            if (j < (SIZE - 1)) {
                printf("|");
            }
        }
        printf("|");
        printf("%d", i+1);
        printf("\n");
        printf(" -----------------\n");
    }
    printf("  1 2 3 4 5 6 7 8\n");
}

void computerMove(int board[][SIZE]) {
    int i, j;
    bool computerAttack = false, openSpace = false;
    
    printf("Computer's turn!\n");
    
    //Attack
    for (i = 7; i > -1; i--) {
        for (j = 7; j > -1; j--) {
            
            if (board[j][i] == -2) {
                if ((board[j+1][i+1] == 1) && (board[j+2][i+2] == 0) && ((j + 2) <= 7) && ((i + 2) <= 7)) {
                    board[j][i] = 0;
                    board[j+1][i+1] = 0;
                    board[j+2][i+2] = -2;
                    j += 2;
                    i += 2;
                    computerAttack = true;
                    
                    while ((((board[j+1][i+1] == 1) || (board[j+1][i+1] == 1)) && (board[j+2][i+2] == 0) && ((j + 2) <= 7) && ((i + 2) <= 7)) || (((board[j-1][i+1] == 1) || (board[j-1][i+1] == -1)) && (board[j-2][i+2] == 0) && ((j - 2) >= 0) && ((i + 2) <= 7)) || (((board[j-1][i-1] == 1) || (board[j-1][i-1] == -1)) && (board[j][i] == -2) && (board[j-2][i-2] == 0)  && ((j - 2) >= 0) && ((i - 2) >= 0)) || (((board[j+1][i-1] == 1) || (board[j+1][i-1] == -1)) && (board[j][i] == -2) && (board[j+2][i-2] == 0)  && ((j + 2) <= 7) && ((i - 2) >= 0))) {
                        
                        printBoard(board);
                        
                        if ((board[j+2][i+2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j+1][i+1] = 0;
                            board[j+2][i+2] = -2;
                            
                            j+=2;
                            i+=2;
                        }
                        else if ((board[j-2][i+2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j-1][i+1] = 0;
                            board[j-2][i+2] = -2;
                            
                            j-=2;
                            i+=2;
                        }
                        else if ((board[j-2][i-2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j-1][i-1] = 0;
                            board[j-2][i-2] = -2;
                            
                            j-=2;
                            i-=2;
                        }
                        else if ((board[j+2][i-2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j+1][i-1] = 0;
                            board[j+2][i-2] = -2;
                            
                            j+=2;
                            i-=2;
                        }
                    }
                    
                    j = 0;
                    i = 0;
                }
                
                else if ((board[j-1][i+1] == 1) && (board[j-2][i+2] == 0) && ((j - 2) >= 0) && ((i + 2) <= 7)) {
                    board[j][i] = 0;
                    board[j-1][i+1] = 0;
                    board[j-2][i+2] = -2;
                    j -= 2;
                    i += 2;
                    computerAttack = true;
                    
                    while ((((board[j+1][i+1] == 1) || (board[j+1][i+1] == 1)) && (board[j+2][i+2] == 0) && ((j + 2) <= 7) && ((i + 2) <= 7)) || (((board[j-1][i+1] == 1) || (board[j-1][i+1] == -1)) && (board[j-2][i+2] == 0) && ((j - 2) >= 0) && ((i + 2) <= 7)) || (((board[j-1][i-1] == 1) || (board[j-1][i-1] == -1)) && (board[j][i] == -2) && (board[j-2][i-2] == 0)  && ((j - 2) >= 0) && ((i - 2) >= 0)) || (((board[j+1][i-1] == 1) || (board[j+1][i-1] == -1)) && (board[j][i] == -2) && (board[j+2][i-2] == 0)  && ((j + 2) <= 7) && ((i - 2) >= 0))) {
                        
                        printBoard(board);
                        
                        if ((board[j+2][i+2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j+1][i+1] = 0;
                            board[j+2][i+2] = -2;
                            
                            j+=2;
                            i+=2;
                        }
                        else if ((board[j-2][i+2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j-1][i+1] = 0;
                            board[j-2][i+2] = -2;
                            
                            j-=2;
                            i+=2;
                        }
                        else if ((board[j-2][i-2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j-1][i-1] = 0;
                            board[j-2][i-2] = -2;
                            
                            j-=2;
                            i-=2;
                        }
                        else if ((board[j+2][i-2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j+1][i-1] = 0;
                            board[j+2][i-2] = -2;
                            
                            j+=2;
                            i-=2;
                        }
                    }
                    
                    i = 0;
                    j = 0;
                }
                
                else if ((board[j-1][i-1] == 1) && (board[j-2][i-2] == 0) && ((j - 2) >= 0) && ((i - 2) >= 0)) {
                    board[j][i] = 0;
                    board[j-1][i-1] = 0;
                    board[j-2][i-2] = -2;
                    j -= 2;
                    i -= 2;
                    computerAttack = true;
                    
                    while ((((board[j+1][i+1] == 1) || (board[j+1][i+1] == 1)) && (board[j+2][i+2] == 0) && ((j + 2) <= 7) && ((i + 2) <= 7)) || (((board[j-1][i+1] == 1) || (board[j-1][i+1] == -1)) && (board[j-2][i+2] == 0) && ((j - 2) >= 0) && ((i + 2) <= 7)) || (((board[j-1][i-1] == 1) || (board[j-1][i-1] == -1)) && (board[j][i] == -2) && (board[j-2][i-2] == 0)  && ((j - 2) >= 0) && ((i - 2) >= 0)) || (((board[j+1][i-1] == 1) || (board[j+1][i-1] == -1)) && (board[j][i] == -2) && (board[j+2][i-2] == 0)  && ((j + 2) <= 7) && ((i - 2) >= 0))) {
                        
                        printBoard(board);
                        
                        if ((board[j+2][i+2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j+1][i+1] = 0;
                            board[j+2][i+2] = -2;
                            
                            j+=2;
                            i+=2;
                        }
                        else if ((board[j-2][i+2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j-1][i+1] = 0;
                            board[j-2][i+2] = -2;
                            
                            j-=2;
                            i+=2;
                        }
                        else if ((board[j-2][i-2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j-1][i-1] = 0;
                            board[j-2][i-2] = -2;
                            
                            j-=2;
                            i-=2;
                        }
                        else if ((board[j+2][i-2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j+1][i-1] = 0;
                            board[j+2][i-2] = -2;
                            
                            j+=2;
                            i-=2;
                        }
                    }
                    
                    j = 0;
                    i = 0;
                }
                
                else if ((board[j+1][i-1] == 1) && (board[j+2][i-2] == 0) && ((j + 2) <= 7) && ((i - 2) >= 0)) {
                    board[j][i] = 0;
                    board[j+1][i-1] = 0;
                    board[j+2][i-2] = -2;
                    j += 2;
                    i -= 2;
                    computerAttack = true;
                    
                    while ((((board[j+1][i+1] == 1) || (board[j+1][i+1] == 1)) && (board[j+2][i+2] == 0) && ((j + 2) <= 7) && ((i + 2) <= 7)) || (((board[j-1][i+1] == 1) || (board[j-1][i+1] == -1)) && (board[j-2][i+2] == 0) && ((j - 2) >= 0) && ((i + 2) <= 7)) || (((board[j-1][i-1] == 1) || (board[j-1][i-1] == -1)) && (board[j][i] == -2) && (board[j-2][i-2] == 0)  && ((j - 2) >= 0) && ((i - 2) >= 0)) || (((board[j+1][i-1] == 1) || (board[j+1][i-1] == -1)) && (board[j][i] == -2) && (board[j+2][i-2] == 0)  && ((j + 2) <= 7) && ((i - 2) >= 0))) {
                        
                        printBoard(board);
                        
                        if ((board[j+2][i+2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j+1][i+1] = 0;
                            board[j+2][i+2] = -2;
                            
                            j+=2;
                            i+=2;
                        }
                        if ((board[j-2][i+2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j-1][i+1] = 0;
                            board[j-2][i+2] = -2;
                            
                            j-=2;
                            i+=2;
                        }
                        else if ((board[j-2][i-2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j-1][i-1] = 0;
                            board[j-2][i-2] = -2;
                            
                            j-=2;
                            i-=2;
                        }
                        else if ((board[j+2][i-2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j+1][i-1] = 0;
                            board[j+2][i-2] = -2;
                            
                            j+=2;
                            i-=2;
                        }
                    }
                    
                    j = 0;
                    i = 0;
                }
            }
            
            else if (board[j][i] == 2) {
                if ((board[j+1][i+1] == 1) && (board[j+2][i+2] == 0) && ((j + 2) <= 7) && ((i + 2) <= 7)) {
                    board[j][i] = 0;
                    board[j+1][i+1] = 0;
                    board[j+2][i+2] = 2;
                    j+=2;
                    i+=2;
                    computerAttack = true;
                    
                    if ((i) == 7) {
                        printf("Uh oh the computer got a Queen (Q). Now it can move that chip forward and backwards!\n");
                        board[j][i] = -2;
                    }
                    
                    while ((((board[j+1][i+1] == 1) || (board[j+1][i+1] == 1)) && (board[j+2][i+2] == 0) && ((j + 2) <= 7) && ((i + 2) <= 7)) || (((board[j-1][i+1] == 1) || (board[j-1][i+1] == -1)) && (board[j-2][i+2] == 0) && ((j - 2) >= 0) && ((i + 2) <= 7)) || (((board[j-1][i-1] == 1) || (board[j-1][i-1] == -1)) && (board[j][i] == -2) && (board[j-2][i-2] == 0)  && ((j - 2) >= 0) && ((i - 2) >= 0)) || (((board[j+1][i-1] == 1) || (board[j+1][i-1] == -1)) && (board[j][i] == -2) && (board[j+2][i-2] == 0)  && ((j + 2) <= 7) && ((i - 2) >= 0))) {
                        
                        printBoard(board);
                        
                        if ((board[j+2][i+2] == 0) && (board[j][i] == 2)) {
                            board[j][i] = 0;
                            board[j+1][i+1] = 0;
                            board[j+2][i+2] = 2;
                            
                            j+=2;
                            i+=2;
                            if ((i) == 7) {
                                printf("Uh oh the computer got a Queen (Q). Now it can move that chip forward and backwards!\n");
                                board[j][i] = -2;
                            }
                        }
                        else if ((board[j-2][i+2] == 0) && (board[j][i] == 2)) {
                            board[j][i] = 0;
                            board[j-1][i+1] = 0;
                            board[j-2][i+2] = 2;
                            
                            j-=2;
                            i+=2;
                            if ((i) == 7) {
                                printf("Uh oh the computer got a Queen (Q). Now it can move that chip forward and backwards!\n");
                                board[j][i] = -2;
                            }
                        }
                        else if ((board[j+2][i+2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j+1][i+1] = 0;
                            board[j+2][i+2] = 2;
                            
                            j+=2;
                            i+=2;
                        }
                        else if ((board[j-2][i+2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j-1][i+1] = 0;
                            board[j-2][i+2] = 2;
                            
                            j-=2;
                            i+=2;
                        }
                        else if ((board[j-2][i-2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j-1][i-1] = 0;
                            board[j-2][i-2] = 2;
                            
                            j-=2;
                            i-=2;
                        }
                        else if ((board[j+2][i-2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j+1][i-1] = 0;
                            board[j+2][i-2] = 2;
                            
                            j+=2;
                            i-=2;
                        }
                    }
                    
                    j = 0;
                    i = 0;
                }
                
                else if ((board[j-1][i+1] == 1) && (board[j-2][i+2] == 0) && ((j - 2) >= 0) && ((i + 2) <= 7)) {
                    board[j][i] = 0;
                    board[j-1][i+1] = 0;
                    board[j-2][i+2] = 2;
                    j -= 2;
                    i += 2;
                    computerAttack = true;
                    
                    if ((i) == 7) {
                        printf("Uh oh the computer got a Queen (Q). Now it can move that chip forward and backwards!\n");
                        board[j][i] = -2;
                    }
                    
                    while ((((board[j+1][i+1] == 1) || (board[j+1][i+1] == 1)) && (board[j+2][i+2] == 0) && ((j + 2) <= 7) && ((i + 2) <= 7)) || (((board[j-1][i+1] == 1) || (board[j-1][i+1] == -1)) && (board[j-2][i+2] == 0) && ((j - 2) >= 0) && ((i + 2) <= 7)) || (((board[j-1][i-1] == 1) || (board[j-1][i-1] == -1)) && (board[j][i] == -2) && (board[j-2][i-2] == 0)  && ((j - 2) >= 0) && ((i - 2) >= 0)) || (((board[j+1][i-1] == 1) || (board[j+1][i-1] == -1)) && (board[j][i] == -2) && (board[j+2][i-2] == 0)  && ((j + 2) <= 7) && ((i - 2) >= 0))) {
                        
                        printBoard(board);
                        
                        if ((board[j+2][i+2] == 0) && (board[j][i] == 2)) {
                            board[j][i] = 0;
                            board[j+1][i+1] = 0;
                            board[j+2][i+2] = 2;
                            
                            j+=2;
                            i+=2;
                            if ((i) == 7) {
                                printf("Uh oh the computer got a Queen (Q). Now it can move that chip forward and backwards!\n");
                                board[j][i] = -2;
                            }
                        }
                        else if ((board[j-2][i+2] == 0) && (board[j][i] == 2)) {
                            board[j][i] = 0;
                            board[j-1][i+1] = 0;
                            board[j-2][i+2] = 2;
                            
                            j-=2;
                            i+=2;
                            if ((i) == 7) {
                                printf("Uh oh the computer got a Queen (Q). Now it can move that chip forward and backwards!\n");
                                board[j][i] = -2;
                            }
                        }
                        else if ((board[j+2][i+2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j+1][i+1] = 0;
                            board[j+2][i+2] = 2;
                            
                            j+=2;
                            i+=2;
                        }
                        else if ((board[j-2][i+2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j-1][i+1] = 0;
                            board[j-2][i+2] = 2;
                            
                            j-=2;
                            i+=2;
                        }
                        else if ((board[j-2][i-2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j-1][i-1] = 0;
                            board[j-2][i-2] = 2;
                            
                            j-=2;
                            i-=2;
                        }
                        else if ((board[j+2][i-2] == 0) && (board[j][i] == -2)) {
                            board[j][i] = 0;
                            board[j+1][i-1] = 0;
                            board[j+2][i-2] = 2;
                            
                            j+=2;
                            i-=2;
                        }
                    }
                    
                    j = 0;
                    i = 0;
                }
            }
        }
    }
    
    //Move To Safe Space
    if (computerAttack == false) {
        for (i = 7; i > -1; i--) {
            for (j = 7; j > -1; j--) {
                
                if (board[j][i] == -2) {
                    if ((board[j+1][i+1] == 0) && ((board[j+2][i+2] == 0) || (board[j+2][i+2] == 2) || (board[j+2][i+2] == -2)) && ((board[j][i+2] == 0) || (board[j][i+2] == 2) || (board[j][i+2] == -2)) && ((j + 1) <= 7) && ((i + 1) <= 7)) {
                        board[j][i] = 0;
                        board[j+1][i+1] = -2;
                        j = 0;
                        i = 0;
                        openSpace = true;
                    }
                    else if ((board[j-1][i+1] == 0) && ((board[j-2][i+2] == 0) || (board[j-2][i+2] == 2) || (board[j-2][i+2] == -2)) && ((board[j][i+2] == 0) || (board[j][i+2] == 2) || (board[j][i+2] == -2)) && ((j - 1) >= 0) && ((i + 1) <= 7)) {
                        board[j][i] = 0;
                        board[j-1][i+1] = -2;
                        j = 0;
                        i = 0;
                        openSpace = true;
                    }
                    else if ((board[j-1][i-1] == 0) && ((board[j-2][i-2] != -1) || (board[j-2][i-2] == -2) || (board[j-2][i-2] == 2)) && ((board[j][i-2] != -1) || (board[j][i-2] == -2) || (board[j][i-2] == 2)) && ((j - 1) >= 0) && ((i - 1) >= 0)) {
                        board[j][i] = 0;
                        board[j-1][i-1] = -2;
                        j = 0;
                        i = 0;
                        openSpace = true;
                    }
                    else if ((board[j+1][i-1] == 0) && ((board[j+2][i-2] != -1) || (board[j+2][i-2] == 2) || (board[j+2][i-2] == -2)) && ((board[j][i-2] != -1) || (board[j][i-2] == 2) || (board[j][i-2] == -2)) && ((j + 2) <= 0) && ((i - 2) >= 0)) {
                        board[j][i] = 0;
                        board[j+1][i-1] = -2;
                        j = 0;
                        i = 0;
                        openSpace = true;
                    }
                }
                
                else if (board[j][i] == 2) {
                    if (((i + 1) == 7)  && ((board[j+1][i+1] == 0) || (board[j-1][i+1] == 0))) {
                        if (board[j+1][i+1] == 0) {
                            printf("Uh oh the computer got a Queen (Q). Now it can move that chip forward and backwards!\n");
                            board[j+1][i+1] = -2;
                        }
                        else if (board[j-1][i+1] == 0) {
                            printf("Uh oh the computer got a Queen (Q). Now it can move that chip forward and backwards!\n");
                            board[j-1][i+1] = -2;
                        }
                    }
                    
                    else if ((board[j+1][i+1] == 0) && ((board[j+2][i+2] == 0) || (board[j+2][i+2] == 2) || (board[j+2][i+2] == -2)) && ((board[j][i+2] == 0) || (board[j][i+2] == 2) || (board[j][i+2] == -2)) && ((j + 2) <= 7) && ((i + 2) <= 7)) {
                        board[j][i] = 0;
                        board[j+1][i+1] = 2;
    
                        openSpace = true;
                        if ((i + 1) == 7) {
                            printf("Uh oh the computer got a Queen (Q). Now it can move that chip forward and backwards!\n");
                            board[j][i+1] = -2;
                        }
                        j = 0;
                        i = 0;
                    }
                    
                    else if ((board[j-1][i+1] == 0) && ((board[j-2][i+2] == 0) || (board[j-2][i+2] == 2) || (board[j-2][i+2] == -2)) && ((board[j][i+2] == 0) || (board[j][i+2] == 2) || (board[j][i+2] == -2)) && ((j - 2) >= 0) && ((i + 2) <= 7)) {
                        board[j][i] = 0;
                        board[j-1][i+1] = 2;
            
                        openSpace = true;
                        if ((i + 1) == 7) {
                            printf("Uh oh the computer got a Queen (Q). Now it can move that chip forward and backwards!\n");
                            board[j-1][i+1] = -2;
                        }
                        j = 0;
                        i = 0;
                    }
                }
                
            }
        }
    }
    
    //Move To Random Space
    if ((computerAttack == false) && (openSpace == false)) {
        for (i = 7; i > -1; i--) {
            for (j = 7; j > -1; j--) {
                if (board[j][i] == 2) {
                    if ((board[j+1][i+1] == 0) && ((i+1) <= 7) && ((j+1) <= 7)) {
                        board[j][i] = 0;
                        board[j+1][i+1] = 2;
                        j = 0;
                        i = 0;
                        if ((i + 1) == 7) {
                            printf("Uh oh the computer got a Queen (Q). Now it can move that chip forward and backwards!\n");
                            board[j+1][i+1] = -2;
                        }
                    }
                    else if ((board[j-1][i+1] == 0) && ((i-1) >= 0) && ((j+1) <= 7)) {
                        board[j][i] = 0;
                        board[j-1][i+1] = 2;
                        j = 0;
                        i = 0;
                        if ((i + 1) == 7) {
                            printf("Uh oh the computer got a Queen (Q). Now it can move that chip forward and backwards!\n");
                            board[j-1][i+1] = -2;
                        }
                    }
                }
                else if (board[j][i] == -2) {
                    if ((board[j+1][i+1] == 0) && ((i+1) <= 7) && ((j+1) <= 7)) {
                        board[j][i] = 0;
                        board[j+1][i+1] = -2;
                        j = 0;
                        i = 0;
                    }
                    else if ((board[j+1][i-1] == 0) && ((i-1) >= 0) && ((j+1) <= 7)) {
                        board[j][i] = 0;
                        board[j+1][i-1] = -2;
                        j = 0;
                        i = 0;
                    }
                    else if ((board[j-1][i+1] == 0) && ((i+1) <= 7) && ((j-1) >= 0)) {
                        board[j][i] = 0;
                        board[j-1][i+1] = -2;
                        j = 0;
                        i = 0;
                    }
                    else if ((board[j-1][i-1] == 0) && ((i-1) >= 0) && ((j-1) >= 0)) {
                        board[j][i] = 0;
                        board[j-1][i+1] = -2;
                        j = 0;
                        i = 0;
                    }
                }
            }
        }
    }
}

int checkBoard(int board[][SIZE]) {
    
    int countX, countO, i, j;
    
    countX = 0;
    countO = 0;
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if ((board[j][i] == 1) || (board[j][i] == -1)) {
                countX++;
            }
            else if ((board[j][i] == 2) || (board[j][i] == -2)) {
                countO++;
            }
        }
    }
    
    if (countX == 0) {
        return 1;
    }
    else if (countO == 0) {
        return 2;
    }
    else {
        return 0;
    }
}
