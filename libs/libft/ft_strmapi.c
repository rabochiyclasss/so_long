/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:56:55 by ibudko            #+#    #+#             */
/*   Updated: 2024/10/03 18:46:12 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	result = (char *)malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
// #include <stdio.h>
// char to_upper_with_index(unsigned int i, char c) {
// 	if (i % 2 == 0 && c >= 'a' && c <= 'z') {
// 		return (c - 32);
// 	}
// 	return (c);
// }
// int main() {
// 	char *s = "hello";
// 	char *result = ft_strmapi(s, to_upper_with_index);
// 	if (result) {
// 		printf("Результат: %s\n", result);
// 		free(result);
// 	} else {
// 		printf("Ошибка выделения памяти\n");
// 	}
// 	return 0;
// }
