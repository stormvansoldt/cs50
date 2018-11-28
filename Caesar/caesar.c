/*
 * A Caesar Cipher written in nothing but C.
 *
 * Author: Storm Van Soldt
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int cipher(char v, int k);

/*
 * Checks to ensure that there are enough command-line arguments, and that those
 * arguments are valid. Then runs the input through a Caesar Cipher, printing
 * the result to STDOUT.
 */
int main (int argc, string argv[])
{	
	int key, n;
	string text;
	char encoded[50];

	if (argc == 2 && argv[1] != 0)
	{
		key = atoi(argv[1]);
	}
	else
	{
		printf("Usage: ./caesar key\n");
		return 1;
	}

	text = get_string("Enter the phrase you want to be encoded: ");
	n = strlen(text);

	printf("ciphertext: ");
	for (int i = 0; i < n; i++)
	{	
		// Check to see if the current value is alphanumeric. If it isn't, don't cipher it.
		if (isalpha(text[i]))
		{
			encoded[i] = cipher(text[i], key);
		}
		else
		{
			encoded[i] = text[i];
		}

		printf("%c", encoded[i]);
	}

	printf("\n");
}

/*
 * Function: cipher
 * ----------------
 *	Increments a single character by k times, rolling over back to 'a' if the 
 *	input continues past 'z'. Eg, cipher(a, 1) would return 'b'.
 *
 *	v: a single character to run through the cipher
 *	k: number of times to increment the character
 *
 *	returns: input character incremented by k times
 */
int cipher(char v, int k)
{
	int position = tolower(v) - 'a';
	char value = ((position + k) % 26) + 'a';

	if (isupper(v))
	{
		value = toupper(value);
	}

	return value;
}