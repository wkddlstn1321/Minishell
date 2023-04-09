/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fd_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:13:17 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:13:18 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	set_fd_default(int	*prev, int	*next, int	*old)
{
	if (prev)
		close(prev[0]);
	if (next)
		close(next[1]);
	dup2(old[0], STDIN_FILENO);
	dup2(old[1], STDOUT_FILENO);
	close(old[0]);
	close(old[1]);
	return (g_status);
}
