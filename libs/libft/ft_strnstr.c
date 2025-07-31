/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:57:02 by ibudko            #+#    #+#             */
/*   Updated: 2024/10/09 18:11:36 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	pos;
	unsigned int	i;

	if (!haystack || !needle)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	pos = 0;
	while (haystack[pos] != '\0' && (size_t)pos < len)
	{
		if (haystack[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[pos + i] == needle[i]
				&& (size_t)(pos + i) < len)
				++i;
			if (needle[i] == '\0')
				return ((char *)&haystack[pos]);
		}
		++pos;
	}
	return (0);
}
// #include <stdio.h>
// int main() {
// 	const char *str = "Hello, World!";
// 	const char *substr = "World";
// 	char *result = ft_strnstr(str, substr, 10);
// 	if (result != NULL) {
// 		printf("Подстрока найдена: %s\n", result);
// 	} else {
// 		printf("Подстрока не найдена\n");
// 	}
// 	return 0;
// }
