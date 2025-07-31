/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:55:52 by ibudko            #+#    #+#             */
/*   Updated: 2024/10/10 15:01:38 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
// #include <fcntl.h>  // Для open
// int main() {
// 	int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
// 	if (fd == -1)//-1 means fail
// 	{
// 		return 1;
// 	}
// 	char *str = "fefgjfjgmjf";
// 	ft_putstr_fd(str , fd);  // Запишет символ 'A' в файл
// 	close(fd);  // Закрываем файл

// 	return 0;
// }
