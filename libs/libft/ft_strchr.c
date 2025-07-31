/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:56:24 by ibudko            #+#    #+#             */
/*   Updated: 2024/10/10 15:25:28 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == (char)uc)
		{
			return ((char *)s);
		}
		s++;
	}
	if (uc == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
// #include <stdio.h>
// int main() {
// 	const char *str = "Hello, World!";
// 	char ch = 'T';
// 	char *result = ft_strchr(str, ch);
// 	if (result != NULL) {
// 		printf("Символ '%c' найден: %s\n", ch, result);
// 	} else {
// 		printf("Символ '%c' не найден\n", ch);
// 	}
// 	return 0;
// }
