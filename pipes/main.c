/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:26:01 by kjroydev          #+#    #+#             */
/*   Updated: 2025/12/17 17:47:09 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
		return (run_pipex(argc, argv, envp));
	else if (argc > 5)
		return (run_pipex_bonus(argc, argv, envp));
	else
	{
		write(2, "Error: not suficient arguments\n", 32);
		return (1);
	}
}
