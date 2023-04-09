/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:11:44 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:05:39 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	set_terminal_attr(int opt)
{
	struct termios	termios;

	if (opt == ECHO_OFF)
	{
		tcgetattr(STDIN_FILENO, &termios);
		termios.c_lflag &= ~ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &termios);
		return (0);
	}
	else if (opt == ECHO_ON)
	{
		tcgetattr(STDIN_FILENO, &termios);
		termios.c_lflag |= ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &termios);
		return (0);
	}
	return (0);
}
