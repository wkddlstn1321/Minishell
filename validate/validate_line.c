/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:15:07 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:15:07 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	change_quotes_status(char c, t_quotes_status *quotes_status)
{
	if (c == '\'')
	{
		if (*quotes_status == QUOTES_OFF)
			*quotes_status = SINGLE_QUOTES_ON;
		else if (*quotes_status == SINGLE_QUOTES_ON)
			*quotes_status = QUOTES_OFF;
	}
	else if (c == '\"')
	{
		if (*quotes_status == QUOTES_OFF)
			*quotes_status = DOUBLE_QUOTES_ON;
		else if (*quotes_status == DOUBLE_QUOTES_ON)
			*quotes_status = QUOTES_OFF;
	}
}

static	int	check_quotes_status(t_quotes_status quotes_status)
{
	if (quotes_status != QUOTES_OFF)
	{
		if (quotes_status == DOUBLE_QUOTES_ON)
			error("\"", UNCLOSED_QUOTES_ERROR);
		else if (quotes_status == SINGLE_QUOTES_ON)
			error("\'", UNCLOSED_QUOTES_ERROR);
		return (-1);
	}
	return (0);
}

static	int	special_char_error(char c)
{
	if (c == '\\')
		error("\\", SPECIAL_CHAR_ERROR);
	else if (c == ';')
		error(";", SPECIAL_CHAR_ERROR);
	return (-1);
}

int	validate_line(char *line)
{
	int				move;
	t_quotes_status	quotes_status;

	quotes_status = QUOTES_OFF;
	while (*line != '\0')
	{
		move = 1;
		if (*line == '\'' || *line == '\"')
			change_quotes_status(*line, &quotes_status);
		else if ((*line == '\\' || *line == ';')
			&& quotes_status == QUOTES_OFF)
			return (special_char_error(*line));
		else if ((*line == '>' || *line == '<' || *line == '|')
			&& quotes_status == QUOTES_OFF)
			move = check_redir_pipe(line);
		if (move == -1)
			return (-1);
		line += move;
	}
	if (check_quotes_status(quotes_status) == -1)
		return (-1);
	return (0);
}
