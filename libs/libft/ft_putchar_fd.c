/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:51:39 by ibudko            #+#    #+#             */
/*   Updated: 2024/10/10 15:24:10 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// #include <fcntl.h>  // Для open
// int main() {
// 	int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
// 	if (fd == -1)//-1 means fail
// 	{
// 		return 1;
// 	}
// 	ft_putchar_fd('A', fd);  // Запишет символ 'A' в файл
// 	close(fd);  // Закрываем файл
// 	return 0;
// }
// int main()
// {
// 	ft_putchar_fd('A', 1);  // Выведет 'A' в стандартный вывод (stdout)
// 	return 0;
// }
