#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <unistd.h>

/*
 * This program accepts one command line argument, which should be a hashed 
 * password. It will then run a brute force attack to attempt to crack that 
 * password hash.
 *
 * For time and resource purposes, we are assuming the given password is no more
 * than 5 characters long, includes only upper- and lowercase letters, and uses
 * the DES encryption standard.
 *
 * While playing around with the hashing function, I learned that the salt 
 * simply prepends itself to the front of the final hash. For example, if the 
 * salt was "4h", the hash would be "4hXXXXXXXXXXX".
 */

int increment_str(char * word);

int main (int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./crack {hash}\n");
		return 1;
	}

	// Get the hash from the command line, then retrieve the salt from the hash.
	string hash = argv[1];
	char salt[5] = {0}, pw[10] = {0};

	strncpy(salt, hash, 2);

	pw[0] = 'a';

	while (increment_str(pw) == 0)
	{
		printf("%s\r", pw);
		if (strlen(pw) > 5)
		{
			break;
		}

		if (strcmp(hash, crypt(pw, salt)) == 0)
		{
			printf("%s\n", pw);
			break;
		}
	}

	return 0;
}

/*
 * Function: increment_str
 * --------------
 *	Increments a string of alphabetical characters by one, going from 'a'-'z',
 * 	then from 'A'-'Z'. Once the 'Z' is hit, the function will roll the string 
 *	over to 'aa', then 'ab', etc.
 *
 *	word: a pointer to an array of characters
 *
 *	returns: 0 on successful completion, 1 if the given array is empty
 */
int increment_str(char * word)
{
    int pos;
    char buf[10];

    pos = strlen(word) - 1;

    if (pos < 0)
    	return 1;

    while (word[pos] == 90)
    {
    	word[pos] = 97;

    	if (pos == 0)
    	{
    		buf[0] = 97;
    		strcat(buf, word);
    		strcpy(word, buf);
    	}

    	pos--;
    }
    
    if (word[pos] == 122)
    	word[pos] = 65;
    else
    	word[pos]++;

    return 0;
}
