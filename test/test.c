#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int *array;
	int index;
	int len;

	index = 0;
	len = 0;
	if (start < end)
		len = end - start + 1;
	else
		len = start - end + 1;
	if(!(array = (int *)malloc(sizeof(int) * len)))
		return (0);

	if (start < end)
	{
		while (index < len)
		{
			array[index] = end;
			index++;
			end--;
		}
	}
	else
	{
		while (index < len)
		{
			array[index] = start;
			index++;
			start--;
		}
	}
	return (array);
}

int main(int argc, char* argv[])
{
	int *array;
	int index;
	(void) argc;
	array = *ft_range(atoi(argv[1]));
	while (array[index])
	{
		printf("%d", array[1]);
	}
	return (0);
}
