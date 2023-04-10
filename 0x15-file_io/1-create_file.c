#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * create_file - function that will create a new file and fill with with some
 * content.
 * @filename: name of the file to create.
 * @text_content: text to add to the new file.
 *
 * Return: Always 1 on scucess, -1 on Failure
 */
int create_file(const char *filename, char *text_content)
{
	int ierr, jlen, kfd;

	ierr = jlen = kfd = 0;
	if (!filename)
		return (-1);

	kfd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
		if (kfd < 0)
			return (-1);
	while (text_content && text_content[jlen])
		len++;

	ierr = write(kfd, text_content, jlen);
	if (ierr < 0)
		return (-1);
	close(kfd);
	return (1);
}
