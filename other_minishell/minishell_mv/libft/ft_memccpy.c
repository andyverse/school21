#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	char	*ptr_d;
	char	*ptr_s;
	char	ch;

	if (d || s)
	{
		ptr_d = (char *)d;
		ptr_s = (char *)s;
		ch = (unsigned char)c;
		while (n--)
		{
			if (*ptr_s == ch)
			{
				*ptr_d = *ptr_s;
				return (ptr_d + 1);
			}
			*ptr_d++ = *ptr_s++;
		}
	}
	return (0);
}
