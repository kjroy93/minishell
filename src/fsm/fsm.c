/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:48:43 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/17 18:08:09 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fsm_dispatcher(t_fsm *fsm, t_token **tokens)
{
	char					c;
	bool					consume;
	static t_state_handler	g_handlers[] = {
		state_start,
		state_word,
		state_squote,
		state_dquote,
		state_pipe,
		state_redirect,
		state_error,
		state_end,
	};

	fsm->i_len = ft_strlen(fsm->input);
	while (fsm->i_input <= fsm->i_len)
	{
		if (fsm->current_state == STATE_ERROR)
			return ;
		c = fsm->input[fsm->i_input];
		consume = g_handlers[fsm->current_state](fsm, c, tokens);
		if (consume)
			fsm->i_input++;
	}
	if (!fsm->has_error)
		state_end(fsm, '\0', tokens);
}

void	entry_point(char *input, t_token **tokens)
{
	t_fsm	*fsm;

	*tokens = NULL;
	fsm = init_fsm(input);
	if (!fsm)
		return ;
	fsm_dispatcher(fsm, tokens);
	destroy_fsm(&fsm);
}
