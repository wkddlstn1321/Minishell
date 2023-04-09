/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tilde.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:28 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:14:29 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	convert_tilde(char **split_line, t_ev_lst *ev_lst)
{
	char	*word;
	char	*home_path;

	while (*split_line != NULL)
	{
		word = *split_line;
		if (*word == '~' && (*(word + 1) == '\0' || *(word + 1) == '/'))
		{
			home_path = get_ev_value("HOME", ev_lst);
			*split_line = ft_strjoin(home_path, ft_strdup(word + 1));
			free(word);
		}
		split_line++;
	}
	return ;
}
