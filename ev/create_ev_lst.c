/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ev_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:08:31 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:08:32 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ev_lst	*create_ev_lst(char *key, char *value, int equal_sign)
{
	t_ev_lst	*new_lst;

	new_lst = malloc(sizeof(t_ev_lst));
	new_lst->key = key;
	new_lst->value = value;
	new_lst->equal_sign = equal_sign;
	new_lst->next = NULL;
	return (new_lst);
}
