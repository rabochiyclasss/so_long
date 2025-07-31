/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:49:10 by ibudko            #+#    #+#             */
/*   Updated: 2025/04/09 15:59:18 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}
// #include <stdio.h>
// int main() {
// 	const char *str1 = "";
// 	const char *str2 = "       2147483647";
// 	const char *str3 = "       -2147483648";
// 	printf("Строка: '%s', Число: %d\n", str1, ft_atoi(str1));
// 	printf("Строка: '%s', Число: %d\n", str2, ft_atoi(str2));
// 	printf("Строка: '%s', Число: %d\n", str3, ft_atoi(str3));
// 	printf("\n");
// 	printf("Строка: '%s', Число: %d\n", str1, atoi(str1));
// 	printf("Строка: '%s', Число: %d\n", str2, atoi(str2));
// 	printf("Строка: '%s', Число: %d\n", str3, atoi(str3));
// 	return 0;
// }
