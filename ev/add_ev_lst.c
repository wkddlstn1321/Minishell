/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ev_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:07:56 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_ev_lst(t_ev_lst **ev_lst_head, t_ev_lst *new_lst)
{
	t_ev_lst	*search;

	if (*ev_lst_head == NULL)
		*ev_lst_head = new_lst;
	else
	{
		search = *ev_lst_head;
		while (search->next != NULL)
			search = search->next;
		search->next = new_lst;
	}
}
