#include <stdio.h>
#include <stdlib.h>
int     *ft_rrange(int start, int end);
	
int main(int argc, char* argv[])
{
	int *array;
	int index;
	(void) argc;
	index = 0;
	array = ft_rrange(atoi(argv[1]), atoi(argv[2]));
	while (array[index])
	{
		printf("%d\n", array[index]);
		index++;
	}
	printf("\n\n\n");

	index  = 0;
	array = ft_rrange(-3, 1);
	while (array[index])
	{
		printf("%d\n", array[index]);
		index++;
	}
	return (0);
}	
