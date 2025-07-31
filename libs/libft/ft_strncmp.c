/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:56:58 by ibudko            #+#    #+#             */
/*   Updated: 2024/09/29 14:56:58 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		i++;
	}
	if (i < n)
	{
		if (str1[i] != str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
	}
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	const char *str1 = "Hello, World!";
// 	const char *str2 = "Hello, Worl";

// 	int result = ft_strncmp(str1, str2, 13); // Сравниваем первые 7 символов

// 	printf("%d", result);
// }
