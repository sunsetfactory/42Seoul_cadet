#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>  
# include <stdlib.h>
# include <unistd.h>   //sleep, usleep, write
# include <pthread.h>
# include <sys/time.h>  // get time of day

# define R	"\x1b[1;31m"
# define G	"\x1b[1;32m"
# define B	"\x1b[1;34m"
# define RS	"\x1b[0m"

// main return val
# define ERR		1

// table->state val
# define RUN		1
# define STOP		2

// act_msg val
# define L_FORK		4
# define R_FORK		5
# define EAT		6
# define SLEEP		7
# define THINK		8

// end_msg val
# define END_COUNT	9
# define END_STARV	10

// err_msg val
# define ERR_ARG1	11
# define ERR_ARG2	12
# define ERR_ARG3	13
# define ERR_ARG4	14
# define ERR_ARG5	15
# define ERR_ARG6	16
# define ERR_MAIN1	21
# define ERR_MAIN2	22
# define ERR_MAIN3	23
# define ERR_MAIN4	24

typedef struct s_philo
{
	int				index;			// 철학자의 번호 n
	int				last_eat_time;	// 마지막 식사 시간
	int				death_time;		// 식사를 다시 해야하는 시간
	pthread_mutex_t	*lfork;			// 본인 포크
	pthread_mutex_t	*rfork;			// 오른쪽 사람 포크
	int				lfork_idx;		// n
	int				rfork_idx;		// (n + 1) % t
	int				cnt_eat;
	int				all_ate;
	struct s_table	*table;
	pthread_mutex_t	eat_mtx;		// 철학자 뮤텍스
}	t_philo;

typedef struct s_table
{
	int				num_philo;
	int				time_die;		// 수명
	int				time_eat;		// 먹는 시간
	int				time_sleep;		// 자는 시간
	int				num_must_eat;	// 식사 횟수

	int				start_time;		// 시작 시간
	t_philo			*philo_arr;		// 철학자 들
	pthread_mutex_t	*fork_mtx_arr;	// 포크 들

	pthread_mutex_t	msg_mtx;
	pthread_mutex_t	main_mtx;

	int				state;			// 동작 상태
}	t_table;

// utils.c
int		ft_strlen(char const *str);
int		ft_atoi(char const *str);
int		get_present_time(void);
void	ft_usleep(int spend_time);

// msg.c
int		err_msg(int what);
void	msg_print(int what, t_philo *philo);

// init.c
int		init_table(t_table *table);

// routine.c
void	*routine(void *data);

// checker.c
void	*checker_death(void *data);
void	*checker_cnt(void *data);

//release_table.c
int		deallocate_all(t_table *table);

#endif
