/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahyulee <nahyulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 00:39:22 by nahyulee          #+#    #+#             */
/*   Updated: 2023/11/04 15:39:51 by nahyulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : microshell
// Expected files   : *.c *.h
// Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill,
// exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
// --------------------------------------------------------------------------------------

// Write a program that will behave like executing a shell command
// - The command line to execute will be the arguments of this program
// - Executable's path will be absolute or relative but your program must not
// build a path (from the PATH variable for example)
// - You must implement "|" and ";" like in bash
// 	- we will never try a "|" immediately followed or preceded by nothing or
// "|" or ";"
// - Your program must implement the built-in command cd only with a path as
// argument (no '-' or without parameters)
// 	- if cd has the wrong number of argument your program should print in
// STDERR "error: cd: bad arguments" followed by a '\n'
// 	- if cd failed your program should print in STDERR "error: cd: cannot
// change directory to path_to_change" followed by a '\n' with path_to_change
// replaced by the argument to cd
// 	- a cd command will never be immediately followed or preceded by a "|"
// - You don't need to manage any type of wildcards (*, ~ etc...)
// - You don't need to manage environment variables ($BLA ...)
// - If a system call, except execve and chdir, returns an error your program
// should immediatly print "error: fatal" in STDERR followed by a '\n' and the
// program should exit
// - If execve failed you should print "error: cannot execute
// executable_that_failed" in STDERR followed by a '\n' with
// executable_that_failed replaced with the path of the failed executable (It
// should be the first argument of execve)
// - Your program should be able to manage more than hundreds of "|" even if we
// limit the number of "open files" to less than 30.

// for example this should work:
// $>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my
// microshell microshell i love my microshell
// $>

// Hints:
// Don't forget to pass the environment variable to execve

// Hints:
// Do not leak file descriptors!

#include "na_microshell.h"

size_t ft_strlen(char *str)
{
  int i = 0;

  while (str[i])
    i++;
  return (i);
}

void print_err(enum errtype e, char *str)
{
  if (e == SYS)
  {
    write(STDERR_FILENO, "error: fatal", 14);
  }
  else if (e == EXE)
  {
    write(STDERR_FILENO, "error: cannot execute ", 23);
    write(STDERR_FILENO, str, ft_strlen(str));
  }
  else if (e == CD_ARG)
  {
    write(STDERR_FILENO, "error: cd: bad arguments\n", 26);
  }
  else if (e == CD_EXE)
  {
    write(STDERR_FILENO, "error: cd: cannot change directory to ", 39);
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

int execute_pipe_command(char **argv, int i, int *fd_in, char **env)
{
  int fd[2];
  pid_t pid;

  pipe(fd);
  pid = fork();
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

int execute_last_command(char **argv, int i, int *fd_in, char **env)
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

int main(int argc, char **argv, char **env)
{
  int i;
  int exit_code = EXIT_SUCCESS;
  int fd_in = dup(STDIN_FILENO);

  while (argv[i] && argv[i + 1])
  {
    argv = &argv[i + 1];
    i = 0;

    // 있고, 구분자면 증감
    while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
      i++;

    if (strcmp(argv[0], "cd") == 0)
      sh_cd(argv, i);
    // 파이프 seq 종료조건이면.
    else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
      exit_code = execute_last_command(argv, i, &fd_in, env);
    // 파이프 seq 유지.
    else if (i != 0 && strcmp(argv[i], "|") == 0)
      exit_code = execute_pipe_command(argv, i, &fd_in, env);
  }
  close(fd_in);
  exit(exit_code);
}