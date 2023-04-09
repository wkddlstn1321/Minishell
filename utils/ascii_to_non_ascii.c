/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_non_ascii.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:24 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:14:25 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	ascii_to_non_ascii(char c, t_char_type type, t_quotes_status status)
{
	if (c == ' ' && type == QUTOES)
		c = SPACE_;
	else if (c == '|')
		c = PIPE;
	else if (c == '<')
		c = IN_REDIR;
	else if (c == '>')
		c = OUT_REDIR;
	else if (c == '\"' && status == SINGLE_QUOTES_ON)
		c = DOUBLE_QUOTES;
	else if (c == '\'' && status == DOUBLE_QUOTES_ON)
		c = SINGLE_QUOTES;
	else if (c == '~')
		c = TILDE;
	return (c);
}
