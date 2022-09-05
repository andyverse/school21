#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_d;
	char	*ptr_s;

	if ((dst || src) && (src != dst))
	{
		ptr_d = (char *)dst;
		ptr_s = (char *)src;
		if (ptr_d < ptr_s)
			while (len--)
				*ptr_d++ = *ptr_s++;
		else
			while (len--)
				*(ptr_d + len) = *(ptr_s + len);
	}
	return (dst);
}
