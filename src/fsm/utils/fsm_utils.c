/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:42:04 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/11 20:53:26 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	create_token(t_fsm *fsm, t_token **tokens, int quoted)
{
	t_token	*new;
	
	if (fsm->i_token == 0)
		return ;
	fsm->token[fsm->i_token] = '\0';
	new = init_token(fsm, quoted);
	if (!new)
	{
		new = NULL;
		return ;
	}
	token_add_back(tokens, new);
	fsm->i_token = 0;
	fsm->token[0] = 0;
}

void	reset_fsm(t_fsm *fsm)
{
	if (fsm->input)
	{
		free(fsm->input);
		fsm->input = NULL;
	}
	fsm->current_state = STATE_START;
	fsm->i_token = 0;
	fsm->i_input = 0;
	fsm->counter = 0;
	ft_bzero(fsm->token, 256);
}

void	destroy_fsm(t_fsm **fsm)
{
	if (!fsm || !*fsm)
		return ;
	free((*fsm)->input);
	(*fsm)->input = NULL;
	free(*fsm);
	*fsm = NULL;
}
