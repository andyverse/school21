#include "libft.h"

void	*ft_bzero(void *b, size_t len)
{
	unsigned char	*ptr_b;

	ptr_b = (unsigned char *)b;
	while (len--)
		*ptr_b++ = 0;
	return (b);
}
