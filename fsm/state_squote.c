/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_squote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:51:04 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/22 15:16:00 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	state_squote(t_fsm *fsm, char c)
{
	if (c == '\'')
	{
		end_word(fsm);
		fsm->current_state = STATE_WORD;
	}
	else
		fsm->line[fsm->line_i++] = c;
}
