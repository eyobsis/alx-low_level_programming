#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - this reads a text file
 * @filename: variable to a file pointer
 * @letters: size of a  letters
 * Description: Write a function that reads text file &prints it
 * to the POSIX stdoutput.
 * Return: number of letters it read and print, 0 otherwise
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t zfile, zletr, writ;
	char *ztext;

	ztext = malloc(letters);
	if (ztext == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	zfile = open(filename, O_RDONLY);

	if (zfile == -1)
	{
		free(ztext);
		return (0);
	}

	zletr = read(zfile, ztext, letters);

	writ = write(STDOUT_FILENO, ztext, zletr);

	close(zfile);

	return (writ);
}
