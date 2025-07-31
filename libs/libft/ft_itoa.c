/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:50:01 by ibudko            #+#    #+#             */
/*   Updated: 2024/09/29 14:50:01 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	else if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		len--;
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
// #include <stdio.h>
// int main()
// {
// 	char *str;
// 	str = ft_itoa(-12345);
// 	printf("%s\n", str); // Вывод: -12345
// 	free(str);	// Освобождаем память
// 	str = ft_itoa(0);
// 	printf("%s\n", str); // Вывод: 0
// 	free(str);	// Освобождаем память
// 	str = ft_itoa(12345);
// 	printf("%s\n", str); // Вывод: 12345
// 	free(str);	// Освобождаем память
// 	return 0;
// }
