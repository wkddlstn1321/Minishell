/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:09:02 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:09:02 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_built_in(char **lst, char *cmd)
{
	int	idx;

	idx = 0;
	while (lst[idx] != NULL)
	{
		if (ft_strncmp(lst[idx], cmd, ft_strlen(cmd) + 1) == 0)
			return (idx);
		idx++;
	}
	return (-1);
}

int	execute_built_in(int bdx, t_cmd_lst *cmd_l, t_ev_lst **ev_l, char	**curr)
{
	if (bdx == IS_ECHO)
		echo(cmd_l);
	else if (bdx == IS_CD)
		cd(cmd_l, *ev_l, curr);
	else if (bdx == IS_PWD)
		pwd(*curr);
	else if (bdx == IS_EXPORT)
		export(cmd_l, *ev_l);
	else if (bdx == IS_UNSET)
		unset(cmd_l, ev_l);
	else if (bdx == IS_ENV)
		env(cmd_l, *ev_l);
	else if (bdx == IS_EXIT)
		ft_exit(cmd_l->word);
	return (g_status);
}

int	validate_exe_str(t_cmd_lst *cmd_lst)
{
	if (cmd_lst->word[0] == NULL || cmd_lst->word[0][0] == 0)
	{
		error(cmd_lst->word[0], COMMAND_ERROR);
		exit (127);
	}
	else if (ft_strncmp(".", cmd_lst->word[0], 2) == 0)
	{
		error(cmd_lst->word[0], COMMAND_ERROR);
		exit (2);
	}
	else if (ft_strncmp("..", cmd_lst->word[0], 3) == 0)
	{
		error(cmd_lst->word[0], COMMAND_ERROR);
		exit (127);
	}
	return (0);
}

void	dup2_fd(int	*redir_fd, int	*old_fd)
{
	old_fd[0] = dup(STDIN_FILENO);
	old_fd[1] = dup(STDOUT_FILENO);
	if (redir_fd[0])
	{
		dup2(redir_fd[0], STDIN_FILENO);
		close(redir_fd[0]);
	}
	if (redir_fd[1])
	{
		dup2(redir_fd[1], STDOUT_FILENO);
		close(redir_fd[1]);
	}
}

int	child_proc(t_cmd_lst *cmd_l, t_ev_lst **ev_l, int	*r_fd, char	**curr_path)
{
	int		built_idx;
	int		old_fd[2];
	char	**ev;
	char	**lst;

	lst = init_build_in();
	dup2_fd(r_fd, old_fd);
	ev = update_ev(*ev_l);
	validate_exe_str(cmd_l);
	built_idx = is_built_in(lst, cmd_l->word[0]);
	if (set_signal(SIG_DUP) == 1)
	{
		ft_free_split(ev);
		return (-1);
	}
	if (built_idx != -1)
		execute_built_in(built_idx, cmd_l, ev_l, curr_path);
	else
		g_status = execute_cmd(cmd_l, ev);
	set_fd_default(NULL, NULL, old_fd);
	ft_free_split(ev);
	ft_free_split(lst);
	return (g_status);
}
