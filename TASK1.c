/* 
A random ASCII character is received every 100ms. 
We need to find a sequence of "GLROX" characters. 
There can be other characters in between! 
Once found- call a Found function and wait for the sequence again, 
if not found then wait until this sequence is found. 
If a new character does not come in 2 seconds call Timeout function 
and wait for the whole "GLROX" again even if previously received part of the sequence. 
The Process function which is your entry point is called every 100ms. 
*/

/*
AUTHER:MARWAN SALAH
DATE:07/11/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* PERIODCITY in ms */
#define PERIODCITY 100
/* Timer to timeout in ms*/
#define TIMEOUT_TIME 2000
/* General Defines */
#define TRUE 1
#define FALSE 0
#define MAX_RAND 74
#define ASCII_START 48


/* Global Variables */
char ASCII_Character;
char Next_Char = 'G';
int First_Char_Found_Flag = FALSE;
clock_t Start_Timeout_Counter = FALSE;


/* Functions Declaration */
void Delay(int Milli_Seconds);
void Reset_Flags(void);
void Time_Out_Check(int Time_Out_Time);
char Generate_ASCII_Character(void);
void Found(void);
void Find_Sequence(char ASCII_Character);


int main(void)
{

    while (TRUE)
    {
        /* 100ms Periodcity */ 
        Delay(PERIODCITY);
        /* Generate Random ASCII and store it in a variable */
        ASCII_Character = Generate_ASCII_Character();
        /* Check the ASCII Character for a match */
        Find_Sequence(ASCII_Character);
    }
    return 0;
}

void Delay(int Milli_Seconds)
{

    /* Storing start time */
    clock_t Start_Time = clock();

    /* looping till required time delay */
    while (clock() < (Start_Time + Milli_Seconds))
    {

    }
}

/* Function to reset all flags and counters */
void Reset_Flags(void)
{

    First_Char_Found_Flag = FALSE;
    Next_Char = 'G';
    Start_Timeout_Counter = FALSE;
}

/* Function to Check for time out */
void Time_Out_Check(int Time_Out_Time)
{

    if (clock() > (Start_Timeout_Counter + Time_Out_Time))
    {
        Reset_Flags();
        printf("%d Milli-Seconds Timeout Detected \n",TIMEOUT_TIME);
    }
}

/* Function to Generate ASCII Characters */
char Generate_ASCII_Character(void)
{
    int Random_Number;
    char Random_Character;
    Random_Number = rand() % MAX_RAND;
    Random_Character = (char) Random_Number + ASCII_START;
    printf("Generated Random Charcter is \"%c\"\n", Random_Character);
    return Random_Character;
}

/* Function to print when the Sequence is found */
void Found(void)
{
    printf("Sequence \"GLROX\" is found\n");
    Reset_Flags();
}

/* Function to Find the Required Sequence */
void Find_Sequence(char ASCII_Character)
{
    switch (ASCII_Character)
    {
    case 'G':
        if (First_Char_Found_Flag == FALSE)
        {
            printf("Character G is found\n");
            Next_Char = 'L';
            First_Char_Found_Flag = TRUE;
            Start_Timeout_Counter = clock();
        }

        break;

    case 'L':
        if (Next_Char == 'L')
        {
            Time_Out_Check(TIMEOUT_TIME);
            printf("Character L is found\n");
            Next_Char = 'R';
            Start_Timeout_Counter = clock();
        }
        break;

    case 'R':
        if (Next_Char == 'R')
        {
            Time_Out_Check(TIMEOUT_TIME);
            printf("Character R is found\n");
            Next_Char = 'O';
            Start_Timeout_Counter = clock();
        }
        break;

    case 'O':
        if (Next_Char == 'O')
        {
            Time_Out_Check(TIMEOUT_TIME);
            printf("Character O is found\n");
            Next_Char = 'X';
            Start_Timeout_Counter = clock();
        }
        break;
    case 'X':
        if (Next_Char == 'X')
        {
            Time_Out_Check(TIMEOUT_TIME);
            printf("Character X is found");
            Found();
            Next_Char = 'G';
        }
        break;
    default:
        if (First_Char_Found_Flag == TRUE)
        {
            Time_Out_Check(TIMEOUT_TIME);
        }
        break;
    }
}
