/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeratul <szeratul@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:05:03 by szeratul          #+#    #+#             */
/*   Updated: 2021/09/01 12:10:00 by szeratul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_error(char *arg, int errcode)
{
	if (errcode == 1)
	{
		ft_putstr_fd("command not found: ", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}

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
		free_temp(cmd);
		free_temp(path_slash);
	}
	free_paths(paths);
	print_error(args[0], 1);
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
		free_temp(cmd);
		free_temp(path_slash);
	}
	free_paths(paths);
	print_error(args[0], 1);
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
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fdin = open(argv[1], O_RDONLY);
	fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fdin < 0 || fdout < 0)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	pipex(fdin, fdout, argv, envp);
	return (EXIT_SUCCESS);
}
