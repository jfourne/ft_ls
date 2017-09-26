/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:14:15 by jfourne           #+#    #+#             */
/*   Updated: 2017/01/31 16:07:59 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../Libft/include/libft.h"
# define MOUNTH		 60*60*24*30
# define ABS(value)	((value > 0) ? value : -value)

typedef struct	s_size
{
	int			size;
	int			maj_size;
	int			min_size;
	int			n_size;
	int			g_size;
	int			l_size;
}				t_size;

char			*ft_strjoin_and_clean(char *s1, char *s2);
void			open_error(char *str);
void			clean_quit(char **param, t_list **first);
void			print_mode(mode_t mode);
void			param_t(char *str, t_list **first, char *param);
void			param_l(char *str, t_list *first);
void			redim(char *str, t_list *tmp, t_size *all, int total);
void			add_color(mode_t mode, char *name, int i, int a);
void			print_with_space(int firt_nb, int nb);
void			print_names(uid_t name, gid_t gr_name, t_size all);
void			print_time_modif(time_t *file_t, int i, int a);
char			*ft_parse_param(int ac, char **av, int *i, int *j);
void			ft_lstpush_back(t_list **alst, t_list *new);
void			ft_lst_sort(t_list **alst, t_list *tmp);
void			ft_lst_sort_by_type(t_list **alst, t_list *tmp);
void			ft_lstfree(t_list **first);
t_list			*ft_lstreverse(t_list **alst);
t_list			*ft_lstjoin(t_list *first, t_list *second);
t_list			*open_list(char **av, int i, int ac, char *param);
int				ft_opendir(char *str, int a, char *param, int mult);
int				read_to_list(t_list **first, struct dirent *ret, char *param);
void			call_print(char *str, t_list **first, char *param, int a);
int				print_perror_usage(char *str, int error);

#endif
