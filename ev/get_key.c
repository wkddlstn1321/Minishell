/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:08:48 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:08:49 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

char	*get_key(char *ev)
{
	char	*key;

	key = ft_strdup("");
	if ('0' <= *ev && *ev <= '9')
		return (key);
	while (*ev != '=' && *ev != '\0')
	{
		if (!('0' <= *ev && *ev <= '9') && !('a' <= *ev && *ev <= 'z')
			&& !('A' <= *ev && *ev <= 'Z') && !(*ev == '_'))
		{
			free(key);
			key = ft_strdup("");
			break ;
		}
		key = ft_strjoin_char(key, *ev);
		ev++;
	}
	return (key);
}
