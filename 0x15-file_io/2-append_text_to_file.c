#include "main.h"

/**
 * append_text_to_file - Entry 
 * @filename: which is file name
 * @text_content: which is text content
 * Return: 1 returns one
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int the_file, writes, e = 0;

	if (filename == NULL)
		return (-1);

	the_file = open(filename, O_RDWR | O_APPEND);
	if (the_file == -1)
		return (-1);



	while (text_content[e])
		e++;

	if (text_content == NULL)
	{
		close(the_file);
		return (1);
	}
	else
	{
		writes = write(file, text_content, e);
	}

	if (writes == -1)
		return (-1);

	close(the_file);
	return (1);
}
