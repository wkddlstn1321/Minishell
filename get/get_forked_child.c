/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_forked_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:09:37 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:09:37 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	make_fd_cur(t_cmd_lst *cmd_lst, int **fd_prev, int **fd_cur)
{
	if (cmd_lst->next == NULL)
	{
		*fd_cur = NULL;
		return (0);
	}
	*fd_cur = malloc(2 * sizeof(int));
	if (*fd_cur == NULL)
	{
		error(NULL, 0);
		free(*fd_prev);
		return (-1);
	}
	pipe(*fd_cur);
	return (0);
}

void	wait_children_death(pid_t pid)
{
	pid_t	wpid;
	int		status;

	wpid = waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
		g_status = WTERMSIG(status) + 128;
	else
		g_status = WEXITSTATUS(status);
	while (wpid > 0)
		wpid = waitpid(-1, &status, 0);
	set_terminal_attr(ECHO_OFF);
	set_signal(SIG_DEF);
}

int	set_fd(t_cmd_lst	*cmd_lst, int	*prev, int	*next, int *redir_fd)
{
	redir_fd[0] = get_infile_fd(cmd_lst->redir_lst);
	redir_fd[1] = get_outfile_fd(cmd_lst->redir_lst);
	if (redir_fd[0] == -1 || redir_fd[1] == -1)
	{
		free(prev);
		free(next);
		return (-1);
	}
	set_terminal_attr(ECHO_ON);
	set_signal(SIG_IGNORE);
	if (redir_fd[0] && prev)
		close(prev[0]);
	else if (redir_fd[0] == 0 && prev)
		redir_fd[0] = prev[0];
	if (redir_fd[1] && next)
		close(next[1]);
	else if (redir_fd[1] == 0 && next)
		redir_fd[1] = next[1];
	return (0);
}

int	close_pips(int	*prev, int	*next, int	*redir_fd, int opt)
{
	(void) redir_fd;
	if (opt == CHILD)
	{
		if (next)
			close(next[0]);
	}
	else
	{
		if (prev)
			close(prev[0]);
		if (next)
			close(next[1]);
	}
	return (g_status);
}

int	get_forked_child(t_cmd_lst *cmds, t_ev_lst **evl, char	**curr_path)
{
	int			*fd_prev;
	int			*fd_cur;
	int			redir_fd[2];
	pid_t		pid;

	fd_prev = NULL;
	while (cmds != NULL)
	{
		make_fd_cur(cmds, &fd_prev, &fd_cur);
		if (set_fd(cmds, fd_prev, fd_cur, redir_fd) == -1)
			return (-1);
		pid = fork();
		if (pid == 0)
		{
			close_pips(fd_prev, fd_cur, redir_fd, CHILD);
			exit(child_proc(cmds, evl, redir_fd, curr_path));
		}
		close_pips(fd_prev, fd_cur, redir_fd, PARENT);
		cmds = cmds->next;
		if (fd_prev)
			free(fd_prev);
		fd_prev = fd_cur;
	}
	wait_children_death(pid);
	return (0);
}
