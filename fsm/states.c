/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:34:46 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/21 16:00:45 by kjroydev         ###   ########.fr       */
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
		fsm->line[fsm->line_i++] = c;
		fsm->current_state = STATE_WORD;
		// logic
	}
}

void	state_word(t_fsm *fsm, char c)
{
	if (c == ' ' || c == '\t')
	{
		fsm->line[fsm->line_i] = '\0';
		fsm->line_i = 0;
		fsm->current_state = STATE_START;
		// word process
	}
	else if (c == '|')
	{
		fsm->line[fsm->line_i] = '\0';
		fsm->line_i = 0;
		fsm->current_state = STATE_PIPE;
	}
	else if (c == '\'')
	{
		fsm->line[fsm->line_i] = '\0';
		fsm->line_i = 0;
		fsm->current_state = STATE_IN_SINGLE_QUOTES;
	}
	else if (c == '\"')
	{
		fsm->line[fsm->line_i] = '\0';
		fsm->line_i = 0;
		fsm->current_state = STATE_IN_DOUBLE_QUOTES;
	}
	else
		fsm->line[fsm->line_i++] = c;
}

void	state_pipe(t_fsm *fsm, char c)
{
	//logic
	fsm->current_state = STATE_START;
}

void	state_in_single_quote(t_fsm *fsm, char c)
{
	if (c == '\'')
		fsm->current_state = STATE_WORD;
	else
		fsm->line[fsm->line_i++] = c;
}