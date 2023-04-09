/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_outfile_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:09:49 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:09:49 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_single(t_redir_lst *redir_lst)
{
	redir_lst->fd = open(redir_lst->filename, O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (redir_lst->fd < 0)
	{
		error(NULL, 0);
		return (-1);
	}
	return (0);
}

int	open_multiple(t_redir_lst *redir_lst)
{
	redir_lst->fd = open(redir_lst->filename, O_WRONLY
			| O_CREAT | O_APPEND, 0644);
	if (redir_lst->fd < 0)
	{
		error(NULL, 0);
		return (-1);
	}
	return (0);
}

static t_redir_lst	*get_last_node(t_redir_lst *redir_lst)
{
	t_redir_lst	*tmp;
	int			error;

	tmp = NULL;
	while (redir_lst != NULL)
	{
		if (redir_lst->redir[0] == '>')
		{
			tmp = redir_lst;
			if (ft_strlen(tmp->redir) == 1)
				error = open_single(redir_lst);
			else
				error = open_multiple(redir_lst);
			if (error == -1)
				return (tmp);
		}
		redir_lst = redir_lst->next;
	}
	return (tmp);
}

int	get_outfile_fd(t_redir_lst *redir_lst)
{
	t_redir_lst	*tmp;

	tmp = get_last_node(redir_lst);
	if (tmp == NULL)
		return (0);
	else if (tmp->fd < 0)
		return (-1);
	else
		return (tmp->fd);
}
