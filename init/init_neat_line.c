/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_neat_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:10:16 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:10:17 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

char	*join_redir_pipe(char **line, char *neat_line)
{
	char	c;

	c = **line;
	neat_line = ft_strjoin_char(neat_line, ' ');
	neat_line = ft_strjoin_char(neat_line, c);
	if (*((*line) + 1) == c)
	{
		(*line)++;
		neat_line = ft_strjoin_char(neat_line, c);
	}
	neat_line = ft_strjoin_char(neat_line, ' ');
	return (neat_line);
}

char	*init_neat_line(char *line, t_ev_lst *ev_lst)
{
	char	*neat_line;

	neat_line = ft_strdup("");
	while (*line != '\0')
	{
		if (*line == '>' || *line == '<' || *line == '|')
			neat_line = join_redir_pipe(&line, neat_line);
		else if (*line == '\"' || *line == '\'')
			neat_line = join_quotes(&line, neat_line, ev_lst);
		else
		{
			if (*line == '$')
				neat_line = convert_to_ev(&line, neat_line,
						ev_lst, QUOTES_OFF);
			else
				neat_line = ft_strjoin_char(neat_line, *line);
		}
		(line)++;
	}
	return (neat_line);
}
