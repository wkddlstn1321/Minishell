/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:05:56 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	char	*get_home_path(t_ev_lst *ev_lst)
{
	t_ev_lst	*ev;
	char		*path;

	ev = get_ev("HOME", ev_lst);
	if (ev == NULL)
	{
		error("HOME", ENVP_NONE_SET_ERROR);
		return (NULL);
	}
	path = ft_strdup(ev->value);
	return (path);
}

void	cd_home(char *word, t_ev_lst *ev_lst, char **curr_path)
{
	char		*old_pwd;
	char		*home_path;

	home_path = get_home_path(ev_lst);
	to_ascii(home_path);
	if (home_path == NULL)
		return ;
	old_pwd = ft_strdup(*curr_path);
	if (ft_strlen(home_path) != 0)
		while (word != NULL && *(++word) != '\0')
			home_path = ft_strjoin_char(home_path, *word);
	exec_chdir(home_path, old_pwd, ev_lst, curr_path);
	free(home_path);
}
