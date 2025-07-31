/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:51:11 by ibudko            #+#    #+#             */
/*   Updated: 2024/10/10 16:22:42 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (!dst || !src)
		return (dst);
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (ptr2 < ptr)
		while (++i <= len)
			ptr[len - i] = ptr2[len - i];
	else
		while (len-- > 0)
			*(ptr++) = *(ptr2++);
	return (dst);
}
// #include<string.h>
// #include <stdio.h>
// int main()
// {
// 	char src[] = "Hello, World";
// 	// Перекрытие областей памяти
// 	//ft_memmove(NULL, src, 5);
// 	memmove(0,src, 5 );
// 	printf("Результат: %s\n", src);
// 	return 0;
// }
