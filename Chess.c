#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>


int collumPos = 0;
int rollPos = 0;
char storedChar = '2';
bool validMove = false;
char matrix[9][17];
char collum;
int roll;
int convertedCollum;
int convertedRoll;
int lastCollumPos = 0;
int lastRollPos = 0;

void ConvertCoord(char collum, int roll)
{
    
    switch (collum)
    {
    case 'a':
        convertedCollum = 2;
        break;
    case 'b':
        convertedCollum = 4;
        break;
    case 'c':
        convertedCollum = 6;
        break;
    case 'd':
        convertedCollum = 8;
        break;
    case 'e':
        convertedCollum = 10;
        break;
    case 'f':
        convertedCollum = 12;
        break;
    case 'g':
        convertedCollum = 14;
        break;
    case 'h':
        convertedCollum = 16;
        break;
    default:
        break;
    }
    switch (roll)
    {
    case 1:
        convertedRoll = 1;
        break;
    case 2:
        convertedRoll = 2;
        break;
    case 3:
        convertedRoll = 3;
        break;
    case 4:
        convertedRoll = 4;
        break;
    case 5:
        convertedRoll = 5;
        break;
    case 6:
        convertedRoll = 6;
        break;
    case 7:
        convertedRoll = 7;
        break;
    case 8:
        convertedRoll = 8;
        break;
    default:
        break;
    }
    
}
bool MovCheck(bool positiveX, bool positiveY)
{
    
    if(positiveX && positiveY)
    {
        int i=lastRollPos, j =lastCollumPos;
        printf("%d %d", lastRollPos, lastCollumPos);
        while(i < rollPos-1)
        {
            
            i++;
            if (matrix[i][j] != '0' && matrix[i][j] != ' ')
            {
                printf("%d %d", i, j);
                printf("peca no caminho1!\n");
                return false;
            }
        }
        while (j < collumPos -2)
        {
            j+=2;
            if (matrix[i][j] != '0' && matrix[i][j] != ' ')
            {
                printf("%c", matrix[i][j]);
                printf("peca no caminho2!\n");
                return false;
            }
        }
    }
    if(!positiveX && !positiveY)
    {
        int i = lastRollPos, j = lastCollumPos;
        printf("%d %d", lastRollPos, lastCollumPos);
        while (i > rollPos +1)
        {
            i--;
            if (matrix[i][j] != '0' && matrix[i][j] != ' ')
            {
                
                printf("peca no caminho1!\n");
                return false;
            }
        }
        while (j > collumPos +2)
        {
            j -= 2;
            if (matrix[i][j] != '0' && matrix[i][j] != ' ')
            {
                
                printf("peca no caminho2!\n");
                return false;
            }
        }
    }
    if(!positiveX && positiveY)
    {
        for (int i = lastRollPos; i < rollPos; i++)
        {
            for (int j = lastCollumPos; j > collumPos; j -= 2)
            {
                if (matrix[i][j] != '0' && matrix[i][j] != ' ')
                {
                    printf("peca no caminho!");
                    return false;
                }
            }
        }
    }
    if(positiveX && !positiveY)
    {
        for (int i = lastRollPos; i > rollPos; i--)
        {
            for (int j = lastCollumPos; j < collumPos; j += 2)
            {
                if (matrix[i][j] != '0' && matrix[i][j] != ' ')
                {
                    printf("peca no caminho!");
                    return false;
                }
            }
        }
    }
    return true;
}
void Pawl(bool upper)
{
    
    

    
    ConvertCoord(collum, roll);
    collumPos = convertedCollum;
    rollPos = convertedRoll;

    
    
    if (upper)
    {


        if (rollPos - 1 == lastRollPos && collumPos == lastCollumPos)
        {

            matrix[rollPos][collumPos] = 'P';
            
            validMove = true;
        }
        else
        {
            printf("coordenadas invalidas!\n");

        }
    }
    else
    {
        if (rollPos + 1 == lastRollPos && collumPos == lastCollumPos)
        {

            matrix[rollPos][collumPos] = 'p';
            
            validMove = true;
        }
        else
        {
            printf("coordenadas invalidas!\n");

        }
    }

    
    
}
void Rook(bool upper)

