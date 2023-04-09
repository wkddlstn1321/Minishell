/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_chdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:06:31 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_chdir(char *path, char *pwd, t_ev_lst *ev_lst, char **curr_path)
{
	char	*dir_exists_flag;

	if (chdir(path) == -1)
		fail_cd(pwd, path);
	else
	{
		dir_exists_flag = getcwd(NULL, 0);
		if (dir_exists_flag == NULL)
			fail_cd(pwd, path);
		else
			set_pwd(pwd, ev_lst, curr_path);
		free(dir_exists_flag);
	}
}
