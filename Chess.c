#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>
int collumPos = 0;
int rollPos = 0;
bool validMove = false;
char matrix[9][17];
char collum;
int convertedCollum;
int lastCollumPos = 0;
int lastRollPos = 0;
//converte a coordenada da coluna de char para int.
void ConvertCoord(char collum)
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
}
//checa na horizontal e vertical se a pecas no caminho. 
bool MovCheck(bool positive)
{
    if(positive)
    {
        int i=lastRollPos, j =lastCollumPos;
        while(i < rollPos-1)
        {
            i++;
            if (matrix[i][j] != '0' && matrix[i][j] != ' ')
            {
                if (rollPos != lastRollPos && collumPos != lastCollumPos)
                {
                    printf("movimento invalido!");
                    return false;
                }
                printf("peca no caminho!\n");
                return false;
            }
        }
        while (j < collumPos -2)
        {
            j+=2;
            if (matrix[i][j] != '0' && matrix[i][j] != ' ')
            {
                if (rollPos != lastRollPos && collumPos != lastCollumPos)
                {
                    printf("movimento invalido!");
                    return false;
                }
                printf("peca no caminho!\n");
                return false;
            }
        }
    }
    if(!positive)
    {
        int i = lastRollPos, j = lastCollumPos;
        while (i > rollPos +1)
        {
            i--;
            if (matrix[i][j] != '0' && matrix[i][j] != ' ')
            {
                if (rollPos != lastRollPos && collumPos != lastCollumPos)
                {
                    printf("movimento invalido!");
                    return false;
                }
                printf("peca no caminho!\n");
                return false;
            }
        }
        while (j > collumPos +2)
        {
            j -= 2;
            if (matrix[i][j] != '0' && matrix[i][j] != ' ')
            {
                if (rollPos != lastRollPos && collumPos != lastCollumPos)
                {
                    printf("movimento invalido!");
                    return false;
                }
                printf("peca no caminho!\n");
                return false;
            }
        }
    }
    return true;
}
//checa nas diagonais se a pecas no caminho.
bool MovCheckDiagonal(bool positiveX,bool positiveY)
{
    int i = lastRollPos, j = lastCollumPos;
    int distI=0;
    int distJ=0;
    if (!positiveX && positiveY)
    while (i > rollPos + 1 || j < collumPos - 2)
    {
        if(i> rollPos + 1)
        {
            i--;
            distI--;
        }
        if (j < collumPos - 2)
        {
            j+=2;
            distJ++;
        }
        if (matrix[i][j] != '0' && matrix[i][j] != ' ')
        {
            if (abs(distI) != abs(distJ))
            {
                printf("movimento invalido!");
                return false;
            }
            printf("peca no caminho!");
            return false;
        }   
    }
    if (positiveX && !positiveY)
    while (i < rollPos - 1 || j > collumPos + 2)
    {
        if (i < rollPos - 1)
        {
            i++;
            distI++;
        }
        if (j > collumPos + 2)
        {
            j -= 2;
            distJ--;
        }
        if (matrix[i][j] != '0' && matrix[i][j] != ' ')
        {
            if (abs(distI) != abs(distJ))
            {
                printf("movimento invalido!");
                return false;
            }
            printf("peca no caminho!");
            return false;
        }
    }
    if (!positiveX && !positiveY)
    while (i > rollPos + 1 || j > collumPos + 2)
    {
        if (i > rollPos + 1)
        {
            i--;
            distI--;
        }
        if (j > collumPos + 2)
        {
            j -= 2;
            distJ--;
        }
        if (matrix[i][j] != '0' && matrix[i][j] != ' ')
        {
            if (abs(distI) != abs(distJ))
            {
                printf("movimento invalido!");
                return false;
            }
            printf("peca no caminho!");
            return false;
        }
    }
    if (positiveX && positiveY)
    while (i < rollPos - 1 || j < collumPos - 2)
    {
        if (i < rollPos - 1)
        {
            i++;
            distI++;
        }
        if (j < collumPos - 2)
        {
            j += 2;
            distJ++;
        }
        if (matrix[i][j] != '0' && matrix[i][j] != ' ')
        {
            if (abs(distI) != abs(distJ))
            {
                printf("movimento invalido!");
                return false;
            }
            printf("peca no caminho!");
            return false;
        }
    }
    if (abs(distI) == abs(distJ))
    {
        return true;
    }
    return false;
}
//controla a logica do piao.
void Pawl(bool upper)
{
    ConvertCoord(collum);
    collumPos = convertedCollum;
    if (upper)
    {
        if ((rollPos == lastRollPos + 1 && collumPos == lastCollumPos && (matrix[rollPos][collumPos] == '0' || matrix[rollPos][collumPos] == ' ')) || (rollPos == lastRollPos + 1 && (collumPos == lastCollumPos - 2 || collumPos == lastCollumPos + 2) &&
            (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ')) || (lastRollPos == 2 && (rollPos == lastRollPos + 2 && collumPos == lastCollumPos) && (matrix[rollPos][collumPos] == '0' || matrix[rollPos][collumPos] == ' ')))
        {
            if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && isupper(matrix[rollPos][collumPos]))
            {
                printf("peca aliada selecionada!\n");
            }
            else
            {
                matrix[rollPos][collumPos] = 'P';
                validMove = true;
            }
        }
        else
        {
            printf("coordenadas invalidas!\n");
        }
    }
    else
    {
        if ((rollPos == lastRollPos - 1 && collumPos == lastCollumPos && (matrix[rollPos][collumPos] == '0' || matrix[rollPos][collumPos] == ' ')) || (rollPos == lastRollPos - 1 && (collumPos == lastCollumPos - 2 || collumPos == lastCollumPos + 2) &&
            (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ')) || (lastRollPos == 7 && (rollPos == lastRollPos - 2 && collumPos == lastCollumPos) && (matrix[rollPos][collumPos] == '0' || matrix[rollPos][collumPos] == ' ')))
        {
            if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && islower(matrix[rollPos][collumPos]))
            {
                printf("peca aliada selecionada!\n");
            }
            else
            {
                matrix[rollPos][collumPos] = 'p';
                validMove = true;
            }
        }
        else
        {
            printf("coordenadas invalidas!\n");
        }
    }
}
//controla a logica da torre.
void Rook(bool upper)
{
    ConvertCoord(collum);
    collumPos = convertedCollum;
    if (upper)
    {
        if (rollPos == lastRollPos || collumPos == lastCollumPos)
        {
            if ((rollPos > lastRollPos || collumPos > lastCollumPos) && MovCheck(true))
            {
                if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && isupper(matrix[rollPos][collumPos]))
                {
                    printf("peca aliada selecionada!\n");
                }
                else
                {
                    matrix[rollPos][collumPos] = 'T';
                    validMove = true;
                }
            }
            else if ((rollPos < lastRollPos || collumPos < lastCollumPos) && MovCheck(false))
            {
                if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && isupper(matrix[rollPos][collumPos]))
                {
                    printf("peca aliada selecionada!\n");
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
            if ((rollPos > lastRollPos || collumPos > lastCollumPos) && MovCheck(true))
            {
                if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && islower(matrix[rollPos][collumPos]))
                {
                    printf("peca aliada seleciionada!\n");
                }
                else
                {
                    matrix[rollPos][collumPos] = 't';
                    validMove = true;
                }
            }
            else if ((rollPos < lastRollPos || collumPos < lastCollumPos) && MovCheck(false))
            {
                if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && islower(matrix[rollPos][collumPos]))
                {
                    printf("peca aliada selecionada!\n");
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
//conntrola a logica do bispo.
void Bishop(bool upper)
{
    ConvertCoord(collum);
    collumPos = convertedCollum;
    if (upper)
    {
        if ((rollPos > lastRollPos && collumPos > lastCollumPos) && MovCheckDiagonal(true,true))
        {
            if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && isupper(matrix[rollPos][collumPos]))
            {
                printf("peca aliada selecionada!\n");
            }
            else
            {
                matrix[rollPos][collumPos] = 'B';
                validMove = true;
            }
        }
        else if ((rollPos < lastRollPos && collumPos < lastCollumPos) && MovCheckDiagonal(false, false))
        {
            if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && isupper(matrix[rollPos][collumPos]))
            {
                printf("peca aliada selecionada!\n");
            }
            else
            {
                matrix[rollPos][collumPos] = 'B';
                validMove = true;
            }
        }
        else if ((rollPos < lastRollPos && collumPos > lastCollumPos) && MovCheckDiagonal(false, true))
        {
            if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && isupper(matrix[rollPos][collumPos]))
            {
                printf("peca aliada selecionada!\n");
            }
            else
            {
                matrix[rollPos][collumPos] = 'B';
                validMove = true;
            }
        }
        else if ((rollPos > lastRollPos && collumPos < lastCollumPos) && MovCheckDiagonal(true, false))
        {
            if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && isupper(matrix[rollPos][collumPos]))
            {
                printf("peca aliada selecionada!\n");
            }
            else
            {
                matrix[rollPos][collumPos] = 'B';
                validMove = true;
            }
        }
        else
        {
            printf("coordenadas invalidas!\n");
        }
    }
    else
    {
        if ((rollPos > lastRollPos && collumPos > lastCollumPos) && MovCheckDiagonal(true, true))
        {
            if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && islower(matrix[rollPos][collumPos]))
            {
                printf("peca aliada seleciionada!");
            }
            else
            {
                matrix[rollPos][collumPos] = 'b';
                validMove = true;
            }
        }
        else if ((rollPos < lastRollPos && collumPos < lastCollumPos) && MovCheckDiagonal(false, false))
        {
            if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && islower(matrix[rollPos][collumPos]))
            {
                printf("peca aliada seleciionada!");
            }
            else
            {
                matrix[rollPos][collumPos] = 'b';
                validMove = true;
            }
        }
        else if ((rollPos < lastRollPos && collumPos > lastCollumPos) && MovCheckDiagonal(false, true))
        {
            if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && islower(matrix[rollPos][collumPos]))
            {
                printf("peca aliada seleciionada!");
            }
            else
            {
                matrix[rollPos][collumPos] = 'b';
                validMove = true;
            }
        }
        else if ((rollPos > lastRollPos && collumPos < lastCollumPos) && MovCheckDiagonal(true, false))
        {
            if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && islower(matrix[rollPos][collumPos]))
            {
                printf("peca aliada seleciionada!");
            }
            else
            {
                matrix[rollPos][collumPos] = 'b';
                validMove = true;
            }
        }
        else
        {
            printf("coordenadas invalidas!\n");
        }
    }
}
//controla a logica do cavalo.
void Knight(bool upper)
{
    ConvertCoord(collum);
    collumPos = convertedCollum;
    if(upper)
    {
        if(
            (rollPos == lastRollPos + 2 && (collumPos == lastCollumPos +2 || collumPos == lastCollumPos - 2)) ||
            (rollPos == lastRollPos - 2 && (collumPos == lastCollumPos + 2 || collumPos == lastCollumPos - 2)) ||
            (collumPos == lastCollumPos + 2 && (rollPos == lastRollPos + 2 || rollPos == lastRollPos - 2)) ||
            (collumPos == lastCollumPos - 2 && (rollPos == lastRollPos + 2 || rollPos == lastRollPos - 2))
        )
        {
            matrix[rollPos][collumPos] = 'C';
            validMove = true;
        }
        else 
        {
            printf("coordenadas invalidas!\n");
        }
    }
    else
    {
        if ((rollPos == lastRollPos + 2 && (collumPos == lastCollumPos + 2 || collumPos == lastCollumPos - 2)) ||
            (rollPos == lastRollPos - 2 && (collumPos == lastCollumPos + 2 || collumPos == lastCollumPos - 2)) ||
            (collumPos == lastCollumPos + 2 && (rollPos == lastRollPos + 2 || rollPos == lastRollPos - 2)) ||
            (collumPos == lastCollumPos - 2 && (rollPos == lastRollPos + 2 || rollPos == lastRollPos - 2)))
        {
            matrix[rollPos][collumPos] = 'c';
            validMove = true;
        }
        else
        {
            printf("coordenadas invalidas!\n");
        }
    }
}
//controla a logica do rei.
void King(bool upper)
{
    ConvertCoord(collum);
    collumPos = convertedCollum;
    if (upper)
    {
        if(matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && isupper(matrix[rollPos][collumPos]))
        {
            printf("peca aliada selecionada!\n");
        }
        else if((rollPos == lastRollPos + 1) ||
                (rollPos == lastRollPos - 1) ||
                (rollPos == lastRollPos + 1 && collumPos == lastCollumPos + 1) ||
                (rollPos == lastRollPos - 1 && collumPos == lastCollumPos - 1) ||
                (rollPos == lastRollPos + 1 && collumPos == lastCollumPos - 1) ||
                (rollPos == lastRollPos - 1 && collumPos == lastCollumPos + 1) ||
                (collumPos == lastCollumPos + 1) ||
                (collumPos == lastCollumPos - 1))
        {
            matrix[rollPos][collumPos] = 'K';
            validMove = true;
        }
        else { printf("coordenadas invalidas!\n"); }
    }
    else
    {
        if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && islower(matrix[rollPos][collumPos]))
        {
            printf("peca aliada selecionada!\n");
        }
        else if((rollPos == lastRollPos + 1) ||
                (rollPos == lastRollPos - 1) ||
                (rollPos == lastRollPos + 1 && collumPos == lastCollumPos + 2) ||
                (rollPos == lastRollPos - 1 && collumPos == lastCollumPos - 2) ||
                (rollPos == lastRollPos + 1 && collumPos == lastCollumPos - 2) ||
                (rollPos == lastRollPos - 1 && collumPos == lastCollumPos + 2) ||
                (collumPos == lastCollumPos + 2) ||
                (collumPos == lastCollumPos - 2))
        {
            matrix[rollPos][collumPos] = 'k';
            validMove = true;
        }
        else { printf("coordenadas invalidas!\n"); }
    }
}
//controla a logica da rainha.
void Queen(bool upper)
{
    ConvertCoord(collum);
    collumPos = convertedCollum;
    if (upper)
    {
        if (((rollPos > lastRollPos && collumPos > lastCollumPos) && MovCheckDiagonal(true, true))||
            ((rollPos < lastRollPos && collumPos < lastCollumPos) && MovCheckDiagonal(false, false))||
            ((rollPos < lastRollPos && collumPos > lastCollumPos) && MovCheckDiagonal(false, true))||
            ((rollPos > lastRollPos && collumPos < lastCollumPos) && MovCheckDiagonal(true, false))||
            ((rollPos == lastRollPos || collumPos == lastCollumPos && (rollPos > lastRollPos || collumPos > lastCollumPos)) && MovCheck(true))||
            ((rollPos == lastRollPos || collumPos == lastCollumPos && (rollPos < lastRollPos || collumPos < lastCollumPos)) && MovCheck(false)))
        {
            if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && isupper(matrix[rollPos][collumPos]))
            {
                printf("peca aliada selecionada!\n");
            }
            else
            {
                matrix[rollPos][collumPos] = 'Q';
                validMove = true;
            }
        }
        else
        {
            printf("coordenadas invalidas!\n");
        }
    }
    else
    {
        if (((rollPos > lastRollPos && collumPos > lastCollumPos) && MovCheckDiagonal(true, true)) ||
            ((rollPos < lastRollPos && collumPos < lastCollumPos) && MovCheckDiagonal(false, false)) ||
            ((rollPos < lastRollPos && collumPos > lastCollumPos) && MovCheckDiagonal(false, true)) ||
            ((rollPos > lastRollPos && collumPos < lastCollumPos) && MovCheckDiagonal(true, false))||
            ((rollPos == lastRollPos || collumPos == lastCollumPos && (rollPos > lastRollPos || collumPos > lastCollumPos)) && MovCheck(true)) ||
            ((rollPos == lastRollPos || collumPos == lastCollumPos && (rollPos < lastRollPos || collumPos < lastCollumPos)) && MovCheck(false)))
        {
            if (matrix[rollPos][collumPos] != '0' && matrix[rollPos][collumPos] != ' ' && islower(matrix[rollPos][collumPos]))
            {
                printf("peca aliada selecionada!\n");
            }
            else
            {
                matrix[rollPos][collumPos] = 'q';
                validMove = true;
            }
        }
        else
        {
            printf("coordenadas invalidas!\n");
        }
    }
}
//main.
int main()
{
    bool quit = false;
    while (quit == false)
    {
        printf("        ,----,                                                                                                                                    ,--,\n"
            " ♞     ,/   .`|                                                       ____                                   ,--.                               ,---.'|\n"
            "    ,`   .'  :            ,---,.        ,-.----.                   ,'  , `.           ,---,               ,--.'|           ,---,               |   | :\n"
            "  ;    ;     /          ,'  .' |        \\    /  \\               ,-+-,.' _ |        ,`--.' |           ,--,:  : |          '  .' \\              :   : |\n"
            ".'___,/    ,'         ,---.'   |        ;   :    \\           ,-+-. ;   , ||        |   :  :        ,`--.'`|  ' :         /  ;    '.            |   ' :\n"
            "|    :     |          |   |   .'        |   | .\\ :          ,--.'|'   |  ;|        :   |  '        |   :  :  | |        :  :       \\           ;   ; '\n"
            ";    |.';  ;          :   :  |-,        .   : |: |         |   |  ,', |  ':        |   :  |        :   |   \\ | :        :  |   /\\   \\          '   | |__\n"
            "`----'  |  |          :   |  ;/|        |   |  \\ :         |   | /  | |  ||        '   '  ;        |   : '  '; |        |  :  ' ;.   :         |   | :.'| \n"
            "    '   :  ;          |   :   .'        |   : .  /         '   | :  | :  |,        |   |  |        '   ' ;.    ;        |  |  ;/  \\   \\        '   :    ; \n"
            "    |   |  '          |   |  |-,        ;   | |  \\         ;   . |  ; |--'         '   :  ;        |   | | \\   |        '  :  | \\  \\ ,'        |   |  ./\n"
            "    '   :  |          '   :  ;/|        |   | ;\\  \\        |   : |  | ,            |   |  '        '   : |  ; .'        |  |  '  '--'          ;   : ;\n"
            "    ;   |.'           |   |    \\        :   ' | \\.'        |   : '  |/             '   :  |        |   | '`--'          |  :  :                |   ,/\n"
            "    '---'             |   :   .'        :   : :-'          ;   | |`-'              ;   |.'         '   : |              |  | ,'                '---'\n"
            "                      |   | ,'     ,--, |   |.'            |   ;/                  '---'           ;   |.'              `--''\n"
            "          ,----..     `----'     ,--.'| `---'      ,---,.  '---'   .--.--.             .--.--.     '---'\n"
            "         /   /   \\            ,--,  | :          ,'  .' |         /  /    '.          /  /    '.\n"
            "        |   :     :        ,---.'|  : '        ,---.'   |        |  :  /`. /         |  :  /`. /\n"
            "        .   |  ;. /        |   | : _' |        |   |   .'        ;  |  |--`          ;  |  |--`\n"
            "        .   ; /--`         :   : |.'  |        :   :  |-,        |  :  ;_            |  :  ;_\n"
            "        ;   | ;            |   ' '  ; :        :   |  ;/|         \\  \\    `.          \\  \\    `.\n"
            "        |   : |            '   |  .'. |        |   :   .'          `----.   \\          `----.   \\\n"
            "        .   | '___         |   | :  | '        |   |  |-,          __ \\  \\  |          __ \\  \\  |\n"
            "        '   ; : .'|        '   : |  : ;        '   :  ;/|         /  /`--'  /         /  /`--'  /\n"
            "        '   | '/  :        |   | '  ,/         |   |    \\        '--'.     /         '--'.     /\n"
            "        |   :    /         ;   : ;--'          |   :   .'          `--'---'            `--'---'\n"
            "         \\   \\ .'          |   ,/              |   | ,'\n"
            "          `---`            '---'               `----'\n");
        printf("Aperte qualquer tecla para jogar ou digite 0 para sair\n");
        char startGame;
        scanf("%c", &startGame);
        if(startGame == '0')
        {
            quit = true;
            continue;
        }
        //cria o estado inicial do tabuleiro.
        char start[9][17] =
        {
            {"  a b c d e f g h"},
            {"1 T C B K Q B C T"},
            {"2 P P P P P P P P"},
            {"3   0   0   0   0"},
            {"4 0   0   0   0  "},
            {"5   0   0   0   0"},
            {"6 0   0   0   0  "},
            {"7 p p p p p p p p"},
            {"8 t c b k q b c t"},
        };
        //copia da variavel start para a matrix.
        memcpy(matrix, start, sizeof(start));
        int round = 1;
        bool matchOn = true;
        while (matchOn == true)
        {
            char slctdCollum;
            int i;
            int j;
            //gera o tabuleiro levando em consideracao as jogadas ja feitas.
            for (i = 0; i < 9; i++)
            {
                printf("\n");
                for (j = 0; j < 17; j++)
                {
                    //converte todo 0 para ■.
                    if (matrix[i][j] == '0')
                        printf("%c", 254);
                    else
                        printf("%c", matrix[i][j]);
                }
            }
            printf("\n\n");
            //indica qual lado joga.
            printf("Rodada:%d\n", round);
            if (round % 2 == 0)
                printf("As Maiusculas jogam!\n\n");
            else
                printf("As Minusculas jogam!\n\n");
            //gera um loop ate que uma jogada valida seja feita.
            do
            {
                validMove = false;
                printf("informe a coordenada da peca: ");
                scanf(" %c%d", &slctdCollum, &lastRollPos);
                int c;
                //limpa caracteres em excesso.
                while ((c = getchar()) != '\n' && c != EOF);
                ConvertCoord(slctdCollum);
                lastCollumPos = convertedCollum;
                //checa se a uma peca no local e se ela e valida.
                if ((isupper(matrix[lastRollPos][lastCollumPos]) && round % 2 == 0) || (islower(matrix[lastRollPos][lastCollumPos]) && round % 2 != 0))
                {
                    printf("de as coordenadas da jogada: ");
                    scanf(" %c%d", &collum, &rollPos);
                    int c;
                    //limpa caracteres em excesso.
                    while ((c = getchar()) != '\n' && c != EOF);
                }
                else if (matrix[lastRollPos][lastCollumPos] == '0' || matrix[lastRollPos][lastCollumPos] == ' ')
                {
                    printf("posicao selecionada vazia!\n");
                    continue;
                }
                else
                {
                    printf("coordenada invalida!\n");
                    continue;
                }
                //checa o tipo de peca que foi escolhida e roda a logica da peca.
                if (matrix[lastRollPos][lastCollumPos] == 'P' || matrix[lastRollPos][lastCollumPos] == 'p')
                    Pawl(matrix[lastRollPos][lastCollumPos] == 'P' && round % 2 == 0);
                if (matrix[lastRollPos][lastCollumPos] == 'T' || matrix[lastRollPos][lastCollumPos] == 't')
                    Rook(matrix[lastRollPos][lastCollumPos] == 'T' && round % 2 == 0);
                if (matrix[lastRollPos][lastCollumPos] == 'B' || matrix[lastRollPos][lastCollumPos] == 'b')
                    Bishop(matrix[lastRollPos][lastCollumPos] == 'B' && round % 2 == 0);
                if (matrix[lastRollPos][lastCollumPos] == 'C' || matrix[lastRollPos][lastCollumPos] == 'c')
                    Knight(matrix[lastRollPos][lastCollumPos] == 'C' && round % 2 == 0);
                if (matrix[lastRollPos][lastCollumPos] == 'K' || matrix[lastRollPos][lastCollumPos] == 'k')
                    King(matrix[lastRollPos][lastCollumPos] == 'K' && round % 2 == 0);
                if (matrix[lastRollPos][lastCollumPos] == 'Q' || matrix[lastRollPos][lastCollumPos] == 'q')
                    Queen(matrix[lastRollPos][lastCollumPos] == 'Q' && round % 2 == 0);
            } while (validMove == false);
            //mantem o padrao xadrez do tabuleiro.
            if (lastRollPos % 2 != 0 && (lastCollumPos == 4 || lastCollumPos == 8 || lastCollumPos == 12 || lastCollumPos == 16))
                matrix[lastRollPos][lastCollumPos] = '0';
            else if (lastRollPos % 2 == 0 && (lastCollumPos == 2 || lastCollumPos == 6 || lastCollumPos == 10 || lastCollumPos == 14))
            {
                matrix[lastRollPos][lastCollumPos] = '0';
            }
            else
                matrix[lastRollPos][lastCollumPos] = ' ';
            round++;
            bool upperAlive = false;
            bool lowerAlive = false;
            //checa se o rei de cada lado esta vivo.
            for (i = 0; i < 9; i++)
            {
                for (j = 0; j < 17; j++)
                {
                    if (matrix[i][j] == 'K')
                        upperAlive = true;
                    else if (matrix[i][j] == 'k')
                        lowerAlive = true;
                }
            }
            //se um dos reis estiver fora do jogo da a vitoria para a outra equipe.
            if (!upperAlive)
            {
                printf("As minusculas venceram!\n"
                    "Aperte enter para continuar");
                matchOn = false;
                char enter = 0;
                while (enter != '\n') { enter = getchar(); }
            }
            if (!lowerAlive)
            {
                printf("As maiusculas venceram!\n"
                    "Aperte enter para continuar");
                matchOn = false;
                char enter = 0;
                while (enter != '\n') { enter = getchar(); }
            }
        }
    }
}