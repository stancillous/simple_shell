#include "shell.h"
#define MAX_LINE_LENGTH 1024
/**
 * my_getline - Function to read input line by line from standard input
 * with support for carriage returns
 * Return: pointer
 **/
char *my_getline(void)
{
	static char buffer[MAX_LINE_LENGTH]; /* Static buffer to store input*/
	static int buffer_index; /* Index to keep track of buffer position*/
	static int num_chars; /* Number of characters in buffer*/
	char *line = NULL; /* Pointer to store the input line*/
	int index = 0; /* Index to iterate through input line*/

	while (1)
	{
		if (buffer_index == num_chars)
		{
			num_chars = read(STDIN_FILENO, buffer, MAX_LINE_LENGTH);
			buffer_index = 0;
			if (num_chars == 0)
				break; /* End of input */
		}
		while (buffer_index < num_chars && buffer[buffer_index] != '\n')
		{
			if (buffer[buffer_index] == '\r')
			{
				buffer_index++;
				continue; /* Skip carriage return characters */
			}
			if (!line)
			{
				line = malloc(MAX_LINE_LENGTH * sizeof(char));
			}
			line[index++] = buffer[buffer_index++];
		}
		if (buffer_index < num_chars && buffer[buffer_index] == '\n')
		{
			line[index] = '\0'; /* Add null terminator */
			buffer_index++; /* Move past newline character */
			break;
		}
	}
	return (line);
}
