/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:21:23 by kjroydev          #+#    #+#             */
/*   Updated: 2025/11/25 23:37:19 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*init_token(char *element, t_fsm *fsm)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->next = NULL;
	token->value = NULL;
	token->type = fsm->current_state; //check
	if (element)
	{
		token->value = ft_strdup(element);
		if (!token->value)
		{
			free(token);
			token = NULL;
			return (NULL);
		}
	}
	return (token);
}

t_token	token_add_back(t_token **tokens, t_token *new)
{
	t_token	*temp;

	if (!tokens || new)
		return ;
	if (*tokens == NULL)
	{
		*tokens = new;
		return ;
	}
	temp = *tokens;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	token_append_str(t_fsm *fsm, const char *str)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		fsm->token[fsm->i_token] = str[i];
		fsm->i_token++;
		i++;
	}
}

void	token_append_char(t_fsm *fsm, const char c)
{
	fsm->token[fsm->i_token++] = c;
}
