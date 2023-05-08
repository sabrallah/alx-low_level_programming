#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * error_and_exit - Print error message and exit with given code
 * @code: Exit code
 * @message: Error message to print
 * @name: Additional string to print after the message
 */
void error_and_exit(int code, const char *message, const char *name)
{
	if (name != NULL)
		dprintf(STDERR_FILENO, "%s %s\n", message, name);
	else
		dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * open_files - Open input and output files
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * @fd_from: File descriptor of the input file
 * @fd_to: File descriptor of the output file
 *
 * Return: 0 on success, -1 on failure
 */
int open_files(int argc, char *argv[], int *fd_from, int *fd_to)
{
	if (argc != 3)
		error_and_exit(97, "Usage: cp file_from file_to", NULL);

	*fd_from = open(argv[1], O_RDONLY);
	if (*fd_from == -1)
		error_and_exit(98, "Error: Can't read from file", argv[1]);

	*fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (*fd_to == -1)
	{
		close(*fd_from);
		error_and_exit(99, "Error: Can't write to", argv[2]);
	}

	return (0);
}

/**
 * copy_files - Copy contents from one file to another
 * @fd_from: File descriptor of the input file
 * @fd_to: File descriptor of the output file
 * @buffer: Buffer to use for copying
 */
void copy_files(int fd_from, int fd_to, char *buffer)
{
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close(fd_from);
			close(fd_to);
			error_and_exit(99, "Error: Can't write to", NULL);
		}
	}

	if (bytes_read == -1)
	{
		close(fd_from);
		close(fd_to);
		error_and_exit(98, "Error: Can't read from file", NULL);
	}
}

/**
 * close_files - Close input and output files
 * @fd_from: File descriptor of the input file
 * @fd_to: File descriptor of the output file
 * @argv: Array of command line arguments
 */
void close_files(int fd_from, int fd_to, char *argv[])
{
	if (close(fd_from) == -1)
		error_and_exit(100, "Error: Can't close fd", argv[1]);

	if (close(fd_to) == -1)
		error_and_exit(100, "Error: Can't close fd", argv[2]);
}

/**
 * main - Entry point
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 *
 * Return: 0 on success, error code on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];

	if (open_files(argc, argv, &fd_from, &fd_to) == -1)
		return (-1);

	copy_files(fd_from, fd_to, buffer);

	close_files(fd_from, fd_to, argv);

	return (0);
}
