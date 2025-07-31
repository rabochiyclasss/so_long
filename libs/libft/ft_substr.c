/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:57:37 by ibudko            #+#    #+#             */
/*   Updated: 2024/09/29 14:57:37 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	if (len > s_len - start)
		s_len = s_len - start;
	else
		s_len = len;
	substr = (char *)malloc((s_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
// #include <stdio.h>

// int main()
// {
// 	char *s = "Hello, World!";
// 	char *result = ft_substr(s, 7, 2);

// 	if (result)
// 	{
// 		printf("Подстрока: %s\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Ошибка выделения памяти.\n");
// 	}

// 	return 0;
// }
