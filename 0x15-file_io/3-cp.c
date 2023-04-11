#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE 1024
#define USAGE "Usage: cp file_from file_to\n"
#define READ_ERR "Error: Can't read from file %s\n"
#define WRITE_ERR "Error: Can't write to %s\n"
#define CLOSE_ERR "Error: Can't close fd %d\n"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments
 *
 * Return: 0 on success, exit with code on failure
 */
int main(int argc, char *argv[])
{
int from_fd, to_fd;
ssize_t rcount, wcount;
char buffer[BUFSIZE];
mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
if (argc != 3)
{
dprintf(STDERR_FILENO, USAGE);
exit(97);
}

from_fd = open(argv[1], O_RDONLY);
if (from_fd == -1)
{
dprintf(STDERR_FILENO, READ_ERR, argv[1]);
exit(98);
}

to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
if (to_fd == -1)
{
dprintf(STDERR_FILENO, WRITE_ERR, argv[2]);
close(from_fd);
exit(99);
}

while ((rcount = read(from_fd, buffer, BUFSIZE)) > 0)
{
wcount = write(to_fd, buffer, rcount);
if (wcount != rcount)
{
dprintf(STDERR_FILENO, WRITE_ERR, argv[2]);
close(from_fd);
close(to_fd);
exit(99);
}
}

if (rcount == -1)
{
dprintf(STDERR_FILENO, READ_ERR, argv[1]);
close(from_fd);
close(to_fd);
exit(98);
}

if (close(from_fd) == -1)
{
dprintf(STDERR_FILENO, CLOSE_ERR, from_fd);
close(to_fd);
exit(100);
}

if (close(to_fd) == -1)
{
dprintf(STDERR_FILENO, CLOSE_ERR, to_fd);
exit(100);
}

return (0);
}
