/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:35 by hyna              #+#    #+#             */
/*   Updated: 2022/09/01 14:00:11 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	change_same_key(t_ev_lst *ev_lst, char *key, char *value,
					int equal_sign)
{
	int	keylen;

	keylen = ft_strlen(key);
	while (ev_lst != NULL)
	{
		if (!ft_strncmp(ev_lst->key, key, keylen + 1))
		{
			ev_lst->equal_sign |= equal_sign;
			if (equal_sign == 1)
			{
				free(ev_lst->value);
				ev_lst->value = value;
			}
			else
				free(value);
			free(key);
			return (1);
		}
		ev_lst = ev_lst->next;
	}
	return (0);
}

int	add_ev(char *word, t_ev_lst *ev_lst)
{
	t_ev_lst	*new_ev_lst;
	char		*key;
	char		*value;
	int			equal_sign;

	equal_sign = 0;
	key = get_key(word);
	if (ft_strlen(key) == 1 && *key == '_')
		return (0);
	if (key == NULL || *key == '\0')
	{
		error(word, KEY_ERROR);
		free(key);
		return (1);
	}
	value = get_value(word, &equal_sign);
	if (change_same_key(ev_lst, key, value, equal_sign) == 0)
	{
		new_ev_lst = create_ev_lst(key, value, equal_sign);
		add_ev_lst(&ev_lst, new_ev_lst);
	}
	return (0);
}
