#include "shell.h"
#define MAX_LINE_LENGTH 1024

char *my_getline(void)
{
	static char buffer[MAX_LINE_LENGTH]; /* Static buffer to store input*/
	static int buffer_index = 0; /* Index to keep track of buffer position*/
	static int num_chars = 0; /* Number of characters in buffer*/
	char *line = NULL; /* Pointer to store the input line*/
	int index = 0; /* Index to iterate through input line*/

	while (1)
	{/* If buffer is empty, read from stdin into buffer*/
		if (buffer_index == num_chars)
		{
			num_chars = read(STDIN_FILENO, buffer, MAX_LINE_LENGTH);
			buffer_index = 0; /* Reset buffer index*/
		}
		/* If read returns 0, end of input reached*/
		if (num_chars == 0)
		{
			break;
		}
		/* Copy characters from buffer to line until newline or end of buffer*/
		while (buffer_index < num_chars && buffer[buffer_index] != '\n')
		{
			if (buffer[buffer_index] == '\r')
			{
				/* Skip carriage return characters*/
				buffer_index++;
				continue;
			}
			/* Allocate memory for line if not allocated yet*/
			if (line == NULL)
			{
				line = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
			}
			/* Copy character from buffer to line*/
			line[index++] = buffer[buffer_index++];
		}
		/* If newline is found, end of line reached*/
		if (buffer_index < num_chars && buffer[buffer_index] == '\n')
		{/* Add null terminator to line*/
			line[index] = '\0';
			buffer_index++; /* Move past newline character*/
			break;
		}
	}
	return (line);
}
