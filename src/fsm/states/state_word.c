/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:13:14 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/25 22:51:40 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	state_word(t_fsm *fsm, char c, t_token **tokens)
{
	if (c == ' ' || c == '\t')
	{
		end_word(fsm, tokens);
		fsm->current_state = STATE_START;
	}
	else if (c == '|')
	{
		end_word(fsm, tokens);
		fsm->current_state = STATE_PIPE;
	}
	else if (c == '\'')
	{
		end_word(fsm, tokens);
		fsm->current_state = STATE_SQUOTE;
	}
	else if (c == '\"')
	{
		end_word(fsm, tokens);
		fsm->current_state = STATE_DQUOTE;
	}
	else
		token_append_char(fsm, c);
}
