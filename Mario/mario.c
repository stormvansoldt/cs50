#include <stdio.h>
#include <cs50.h>

int main(void)
{
	int linenum = 1;
	int height = -1;

	while (height <= 0 || height > 8)
	{
		height = get_int("Enter a height for the pyramid: ");
	}

	while (linenum <= height)
	{
		for (int j = 0; j < (height - linenum); j++)
		{
			putchar(' ');
		}

		for (int i = 0; i < linenum; i++)
		{
			putchar('#');
		}
		
		printf("  ");

		for (int x = 0; x < linenum; x++)
		{
			putchar('#');
		}

		printf("\n");
		linenum++;
	}
}