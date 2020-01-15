#include <libc.h>

int		main()
{
	char *test = "coucou je m'appel l'autre";
	char *test2 = NULL;
	printf("test %10s\n",test);
	printf("test %10.5s\n",test);
	printf("test %5.10s\n",test);
	printf("test %.5s\n",test);
	printf("test %.3s\n",test2);
	printf("test %10s\n",test2);
}
