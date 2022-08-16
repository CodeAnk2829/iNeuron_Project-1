#include <stdio.h>
#include <windows.h>
#include <conio.h>
void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void SearchForNull(int a[4][4], int *p)
{
    int i, j;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if (a[i][j] == 0)
            {
                p[0] = i;
                p[1] = j;
                return;
            }
        }
    }
}

void GenerateNewArray(int a[4][4])
{
    int b[2], x, y;
    int i, j;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if (a[i][j] > 0 && a[i][j] < 10)
            {
                a[i][j] = 10 - a[i][j];
            }
            else if (a[i][j] >= 10)
            {
                a[i][j] = 25 - a[i][j];
            }
        }
    }
    SearchForNull(a, b);
    x = b[0];
    y = b[1];
    Swap(&a[x][y], &a[3][3]);
}

int CheckSorted(int a[4][4])
{
    int b[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    int i, j;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if (a[i][j] != b[4 * i + j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void display(int a[4][4], int count, int chances)
{
    int i, j;
    printf("Moves  %d\tLeft  %d\n\n", count, chances);
    printf("____________________________\n\n");
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            printf("| ");
            if (a[i][j] < 10 && a[i][j] != 0)
            {
                printf("%d    ", a[i][j]);
            }
            else if (a[i][j] != 0)
            {
                printf("%d   ", a[i][j]);
            }
            else
            {
                printf("%c     ", a[i][j]);
            }
        }
        printf("|\n");
    }
    printf("____________________________\n");
}

void Message(char *s, int* count, int* chances)
{
    int a[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
    int i, j;
    char c;
    printf("\tHello! %s, Welcome to the world of numbers \n\n", s);
    printf("\tPLEASE FOLLOW THE INSTRUCTIONS BELOW:-\n\n");
    printf("\t1. You can move ONLY 1 step at a time.");
    system("color f4");
    printf("\n\t   Move Up   : By UP Key\n\t   Move Down : By DOWN Key\n\t   Move Right: By RIGHT Key\n\t   Move Left : By LEFT Key");
    
    printf("\n\t2. You can move a number at empty position ONLY.\n\t3. For each number of moves your chances will decreased by 1.\n\t4. Winning Situation: Numbers in a 4 x 4 matrix should be in order 1 to 15.\n\n\t");

    printf("____________________________\n\n\t");
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if (a[i][j] < 10 && a[i][j] != 0)
            {
                printf("| %d    ", a[i][j]);
            }
            else if (a[i][j] != 0)
            {
                printf("| %d   ", a[i][j]);
            }
            else
            {
                printf("| %c\t    ", a[i][j]);
            }
        }
        printf("|\n\t");
    }
    printf("____________________________\n\n\t");

    printf("5. You can exit the game at any time by pressing 'E' or 'e'.\n\tSo try to win in minimum no. of moves\n\n\t\tHAPPY GAMING, GOOD LUCK!\n\n\tEnter any key to start...");

    c = getch();
    if(c == -32) {
        *count = -1;
        *chances = 201;
    }
    system("cls");
}

int main()
{
    int a[4][4] = {{7,11,2,9}, {5,3,1,10}, {14,4,6,12}, {8, 15, 13, 0}};
    char ch, c;
    int count = 0, chances = 200;
    char str[100];

    system("color f5");
    printf("\t\t\t\t∑ℹ️Śɧ∑ãŚɧ▶▶⨅⨆⨝\n\n\t\t\t Player's name: ");
    gets(str);

    system("cls");
    Message(str, &count, &chances);
    system("color f1");
    display(a, count, chances);

    int b[2], x, y;
    while (1)
    {
        SearchForNull(a, b);
        x = b[0];
        y = b[1];
        ch = getch();
        switch (ch)
        {
        case 72: // Move Up
            if (x < 3)
                Swap(&a[x][y], &a[x + 1][y]);
            ++count;
            chances--;
            break;

        case 80:
            if (x > 0) // Move Down
                Swap(&a[x][y], &a[x - 1][y]);
            ++count;
            chances--;
            break;

        case 77: // Move Right
            if (y > 0)
                Swap(&a[x][y], &a[x][y - 1]);
            ++count;
            chances--;
            break;

        case 75: // Move Left
            if (y < 3)
                Swap(&a[x][y], &a[x][y + 1]);
            ++count;
            chances--;
            break;

        case 'e':
            exit(0);

        case 'E':
            exit(0);
        }

        if (CheckSorted(a) == 1)
        {
            system("cls");
            system("color f2");
            display(a, count, chances);
            printf("\n\nWELL PLAYED\nYOU WIN!");
            printf("\n\nDo you want to play again?\nIf yes, press 'y' otherwise 'n'.\n\nNOTE:- If you pressing any of the arrow key then you will redirect to the new game \nand your chances will also be deducted by 1\n");

            c = getch();
            if (c == 'y')
            {
                count = 0;
                chances = 200;
                system("cls");
                GenerateNewArray(a);
                display(a, count, chances);
            }
            else if (c == 'n')
            {
                exit(0);
            }
            else if (c == -32)
            {
                count = 0;
                chances = 200;
                system("cls");
                GenerateNewArray(a);
                display(a, count, chances);
            }
        }

        system("cls");
        display(a, count, chances);

        if (count == 200)
        {
            system("cls");
            printf("\n\nGAME OVER\nYOU LOSE!");
            printf("\n\nDo you want to play again?\nIf yes, press 'y' otherwise 'n'.\n\nNOTE:- If you pressing any of the arrow key then you will redirect to the new game \nand your chances will also be deducted by 1\n");

            c = getch();
            if (c == 'y')
            {
                count = 0;
                chances = 200;
                system("cls");
                GenerateNewArray(a);
                display(a, count, chances);
            }
            else if (c == 'n')
            {
                exit(0);
            }
            else if(c == -32) {
                count = 0;
                chances = 200;
                system("cls");
                GenerateNewArray(a);
                display(a, count, chances);
            }
        }
    }

    return 0;
}