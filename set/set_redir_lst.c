/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:13:20 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:13:20 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

t_redir_lst	*add_new_redir(char **split_str, int *nbrs)
{
	t_redir_lst	*redir_lst;

	redir_lst = malloc(sizeof(t_redir_lst));
	if (redir_lst == NULL)
	{
		error(NULL, 0);
		return (NULL);
	}
	redir_lst->redir = ft_strdup(split_str[nbrs[START_IDX]]);
	redir_lst->filename = ft_strdup(split_str[nbrs[END_IDX]]);
	if (redir_lst->redir == NULL || redir_lst->filename == NULL)
	{
		free(redir_lst->redir);
		free(redir_lst->filename);
		error(NULL, 0);
		return (NULL);
	}
	redir_lst->next = NULL;
	redir_lst->fd = 0;
	return (redir_lst);
}

int	set_redir_lst(t_cmd_lst *cmd_lst, int *tokens, int *nbrs)
{
	t_redir_lst	*redir_lst;

	redir_lst = NULL;
	while (1)
	{
		nbrs[START_IDX] = get_type_idx(tokens, nbrs[END_IDX], IS_REDIR);
		if (tokens[nbrs[START_IDX]] == IS_END)
			break ;
		nbrs[END_IDX] = nbrs[START_IDX] + 1;
		if (redir_lst == NULL)
			redir_lst = add_new_redir(cmd_lst->word, nbrs);
		else
		{
			redir_lst->next = add_new_redir(cmd_lst->word, nbrs);
			redir_lst = redir_lst->next;
		}		
		if (!redir_lst)
		{
			error(NULL, 0);
			return (1);
		}
		if (cmd_lst->redir_lst == NULL)
			cmd_lst->redir_lst = redir_lst;
	}
	return (0);
}
