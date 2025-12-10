/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:13:39 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/10 21:41:12 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	char    *input;
	t_token *tokens;
	int	i;

	tokens = NULL;
	while (true)
	{
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
		i++;
	}
	printf("exit\n");
	return 0;
}
