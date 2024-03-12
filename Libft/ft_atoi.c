#include "libft.h"

int	ft_atoi(const char *str)
{
	int	s;
	int	val;

	s = 1;
	val = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		s = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (ft_isdigit(*str))
	{
		val = val * 10 + (*str - '0');
		str++;
	}
	val *= s;
	return (val);
}
