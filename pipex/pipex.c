/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:05:03 by szeratul          #+#    #+#             */
/*   Updated: 2021/08/26 12:05:13 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_one_process(int *fd, int fdin, char **argv, char **envp)
{
	char	*cmd;
	char	*path_slash;
	char	**args;
	char	**paths;
	int		i;

	paths = parse_envp(envp);
	args = ft_split(argv[2], ' ');
	dup2(fd[1], STDOUT_FILENO);
	dup2(fdin, STDIN_FILENO);
	close(fd[0]);
	close(fdin);
	i = -1;
	while (paths[++i])
	{
		path_slash = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(path_slash, args[0]);
		if (access(cmd, X_OK) == 0)
			execve(cmd, args, envp);
		free(cmd);
		cmd = NULL;
	}
	free_paths(paths);
}

static void	child_two_process(int *fd, int fdout, char **argv, char **envp)
{
	char	*cmd;
	char	*path_slash;
	char	**args;
	char	**paths;
	int		i;

	paths = parse_envp(envp);
	args = ft_split(argv[3], ' ');
	dup2(fd[0], STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
	close(fd[1]);
	i = -1;
	while (paths[++i])
	{
		path_slash = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(path_slash, args[0]);
		if (access(cmd, X_OK) == 0)
			execve(cmd, args, envp);
		free(cmd);
		cmd = NULL;
	}
	free_paths(paths);
}

void	pipex(int fdin, int fdout, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) < 0)
		exit(1);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork 1"));
	if (pid1 == 0)
		child_one_process(fd, fdin, argv, envp);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Fork 2"));
	if (pid2 == 0)
		child_two_process(fd, fdout, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fdin;
	int	fdout;

	if (argc != 5)
	{
		perror("./pipex file1 cmd1 cmd2 file2");
		return (1);
	}
	fdin = open(argv[1], O_RDONLY);
	fdout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fdin < 0 || fdout < 0)
		return (-1);
	pipex(fdin, fdout, argv, envp);
	return (0);
}
