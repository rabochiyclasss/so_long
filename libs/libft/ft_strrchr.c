/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:57:06 by ibudko            #+#    #+#             */
/*   Updated: 2024/10/10 15:27:30 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == uc)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	if (uc == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
// char	*ft_strrchr(const char *s, int c)
// {
// 	unsigned char	uc;
// 	char			*last_occurrence;

// 	uc = (unsigned char)c;
// 	last_occurrence = NULL;
// 	while (*s)
// 	{
// 		if (*s == uc)
// 			last_occurrence = (char *)s;
// 		s++;
// 	}
// 	if (uc == '\0')
// 		return ((char *)s);
// 	return (last_occurrence);
// }
// #include <stdio.h>
// int main()
// {
// 	const char *str = "1234567892";
// 	char ch = '2';
// 	char *result = ft_strrchr(str, ch);
// 	if (result != NULL) {
// 		printf("Символ '%c' найден: %s\n", ch, result);
// 	} else {
// 		printf("Символ '%c' не найден\n", ch);
// 	}
// 	return 0;
// }
