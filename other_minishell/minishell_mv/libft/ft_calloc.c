#include "libft.h"

void	*malloc(size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
