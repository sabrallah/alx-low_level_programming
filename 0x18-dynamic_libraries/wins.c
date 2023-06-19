#include <stdlib.h>
#include <unistd.h>

/**
 * srand - Overwrites the srand function in the libc shared object
 * @sed: The seed to use for the random number generator.
 */
void srand(unsigned int sed)
{
	const char *num_txt = "9 8 10 24 75 - 9\n";
	const char *txxt = "Congratulations, you win the Jackpot!\n";

	(void)sed;
	write(STDOUT_FILENO, (void *)num_txt, 17);
	write(STDOUT_FILENO, (void *)txxt, 38);
	exit(EXIT_SUCCESS);
}
