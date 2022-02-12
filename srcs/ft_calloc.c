
#include <rush.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*r;
	int		index;

	index = 0;
	r = malloc(nmemb * size);
	if (r)
	{
		while (index < nmemb * size)
		{
			r[index] = 0;
			index++;
		}
		return (r);
	}
	return (0);
}