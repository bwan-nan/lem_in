/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:49:27 by bwan-nan          #+#    #+#             */
/*   Updated: 2019/06/17 15:49:26 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
void		print_path(t_list *room)
{
	ft_printf("PATH ID: %d\n", ((t_room *)room->content)->path_id);
	while (room)
	{
		ft_printf("%s%c"
		, ((t_room *)room->content)->name
		, ((t_room *)room->content)->next ? '-' : '\n');
		room = ((t_room *)room->content)->next;
	}
}
*/
void print_steps(t_list *room)
{
	ft_printf("Path id %d\n", ((t_room *)room->content)->path_id);
	while (room)
	{
		ft_printf("%s%c"
		, ((t_room *)room->content)->name
		, ((t_room *)room->content)->next ? '-' : '\n');
		room = ((t_room *)room->content)->next;
	}
}

void		print_paths(t_list *path)
{
	t_list	*room;

	while (path)
	{
		room = ((t_path *)path->content)->room;
		ft_printf("sent = %d\n", ((t_path *)path->content)->sent);
		print_steps(room);
		path = path->next;
	}
}