{
    ConvertCoord(collum, roll);
    collumPos = convertedCollum;
    rollPos = convertedRoll;


    
    if (upper)
    {
        if (rollPos == lastRollPos || collumPos == lastCollumPos)
        {

            if ((rollPos > lastRollPos || collumPos > lastCollumPos) && MovCheck(true, true))
            {
                if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && isupper(matrix[rollPos][collumPos]))
                {
                    printf("peca aliada seleciionada!");
                }
                else
                {
                    matrix[rollPos][collumPos] = 'T';
                    validMove = true;
                }
            }
            else if ((rollPos < lastRollPos || collumPos < lastCollumPos) && MovCheck(false, false))
            {
                if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && isupper(matrix[rollPos][collumPos]))
                {
                    printf("peca aliada selecionada!");
                }
                else
                {
                    matrix[rollPos][collumPos] = 'T';
                    validMove = true;
                }
            }

        }
        else
        {
            printf("coordenadas invalidas!\n");
        }
    }
    else
    {
        if (rollPos == lastRollPos || collumPos == lastCollumPos)
        {

            if ((rollPos > lastRollPos || collumPos > lastCollumPos) && MovCheck(true, true))
            {
                if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && islower(matrix[rollPos][collumPos]))
                {
                    printf("peca aliada seleciionada!");
                }
                else
                {
                    matrix[rollPos][collumPos] = 't';
                    validMove = true;
                }
            }
            else if ((rollPos < lastRollPos || collumPos < lastCollumPos) && MovCheck(false, false))
            {
                if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && islower(matrix[rollPos][collumPos]))
                {
                    printf("peca aliada selecionada!");
                }
                else
                {
                    matrix[rollPos][collumPos] = 't';
                    validMove = true;
                }
            }
            
        }
        else
        {
            printf("coordenadas invalidas!\n");
        }
    }
    
}

int main()
{
    
    char start[9][17] = 
    {
        {"  a b c d e f g h"},
        {"1 T 0   0   0   T"},
        {"2 P P P P P P P P"},
        {"3   0   0   0   0"},
        {"4 0   0   0   0  "},
        {"5   0   0   0   0"},
        {"6 0   0   0   0  "},
        {"7 p p p p p p p p"},
        {"8 t   0   0   0 t"},
    };
    
    memcpy(matrix, start,sizeof(start));

    
    
    int round = 1;
    bool quit = false;
    while (quit == false)
    {
        
        
        char slctdCollum;
        int slctdRoll;
        
        
        int i;
        int j;
        for (i = 0; i < 9; i++)
        {
            printf("\n");
            for (j = 0; j < 17; j++)
            {
                if (matrix[i][j] == '0')
                    printf("%c", 254);
                else
                printf("%c", matrix[i][j]);
            }

        }
        printf("\n\n");
        printf("Rodada:%d\n", round);
        if (round % 2 == 0)
            printf("As Maiusculas jogam!\n\n");
        else
            printf("As Minusculas jogam!\n\n");
        
        do
        {
            validMove = false;
            printf("informe a coordenada da peca: ");
            scanf(" %c %d", &slctdCollum, &slctdRoll);
            ConvertCoord(slctdCollum, slctdRoll);
            lastCollumPos = convertedCollum;
            lastRollPos = convertedRoll;
            if ((isupper(matrix[lastRollPos][lastCollumPos]) && round %2 == 0) || (islower(matrix[lastRollPos][lastCollumPos]) && round % 2 != 0))
            {
                printf("de as coordenadas da jogada: ");
                if (scanf(" %c %d", &collum, &roll) !=2)
                {
                    printf("coordenada invalida!");
                    free(collum, roll);
                    continue;
                }
                //char rusultString[3];
                //strcat 
                //if (strlen(2,))
                
            }
            else if (matrix[lastRollPos][lastCollumPos] == '0' || matrix[lastRollPos][lastCollumPos] == ' ')
            {
                printf("posicao selecionada vazia!\n");
                continue;
            }
            else
            {
                printf("coordenada invalida!\n");
                printf("%d", round);
                continue;
            }

            
            
            

            if (matrix[lastRollPos][lastCollumPos] == 'P' || matrix[lastRollPos][lastCollumPos] == 'p')
                Pawl(matrix[lastRollPos][lastCollumPos] == 'P' && round % 2 == 0);
            if (matrix[lastRollPos][lastCollumPos] == 'T' || matrix[lastRollPos][lastCollumPos] == 't')
                Rook(matrix[lastRollPos][lastCollumPos] == 'T' && round % 2 == 0);


        } while (validMove == false);
        if (lastRollPos % 2 != 0 && (lastCollumPos == 4 || lastCollumPos == 8 || lastCollumPos == 12 || lastCollumPos == 16))
            matrix[lastRollPos][lastCollumPos] = '0';
        else if (lastRollPos %2 == 0 && (lastCollumPos == 2 || lastCollumPos == 6 || lastCollumPos == 10 || lastCollumPos == 14))
        {
            matrix[lastRollPos][lastCollumPos] = '0';

        }
        else
            matrix[lastRollPos][lastCollumPos] = ' ';
        round++;
    }

    
}



