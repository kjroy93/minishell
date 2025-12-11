/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:04:05 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/11 21:05:48 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_handler(t_fsm *fsm, const char *line)
{
	char	*extra;
	char	*new_input;
	size_t	len;

	extra = readline(line);
	if (!extra)
	{
		fsm->current_state = STATE_ERROR;
		state_error(fsm, '\"', NULL);
		return ;
	}
	len = ft_strlen(fsm->input) + ft_strlen(extra) + 2;
	new_input = malloc(len);
	if (!new_input)
	{
		free(extra);
		return ;
	}
	ft_strlcpy(new_input, fsm->input, len);
	ft_strlcat(new_input, extra, len);
	ft_strlcat(new_input, "\n", len);
	free(fsm->input);
	free(extra);
	fsm->input = new_input;
	fsm->i_input = 0;
}

void	default_state(t_fsm *fsm)
{
	fsm->current_state = STATE_START;
	fsm->counter = 0;
	fsm->i_token = 0;
}
