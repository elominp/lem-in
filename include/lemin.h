/*
** lemin.h for lemin in /home/guigui/working/CPE_2014_lemin/include
**
** Made by guigui
** Login   <guigui@epitech.net>
**
** Started on  Sat May  2 10:24:57 2015 guigui
** Last update Sun May  3 19:02:39 2015 guigui
*/

#ifndef LEMIN_H_
# define LEMIN_H_

# include "my.h"
# include "listes.h"

void	show_branchs(t_tre *);
void	show_tree(t_tre *);
char	**get_alllinkedrooms(char *, t_mls *);
int	roomcmp(void *, void *);
BOOL	build_branchs(t_tre *, t_mls *, int);
BOOL	create_childs(t_tre *, t_lid *);
t_tre	*create_lemin_tree(t_lid *);
char 	*get_start(t_mls *);
char   	*get_end(t_mls *);
BOOL	is_strstart(char *);
t_tre  	*add_start(t_tre *);
t_tre	*new_tree(void *);
BOOL	init_branchs(t_tre *);
BOOL	add_trenode(t_tre *, void *);
BOOL	delete_node(t_tre *, void (*)(void *));
BOOL	exist_in_tree(t_tre *, void *, int (*)(void *, void *));
t_tre	*get_to_end(t_tre *);
void	aff_tre(t_mls *);
void	ant_move(t_tre *, int *, int *, int);
void	ant_march(t_mls *);

#endif /* !LEMIN_H_ */
