/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:01:07 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/12 18:24:32 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool state_redirect(t_fsm *fsm, char c, t_token **tokens)
{
    char	next;

	next = fsm->input[fsm->i_input + 1];
    if (c == '>' && next == '>')
        token_append_str(fsm, ">>", tokens);
    else if (c == '>')
        token_append_char(fsm, c, tokens);
    else if (c == '<' && next == '<')
        token_append_str(fsm, "<<", tokens);
    else if (c == '<')
        token_append_char(fsm, c, tokens);
    else
    {
        fsm->current_state = STATE_ERROR;
        state_error(fsm, c, NULL);
        return (false);
    }
    create_token(fsm, tokens, 0);
    fsm->current_state = STATE_START;
    if ((c == '>' && next == '>') || (c == '<' && next == '<'))
        fsm->i_input++;
    return (true);
}
