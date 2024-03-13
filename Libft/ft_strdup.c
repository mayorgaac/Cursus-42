
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dest;

	dest = (char *) malloc (sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
