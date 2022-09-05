#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*ptr_b;
	char	*ptr_s;

	if (dst || src)
	{
		ptr_b = (char *)dst;
		ptr_s = (char *)src;
		while (len--)
			*ptr_b++ = *ptr_s++;
	}
	return (dst);
}
