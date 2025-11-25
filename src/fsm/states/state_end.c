/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:15:30 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/25 17:46:39 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	state_end(t_fsm *fsm, char c)
{
	if (c == '\0' || c == '\n')
	{
		if (fsm->i_token > 0)
			end_word(fsm);
		fsm->current_state = STATE_END;
		reset_fsm(fsm);
	}
}
