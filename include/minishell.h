/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:56:36 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/22 15:18:27 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "pipex.h"

typedef enum e_state
{
	STATE_START,
	STATE_WORD,
	STATE_SQUOTE,
	STATE_DQUOTE,
	STATE_PIPE,
	STATE_REDIRECT_IN,
	STATE_REDIRECT_OUT,
	STATE_APPEND,
	STATE_HEREDOC,
	STATE_END,
	STATE_ERROR,
}	t_state;

typedef struct s_ifsm
{
	t_state		current;
	int			counter;
}	t_ifsm;

typedef struct s_fsm
{
	t_state			current_state;
	t_state			prev_state;
	char			input;
	char			*line;
	int				line_i;
	struct s_ifsm	*internal;
}	t_fsm;

typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*next;
}	t_token;

void	end_word(t_fsm *fsm);

#endif