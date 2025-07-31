/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:56:35 by ibudko            #+#    #+#             */
/*   Updated: 2024/10/06 15:57:28 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
	{
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
// #include <stdio.h>

// void to_upper(unsigned int i, char *c) {
// 	(void)i;  // Индекс нам не нужен в этом примере

// 	if (*c >= 'a' && *c <= 'z') {
// 		*c -= 32;
// 	}
// }

// int main() {
// 	char str[] = "hello, world!";

// 	ft_striteri(str, to_upper);  // Применяем функцию к каждому символу строки
// 	printf("Transformed string: %s\n", str);  // Выведет: "HELLO, WORLD!"

// 	return 0;
// }
