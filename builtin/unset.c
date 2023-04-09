/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:07:50 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	char	*get_unset_key(char *input)
{
	char	*key;

	key = ft_strdup("");
	if ('0' <= *input && *input <= '9')
		return (key);
	while (*input != '\0')
	{
		if (!('0' <= *input && *input <= '9')
			&& !('a' <= *input && *input <= 'z')
			&& !('A' <= *input && *input <= 'Z') && !(*input == '_'))
		{
			free(key);
			key = ft_strdup("");
			break ;
		}
		key = ft_strjoin_char(key, *input);
		input++;
	}
	return (key);
}

static	void	del_ev(char *key, t_ev_lst **ev_lst)
{
	int			i;
	t_ev_lst	*prev;
	t_ev_lst	*curr;

	i = 0;
	curr = *ev_lst;
	while (curr != NULL)
	{
		if (ft_strncmp(key, curr->key, ft_strlen(key) + 1) == 0)
		{
			if (i == 0)
				*ev_lst = curr->next;
			else
				prev->next = curr->next;
			free(curr->key);
			free(curr->value);
			free(curr);
			break ;
		}
		prev = curr;
		curr = curr->next;
		i++;
	}
}

void	unset(t_cmd_lst *cmd_lst, t_ev_lst **ev_lst)
{
	char	**word;
	char	*key;
	int		idx;

	word = (cmd_lst->word + 1);
	idx = 0;
	g_status = 0;
	while (word[idx] != NULL)
	{
		key = get_unset_key(word[idx]);
		if (key == NULL || *key == '\0')
		{
			error(word[idx], KEY_ERROR);
		}
		else
			del_ev(key, ev_lst);
		free(key);
		idx++;
	}
}
