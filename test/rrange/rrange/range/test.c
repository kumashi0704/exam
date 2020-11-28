#include <stdlib.h>
int lencheck(int start, int end)
{
	int len;
	start = (start > 0) ? start : -start;
	end = (end > 0) ? end : -end;
	
	if (start < end)
		len = end - start +1;
	else
		len = start - end +1;
	return (len);
}

int *ft_negative(int start, int end)
{
	int *array;
	int index;
	int len;
	int init;

	index = 0;
	len = lencheck(start, end);
	if (len == 1)
	{
		if(!(array = (int *)malloc(sizeof(int) * (len-1))))
			return (0);
	}
	else {
		if(!(array = (int *)malloc(sizeof(int) * len)))
			return (0);
	}
	init = (start < end) ? 1 : 0;
	start = (start > 0) ? start : -start;
	end = (end > 0) ? end : -end;


	if (init)
	{
			while (index < len)
			{
				array[index] = -start;
				index++;
				start--;
			}
	}
	else if (start == end)
	{
		array[0] = -start;
	}
	else
	{
		while (index < len)
		{
			array[index] = -end;
			index++;
			end--;
		}
	}
	return (array);
}

int     *ft_rrange(int start, int end)
{
	int *array;
	int index;
	int len;
	
	index = 0;
	if (start <= 0 && end <= 0)
	{
		array = ft_negative(start, end);
		return (array);
	}
	len = lencheck(start, end);
	if (len == 1)
	{
		if(!(array = (int *)malloc(sizeof(int) * (len-1))))
			return (0);
	}
	else {
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
	else if (start == end)
	{
		array[0] = start;
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
