#ifndef MICROSHELL_H
#define MICROSHELL_H

#include <limits.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define ERROR -1
#define CHILD 0

enum { READ, WRITE };

enum errtype { SYS, EXE, CD_ARG, CD_EXE };

#endif