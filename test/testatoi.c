#include <stdio.h>
int ft_atoi(const char *str)
{
	int index;
	int total;
	int count;

	index = 0;
	total = 0;
	count = 1;
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\f' || str[index] == '\r' || str[index] == '\v' || str[index] == '\n')
		index++;
	if  (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
		{
			count = -1;
		}
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		total = (total * 10) + (str[index] - '0');
		index++;
	}
	return (total * count);
}

int main(int argc, char* argv[])
{
	(void)argc;

	int result;
	result = ft_atoi(argv[1]);
	printf("%d\n\n", result);
}
