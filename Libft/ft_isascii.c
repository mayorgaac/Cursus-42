#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main ()
{
	char c = '和';
	printf("%d", ft_isascii(c));
	return (0);
}*/
