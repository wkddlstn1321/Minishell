/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:09:26 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:09:26 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	validate_path(char *command, char	**paths)
{
	char	*temp;
	int		idx;

	idx = 0;
	temp = ft_join("/", command);
	if (temp == NULL)
	{
		error(NULL, 0);
		return (-1);
	}
	while (paths[idx])
	{
		paths[idx] = ft_join(paths[idx], temp);
		if (paths[idx] == NULL)
		{
			ft_free_split(paths);
			error(NULL, 0);
			return (-1);
		}
		idx++;
	}
	free(temp);
	return (0);
}

int	exec_absolute_path(t_cmd_lst *cmd_lst, char	**ev)
{
	char	*cmd;
	char	*path;
	int		result;

	cmd = ft_strrchr(cmd_lst->word[0], '/');
	if (cmd == NULL)
		return (-1);
	cmd = ft_strdup(cmd + 1);
	if (cmd == NULL)
	{
		error(NULL, 0);
		return (1);
	}
	path = cmd_lst->word[0];
	cmd_lst->word[0] = cmd;
	result = execve(path, cmd_lst->word, ev);
	cmd_lst->word[0] = path;
	free(cmd);
	return (result);
}

int	validate_exe_cmd(t_cmd_lst *cmd_lst, char **ev)
{
	if (ft_strncmp(cmd_lst->word[0], "./", 2) == 0
		|| ft_strncmp(cmd_lst->word[0], "../", 3) == 0)
	{
		if (exec_absolute_path(cmd_lst, ev) == -1)
		{
			error(cmd_lst->word[0], REDIR_ERROR);
			return (g_status);
		}
		else
			return (0);
	}
	if (exec_absolute_path(cmd_lst, ev) != -1)
		return (0);
	return (-2);
}

char	**get_path(char	*cmd, char **ev)
{
	char	**paths;
	int		i;

	i = 0;
	if (ev == NULL)
		return (NULL);
	while (ev[i] && ft_strnstr(ev[i], "PATH", 5) == 0)
		++i;
	if (ev[i] == NULL)
		return (NULL);
	paths = ft_split(ev[i] + 5, ':');
	if (paths == 0)
	{
		error(NULL, 0);
		return (0);
	}
	if (validate_path(cmd, paths) == -1)
		return (NULL);
	return (paths);
}

int	execute_cmd(t_cmd_lst	*cmd_lst, char	**ev)
{
	char	**paths;
	int		idx;
	int		result;

	idx = 0;
	result = validate_exe_cmd(cmd_lst, ev);
	if (result != -2)
		return (result);
	paths = get_path(cmd_lst->word[0], ev);
	if (paths != NULL && *cmd_lst->word[0] != '/')
	{
		result = execve(paths[idx++], cmd_lst->word, ev);
		while (result == -1 && paths[idx])
			result = execve(paths[idx++], cmd_lst->word, ev);
	}
	ft_free_split(paths);
	if (result == 0)
		return (0);
	else
	{
		error(cmd_lst->word[0], result + 3);
		return (g_status);
	}
}
