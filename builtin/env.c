/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:15:20 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:15:20 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	print_env(t_ev_lst	*ev_lst)
{
	char	*tmp;

	tmp = ft_strdup(ev_lst->value);
	if (tmp == NULL)
	{
		error(NULL, 0);
		return (-1);
	}
	to_ascii(tmp);
	printf("%s=%s\n", ev_lst->key, tmp);
	free(tmp);
	return (0);
}

void	env(t_cmd_lst *cmd_lst, t_ev_lst *ev_lst)
{
	char	**word;

	word = cmd_lst->word;
	g_status = 0;
	if (*(word + 1) != NULL)
	{
		error(*(word + 1), REDIR_ERROR);
		return ;
	}
	while (ev_lst != NULL)
	{
		if (ev_lst->equal_sign == 1)
		{
			if (print_env(ev_lst) == -1)
				return ;
		}
		ev_lst = ev_lst->next;
	}
}
