/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:57:44 by ibudko            #+#    #+#             */
/*   Updated: 2024/10/06 16:06:47 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}
//#include <stdio.h>
// int main() {
//	 char ch = 'B';
//	 char upper = ft_toupper(ch);

//	 printf("Исходный символ: %c\n", ch);
//	 printf("Символ в верхнем регистре: %c\n", upper);

//	 return 0;
// }
