#include <stdlib.h>
#include <stddef.h>

/**
 * _strlen - simple char count counter
 * @str: the string to count its letters
 * Return: returns the numher of bytes in bytes
 */
size_t _strlen(const char *str)
{
	size_t i = 0;

	if (!str)
		return (0);

	while (str[i] != '\0')
		i++;

	return (i);
}

/**
 * _strcpy - copies source to dest
 * @dest: the space to copy the source into
 * @source: the str to copy
 * Return: returns NULL or dest if successful
 */
char *_strcpy(char *dest, char *source)
{
	int i = 0;

	if (!dest || !source)
		return (NULL);

	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}

	dest[i] = 0;

	return (dest);
}

/**
 * _strcat - appends src to dest
 * @dest: the destination to append to
 * @src: the str to append
 * Return: returns the new dest
 */
char *_strcat(char *dest, char *src)
{
	int dest_end = 0, src_idx = 0;

	if (!dest || !src)
		return (NULL);

	while (dest[dest_end] != '\0')
		dest_end++;

	while (src[src_idx] != '\0')
	{
		dest[dest_end] = src[src_idx];
		dest_end++;
		src_idx++;
	}
	dest[dest_end] = '\0';

	return (dest);
}

/**
 * _strncmp - compares the forst n bytes of two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the number of bytes to compare
 * Return: returns 0 for same
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i = 0;

	if (!s1 || !s2)
		return (-1);
	if (n == 0)
		return (0);

	while (i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
	}

	return (0);
}

/**
 * strcmp - compares two str
 * @s1: first str
 * @s2: second str
 * Return: returns the difference
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;
	while (s1[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (-1);
	}

	return (0);
}
