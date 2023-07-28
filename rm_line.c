#include "shell.h"

/**
 * rm_line - Delete fresh line added up
 * @buffer: The string with the new line to remov
 *
 * Return: Nothing
 */

void rm_line(char *buffer)
{
	int dex = 0;

	while (buffer[dex])
	{
		if (buffer[dex] == '\n')
		{
			buffer[dex] = 0;
		}
		dex++;
	}
}

