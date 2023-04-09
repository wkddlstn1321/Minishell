/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:07:44 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	set_old_pwd(char *old_pwd, t_ev_lst *ev_lst)
{
	char	*old_pwd_key;

	old_pwd_key = ft_strdup("OLDPWD=");
	if (old_pwd_key == NULL)
		return ;
	old_pwd = ft_strjoin(old_pwd_key, old_pwd);
	add_ev(old_pwd, ev_lst);
	free(old_pwd);
}

static	void	set_curr_pwd(t_ev_lst *ev_lst, char **curr_path)
{
	char	*pwd;
	char	*pwd_key;

	pwd_key = ft_strdup("PWD=");
	if (pwd_key == NULL)
		return ;
	free(*curr_path);
	*curr_path = getcwd(NULL, 0);
	pwd = ft_strjoin(pwd_key, ft_strdup(*curr_path));
	add_ev(pwd, ev_lst);
	free(pwd);
}

void	set_pwd(char *old_pwd, t_ev_lst *ev_lst, char **curr_path)
{
	set_curr_pwd(ev_lst, curr_path);
	set_old_pwd(old_pwd, ev_lst);
}
