/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:50:55 by ibudko            #+#    #+#             */
/*   Updated: 2024/09/29 14:50:55 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char	*p;
	unsigned char		byte;

	p = (const unsigned char *)ptr;
	byte = (unsigned char)value;
	while (num--)
	{
		if (*p == byte)
		{
			return ((void *)p);
		}
		p++;
	}
	return (NULL);
}
// #include <stdio.h>
// int main()
// {
// 	char data[] = "Hello, World!";
// 	char ch = ',';
// 	char *result = my_memchr(data, ch, 6);
// 	if (result != NULL)
// 	{
// 		printf("Символ '%c' найден: %s\n", ch, result);
// 	}
// 	else
// 	{
// 		printf("Символ '%c' не найден\n", ch);
// 	}

// 	return 0;
// }
