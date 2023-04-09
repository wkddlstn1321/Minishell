/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorted_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:07:31 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ev_lst	*copy_lst(t_ev_lst *ev_lst)
{
	t_ev_lst	*new_lst;
	t_ev_lst	*prev;
	t_ev_lst	*head;

	head = NULL;
	while (ev_lst != NULL)
	{
		new_lst = malloc(sizeof(t_ev_lst));
		new_lst->key = ev_lst->key;
		new_lst->value = ev_lst->value;
		new_lst->equal_sign = ev_lst->equal_sign;
		new_lst->next = ev_lst->next;
		if (head == NULL)
			head = new_lst;
		else
			prev->next = new_lst;
		prev = new_lst;
		ev_lst = ev_lst->next;
	}
	return (head);
}

void	swap_lst(t_ev_lst **curr, t_ev_lst **search)
{
	t_ev_lst	*tmp;

	tmp = malloc(sizeof(t_ev_lst));
	tmp->key = (*curr)->key;
	tmp->value = (*curr)->value;
	tmp->equal_sign = (*curr)->equal_sign;
	(*curr)->key = (*search)->key;
	(*curr)->value = (*search)->value;
	(*curr)->equal_sign = (*search)->equal_sign;
	(*search)->key = tmp->key;
	(*search)->value = tmp->value;
	(*search)->equal_sign = tmp->equal_sign;
	free(tmp);
}

t_ev_lst	*init_sorted_lst(t_ev_lst *ev_lst)
{
	t_ev_lst	*curr;
	t_ev_lst	*search;
	int			key_len;
	t_ev_lst	*new_lst;

	new_lst = copy_lst(ev_lst);
	curr = new_lst;
	while (curr != NULL)
	{
		search = curr->next;
		while (search != NULL)
		{
			key_len = ft_strlen(curr->key);
			if (ft_strncmp(curr->key, search->key, key_len) > 0)
				swap_lst(&curr, &search);
			search = search->next;
		}
		curr = curr->next;
	}
	return (new_lst);
}
