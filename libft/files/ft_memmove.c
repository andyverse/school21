#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t n)
{
    size_t             i;
    unsigned char   *dest1;
    unsigned char   *source1;

    if (dst == NULL && src == NULL)
        return (NULL);
    i = 1;
    dest1 = ((unsigned char *) dst);
    source1 = ((unsigned char *) src);
    if (source1 < dest1)
	{
		while (i <= n)
		{
			dest1[n - i] = source1[n - i];
			i++;
		}
	}
    else
        ft_memcpy(dest1, source1, n);
    return (dst);
}