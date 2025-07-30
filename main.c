/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibudko <ibudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:26:37 by ibudko            #+#    #+#             */
/*   Updated: 2025/07/29 17:47:12 by ibudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib-linux/mlx.h"
#include <stdlib.h>

// void	*mlx_new_window(void *mlx_ptr, int ssize_x, int size_y, char *title);

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "hi:)");
	if (!win_ptr)
		return (free(mlx_ptr), 1);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);

}
