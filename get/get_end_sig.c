/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_end_sig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:09:30 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:09:31 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_end_sig(t_redir_lst	*redir_lst)
{
	char		*end_sig;

	while (redir_lst)
	{
		if (ft_strncmp(redir_lst->redir, "<<", 3) == 0)
			end_sig = redir_lst->filename;
		redir_lst = redir_lst->next;
	}
	return (end_sig);
}
