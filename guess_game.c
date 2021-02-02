#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void data(char name[20], int score)                        //Code to print score and of game1
{
    int *arr;
    arr = (int *)malloc(3 * sizeof(int));                  //array to load previous high score
    char a2[20], b2[20], c2[20], ra[20] = "none";          //string for name in high score file
    FILE *ptr;
    ptr = fopen("high_score.txt", "r");
    if (ptr == NULL)
    {
        arr[0] = 0; 
        arr[1] = 0;
        arr[2] = 0;
        fclose(ptr);
        strcpy(a2, ra);
        strcpy(b2, ra);
        strcpy(c2, ra);
        ptr = fopen("high_score.txt", "w");
        fprintf(ptr, "%s %d %s %d %s %d", a2, arr[0], b2, arr[1], c2, arr[2]);
        fclose(ptr);
    }
    ptr = fopen("high_score.txt", "r");
    fscanf(ptr, "%s %d %s %d %s %d", &a2, &arr[0], &b2, &arr[1], &c2, &arr[2]);
    fclose(ptr);

    if (score < arr[0] && score < arr[1] && score < arr[2])        //loops to compare with previous high scores
    {
        printf("Your Score is %d\n", score);
    }
    if (score >= arr[2] && score < arr[1])
    {
        printf("\n\t\t\t\t3rd Place\n\n\n");
        printf("\t\t\t\tYour Score is %d\n", score);
        arr[2] = score;
        strcpy(c2, name);
    }
    if (score >= arr[1] && score < arr[0])
    {
        printf("\n\t\t\t\t2nd Place\n\n\n");
        printf("\t\t\t\tYour Score is %d\n", score);
        strcpy(c2, b2);
        arr[2] = arr[1];
        arr[1] = score;
        strcpy(b2, name);
    }
    if (score >= arr[0])
    {
        printf("\n\t\t\t\t\t1st Place\n\n\n");
        printf("\n\t\t\t\tYour Score is %d\n", score);
        arr[2] = arr[1], strcpy(c2, b2);
        strcpy(b2, a2);
        arr[1] = arr[0];
        arr[0] = score;
        strcpy(a2, name);
    }
    ptr = fopen("high_score.txt", "w");
    fprintf(ptr, "%s %d %s %d %s %d", a2, arr[0], b2, arr[1], c2, arr[2]); //to update high score list
    fclose(ptr);

    printf("\n\t\t\tLeaderboard\n");
    printf("1.%s\t\t\t\t%d\n", a2, arr[0]);
    printf("2.%s\t\t\t\t%d\n", b2, arr[1]);
    printf("3.%s\t\t\t\t%d\n", c2, arr[2]);
    free(arr);
}
int game1(char name[])
{
    int number, guess, nguesses = 1, score;
    double *run_time;
    run_time = (double *)malloc(2 * sizeof(double));

    srand(time(0));
    number = rand() % 100 + 1;

    run_time[0] = time(NULL);
    do
    {
        printf("Enter your Guess between 0 to 100 : ");
        scanf("%d", &guess);
        if (guess > number)
        {
            printf("Your entered number is larger. Guess a smaller number\n\n");
        }
        else if (guess < number)
        {
            printf("Your enetred number is smaller. Guess a larger number\n\n");
        }
        else
        {
            run_time[1] = time(NULL);
            double time_spent = (double)(run_time[1] - run_time[0]);
            free(run_time);
            score = 2000 - time_spent * 15 - 100 * nguesses;
            if (score <= 0)
            {
                printf("\n\n\t\t\tYour score is 0\n\n");
            }
            else
            {
                data(name, score);
            }

            nguesses = 1;
            break;
        }
        nguesses++;
    } while (number != guess);
}
void game2()
{
    int a, b, c, d, e, number;
    char x;
    do
    {
        printf("\t\nThink a nummber between 1 to 30\n");
        printf("\tCheck that is it in the given numbers\n\n");
        printf("\t16,17,18,19,20,21,22,23,24,25,26,27,28,29,30\n\n");
        printf("\tIf yes Press Y if no press N:");
        fflush(stdin);
        scanf("%c", &x);
        if (x == 'y' || x == 'Y')
        {
            a = 1;
        }
        else if (x == 'N' || x == 'n')
        {
            a = 0;
        }
        else
        {
            printf("\n\n\t\t\tInvalid Entry\n\n");
        }
    } while (x != 'n' && x != 'N' && x != 'y' && x != 'Y');
    do
    {
        printf("\tCheck that is it in the given numbers\n\n");
        printf("\t8,9,10,11,12,13,14,15,24,25,26,27,28,29,30\n\n");
        printf("\tIf yes Press Y if no press N:");
        fflush(stdin);
        scanf("%c", &x);

        if (x == 'y' || x == 'Y')
        {
            b = 1;
        }
        else if (x == 'N' || x == 'n')
        {
            b = 0;
        }
        else
        {
            printf("\n\n\t\t\tInvalid Entry\n\n");
        }
    } while (x != 'n' && x != 'N' && x != 'y' && x != 'Y');
    do
    {
        printf("\tCheck that is it in the given numbers\n\n");
        printf("\t4,5,6,7,12,13,14,15,20,21,22,23,28,29,30\n\n");
        printf("\tIf yes Press Y if no press N:");
        fflush(stdin);
        scanf("%c", &x);
        if (x == 'y' || x == 'Y')
        {
            c = 1;
        }
        else if (x == 'N' || x == 'n')
        {
            c = 0;
        }
        else
        {
            printf("\n\n\t\t\tInvalidInvalid Entry\n\n");
        }
    } while (x != 'n' && x != 'N' && x != 'y' && x != 'Y');
    do
    {
        printf("\tCheck that is it in the given numbers\n\n");
        printf("\t2,3,6,7,10,11,14,15,18,19,22,23,26,27,30\n\n");
        printf("\tIf yes Press Y if no press N:");
        fflush(stdin);
        scanf("%c", &x);
        if (x == 'y' || x == 'Y')
        {
            d = 1;
        }
        else if (x == 'N' || x == 'n')
        {
            d = 0;
        }
        else
        {
            printf("\n\n\t\t\tInvalid Entry\n\n");
        }
    } while (x != 'n' && x != 'N' && x != 'y' && x != 'Y');
    do
    {
        printf("\tCheck that is it in the given numbers\n\n");
        printf("\t1,3,5,7,9,11,13,15,17,19,21,23,25,27,29\n\n");
        printf("\tIf yes Press Y if no press N:");
        fflush(stdin);
        scanf("%c", &x);
        if (x == 'y' || x == 'Y')
        {
            e = 1;
        }
        else if (x == 'N' || x == 'n')
        {
            e = 0;
        }
        else
        {
            printf("\n\n\t\t\tInvalid Entry\n\n");
        }
    } while (x != 'n' && x != 'N' && x != 'y' && x != 'Y');
    number = (16 * a) + (8 * b) + (4 * c) + (2 * d) + e;
    printf("Your Number is %d\n", number);
}
int main()
{
    char name[20], p, mode;
    printf("\n\n\n\n\t\t\t\t\t******Number Guess Game******\n\n\n");
    printf("Enter Your Name:");
    scanf("%s", &name);
    fflush(stdin);

    do
    {
        do
        {
            printf("\nYou Want to guess the Numeber Or You Want Computer To guess it(Y/C):");
            scanf("%c", &mode);
            if (mode == 'y' || mode == 'Y')
            {
                game1(name);
            }
            else if (mode == 'C' || mode == 'c')
            {
                game2();
            }
            else
            {
                printf("\n\t\t\tInvalid Entry\n");
            }
            fflush(stdin);
        } while (mode != 'C' && mode != 'c' && mode != 'y' && mode != 'Y');
        printf("Do you want to play again(Y/N):");
        scanf("%c", &p);
        fflush(stdin);

    } while (p == 'Y' || p == 'y');
    return 0;
}
