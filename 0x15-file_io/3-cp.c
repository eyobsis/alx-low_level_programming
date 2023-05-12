#include "main.h"
void closer(int arg_files);
/**
 * main - Entry Point is shown here
 * @argc: # number of existing args
 * @argv: this is the array pointer for args
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int ffrom, fto, ffrom_r, wri_error;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}

	ffrom = open(argv[1], O_RDONLY);
	if (ffrom == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fto = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fto == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while (ffrom_r >= 1024)
	{
		ffrom_r = read(ffrom, buf, 1024);
		if (ffrom_r == -1)
		{
			dprintf(2, "Error: Can't read from file %s\n", argv[1]);
			closer(ffrom);
			closer(fto);
			exit(98);
		}
		wri_error = write(fto, buf, ffrom_r);
		if (wri_error == -1)
		{
			dprintf(2, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	closer(ffrom);
	closer(fto);
	return (0);
}

/**
 * closer - this closes with error
 * @arg_files: argv 1 or 2 the two arguments 
 * Return: void data type
 */
void closer(int arg_files)
{
	int cl_er;

	cl_er = close(arg_files);

	if (cl_er == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", arg_files);
		exit(100);
	}
}
