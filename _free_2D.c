#include "shell.h"

/**
 * _free - frees a 2D array
 * @arr: A pointer to the array
 */
void _free(char **arr)
{
	unsigned int j;

	for (j = 0; arr[j]; j++)
		free(arr[j]);
	free(arr);
}
