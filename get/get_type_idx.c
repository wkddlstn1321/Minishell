/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_idx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:09:54 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:10:09 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_type_idx(int	*tokens, int start_idx, int type)
{
	while (tokens[start_idx] != type && tokens[start_idx] != IS_END)
		start_idx++;
	return (start_idx);
}
