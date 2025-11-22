/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:23:22 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/22 14:49:59 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	state_pipe(t_fsm *fsm, char c)
{
	if (c == '|')
	{
		fsm->line[fsm->line_i] = '\0';
		fsm->line_i = 0;
	}
	fsm->current_state = STATE_START;
}
