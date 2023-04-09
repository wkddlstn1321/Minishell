/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal_term.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:13:28 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:13:29 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	set_signal_term(int sig_opt, int term_opt)
{
	if (sig_opt != -1)
		set_signal(sig_opt);
	if (term_opt != -1)
		set_terminal_attr(term_opt);
	return (0);
}
