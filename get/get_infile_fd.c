/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infile_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:09:45 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:09:45 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_redir_lst	*get_last_node(t_redir_lst *redir_lst)
{
	t_redir_lst	*tmp;

	tmp = NULL;
	while (redir_lst != NULL)
	{
		if (redir_lst->redir[0] == '<')
		{
			tmp = redir_lst;
			if (ft_strlen(tmp->redir) == 1)
			{
				redir_lst->fd = open(redir_lst->filename, O_RDONLY, 0644);
				if (redir_lst->fd < 0)
				{
					g_status = 1;
					error(NULL, 0);
					return (tmp);
				}
			}
		}
		redir_lst = redir_lst->next;
	}
	return (tmp);
}

int	get_infile_fd(t_redir_lst *redir_lst)
{
	t_redir_lst	*tmp;

	tmp = get_last_node(redir_lst);
	if (get_heredoc(redir_lst) == -1)
		return (-1);
	if (tmp == NULL)
		return (0);
	else if (tmp->fd < 0)
		return (-1);
	else if (ft_strlen(tmp->redir) == 1)
		return (tmp->fd);
	tmp->fd = open(tmp->filename, O_RDONLY, 0644);
	if (tmp->fd < 0)
		error(NULL, 0);
	return (tmp->fd);
}
