/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ev_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:08:41 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:08:42 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_ev_value(char *input, t_ev_lst *ev)
{
	char	*key;
	int		idx;

	if (input == NULL)
		return (NULL);
	while (ev != NULL)
	{
		idx = 0;
		key = ev->key;
		while ((key[idx] == input[idx]) && key[idx] != '\0')
			idx++;
		if (key[idx] == '\0' && input[idx] == '\0')
			return (ft_strdup(ev->value));
		ev = ev->next;
	}
	return (ft_strdup(""));
}
