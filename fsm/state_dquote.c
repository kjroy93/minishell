/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_dquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:23:45 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/22 15:11:03 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	state_dquote(t_fsm *fsm, char c)
{
	if (c == '\"')
	{
		end_word(fsm);
		fsm->current_state = STATE_WORD;
	}
	else
		fsm->line[fsm->line_i++] = c;
}
