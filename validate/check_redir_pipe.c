/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:57 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:14:58 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	syntax_error(char c, int nbr)
{
	char	*str;

	str = ft_strdup("");
	if (nbr > 2)
		nbr = 2;
	while (nbr--)
		str = ft_strjoin_char(str, c);
	error(str, SYNTAX_ERROR);
	free(str);
}

int	check_redir_pipe(char *str)
{
	int		nbr;
	char	c;
	int		move;

	nbr = 0;
	c = *str;
	move = 0;
	while (*str == c)
	{
		nbr++;
		str++;
		move++;
	}
	if ((c == '<' || c == '>') && nbr > 2)
	{
		syntax_error(c, nbr - 2);
		return (-1);
	}
	else if (c == '|' && nbr > 1)
	{
		syntax_error(c, 1);
		return (-1);
	}
	return (move);
}
