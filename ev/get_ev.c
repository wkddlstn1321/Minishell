/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:08:36 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:08:37 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ev_lst	*get_ev(char *input, t_ev_lst *ev_lst)
{
	char	*key;
	int		idx;

	if (input == NULL)
		return (NULL);
	while (ev_lst != NULL)
	{
		idx = 0;
		key = ev_lst->key;
		while ((key[idx] == input[idx]) && key[idx] != '\0')
			idx++;
		if (key[idx] == '\0' && input[idx] == '\0' && ev_lst->equal_sign == 1)
			return (ev_lst);
		ev_lst = ev_lst->next;
	}
	return (NULL);
}
