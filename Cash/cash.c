#include <stdio.h>
#include <math.h>
#include <cs50.h>

/*
 * Here we are taking a user-defined input which will be the amount of change 
 * they are owed. The program will then output the least amount of coins needed 
 * to give the customer that amount of change. 
 *
 * For example, say the user input is 0.41 ($0.41). The program will output '4' 
 * (one quarter, one dime, one nickel, and one penny).
 */

int main(void)
{
    int cents;
	int denoms[4] = {25, 10, 5, 1};
	int result = 0;
	float change = -0.01;

    do
    {
 	    change = get_float("Enter amount of cash owed: ");
	    cents = round(change * 100);       
    } while (change <= 0.0);

	while (cents != 0)
	{
		for (int i = 0; i < 4; i++)
		{
			while (cents / denoms[i] > 0)
			{
				cents = cents - denoms[i];
				result++;
			}
		}
	}

	printf("Number of coins: %i\n", result);
}