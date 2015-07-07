/*
** lemindata.h for lemin in /home/guigui/working/CPE_2014_lemin/include
**
** Made by guigui
** Login   <guigui@epitech.net>
**
** Started on  Sat May  2 10:49:26 2015 guigui
** Last update Sat May  2 11:00:00 2015 guigui
*/

#ifndef LEMINDATA_H_
# define LEMINDATA_H_

# include "my.h"
# include "file.h"

int	putstrlist(t_lid *);
int	lid_file_add_line(t_lid *, char *);
int	lid_add_room(t_lid *, t_room *);
int	lid_add_pipe(t_lid *, t_pip *);
int    	lid_exist_room(t_lid *, t_room *);
int    	lid_exist_pipe(t_lid *, t_pip *);
t_lid	*construct_lid(t_lid *);
int	is_specialstr(char *);
int	tab_length(char **);
t_room 	*create_room(char *, int, int, int);
int    	createSpecialRoom(char *, t_fle *, t_lid *);
int    	createRoom(char *, t_lid *);
int	lineistube(char *);
int	readrooms(t_fle *, t_lid *);
t_fle	*openstdin();
t_pip	*create_pipe(char *, char *);
char	*get_last_line(t_mls *);
int	createpipe(t_lid *);
t_lid	*construct_lemin_data(t_lid *);
t_lid	*remove_last_line(t_lid *);
t_lid	*parsestdin();

#endif /* !LEMINDATA_H_ */
