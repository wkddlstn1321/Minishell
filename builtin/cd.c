/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:05:39 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fail_cd(char *path, char *value)
{
	error(value, CD_ERROR);
	free(path);
}

void	cd_path(char *word, t_ev_lst *ev_lst, char **curr_path)
{
	char	*old_pwd;
	char	*path;

	path = word;
	old_pwd = ft_strdup(*curr_path);
	exec_chdir(path, old_pwd, ev_lst, curr_path);
}

void	cd(t_cmd_lst *cmd_lst, t_ev_lst *ev_lst, char **curr_path)
{
	char	**word;

	word = cmd_lst->word + 1;
	if (*word == NULL)
		cd_home(*word, ev_lst, curr_path);
	else if (**word == '-' && *(*word + 1) == '\0')
		cd_old_path(ev_lst, curr_path);
	else
		cd_path(*word, ev_lst, curr_path);
}
