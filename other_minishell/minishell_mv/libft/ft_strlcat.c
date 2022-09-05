#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)

{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	dstlen = 0;
	if (size > 0)
	{
		i = ft_strlen(dst);
		dstlen = i;
		if (i > size)
			dstlen = size;
		j = 0;
		while (i < size - 1 && src[j] != 0)
			dst[i++] = src[j++];
		dst[i] = 0;
	}
	return (dstlen + ft_strlen(src));
}
