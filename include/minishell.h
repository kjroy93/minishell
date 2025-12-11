/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:56:36 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/11 21:06:09 by kjroydev         ###   ########.fr       */
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
	STATE_REDIRECT,
	STATE_ERROR,
	STATE_END,
}	t_state;

/**
 * @struct s_fsm
 * @brief Final State Machine that controls the input offered by the user.
 * This analyze the string given of the shell and convert them into tokens,
 * that will be interpreted by the lexer. 
 * 
 * Composition:
 * 
 * - current_state = the state of the FSM at the moment in actual character.
 * 
 * - prev_state = previous state of FSM to control quotes and special status.
 * 
 * - i_token = inner index of the token (buffer control)
 * 
 * - i_input = inner inxed of the input (buffer control)
 * 
 * - counter = number that represent another value of interest in the FSM.
 * 
 * - input = user entry allocated with readline function
 * 
 * - token = constructed buffer to save the user input. The token is created
 * from it's content.
 */
typedef struct s_fsm
{
	t_state			current_state; /**< Current state of FSM. */
	t_state			prev_state; /**< Previous state of FSM. */
	size_t			i_token; /**< Inner index of buffer. */
	size_t			i_input; /**< Inner state of user input. */
	size_t			counter; /**< Aux counter of the FSM. */
	bool			has_error;
	char			*input; /**< User input (readline). */
	char			token[256]; /**< Buffer to construct tokens. */
}	t_fsm;

/**
 * @struct s_token
 * @brief Represents the tokens and inner composition for analysis.
 * 
 * Each token can point to the next, contain a text value,
 * a token type (word, pipe, redirection, etc.) and a type of quote.
 * 
 * Composition:
 * 
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
	char			*content; /**< Token to be interpreted. */
	int				type; /**< Type of the content (determined by enum). */
	int				quote; /**< Quote type. */
	struct s_token	*next; /**< Next token. */
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
bool	state_error(t_fsm *fsm, char c, t_token **tokens);
void	error_handler(t_fsm *fsm, const char *line);
void	default_state(t_fsm *fsm);
void	create_token(t_fsm *fsm, t_token **tokens, int quoted);
void	reset_fsm(t_fsm *fsm);
void	destroy_fsm(t_fsm **fsm);

t_token	*init_token(t_fsm *fsm, int quoted);
void	token_append_str(t_fsm *fsm, const char *str);
void	token_append_char(t_fsm *fsm, const char c);
void	token_add_back(t_token **tokens, t_token *new);
void	free_tokens(t_token **tokens);

#endif