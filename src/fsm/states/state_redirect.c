/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:01:07 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/25 22:05:39 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	state_redirect(t_fsm *fsm, char c)
{
	char	next;

	next = fsm->input[fsm->i_input + 1];
	if (c == '>' && next == '>')
	{
		token_append_str(fsm, ">>");
		fsm->i_input++;
	}
	else if (c == '>')
		token_append_char(fsm, c);
	else if (c == '<' && next == '<')
	{
		token_append_str(fsm, "<<");
		fsm->i_input++;
	}
	else if (c == '<')
		token_append_char(fsm, c);
	else
	{
		fsm->current_state = STATE_ERROR;
		state_error(fsm, "Syntax error near unexpected token");
		return ;
	}
	end_word(fsm);
	fsm->current_state = STATE_START;
}
