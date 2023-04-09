/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:08:53 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:08:54 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

char	*get_value(char *ev, int *equal_sign)
{
	char	*value;
	char	c;

	value = ft_strdup("");
	while (*ev != '=' && *ev != '\0')
		ev++;
	if (*ev == '=')
	{
		*equal_sign = 1;
		ev++;
	}
	while (*ev != '\0')
	{
		c = ascii_to_non_ascii(*ev, ENVP, QUOTES_OFF);
		value = ft_strjoin_char(value, c);
		ev++;
	}
	return (value);
}
