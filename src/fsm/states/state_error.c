/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:17:32 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/17 18:11:15 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	state_error(t_fsm *fsm, char c, t_token **tokens)
{
	char	*msg;

	(void)c;
	(void)tokens;
	msg = "\0";
	if (fsm->current_state == STATE_PIPE)
		msg = "unexpected EOF while looking for extra command \n";
	else if (fsm->current_state == STATE_DQUOTE
		|| fsm->current_state == STATE_SQUOTE)
		msg = "unexpected EOF while looking for a quote \n";
	else if (fsm->current_state == STATE_REDIRECT)
		msg = "unexpected EOF while looking for fd to redirect I/O \n";
	ft_putstr_fd(msg, 2);
	fsm->has_error = true;
	fsm->current_state = STATE_ERROR;
	free_tokens(tokens);
	destroy_fsm(&fsm);
	return (false);
}
