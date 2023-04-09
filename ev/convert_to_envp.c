/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:08:03 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:08:05 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*join_neat_line(char *input_key, char *neat_line,
	t_ev_lst *ev_lst, t_quotes_status quotes_status)
{
	char	*value;
	int		i;

	if (*input_key == '\0')
		neat_line = ft_strjoin_char(neat_line, '$');
	else
	{
		value = get_ev_value(input_key, ev_lst);
		if (quotes_status == DOUBLE_QUOTES_ON)
		{
			i = 0;
			while (value[i] != '\0')
			{
				neat_line = ft_strjoin_char(neat_line,
						ascii_to_non_ascii(value[i], QUTOES, QUOTES_OFF));
				i++;
			}
			free(value);
		}
		else
			neat_line = ft_strjoin(neat_line, value);
	}
	return (neat_line);
}

char	*convert_to_ev(char **line, char *neat_line, t_ev_lst *ev_lst,
		t_quotes_status quotes_status)
{
	char	*input_key;

	if (*(*line + 1) == '?')
	{
		neat_line = ft_strjoin(neat_line, ft_itoa(g_status));
		(*line)++;
	}
	else
	{
		input_key = ft_strdup("");
		while (('0' <= *(*line + 1) && *(*line + 1) <= '9')
			|| ('A' <= *(*line + 1) && *(*line + 1) <= 'Z')
			|| ('a' <= *(*line + 1) && *(*line + 1) <= 'z')
			|| (*(*line + 1) == '_'))
			input_key = ft_strjoin_char(input_key, *(++(*line)));
		neat_line = join_neat_line(input_key, neat_line,
				ev_lst, quotes_status);
		free(input_key);
	}
	return (neat_line);
}
