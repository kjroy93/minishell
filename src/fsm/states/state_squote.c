/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_squote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:51:04 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/22 18:04:48 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	state_squote(t_fsm *fsm, char c)
{
	if (c == '\'')
	{
		end_word(fsm);
		fsm->current_state = STATE_WORD;
	}
	else
		fsm->token[fsm->i_token++] = c;
}
