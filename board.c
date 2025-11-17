#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "colors.h"
#include "board.h"


void listBoards(){
    char pattern[] = "Boards\\*.txt";
    WIN32_FIND_DATA fd;
    HANDLE h = FindFirstFile(pattern, &fd);

        do {
        if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            char full[260];
            sprintf(full, "%s\\%s", "Boards", fd.cFileName);

            FILE* f = fopen(full, "r");

            char nameOfAlbum[260];
            strcpy(nameOfAlbum, fd.cFileName);
            nameOfAlbum[strlen(nameOfAlbum) - 4] = '\0';

            if (f) {
                printf("\n--- %s ---\n", nameOfAlbum);
                printf("Artist: ");
                int c;
                while ((c = fgetc(f)) != '\n')
                    putchar(c);
                fclose(f);
            }
        }
    } while (FindNextFile(h, &fd));

    FindClose(h);
    printf("\n\n");
}

void updateBoard(int board[24][24], int x, int y, int p){
    system("cls");
    
    printf("  ");
    if (p) board[y - 1][x - 1] = p;
    for (size_t i = 1; i <= 24; i++)
    {
        printf(BRIGHT_BLUE"%2d "RESET, i);
    }
    
    printf("\n");

    for (size_t i = 0; i < 24; i++)
    {
        printf(BRIGHT_RED"%2d "RESET, i+1);
        for (size_t j = 0; j < 24; j++)
        {
            if (j == 0)
            {
                if (i == 0)
                {
                    switch (board[i][j])
                    {
                        case 0:
                            printf(DIM UNDERLINE"○ "RESET, board[i][j]);
                            break;
                        
                        case 1:
                            printf(BOLD BRIGHT_BLUE UNDERLINE"○ "RESET, board[i][j]);
                            break;
            
                        case -1:
                            printf(BOLD BRIGHT_RED UNDERLINE"○ "RESET, board[i][j]);
                            break;
            
                        default:
                            break;
                    }
                }
                else if (i == 22)
                {
                    switch (board[i][j])
                    {
                        case 0:
                            printf(DIM UNDERLINE"○ "RESET, board[i][j]);
                            break;
                        
                        case 1:
                            printf(BOLD BRIGHT_BLUE UNDERLINE"○ "RESET, board[i][j]);
                            break;
            
                        case -1:
                            printf(BOLD BRIGHT_RED UNDERLINE"○ "RESET, board[i][j]);
                            break;
            
                        default:
                            break;
                    }
                }
                else
                {
                    switch (board[i][j])
                        {
                        case 0:
                            printf(DIM"○ "RESET, board[i][j]);
                            break;
                        
                        case 1:
                            printf(BOLD BRIGHT_BLUE"○ "RESET, board[i][j]);
                            break;
            
                        case -1:
                            printf(BOLD BRIGHT_RED"○ "RESET, board[i][j]);
                            break;
            
                        default:
                            break;
                        }
                } 
                printf(DIM BRIGHT_RED"|"RESET);
            }
            else if (j == 22)
            {
                if (i == 0)
                {
                    switch (board[i][j])
                    {
                        case 0:
                            printf(DIM UNDERLINE"○ "RESET, board[i][j]);
                            break;
                        
                        case 1:
                            printf(BOLD BRIGHT_BLUE UNDERLINE"○ "RESET, board[i][j]);
                            break;
            
                        case -1:
                            printf(BOLD BRIGHT_RED UNDERLINE"○ "RESET, board[i][j]);
                            break;
            
                        default:
                            break;
                    }
                }
                else if (i == 22)
                {
                    switch (board[i][j])
                    {
                        case 0:
                            printf(DIM UNDERLINE"○ "RESET, board[i][j]);
                            break;
                        
                        case 1:
                            printf(BOLD BRIGHT_BLUE UNDERLINE"○ "RESET, board[i][j]);
                            break;
            
                        case -1:
                            printf(BOLD BRIGHT_RED UNDERLINE"○ "RESET, board[i][j]);
                            break;
            
                        default:
                            break;
                    }
                }
                else
                {
                    switch (board[i][j])
                        {
                        case 0:
                            printf(DIM"○ "RESET, board[i][j]);
                            break;
                        
                        case 1:
                            printf(BOLD BRIGHT_BLUE"○ "RESET, board[i][j]);
                            break;
            
                        case -1:
                            printf(BOLD BRIGHT_RED"○ "RESET, board[i][j]);
                            break;
            
                        default:
                            break;
                        }
                } 
                printf(DIM BRIGHT_RED"|"RESET);
            }
            else
            {
                if (i == 0)
                {
                    switch (board[i][j])
                    {
                        case 0:
                            printf(DIM UNDERLINE"○  "RESET, board[i][j]);
                            break;
                        
                        case 1:
                            printf(BOLD BRIGHT_BLUE UNDERLINE"○  "RESET, board[i][j]);
                            break;
            
                        case -1:
                            printf(BOLD BRIGHT_RED UNDERLINE"○  "RESET, board[i][j]);
                            break;
            
                        default:
                            break;
                    }
                }
                else if (i == 22)
                {
                    switch (board[i][j])
                    {
                        case 0:
                            printf(DIM UNDERLINE"○  "RESET, board[i][j]);
                            break;
                        
                        case 1:
                            printf(BOLD BRIGHT_BLUE UNDERLINE"○  "RESET, board[i][j]);
                            break;
            
                        case -1:
                            printf(BOLD BRIGHT_RED UNDERLINE"○  "RESET, board[i][j]);
                            break;
            
                        default:
                            break;
                    }
                }
                else
                {
                        switch (board[i][j])
                        {
                        case 0:
                            printf(DIM"○  "RESET, board[i][j]);
                            break;
                        
                        case 1:
                            printf(BOLD BRIGHT_BLUE"○  "RESET, board[i][j]);
                            break;
            
                        case -1:
                            printf(BOLD BRIGHT_RED"○  "RESET, board[i][j]);
                            break;
            
                        default:
                            break;
                    }
                } 
            }
        }
        printf("\n");
    }
    printf("\n");
}