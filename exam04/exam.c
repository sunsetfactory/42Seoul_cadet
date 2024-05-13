#include "exam.h"

size_t ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

void print_err(enum errtype e, char *str)
{
	if (e == SYS)
	{
		write(STDERR_FILENO, "error: fatal ", 14);
	}
	else if (e == EXE)
	{
		write(STDERR_FILENO, "error: cannot execute ", 23);
		write(STDERR_FILENO, str, ft_strlen(str));
	}
	else if (e == CD_ARG)
	{
		write(STDERR_FILENO, "error: cd: bad argments\n", 26);
	}
	else if (e == CD_EXE)
	{
		write(STDERR_FILENO, "error: cd: cannot change directroy to ", 39);
		write(STDERR_FILENO, str, ft_strlen(str));
	}
	write(STDERR_FILENO, "\n", 1);
	if (e == SYS || e == EXE)
		exit(EXIT_FAILURE);
}

int sh_cd(char **argv, int i)
{
	if (i != 2)
		print_err(CD_ARG, NULL);
	if (chdir(argv[1]) != 0)
		print_err(CD_EXE, argv[1]);
	return (EXIT_SUCCESS);
}

void ft_exe(char **argv, int i, int *fd_in, char **env)
{
	argv[i] = NULL;
	dup2(*fd_in, STDIN_FILENO);
	close(*fd_in);
	if (execve(argv[0], argv, env) == ERROR)
		print_err(EXE, argv[0]);
	exit(EXIT_FAILURE);
}

int excute_last_command(char **argv, int i, int *fd_in, char **env)
{
	int status;
	int exit_code = EXIT_SUCCESS;
	pid_t pid = fork();

	if (pid == CHILD)
		ft_exe(argv, i, fd_in, env);
	else
	{
		close(*fd_in);
		while (waitpid(-1, &status, NULL) != ERROR)
			exit_code = WEXITSTATUS(status);
		*fd_in = dup(STDIN_FILENO);
	}
	return (exit_code);
}

int execute_pipe_command(char **argv, int i, int *fd_in, char **env)
{
	int fd[2];
	pid_t pid;

	pipe(fd);
	if (pid == CHILD)
	{
		dup2(fd[WRITE], STDOUT_FILENO);
		close(fd[WRITE]);
		close(fd[READ]);
		ft_exe(argv, i, fd_in, env);
	}
	else
	{
		close(fd[WRITE]);
		close(*fd_in);
		*fd_in = fd[READ];
	}
}

int main(int argc, char **argv, char **env)
{
	int i;
	int exit_code = EXIT_SUCCESS;
	int fd_in = dup(STDIN_FILENO);

	i = 0;
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
		{
			i++;
		}

		if (strcmp(argv[0], "cd") == 0)
			sh_cd(argv, i);
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
			exit_code = excute_last_command(argv, i, &fd_in, env);
		else if (i != 0 && strcmp(argv[i], "|") == 0)
			exit_code = excute_pipe_command(argv, i, &fd_in, env);
	}
	close(fd_in);
	exit(exit_code);
}