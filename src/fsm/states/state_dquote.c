/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_dquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:23:45 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/25 23:26:20 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_handler(t_fsm *fsm)
{
	char	*extra;
	char	*new_input;
	size_t	len;

	extra = readline("quote> ");
	if (!extra)
	{
		fsm->current_state = STATE_ERROR;
		state_error(fsm, "unexpected EOF while looking for quote '");
		return ;
	}
	len = ft_srlen(fsm->input) + ft_strlen(extra) + 2;
	new_input = malloc(len);
	if (!new_input)
	{
		free(extra);
		return ;
	}
	ft_strlcpy(new_input, fsm->input, len);
	ft_strlcat(new_input, extra, len);
	ft_strlecat(new_input, "\n", len);
	free(fsm->input);
	free(extra);
	fsm->input = new_input;
	fsm->i_input = 0;
}

void	state_dquote(t_fsm *fsm, char c, t_token **tokens)
{
	if (c == '\"')
	{
		fsm->current_state = STATE_WORD;
		end_word(fsm, tokens);
	}
	else if (c == '\0')
	{
		error_handler(fsm);
		return ;
	}
	else
		token_append_char(fsm, c);
}
