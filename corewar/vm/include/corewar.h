/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaurent <dlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:39:39 by dlaurent          #+#    #+#             */
/*   Updated: 2018/06/29 00:42:12 by dlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

/*
** Constants dedicated to in-game conditions
*/
# define DUMP_SIZE		32
# define CYCLES_TO_DIE	1536
# define CYCLE_DELTA	50
# define NBR_LIVE		21
# define MAX_CHECKS		10

/*
** Constants dedicated to arena's structure
*/
# define MEM_SIZE		(4*1024)
# define IDX_MOD		(MEM_SIZE / 8)
# define MAX_CHAMPIONS	4

/*
** Constants dedicated to champions' structure
*/
# define CW_MAGIC		0xea83f3
# define CHAMP_MAX_SIZE	(MEM_SIZE / 6)
# define DESC_SIZE		2048
# define PROG_NAME_SIZE	128

/*
** Constants dedicated to params
*/
# define REG_IDX		1
# define REG_SIZE		4
# define REG_NUMBER		16
# define IND_SIZE		2
# define DIR_SIZE		REG_SIZE

/*
** Constants dedicated to colors
*/
# define NO_COLOR		0
# define RED			1
# define GREEN			2
# define YELLOW			3
# define BLUE			4
# define MAGENTA		5
# define CYAN			6

# include "../libft/include/libft.h"
# include <ncurses.h>

/*
** Definition of the structure containing each champion
**		prog			:	contain the program
**		number			:	player id
**		num_auto		:	boolean defining if number has been assigned auto
**		size			:	size of the program
**		color			:	color for visualisation
**		name			:	player name
**		desc			:	player description
*/
typedef struct			s_c
{
	void				*prog;
	int					number;
	int					num_auto;
	int					size;
	int					color;
	int					color_auto;
	int					lives;
	unsigned char		name[PROG_NAME_SIZE + 1];
	unsigned char		desc[DESC_SIZE + 1];
}						t_c;

/*
** Definition of the structure containing each octet
**		octet			:	contain the octet for the arena
**		owner			:	for visualisation only.
*/
typedef struct			s_o
{
	unsigned char		octet;
	t_c					*owner;
}						t_o;

/*
** Definition of the structure containing each process
**		reg				:	int array from 1 to 16 where 1 is player id
**		carry			:	/
**		to_exec			:	lives counter before exec
**		live			:	alive ?
**		mem				:	starting addr
*/
typedef struct			s_p
{
	int					reg[REG_NUMBER + 1];
	int					carry;
	int					to_exec;
	int					live;
	int					mem;
	int					instruct;
	short				need_init;
	t_c					*owner;
}						t_p;

/*
** Definition of the structure containing the arena
**		cycles			:	counter.
**								If, after CYCLES TO DIE, each processus does not
**							exec 1 'live' at least since last check, then the
**							processus is killed.
**								If, during the check, there is no more NBR_LIVE
**							execution of 'live', decrement by CYCLE_DELTA
**								If no decrement since MAX_CHECKS, then decrement
**		cycles_delta	:	cf. above
**		cycles_to_die	:	cf. above
**		last_check		:	cf. above
**		lives			:	cf. above
**		dump			:	option flag. If, after 'nbr_cycles', dump mem on fd1
**		mem				:	contain arena
**		champ			:	array containing champions
**		last_alive		:	contain the address of the last champion alive
**		pc				:	program counter. Array containing each processus
*/
typedef struct			s_a
{
	int					cycles;
	int					cycles_delta;
	int					cycles_to_die;
	int					cycles_total;
	int					checks;
	int					lives;
	int					lives_total;
	int					dump;
	int					verbose;
	int					visual;
	int					audio;
	int					hard;
	t_o					*mem[MEM_SIZE];
	t_c					**champ;
	t_c					*last_alive;
	t_p					**pc;
}						t_a;

/*
** arena.function.c	:	functions relative to arena
*/
int						count_champions(t_a *arena);
int						count_pc(t_a *arena);
void					delete_processus(t_a *arena, t_p *processus);

/*
** arena.init.c		:	initialization of arena
*/
t_a						*init_a(void);
t_a						*load_players(t_a *arena, int p);

/*
** champion.init.c	:	initialization of champions
*/
t_c						*init_c(t_a *arena, int number, int color);
char					*get_color(t_c *c, int end);

