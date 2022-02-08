/* 

The code should take integers from defined range e.g. 0-100 and process them as follows.


•	If a number is divisible by 3, print “Global”
•	If a number is divisible by 5, print “Logic”
•	If a number is divisible by 3 AND by 5, print “GlobalLogic” in a single line
•	Each printout should be done on a separate line. 

*/

/*
AUTHER:MARWAN SALAH
DATE:07/11/2021
*/

#include <stdio.h>

/* General Defines */
#define MIN 0
#define MAX 100
#define TRUE 1
#define FALSE 0
#define FIRST_DIV_NUM 3
#define SECOND_DIV_NUM 5

/* Functions Declaration */
void Global_Logic_Print(int Minimum, int Maximum);

int main(void)
{
    /* Local Variables */
    int Minimum = MIN;
    int Maximum = MAX;

    Global_Logic_Print(Minimum, Maximum);
    return 0;
}

/* Function to check for divisable numbers and print accordingly */
void Global_Logic_Print(int Minimum, int Maximum)
{
    for (int i = Minimum; i <= Maximum; i++)
    {
        if ((FALSE == i % FIRST_DIV_NUM) && (FALSE != i))
        {
            if (FALSE == i % SECOND_DIV_NUM)
            {
                printf("%d = GlobalLogic\n", i);
            }
            else
            {
                printf("%d = Global\n", i);
            }
        }
        else if (FALSE == i % SECOND_DIV_NUM && (FALSE != i))
        {
            printf("%d = Logic\n", i);
        }
        else
        {
            printf("%d \n", i);
        }
    }
}
