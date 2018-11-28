#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cs50.h>

/*
 * Takes a card number from user input and validates it as either a Mastercard,
 * VISA, or American Express using Luhn's algorithm and vendor attributes (ie,
 * number of digits in card number, first one/two digits).
 */

int get_int_length(long num);
int check_card_type(long card, int len);

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

    switch (check_card_type(card_num, card_length)) {
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

/*
 * Function: get_int_length
 * ------------------------
 *  Takes an arbitrary integer as an input and return the length of said integer.
 *  Simply checks if the input is less than the length of the current multiplier
 *  (some multiple of 10). If so, return the length (starting at 1). Otherwise, 
 *  increment length by one and multiply the check int by 10.
 *
 *  num: a positive integer
 *
 *  returns: length of the provided integer
 */
int get_int_length(long num)
{
    int result = 1;
    long multiplier = 10;

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
 * Function: check_card_type
 * -------------------------
 *  Accepts a card number and the number of digits in the card number as inputs
 *  and returns the type of card that was provided.
 *  
 *  AMEX: Length is 15, first two digits are 34 or 37
 *  VISA: Length is 13 or 16, first digit is 4
 *  MASTERCARD: length is 16, first two digits are generally 51-55
 *
 *  card: a card number of type long
 *  len: an integer representing the number of digits in the card number
 *
 *  returns: 1 for AmEx, 2 for MasterCard, 3 for Visa, or 0 for INVALID.
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