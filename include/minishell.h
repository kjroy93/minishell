/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:56:36 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/10 20:20:06 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "pipex.h"
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum e_state
{
	STATE_START,
	STATE_WORD,
	STATE_SQUOTE,
	STATE_DQUOTE,
	STATE_PIPE,
	STATE_END,
	STATE_REDIRECT,
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
	char			token[256];
}	t_fsm;


/**
 * @struct s_token
 * @brief Represents the tokens and inner composition for grammatical analysis.
 * 
 * Each token can point to the next, contain a text value,
 * a token type (word, pipe, redirection, etc.) and a type of quote.
 * 
 * Composition:
 * - next = pointer to the next token.
 * 
 * - content = it contains the token string.
 * 
 * - type: (1 = word, 2 = squote, 3 = dquote, etc.).
 * 
 * - quote: type of quote (0 = no quote; 1 = squote; 2 = dquote).
 */
typedef struct s_token
{
	char			*content;
	int				type;
	int				quote;
	struct s_token	*next;
}	t_token;

void	entry_point(char *input, t_token **tokens);
t_fsm	*init_fsm(char *input);
typedef	bool(*t_state_handler)(t_fsm *, char, t_token **);
bool	state_start(t_fsm *fsm, char c, t_token **tokens);
bool	state_word(t_fsm *fsm, char c, t_token **tokens);
bool	state_squote(t_fsm *fsm, char c, t_token **tokens);
bool	state_dquote(t_fsm *fsm, char c, t_token **tokens);
bool	state_pipe(t_fsm *fsm, char c, t_token **tokens);
bool	state_end(t_fsm *fsm, char c, t_token **tokens);
bool	state_redirect(t_fsm *fsm, char c, t_token **tokens);
bool	state_var(t_fsm *fsm, char c, t_token **tokens);
bool	state_error(t_fsm *fsm, char *msg);
void	create_token(t_fsm *fsm, t_token **tokens, int quoted);
void	reset_fsm(t_fsm *fsm);

t_token	*init_token(t_fsm *fsm, int quoted);
void	token_append_str(t_fsm *fsm, const char *str);
void	token_append_char(t_fsm *fsm, const char c);
void	token_add_back(t_token **tokens, t_token *new);

#endif