/*
** common.checks.c	:	check all constants defined in .h
*/
void					check_constants(void);

/*
** common.display.c	:	display structures for debug
*/
void					display_arena(t_a *arena);

/*
** common.error.c	:	error handler
*/
void					error(t_a *arena, int display_usage, char *msg);
void					error_champion(t_a *arena, t_c *champion,
						int display_usage, char *msg);
void					error_ocp(t_a *arena, char *ocp,
						int display_usage, char *msg);
/*
** common.memory.c	:	free memory handler
*/
void					free_arena(t_a *arena);
void					free_champion(t_c *champion);

/*
** common.usage.c	:	display usage and exit
*/
void					usage(void);

/*
** instruct.*.c		:	list of instructions
*/
void					exec_nothing(t_a *arena, t_p *processus);
void					exec_live(t_a *arena, t_p *processus);
void					exec_ld(t_a *arena, t_p *processus);
void					exec_st(t_a *arena, t_p *processus);
void					exec_add(t_a *arena, t_p *processus);
void					exec_sub(t_a *arena, t_p *processus);
void					exec_and(t_a *arena, t_p *processus);
void					exec_or(t_a *arena, t_p *processus);
void					exec_xor(t_a *arena, t_p *processus);
void					exec_zjmp(t_a *arena, t_p *processus);
void					exec_ldi(t_a *arena, t_p *processus);
void					exec_sti(t_a *arena, t_p *processus);
void					exec_fork(t_a *arena, t_p *processus);
void					exec_lld(t_a *arena, t_p *processus);
void					exec_lldi(t_a *arena, t_p *processus);
void					exec_lfork(t_a *arena, t_p *processus);
void					exec_aff(t_a *arena, t_p *processus);
int						get_exec(unsigned char mem);
int						get_dir(t_a *arena, t_p *proc, int start, int size);
int						get_ind(t_a *arena, t_p *proc, int start, int size);
int						get_reg(t_a *arena, t_p *proc, int start, int size);
int						get_reg_val(int *param, t_p *p);
char					*get_ocp(int octet);
int						is_dir(char *str, int i);
int						is_ind(char *str, int i);
int						is_reg(char *str, int i);
int						is_empty(char *str, int i);
void					init_instruct(t_a *arena, t_p *processus);
void					mv(t_p *processus, char *ocp, int lbl_size, int n);
int						get_mv(char *ocp, int i, int dir);

/*
** parser.c			:	main parsing file
*/
t_a						*parse_input(t_a *arena, char **av);

/*
** parser.champions.c:	parser dedicated to champions
*/
char					**parse_color(char **av, t_a *arena, int number);
char					**parse_num(char **av, t_a *arena, int color);
char					**parse_champion(char **av, t_a *arena, int n, int c);

/*
** parser.options.c	:	parser dedicated to options
*/
char					**parse_dump(char **av, t_a *arena);
char					**parse_verbose(char **av, t_a *arena);
char					**parse_visual(char **av, t_a *arena);
char					**parse_audio(char **av, t_a *arena);
char					**parse_hard(char **av, t_a *arena);

/*
** parser.read_file.c:	read file .cor
*/
void					read_champion(t_a *arena, t_c *champion, int fd);

/*
** solver.c			:	main solver file
*/
void					play(t_a *arena);

/*
** solver.cycles.c	:	manage cycles and checks at end of cycle
*/
void					cycles_handler(t_a *arena, int i);

/*
** solver.instruct.c:	manage the execution of instructions
*/
void					exec_instruct(t_a *arena, t_p *processus);

/*
** visual.colors.c	:	handle colors for ncurses
*/
void					init_pairs(t_a *arena);
void					select_color(t_a *arena, int i);
void					unselect_color(t_a *arena, int i);

/*
** visual.draws.c	:	handle drawings
*/
void					display_info(t_a *arena);
void					draw_borders(void);
void					draw_memory(t_a *arena);
void					draw_champions(t_a *arena);
int						draw_process(t_a *arena, int i);

/*
** visual.functions.c:	functions used for visual
*/
int						is_pc(t_a *arena, int i);
int						kbhit(void);

/*
** visual.init.c	:	init visual
*/
void					init_visual(t_a *arena);

#endif
