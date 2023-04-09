/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_parent_built.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:09:22 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:09:23 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_parent_built(t_cmd_lst *lst)
{
	if (lst->next != NULL || lst->word[0] == NULL || lst->word[0][0] == 0)
		return (0);
	if (ft_strncmp("cd", lst->word[0], ft_strlen(lst->word[0]) + 1) == 0)
		return (IS_CD);
	if (ft_strncmp("export", lst->word[0], ft_strlen(lst->word[0]) + 1) == 0)
		return (IS_EXPORT);
	if (ft_strncmp("exit", lst->word[0], ft_strlen(lst->word[0]) + 1) == 0)
		return (IS_EXIT);
	if (ft_strncmp("unset", lst->word[0], ft_strlen(lst->word[0]) + 1) == 0)
		return (IS_UNSET);
	return (0);
}

static int	set_fd(t_cmd_lst *cmd_lst, int *prev, int *next, int *old)
{
	int	redir_fd[2];

	redir_fd[0] = get_infile_fd(cmd_lst->redir_lst);
	redir_fd[1] = get_outfile_fd(cmd_lst->redir_lst);
	if (redir_fd[0] == -1 || redir_fd[1] == -1)
	{
		free(prev);
		free(next);
		return (-1);
	}
	old[0] = dup(STDIN_FILENO);
	old[1] = dup(STDOUT_FILENO);
	if (redir_fd[0])
		dup2(redir_fd[0], STDIN_FILENO);
	else if (prev)
		dup2(prev[0], STDIN_FILENO);
	if (redir_fd[1])
		dup2(redir_fd[1], STDOUT_FILENO);
	else if (next)
		dup2(next[1], STDOUT_FILENO);
	return (0);
}

int	exec_parent_built(int bdx, t_cmd_lst *cmd_l, t_ev_lst **ev_l, char	**cur)
{
	int		*fd_prev;
	int		*fd_cur;
	int		old_fd[2];

	fd_prev = NULL;
	make_fd_cur(cmd_l, &fd_prev, &fd_cur);
	if (set_fd(cmd_l, fd_prev, fd_cur, old_fd) == -1)
		return (-1);
	if (bdx == IS_CD)
		cd(cmd_l, *ev_l, cur);
	else if (bdx == IS_EXPORT)
		export(cmd_l, *ev_l);
	else if (bdx == IS_EXIT)
		ft_exit(cmd_l->word);
	else if (bdx == IS_UNSET)
		unset(cmd_l, ev_l);
	set_fd_default(fd_prev, fd_cur, old_fd);
	return (0);
}
