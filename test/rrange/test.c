#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int *array = {0};
	int index;
	int len;
	int new_start;
	int new_end;

	index = 0;
	len = 0;
	if (start > 0 && end > 0)
	{	
		if (start < end)
			len = end - start + 1;
		else if (start > end)
			len = start - end + 1;
	}
	else
	{
		new_end = end;
		new_start = start;
		if (new_end < 0)
			new_end *= -1;
		if (new_start <0)
			new_start *= -1;
		if (new_start < new_end)
			len = new_end - new_start + 1;
		else
			len = new_start - new_end + 1;
	}
	if (start == end)
	{
		if(!(array = (int *)malloc(sizeof(int) * len)))
			return (0);
		if (start == 0)
			array[0] = 0;
		else
			array[0] = start;
			array[1] = start;
		return (array);
	}
	else
	{	
		if(!(array = (int *)malloc(sizeof(int) * len)))
			return (0);
	}
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

