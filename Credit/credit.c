#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cs50.h>

/*
 * AmEx: 15 digits, starts with 34 or 37
 * MasterCard: 16 digits
 * Visa: 13 OR 16 digits, starts with a 4
 */

/*
 * Takes some arbitrary integer as an input and return the length of said integer.
 * Simply checks if the input is less than the length of the current multiplier (some multiple of
 * 10). If it is, return the length (starting at 1). Otherwise, increment length by one and
 * multiply the check int by 10.
 */
int get_int_length(long num)
{
	int result = 1;
	long multiplier = 10;		// This will be multiplied by 10 for every iteration
								// of the loop

	while (1 == 1)
	{
		if (num < multiplier)
		{
			return result;
		}

		result += 1;
		multiplier *= 10;
	}

	return -1;
}

/*
 * Assuming the card number has already passed Luhn's algorithm, start checking the digits.
 * If the length is 15 and first two digits are 3,4 or 3,7, it's an AmEx. If the length
 * is 16 or 13 and card starts with 4, it's a Visa. Else if the card length is 16, it's a
 * Mastercard.
 *
 * Returns 1 for AmEx, 2 for MasterCard, 3 for Visa, or 0 for INVALID.
 */
int check_card_type(long card, int len)
{
	int first_two = card / (pow(10, (len - 2)));

	if (len == 15)
	{
        if (first_two == 34 || first_two == 37)
		{
            return 1;
        }
	}

    if (len == 16 && first_two >= 51 && first_two <= 55)
    {
        return 2;
    }

    if (first_two / 10 == 4)
	{
        if (len == 16 || len == 13)
        {
            return 3;
        }
	}

    return 0;
}

int main(void)
{
    long card_num = get_long("Enter a card number: ");
    int card_length = get_int_length(card_num);
    int counter = 0, sum = 0, cur_digit = 0;
    int digits[32];

    // Split the given card number into an array of ints, starting from last digit to the first.
    // For every other number, multiply it by 2 as per the Luhn Algorithm.
    long temp_num = card_num;			// This will allow us to decrement the card number by
    									// a factor of 10 to retrieve all the digits in the number
    while (temp_num > 0)
    {
    	cur_digit = temp_num % 10;
    	digits[counter] = cur_digit;

    	if (counter != 0 && counter % 2 != 0)
    	{
    		digits[counter] *= 2;
    	}

    	counter++;
    	temp_num /= 10;
    }

    // Now let's add all of the DIGITS in the array together, splitting the integer if
    // it's bigger than 10.
    for (int j = 0; j < card_length; j++)
    {
    	if (digits[j] >= 10)
    	{
    		sum += (digits[j] % 10);
    		sum += (digits[j] / 10);
    	}
    	else
    	{
    		sum += digits[j];
    	}
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    switch (check_card_type(card_num, card_length))
    {
        case 1:
            printf("AMEX\n");
            break;
        case 2:
            printf("MASTERCARD\n");
            break;
        case 3:
            printf("VISA\n");
            break;
        default:
            printf("INVALID\n");
    }

}