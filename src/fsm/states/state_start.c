/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:34:46 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/22 17:17:28 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	state_start(t_fsm *fsm, char c)
{
	if (c == ' ' || c == '\t')
		return ;
	else if (c == '|')
		fsm->current_state = STATE_PIPE;
	else
	{
		fsm->token[fsm->i_token++] = c;
		fsm->current_state = STATE_WORD;
	}
}
