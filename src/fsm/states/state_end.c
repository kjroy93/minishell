/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:15:30 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/12 19:44:39 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	state_end(t_fsm *fsm, char c, t_token **tokens)
{
	if (c == '\0' || c == '\n')
	{
		create_token(fsm, tokens, 0);
		fsm->prev_state = fsm->current_state;
		fsm->current_state = STATE_END;
	}
	return (true);
}
