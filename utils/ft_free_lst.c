/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:32 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:14:32 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	ft_free_redir_lst(t_redir_lst *redir_lst)
{
	t_redir_lst	*tmp;

	while (redir_lst)
	{
		if (ft_strncmp("<<", redir_lst->redir, 3) == 0)
			unlink(redir_lst->filename);
		free(redir_lst->redir);
		free(redir_lst->filename);
		if (redir_lst->fd != 0)
			close(redir_lst->fd);
		tmp = redir_lst;
		redir_lst = redir_lst->next;
		free(tmp);
	}
}

char	*ft_free_lst(t_cmd_lst *cmd_lst)
{
	t_cmd_lst	*tmp;

	while (cmd_lst)
	{
		tmp = cmd_lst;
		ft_free_split(tmp->word);
		ft_free_redir_lst(tmp->redir_lst);
		cmd_lst = cmd_lst->next;
		free(tmp);
	}
	return (NULL);
}
