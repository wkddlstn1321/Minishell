/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_old_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:06:00 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	exec_chdir_old_pwd(char *path, char *old_path,
		t_ev_lst *ev_lst, char **curr_path)
{
	int		chdir_result;
	char	*dir_exists_flag;

	chdir_result = chdir(path);
	if (ft_strlen(path) != 0 && chdir_result == -1)
		fail_cd(old_path, path);
	else
	{
		dir_exists_flag = getcwd(NULL, 0);
		if (dir_exists_flag == NULL)
			fail_cd(old_path, path);
		else
		{
			set_pwd(old_path, ev_lst, curr_path);
			pwd(path);
		}
		free(dir_exists_flag);
	}
	free(path);
}

static	void	cd_old_pwd(t_ev_lst *old_pwd_ev,
		t_ev_lst *ev_lst, char **curr_path)
{
	char	*old_pwd;
	char	*curr_pwd;

	old_pwd = ft_strdup(old_pwd_ev->value);
	to_ascii(old_pwd);
	if (old_pwd == NULL)
		return ;
	curr_pwd = ft_strdup(*curr_path);
	exec_chdir_old_pwd(old_pwd, curr_pwd, ev_lst, curr_path);
}

void	cd_old_path(t_ev_lst *ev_lst, char **curr_path)
{
	t_ev_lst	*ev;

	ev = get_ev("OLDPWD", ev_lst);
	if (ev == NULL)
	{
		error("OLDPWD", ENVP_NONE_SET_ERROR);
		return ;
	}
	cd_old_pwd(ev, ev_lst, curr_path);
}
