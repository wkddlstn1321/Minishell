/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:14:42 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:14:49 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*ft_arrjoin(int *arr, int newnbr, int count)
{
	int	*new_arr;
	int	i;

	i = 0;
	new_arr = malloc(sizeof(int) * (count + 1));
	if (new_arr == NULL)
		return (NULL);
	while (i < count)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = newnbr;
	if (arr)
		free(arr);
	return (new_arr);
}

int	*tokenizer(char **str)
{
	int	idx;
	int	*tmp;

	idx = 0;
	tmp = 0;
	while (str[idx])
	{
		if (str[idx][0] == '|')
			tmp = ft_arrjoin(tmp, IS_PIPE, idx);
		else if (str[idx][0] == '<' || str[idx][0] == '>')
			tmp = ft_arrjoin(tmp, IS_REDIR, idx);
		else if (idx != 0 && tmp[idx - 1] == IS_REDIR)
			tmp = ft_arrjoin(tmp, IS_FILE, idx);
		else
			tmp = ft_arrjoin(tmp, IS_WORD, idx);
		idx++;
	}
	tmp = ft_arrjoin(tmp, IS_END, idx);
	return (tmp);
}
