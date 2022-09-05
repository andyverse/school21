#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	char	*ptr_s;
	char	ch;

	ptr_s = (char *)src;
	ch = (unsigned char)c;
	while (len--)
	{
		if (*ptr_s == ch)
			return (ptr_s);
		ptr_s++;
	}
	return (0);
}
