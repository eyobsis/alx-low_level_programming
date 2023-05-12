#include <stdio.h>
#include "main.h"
/**
 * append_text_to_file - append text to the end of a file
 * @filename: name of file to write into.
 * @text_content: text to append to file
 *
 * Return: 1 (SUCCESS), else -1 (FAILURE)
 */
int append_text_to_file(const char *filename, char *text_content)
{
FILE *file;
int result = 1;

if (filename == NULL)
return (-1);

file = fopen(filename, "a");
if (file == NULL)
return (-1);

if (text_content != NULL)
{
if (fputs(text_content, file) == EOF)
result = -1;
}

if (fclose(file) == EOF)
result = -1;

return (result);
}
