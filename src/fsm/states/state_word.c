/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:13:14 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/10 20:31:19 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	state_word(t_fsm *fsm, char c, t_token **tokens)
{
	if (c == ' ' || c == '\t')
	{
		create_token(fsm, tokens, 0);
		fsm->current_state = STATE_START;
		return (true);
	}
	else if (c == '|')
	{
		fsm->current_state = STATE_PIPE;
		return (false);
	}
	else if (c == '\'')
	{
		fsm->current_state = STATE_SQUOTE;
		return (true);
	}
	else if (c == '\"')
	{
		fsm->current_state = STATE_DQUOTE;
		return (true);
	}
	else
		return ((token_append_char(fsm, c), true));
}
