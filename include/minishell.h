/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:56:36 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/22 19:26:23 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "pipex.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_state
{
	STATE_START,
	STATE_WORD,
	STATE_SQUOTE,
	STATE_DQUOTE,
	STATE_PIPE,
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
	size_t			i_token;
	size_t			i_input;
	struct s_ifsm	*internal;
	char			*input;
	char			*token;
}	t_fsm;

typedef struct s_token
{
	struct s_token	*next;
	char			*value;
	int				type;
}	t_token;

t_fsm	*init_fsm(char *input);
void	state_start(t_fsm *fsm, char c);
void	state_word(t_fsm *fsm, char c);
void	state_squote(t_fsm *fsm, char c);
void	state_dquote(t_fsm *fsm, char c);
void	state_pipe(t_fsm *fsm, char c);
void	state_error(t_fsm *fsm, const char *msg);
void	end_word(t_fsm *fsm);
void	reset_fsm(fsm);
void	token_append_str(t_fsm *fsm, char *string);
void	token_append(t_fsm *fsm, char c);

#endif