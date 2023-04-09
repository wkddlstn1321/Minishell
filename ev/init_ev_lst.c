/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ev_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:08:58 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:08:59 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

t_ev_lst	*init_new_lst(char *ev)
{
	t_ev_lst	*new_lst;
	char		*key;
	char		*value;
	int			equal_sign;

	equal_sign = 0;
	key = get_key(ev);
	if (key == NULL)
		exit(0);
	value = get_value(ev, &equal_sign);
	if (value == NULL)
		exit(0);
	new_lst = create_ev_lst(key, value, equal_sign);
	return (new_lst);
}

t_ev_lst	*init_ev_lst(char **ev)
{
	t_ev_lst	*head;
	t_ev_lst	*new_lst;
	int			i;

	i = 0;
	head = NULL;
	while (ev[i])
	{
		new_lst = init_new_lst(ev[i]);
		add_ev_lst(&head, new_lst);
		i++;
	}
	return (head);
}
