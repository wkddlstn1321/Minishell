/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:35 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:14:35 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_file_name(void)
{
	static int	idx;
	char		*nbr;
	char		*str;

	nbr = ft_itoa(idx);
	str = ft_strdup(".tmp_file_");
	if (nbr == NULL || str == NULL)
	{
		free(nbr);
		free(str);
		error(NULL, 0);
		return (NULL);
	}
	str = ft_strjoin(str, nbr);
	if (str == NULL)
	{
		error(NULL, 0);
		return (NULL);
	}
	idx++;
	return (str);
}

void	print_gnl(char *end_sig, int fd, int flag)
{
	char	*str;

	while (1)
	{
		write(1, "> ", 2);
		str = get_next_line(0);
		if (str == NULL || !(ft_strncmp(end_sig, str, ft_strlen(end_sig))))
			break ;
		if (flag)
			ft_putstr_fd(str, fd);
		free(str);
	}
	free(str);
}

int	heredoc_child_proc(t_redir_lst *rl, char *end_sig, int flag, char *tmp)
{
	int	fd;

	set_signal_term(SIG_DUP, ECHO_ON);
	end_sig = ft_strjoin_char(end_sig, '\n');
	fd = open(tmp, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (end_sig == NULL || fd < 0)
	{
		error(NULL, 0);
		free(end_sig);
		rl->filename = NULL;
		exit (1);
	}
	print_gnl(end_sig, fd, flag);
	close(fd);
	free(tmp);
	exit(0);
}

int	heredoc_single(t_redir_lst	*redir_lst)
{
	char	*end_sig;
	int		status;
	pid_t	pid;

	end_sig = redir_lst->filename;
	redir_lst->filename = get_file_name();
	if (redir_lst->filename == NULL)
		return (-1);
	pid = fork();
	if (pid == 0)
		heredoc_child_proc(redir_lst, end_sig, 1, redir_lst->filename);
	else
	{
		set_signal(SIG_IGNORE);
		waitpid(pid, &status, 0);
		free(end_sig);
		set_signal_term(SIG_DEF, ECHO_OFF);
		if (WIFSIGNALED(status))
		{
			g_status = WTERMSIG(status) + 128;
			return (-1);
		}
	}
	return (0);
}
