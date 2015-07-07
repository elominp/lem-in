/*
** lid_methods2.c for lemin in /home/guigui/working/CPE_2014_lemin/src
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Sat May  2 10:52:09 2015 guigui
** Last update Sat May  2 11:40:02 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "lemindata.h"

int    	lid_exist_pipe(t_lid *this, t_pip *test)
{
  t_mls	*cpy;
  t_pip	*tmp;

  if (this == NULL || test == NULL || this->pipes == NULL ||
      (cpy = this->pipes->next) == NULL)
    return (FALSE);
  while (cpy != NULL)
    {
      tmp = cpy->item;
      if (!my_strcmp(test->edge1, tmp->edge1) &&
	  !my_strcmp(test->edge2, tmp->edge2))
	return (TRUE);
      cpy = cpy->next;
    }
  return (FALSE);
}

t_lid	*construct_lid(t_lid *lid)
{
  if (lid == NULL || (lid->file = createlist(NULL, NULL)) == NULL ||
      (lid->rooms = createlist(NULL, NULL)) == NULL ||
      (lid->pipes = createlist(NULL, NULL)) == NULL)
    return (NULL);
  lid->affFile = putstrlist;
  lid->addFileLine = lid_file_add_line;
  lid->addRoom = lid_add_room;
  lid->addPipe = lid_add_pipe;
  lid->existRoom = lid_exist_room;
  lid->existPipe = lid_exist_pipe;
  return (lid);
}

int	is_specialstr(char *line)
{
  if (line == NULL)
    return (FALSE);
  return (((my_strlen(line) > 2) && line[0] == '#' && line[1] == '#') ? TRUE :
	  FALSE);
}

int	tab_length(char **tab)
{
  int	i;

  i = -1;
  if (tab != NULL)
    while (tab[++i] != NULL);
  return (i);
}
