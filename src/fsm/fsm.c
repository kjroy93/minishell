/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:48:43 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/25 22:42:04 by kjroydev         ###   ########.fr       */
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
	state_var,
	state_error,
};

static void	fsm_dispatcher(t_fsm *fsm, t_token **tokens)
{
	char	c;

	while (fsm->input[fsm->i_input] != '\0')
	{
		c = fsm->input[fsm->i_input];
		g_handlers[fsm->current_state](fsm, c, tokens);
	}
}

void	entry_point(char *input)
{
	t_fsm	*fsm;
	t_token	*tokens;
	char	c;

	tokens = NULL;
	fsm = init_fsm(input);
	if (!fsm)
		return ;
	fsm_dispatcher(fsm, &tokens);
}
