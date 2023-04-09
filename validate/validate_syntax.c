/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:15:11 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:15:11 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	validate_first(int	*token)
{
	if (token[0] == IS_PIPE)
	{
		error("|", SYNTAX_ERROR);
		g_status = 258;
		return (1);
	}
	else if (token[0] == IS_REDIR && token[1] == IS_END)
	{
		error("newline", SYNTAX_ERROR);
		g_status = 258;
		return (1);
	}
	else if (token[0] == IS_REDIR && token[1] == IS_PIPE)
	{
		error("|", SYNTAX_ERROR);
		g_status = 258;
		return (1);
	}
	return (0);
}

int	validate_token_value(int *token, char **split_line, int idx)
{
	int	tmp;

	tmp = 0;
	if (token[idx] != IS_WORD)
	{
		if ((token[idx] == IS_PIPE && token[idx + 1] == IS_PIPE)
			|| (token[idx] == IS_REDIR && token[idx + 1] == IS_PIPE))
		{
			error("|", SYNTAX_ERROR);
			g_status = 258;
			tmp++;
		}
		else if (token[idx] == IS_REDIR && token[idx + 1] != IS_FILE)
		{
			if (token[idx + 1] == IS_END)
				error(split_line[idx], SYNTAX_ERROR);
			else
				error(split_line[idx + 1], SYNTAX_ERROR);
			g_status = 258;
			tmp++;
		}
	}
	return (tmp);
}

int	validate_syntax(char **split_line)
{
	int	tmp;
	int	idx;
	int	*token;

	idx = 1;
	token = tokenizer(split_line);
	if (token == NULL)
		return (1);
	tmp = validate_first(token);
	while (token[idx] != IS_END && tmp == 0)
	{
		tmp += validate_token_value(token, split_line, idx);
		idx++;
	}
	free(token);
	return (tmp);
}
