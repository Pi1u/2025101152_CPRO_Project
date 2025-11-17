#include <stdio.h>
#include <windows.h>
#include "colors.h"
#include "board.h"

void printMain(){
    //Header is a work in progress right now, coudn't decide on what should be the final one so this is just a placeholder right now
    printf("\x1b[38;5;199m"
"████████╗\x1b[38;5;201m██╗    ██╗\x1b[38;5;207m██╗\x1b[38;5;213m██╗  ██╗\x1b[38;5;219m████████╗\n"
"\x1b[38;5;199m╚══██╔══╝\x1b[38;5;201m██║    ██║\x1b[38;5;207m██║\x1b[38;5;213m██║ ██╔╝\x1b[38;5;219m╚══██╔══╝\n"
"\x1b[38;5;199m   ██║   \x1b[38;5;201m██║ █╗ ██║\x1b[38;5;207m██║\x1b[38;5;213m█████╔╝ \x1b[38;5;219m   ██║   \n"
"\x1b[38;5;199m   ██║   \x1b[38;5;201m██║███╗██║\x1b[38;5;207m██║\x1b[38;5;213m██╔═██╗ \x1b[38;5;219m   ██║   \n"
"\x1b[38;5;199m   ██║   \x1b[38;5;201m╚███╔███╔╝\x1b[38;5;207m██║\x1b[38;5;213m██║  ██╗\x1b[38;5;219m   ██║   \n"
"\x1b[38;5;199m   ╚═╝    \x1b[38;5;201m╚══╝╚══╝ \x1b[38;5;207m╚═╝\x1b[38;5;213m╚═╝  ╚═╝\x1b[38;5;219m   ╚═╝   \n"
"\x1b[0m");

printf("\x1b[38;5;46m"
"██████████╗\x1b[38;5;48m██╗    ██╗\x1b[38;5;49m██╗\x1b[38;5;50m██╗\x1b[38;5;51m██╗\x1b[38;5;50m████████╗\n"
"\x1b[38;5;46m╚══██╔════╝\x1b[38;5;48m██║    ██║\x1b[38;5;49m██║\x1b[38;5;50m██║\x1b[38;5;51m██║\x1b[38;5;50m╚══██╔══╝\n"
"\x1b[38;5;46m   ██║     \x1b[38;5;48m██║ █╗ ██║\x1b[38;5;49m██║\x1b[38;5;50m██║\x1b[38;5;51m██║   ██║   \n"
"\x1b[38;5;46m   ██║     \x1b[38;5;48m██║███╗██║\x1b[38;5;49m██║\x1b[38;5;50m██║\x1b[38;5;51m██║   ██║   \n"
"\x1b[38;5;46m   ██║     \x1b[38;5;48m╚███╔███╔╝\x1b[38;5;49m██║\x1b[38;5;50m██║\x1b[38;5;51m██║   ██║   \n"
"\x1b[38;5;46m   ╚═╝      \x1b[38;5;48m╚══╝╚══╝ \x1b[38;5;49m╚═╝\x1b[38;5;50m╚═╝\x1b[38;5;51m╚═╝   ╚═╝   \n"
"\x1b[0m");

    printf(BRIGHT_WHITE"["BRIGHT_RED"1"BRIGHT_WHITE"]New Game\n"RESET);
    printf(BRIGHT_WHITE"["BRIGHT_RED"2"BRIGHT_WHITE"]Load Game\n"RESET);
    printf(BRIGHT_WHITE"["BRIGHT_RED"3"BRIGHT_WHITE"]Quit\n\n"RESET);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int board[24][24] = {0};

    printMain();
    
    while (1)
    {
        printf(BLINK BRIGHT_BLACK"->"RESET);
        int n;
        int k = 1;
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                updateBoard(board, 1, 1, 0);
                while (1)
                {
                    int x, y;
                    (k == 1) ? (printf("Player 1 turn: ")) : (printf("Player 2 turn: "));
                    scanf("%d %d", &x, &y);
                    if (x == 0 && y == 0) 
                    {
                        system("cls");
                        printMain();
                        break;
                    }
                    
                    if (x <= 0 || y <= 0 || x >= 25 || y >= 25) {
                        updateBoard(board, 1, 1, 0);
                        printf(BRIGHT_RED BLINK"INVALID INPUT\nPLEASE GO AGAIN\n"RESET);
                        continue;
                    }
                    
                    if (board[y - 1][x - 1])
                    {
                        updateBoard(board, 1, 1, 0);
                        printf(BRIGHT_RED BLINK"ALREADY PEGGED\n"RESET);
                        continue;
                    }
                    
                    if ((x == 1 & y == 1) || (x == 1 & y == 24) || (x == 24 & y == 1) || (x == 24 & y == 24))
                    {
                        updateBoard(board, 1, 1, 0);
                        printf(BRIGHT_RED BLINK"CAN'T PLACE THERE\nPLEASE GO AGIAN\n"RESET);
                        continue;
                    }
                    if (k == 1) {
                        if (x == 1 || x == 24)
                        {
                            updateBoard(board, 1, 1, 0);
                            printf(BRIGHT_RED BLINK"CAN'T PLACE THERE\nPLEASE GO AGIAN\n"RESET);
                            continue;
                        }
                        updateBoard(board, x, y, k);
                        k = -1;
                    } 
                    else {
                        if (y == 1 || y == 24)
                        {
                            updateBoard(board, 1, 1, 0);
                            printf(BRIGHT_RED BLINK"CAN'T PLACE THERE\nPLEASE GO AGIAN\n"RESET);
                            continue;
                        }
                        updateBoard(board, x, y, k);
                        k = 1;
                    }
                }
                break;
        
        case 2:
            break;

        case 3:
            return 0;

        default:
            break;
        }
    }
    return 0;
}