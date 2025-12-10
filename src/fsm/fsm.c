/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:48:43 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/10 21:41:57 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_state_handler g_handlers[] = {
	state_start,
	state_word,
	state_squote,
	state_dquote,
	state_pipe,
	state_end,
	state_redirect,
};

static void	fsm_dispatcher(t_fsm *fsm, t_token **tokens)
{
	char	c;
	bool	consume;

	while (fsm->input[fsm->i_input] != '\0')
	{
		c = fsm->input[fsm->i_input];
		consume = g_handlers[fsm->current_state](fsm, c, tokens);
		if (consume)
			fsm->i_input++;
	}
	if (fsm->input[fsm->i_input] == '\0')
		create_token(fsm, tokens, 0);
}

void	entry_point(char *input, t_token **tokens)
{
	t_fsm	*fsm;

	*tokens = NULL;
	fsm = init_fsm(input);
	if (!fsm)
		return ;
	fsm_dispatcher(fsm, tokens);
}
