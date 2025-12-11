/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:15:30 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/11 21:42:00 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	state_end(t_fsm *fsm, char c, t_token **tokens)
{
	if (c == '\0' || c == '\n')
	{
		if (fsm->i_token > 0 && fsm->input[fsm->i_input] != '\0')
			create_token(fsm, tokens, 0);
		fsm->current_state = STATE_END;
		reset_fsm(fsm);
	}
	return (true);
}
