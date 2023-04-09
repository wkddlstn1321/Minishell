/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:20 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:14:21 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	to_ascii(char *word)
{
	while (*word)
	{
		if (*word == SPACE_)
			*word = ' ';
		else if (*word == PIPE)
			*word = '|';
		else if (*word == IN_REDIR)
			*word = '<';
		else if (*word == OUT_REDIR)
			*word = '>';
		else if (*word == SINGLE_QUOTES)
			*word = '\'';
		else if (*word == DOUBLE_QUOTES)
			*word = '\"';
		else if (*word == TILDE)
			*word = '~';
		word++;
	}
}

static void	non_ascii_to_ascii(char	**words)
{
	int		idx;
	char	*word;

	idx = 0;
	while (words[idx])
	{
		word = words[idx];
		to_ascii(word);
		idx++;
	}
}

int	set_word(t_cmd_lst *cmd_lst, int *tokens)
{
	char	**word;
	int		nbrs[2];

	nbrs[START_IDX] = 0;
	nbrs[END_IDX] = 0;
	word = NULL;
	while (1)
	{
		nbrs[START_IDX] = get_type_idx(tokens, nbrs[START_IDX], IS_WORD);
		nbrs[END_IDX] = get_type_idx(tokens, nbrs[START_IDX], IS_REDIR);
		word = ft_double_strjoin(word, ft_clip_split(cmd_lst->word, nbrs));
		if (word == NULL)
		{
			error(NULL, 0);
			return (1);
		}
		nbrs[START_IDX] = nbrs[END_IDX] + 2;
		if (tokens[nbrs[END_IDX]] == IS_END)
			break ;
	}
	ft_free_split(cmd_lst->word);
	non_ascii_to_ascii(word);
	cmd_lst->word = word;
	return (0);
}
