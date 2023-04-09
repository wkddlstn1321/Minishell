/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:09:41 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:09:41 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_heredoc(t_redir_lst *redir_lst)
{
	int			nbr;

	nbr = 0;
	while (redir_lst != NULL)
	{
		if (!ft_strncmp(redir_lst->redir, "<<", 3))
		{
			if (heredoc_single(redir_lst) == -1)
				return (-1);
			nbr++;
		}
		redir_lst = redir_lst->next;
	}
	return (0);
}
