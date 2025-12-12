/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:13:39 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/12 20:25:57 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	char    *input;
	t_token *tokens;
	int	i;

	i = 0;
	while (i < 10)
	{
		tokens = NULL;
		input = readline("minishell> ");
		if (!input)
			break;
		if (*input)
			add_history(input);
		entry_point(input, &tokens);
		t_token *tmp = tokens;
		while (tmp)
		{
			printf("Token: '%s' Type: %d Quote: %d\n", tmp->content, tmp->type, tmp->quote);
			tmp = tmp->next;
		}
		free(input);
		free_tokens(&tokens);
		tokens = NULL;
		i++;
	}
	printf("exit\n");
	return (0);
}
