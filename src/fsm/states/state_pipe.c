/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:23:22 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/11 21:22:04 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	state_pipe(t_fsm *fsm, char c, t_token **tokens)
{
	size_t	tmp;

	token_append_char(fsm, c);
	create_token(fsm, tokens, 0);
	tmp = fsm->i_input + 1;
	while (fsm->input[tmp] == ' ' || fsm->input[tmp] == '\t')
		tmp++;
	if (fsm->input[tmp] == '\0')
	{
		error_handler(fsm, "pipe> ");
		free_tokens(tokens);
		*tokens = NULL;
		return (false);
	}
	fsm->current_state = STATE_START;
	return (true);
}
