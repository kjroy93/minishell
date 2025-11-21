/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroydev <kjroydev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:06:15 by kmarrero          #+#    #+#             */
/*   Updated: 2025/11/21 14:31:32 by kjroydev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pipex(t_pipex *data, int argc, char **argv, char **envp)
{
	data->envp = envp;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		data->heredoc = 1;
		data->infile = NULL;
		data->outfile = argv[argc - 1];
		ft_memset(data->pipe_fd, 0, sizeof(data->pipe_fd));
		get_commands_here_doc(argc, argv, data);
	}
	else
	{
		data->heredoc = 0;
		data->infile = argv[1];
		data->outfile = argv[argc - 1];
		ft_memset(data->pipe_fd, 0, sizeof(data->pipe_fd));
		get_commands(argc, argv, data);
	}
}

int	run_pipex_bonus(int argc, char **argv, char **envp)
{
	t_pipex	*data;
	int		exit_code;

	data = malloc(sizeof(t_pipex));
	if (!data)
	{
		perror("malloc for data structure not done");
		return (1);
	}
	init_pipex(data, argc, argv, envp);
	if (open_files(data) == 1)
	{
		cmd_free(&data->cmds);
		free(data);
		return (1);
	}
	exit_code = pater_familias_bonus(data);
	if (data->heredoc)
		unlink(".heredoc_tmp");
	free_pipex(data);
	return (exit_code);
}
