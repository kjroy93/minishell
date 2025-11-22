/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:48:43 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/22 19:21:49 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fsm_dispatcher(t_fsm *fsm)
{
	char	c;
	
	while (fsm->input[fsm->i_input] != '\0')
	{
		c = fsm->input[fsm->i_input];
		if (fsm->current_state == STATE_START)
			state_start(fsm, c);
		else if (fsm->current_state == STATE_WORD)
			state_word(fsm, c);
		else if (fsm->current_state == STATE_SQUOTE)
			state_squote(fsm, c);
		else if (fsm->current_state == STATE_DQUOTE)
			state_dquote(fsm, c);
		else if (fsm->current_state == STATE_PIPE)
			state_pipe(fsm, c);
		else if (fsm->current_state == STATE_END)
			state_end(fsm, c);
		else if (fsm-> current_state == STATE_ERROR)
			state_error(fsm, c);
		if(c == '>' || c == '<')
			fsm_redirections(fsm);
		fsm->i_input++;
	}
}

static void fsm_redirections(t_fsm *fsm)
{
	char	c;

	c = fsm->input[fsm->i_input];
	if (c == '>')
	{
		if (fsm->input[fsm->i_input + 1] == '>')
		{
			token_append_str(fsm, ">>");
			fsm->i_input++;
		}
		else
			token_append(fsm, '>');
	}
	else if (c == '<')
	{
		if (fsm->input[fsm->i_input + 1] == '<')
		{
			token_append_str(fsm, "<<");
			fsm->i_input++;
		}
		else
			token_append(fsm, '<');
	}
	end_token(fsm);
	fsm->current_state = STATE_START;
}

t_fsm	*init_fsm(char *input)
{
	t_fsm	*fsm;

	fsm = malloc(sizeof(t_fsm));
	if (!fsm)
		return (NULL);
	ft_memset(fsm, 0, sizeof(t_fsm));
	fsm->current_state = STATE_START;
	if (input)
	{
		fsm->input = ft_strdup(input);
		if (!fsm->input)
		{
			free(fsm);
			fsm = NULL;
			return (NULL);
		}
	}
	else
		fsm->input = NULL;
	return (fsm);
}

void	entry_point(char *input)
{
	t_fsm	*fsm;
	char	c;

	fsm = init_fsm(input);
	if (!fsm)
		return ;
	fsm_dispatcher(fsm);
}
