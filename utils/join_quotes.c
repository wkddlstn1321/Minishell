/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:39 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:14:44 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

char	*join_double_quotes(char **line, char *neat_line, t_ev_lst *ev_lst)
{
	char	c;

	while (**line != '\0' && **line != '\"')
	{
		if (**line == '$')
			neat_line = convert_to_ev(line, neat_line, ev_lst,
					DOUBLE_QUOTES_ON);
		else
		{
			c = ascii_to_non_ascii(**line, QUTOES, DOUBLE_QUOTES_ON);
			neat_line = ft_strjoin_char(neat_line, c);
		}
		(*line)++;
	}
	neat_line = ft_strjoin_char(neat_line, '\"');
	return (neat_line);
}

char	*join_single_quotes(char **line, char *neat_line)
{
	char	c;

	while (**line != '\0' && **line != '\'')
	{
		c = ascii_to_non_ascii(**line, QUTOES, SINGLE_QUOTES_ON);
		neat_line = ft_strjoin_char(neat_line, c);
		(*line)++;
	}
	neat_line = ft_strjoin_char(neat_line, '\'');
	return (neat_line);
}

char	*join_quotes(char **line, char *neat_line, t_ev_lst *ev_lst)
{
	char	quotes;

	quotes = **line;
	neat_line = ft_strjoin_char(neat_line, **line);
	(*line)++;
	if (quotes == '\"')
		neat_line = join_double_quotes(line, neat_line, ev_lst);
	else if (quotes == '\'')
		neat_line = join_single_quotes(line, neat_line);
	return (neat_line);
}
