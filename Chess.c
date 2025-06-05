#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{

    char matrix[9][17] = { {"  a b c d e f g h"}, {"1 M O M O M O M O"}, {"2 O M O M O M O M"}, {"3 M O M O M O M O"}, {"4 O M O M O M O M"}, {"5 M O M O M O M O"}, {"6 O M O M O M O M"}, {"7 M O M O M O M O"}, {"8 O M O M O M O M"} };
    int pawl();
    {
        
    }
    bool quit = false;
    while (quit == false)
    {
        
        char collum;
        int roll;
        
        int slctdPiece = 0;
        int i;
        int j;
        for (i = 0; i < 9; i++)
        {
            printf("\n");
            for (j = 0; j < 17; j++)
            {
                printf("%c", matrix[i][j]);
            }

        }
        printf("\n\n");
        printf("1 - peao\n");
        printf("2 - bispo\n");
        printf("3 - cavalo\n");
        printf("4 - torre\n");
        printf("5 - rainha\n");
        printf("6 - rei\n");
        printf("escolha a peca:");
        scanf(" %d", &slctdPiece);
        printf("de as coordenadas da jogada:");
        scanf(" %c %d", &collum, &roll);
        
        if (slctdPiece == 1)
        {
            int collumPos;
            int rollPos;
            switch (collum)
            {
            case 'a':
                collumPos = 3;
                printf("asfasf");
                break;
            case 'b':
                collumPos = 5;
                break;
            case 'c':
                collumPos = 7;
                break;
            case 'd':
                collumPos = 9;
                break;
            case 'e':
                collumPos = 11;
                break;
            case 'f':
                collumPos = 13;
                break;
            case 'g':
                collumPos = 15;
                break;
            case 'h':
                collumPos = 17;
                break;
            default:
                break;
            }
            switch (roll)
            {
            case 1:
                rollPos = 2;
                printf("asfasf");
                break;
            case 2:
                rollPos = 3;
                break;
            case 3:
                rollPos = 4;
                break;
            case 4:
                rollPos = 5;
                break;
            case 5:
                rollPos = 6;
                break;
            case 6:
                rollPos = 7;
                break;
            case 7:
                rollPos = 8;
                break;
            case 8:
                rollPos = 9;
                break;
            default:
                break;
            }
            printf("%d %d", rollPos, collumPos);
            matrix[rollPos-1][collumPos-1] = 80;
        }
           
    }

    
}


