/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:17:32 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/11 19:37:16 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	state_error(t_fsm *fsm, char c, t_token **tokens)
{
	char	*msg;

	(void)tokens;
	if (c == '|')
		msg = "unexpected EOF while looking for extra command \n";
	else if (c == '\'' || c == '\"')
		msg = "unexpected EOF while looking for extra command \n";
	else if (c == '>' || c == '<')
		msg = "unexpected EOF while looking for file to redirect I/O \n";
	ft_putstr_fd(msg, 2);
	fsm->has_error = true;
	fsm->current_state = STATE_ERROR;
	return (false);
}
