/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_squote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:51:04 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/12 18:25:59 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	state_squote(t_fsm *fsm, char c, t_token **tokens)
{
	if (c == '\'')
	{
		fsm->prev_state = fsm->current_state;
		fsm->counter++;
		if (fsm->counter == 2)
		{
			fsm->current_state = STATE_WORD;
			create_token(fsm, tokens, 1);
			fsm->counter = 0;
		}
		return (true);
	}
	else if (c == '\0')
	{
		error_handler(fsm, "quote> ");
		free_tokens(tokens);
		default_state(fsm);
		return (false);
	}
	else
	{
		token_append_char(fsm, c, tokens);
		return (true);
	}
}
