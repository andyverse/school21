
#include "../minishell.h"

// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*str;

// 	str = (unsigned char *) s;
// 	while (n--)
// 		*str++ = 0;
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*ptr;

// 	ptr = malloc(count * size);
// 	if (ptr)
// 		ft_bzero(ptr, count * size);
// 	return (ptr);
// }

// void *ft_calloc(size_t n, size_t size)
// {
//  char   *s;
//  size_t   total;
//  size_t   i;

//  if (size && SIZE_MAX / size < n)
//   return (NULL);
//  total = n * size;
//  s = malloc(total);
//  if (s == NULL)
//   return (NULL);
//  i = 0;
//  while (total--)
//  {
//   s[i] = 0;
//   i++;
//  }
//  return (s);
// }