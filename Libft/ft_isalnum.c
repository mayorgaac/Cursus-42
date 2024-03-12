
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main ()
{
	char c = '$';
	printf("%d", ft_isalnum(c));
	return (0);
}*/
