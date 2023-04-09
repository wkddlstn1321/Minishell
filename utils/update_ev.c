/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:52 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:14:53 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*validate_copy_ev(t_ev_lst *ev_lst, char *tmp)
{
	char	*string_ev;

	if (!ev_lst->equal_sign)
		return (tmp);
	tmp = ft_strjoin_char(tmp, '=');
	if (tmp == NULL)
	{
		error(NULL, 0);
		return (NULL);
	}
	string_ev = ft_join(tmp, ev_lst->value);
	free(tmp);
	if (string_ev == NULL)
	{
		error(NULL, 0);
		return (NULL);
	}
	return (string_ev);
}

static char	*copy_ev(t_ev_lst	*ev_lst)
{
	char	*tmp;

	tmp = ft_strdup(ev_lst->key);
	to_ascii(tmp);
	if (tmp == NULL)
	{
		error(NULL, 0);
		return (NULL);
	}
	return (validate_copy_ev(ev_lst, tmp));
}

static int	count_ev(t_ev_lst	*ev_lst)
{
	int	count;

	count = 0;
	while (ev_lst)
	{
		count++;
		ev_lst = ev_lst->next;
	}
	return (count);
}

char	**update_ev(t_ev_lst	*ev_lst)
{
	char	**updated_ev;
	int		count;
	int		idx;

	idx = 0;
	if (ev_lst == NULL)
		return (NULL);
	count = count_ev(ev_lst);
	updated_ev = malloc(sizeof(char *) * (count + 1));
	if (updated_ev == NULL)
		return (NULL);
	while (ev_lst)
	{
		updated_ev[idx] = copy_ev(ev_lst);
		if (updated_ev[idx++] == NULL)
			return (ft_free_split(updated_ev));
		ev_lst = ev_lst->next;
	}
	updated_ev[idx] = NULL;
	return (updated_ev);
}
