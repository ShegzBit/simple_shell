#include "shell.h"

char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
int _strncmp(char *s1, const char *s2, size_t n);
int xs_space(char *str);

/**
 * _memcpy - copies memory area.
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Number of bytes to copy
 *
 * Return: A pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	char *temp;

	temp = malloc(n);
	if (temp == NULL)
		return (NULL);
	for (i = 0; i < n; i++)
	{
		*(temp + i) = *(src + i);
	}

	for (i = 0; i < n; i++)
		dest[i] = temp[i];

	free(temp);

	return (dest);
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: A pointer to the memory previously allocated with a call
 *	to malloc: malloc(old_size).
 * @old_size: The size, in bytes, of the allocated space for ptr.
 * @new_size: The size, in bytes, of the memory block.
 *
 * Return: If new_size == old_size, just return ptr. If new_size is equal
 *	to zero, and ptr is not NULL, then the call is equivalent
 *	to free(ptr). Return NULL.
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *new_ptr;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(sizeof(char) * new_size);
	if (new_ptr == NULL)
		return (NULL);

	_memcpy(new_ptr, ptr, (old_size < new_size) ? old_size : new_size);
	free(ptr);
	return (new_ptr);
}

/**
 * _strncmp - compare first n bytes of s1 & s2
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: number of bytes to compare
 * Return: 0 when equal | -1 other wise
 */
int _strncmp(char *s1, const char *s2, size_t n)
{
	int count = 0;

	for (count = 0; n && s2[count]; count++, n--)
	{
		if (s1[count] != s2[count])
			return (-1);
	}
	return (0);
}

/**
 * xs_space - checks if a string is made of only spaces
 * @str: str to check through
 * Return: 0 if str contains other characters
 * -1 otherwise
 */
int xs_space(char *str)
{
	int i;

	for (i = 0; str[i] && str[i] != '\n'; i++)
	{
		if (str[i] != ' ')
			return (0);
	}
	return (-1);
}
