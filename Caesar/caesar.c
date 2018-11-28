#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// To get from the ASCII value of a number to the alphabetical index we need to do some math.
// If the letter is capital, subtract 65 from the ASCII value. If it is lowercase,
// we need to subtract an additional 32 to get the correct value.

// Converts a character (v) to its alphabetical index, ciphers it using the key (k), then
// returns the ciphered character's ASCII value.
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

int main (int argc, string argv[])
{	
	// Variable declaration
	int key, n;
	string text;
	char encoded[n];

	// Let's check to make sure we have the required arguments, and that they are valid.
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