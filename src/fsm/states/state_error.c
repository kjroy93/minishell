/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:17:32 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/22 15:24:42 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	state_error(t_fsm *fsm, const char *msg)
{
	ft_putstr_fd(msg, 2);
	fsm->current_state = STATE_ERROR;
	reset_fsm(fsm);
}
