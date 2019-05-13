/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khtran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 05:20:09 by khtran            #+#    #+#             */
/*   Updated: 2018/06/24 01:44:17 by khtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# define ERROR_NOT_NBR "Error : Not a natural number\n"
# define ERROR_EMPTY "Error : Empty string\n"
# define ERROR_PARSER "Error : Bad command\n"
# define ERROR_MALLOC "Error : Malloc failed\n"
# define ERROR_ROOM "Error : Room already exist\n"
# define ERROR_NOROOM "Error : Room does not exist\n"
# define ERROR_PLACED "Error : Cant move this room\n"
# define ERROR_NOSTART "Error : No start or end\n"
# define ERROR_SAME "Error : Cant make a pipe to the same room\n"
# define MAX_SOL -1
# define BONUS_AUTO 0
# define BONUS_R 0
# define BONUS_W 0
# define BONUS_S 0

typedef struct		s_room
{
	char			*name;
	int				status;
	int				x;
	int				y;
	t_list			*chemin;
	struct s_room	*next;
}					t_room;

typedef struct		s_env
{
	int				nbr_ant;
	int				mode;
	int				b_room;
	int				b_way;
	int				b_stats;
	int				trigger;
	t_room			*m_start;
	t_room			*m_end;
	t_room			*room;
	char			*input;
	int				cur_sol;
	int				max_sol;
}					t_env;

typedef struct		s_solve
{
	int				min_sol;
	int				max_entry;
	int				cur_entry;
	int				entry;
	int				len;
}					t_solve;

int					ft_isall(char *line, int (is_thing)(int elem), int mode);
int					ft_isstr(int elem, char *symbol);
int					ft_count_occur(char *line, int elem, int occur);
int					ft_count_char(char *line, int elem);
int					lem_in_check_pos(char *line, int *index, int mode);
int					lem_in_check_room(char *line);
int					lem_in_check_pipe(char *line);
int					lem_in_nbrant(char *line, t_env *env);
void				room_lstadd(t_room **alst, t_room *newe);
int					lem_in_build_room(char *line, t_env *env);
int					lem_in_build_pipe(char *line, t_env *env);
int					lem_in_room_exist(char *line, char *dest, t_env *env,
		int mode);
t_room				*lem_in_find_room(char *name, t_env *env);
int					lem_in_find_pos(char *line, int x, int y, t_env *env);
int					lem_in_parser(char *line, t_env *env);
void				lem_in_freeway(t_list *list);
void				lem_in_freeroom(t_room *room);
void				lem_in_solve(t_env *env);
void				lem_in_solution_process(t_list **way, t_env *env);
int					lem_in_comb_compare(t_list **cur_comb, t_list *to_add);
void				lem_in_add(t_list **all_comb, t_list *cur_comb);
void				lem_in_del_last(t_list **comb);
t_list				*lem_in_list_in_list(t_list *maillon);
int					lem_in_comb_recursive_set(t_solve *data, t_list
		**all_comb, t_list **way);
void				lem_in_comb_free(t_list **all_comb);
void				ft_lstfree_safecontent(t_list *to_free);
void				lem_in_add_nodup(t_list **all_comb, t_list *cur_comb);
void				lem_in_way_best(t_list **way, t_env *env);
int					ft_intdif(int a, int b);
t_list				*ft_lstbef(t_list *base, t_list *cur);
t_list				*ft_lstmin_chain(t_list *comb);
int					ft_lstmax(t_list *comb);
int					ft_lsttotal(t_list *list);
void				lem_in_print_ant(char *name, int ant, t_list *tmp);
void				lem_in_print_one_way(t_env *env);
void				lem_in_all_room(t_room *room);
int					ft_strncmp(const char *s1, const char *s2, int max);
void				lem_in_info(t_env *env, t_list *way);
void				lem_in_all_room(t_room *room);

#endif
