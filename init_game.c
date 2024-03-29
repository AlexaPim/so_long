/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ado-prad <ado-prad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:05:37 by ado-prad          #+#    #+#             */
/*   Updated: 2023/01/26 19:01:48 by ado-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/so_long.h"

int	ft_init_game(t_mlx *window)
{
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == NULL)
	{
		ft_print_error(ERROR_12"\n");
		return (1);
	}
	window->win_ptr = mlx_new_window(window->mlx_ptr, window->col * \
		PIXEL_SIZE, window->line * PIXEL_SIZE, "Yoyo, So_long");
	if (window->win_ptr == NULL)
	{
		ft_print_error(ERROR_12"\n");
		return (1);
	}
	window->movements = 0;
	ft_put_sprites(window);
	window->player = window->player_down;
	mlx_hook(window->win_ptr, 2, (1L << 0), &ft_event, window);
	mlx_hook(window->win_ptr, 17, 0, &ft_close, window);
	mlx_loop_hook(window->mlx_ptr, &ft_show_map, window);
	mlx_loop(window->mlx_ptr);
	return (0);
}

void	ft_put_sprites(t_mlx *window)
{
	ft_sprites(window, &window->player_left, "textures/player.xpm");
	ft_sprites(window, &window->player_right, "textures/player.xpm");
	ft_sprites(window, &window->player_up, "textures/player.xpm");
	ft_sprites(window, &window->player_down, "textures/player.xpm");
	ft_sprites(window, &window->wall, "textures/wall.xpm");
	ft_sprites(window, &window->collec, "textures/collect.xpm");
	ft_sprites(window, &window->exit_c, "textures/door_close.xpm");
	ft_sprites(window, &window->exit_o, "textures/door_open.xpm");
	ft_sprites(window, &window->floor, "textures/background.xpm");
}

void	ft_sprites(t_mlx *window, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(window->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{	
		ft_print_error(ERROR_13"\n");
		ft_close(window);
	}
}

int	ft_close(t_mlx *window)
{
	mlx_destroy_image(window->mlx_ptr, window->player_left);
	mlx_destroy_image(window->mlx_ptr, window->player_right);
	mlx_destroy_image(window->mlx_ptr, window->player_down);
	mlx_destroy_image(window->mlx_ptr, window->player_up);
	mlx_destroy_image(window->mlx_ptr, window->collec);
	mlx_destroy_image(window->mlx_ptr, window->exit_c);
	mlx_destroy_image(window->mlx_ptr, window->exit_o);
	mlx_destroy_image(window->mlx_ptr, window->wall);
	mlx_destroy_image(window->mlx_ptr, window->floor);
	ft_free_matrix(window->map);
	mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	exit (0);
	return (0);
}
