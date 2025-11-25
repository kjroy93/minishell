/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:56:36 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/25 22:54:28 by kjroydev         ###   ########.fr       */
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
	STATE_REDIRECT,
	STATE_VAR,
	STATE_ERROR,
}	t_state;

typedef struct s_fsm
{
	t_state			current_state;
	t_state			prev_state;
	size_t			i_token;
	size_t			i_input;
	size_t			counter;
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
typedef	void(*t_state_handler)(t_fsm *, char, t_token **);
void	state_start(t_fsm *fsm, char c, t_token **tokens);
void	state_word(t_fsm *fsm, char c, t_token **tokens);
void	state_squote(t_fsm *fsm, char c, t_token **tokens);
void	state_dquote(t_fsm *fsm, char c, t_token **tokens);
void	state_pipe(t_fsm *fsm, char c, t_token **tokens);
void	state_end(t_fsm *fsm, char c, t_token **tokens);
void	state_redirect(t_fsm *fsm, char c, t_token **tokens);
void	state_var(t_fsm *fsm, char c, t_token **tokens);
void	state_error(t_fsm *fsm, const char *msg);
void	end_word(t_fsm *fsm, t_token **tokens);
void	reset_fsm(t_fsm *fsm);

t_token	*init_token(char *element);
void	token_append_str(t_fsm *fsm, const char *str);
void	token_append_char(t_fsm *fsm, const char c);
void	token_add_back(t_token **tokens, t_token *new);

#endif