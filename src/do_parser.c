/*
** do_parser.c for lem-in in /home/schmou_a/Progelem/CPE_2014_lemin/src
**
** Made by schmou_a
** Login   <schmou_a@epitech.net>
**
** Started on  Thu Apr 23 10:36:19 2015 schmou_a
** Last update Sat May  2 11:03:12 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "my_graph.h"

t_room		*build_room(char *name, int x, int y, int nb_ants)
{
  t_room	*ret;

  if ((ret = gbgc_calloc(sizeof(t_room))) == NULL)
    return (NULL);
  if ((ret->name = my_strdup(name)) == NULL)
    return (NULL);
  ret->x = x;
  ret->y = y;
  ret->nb_ants = nb_ants;
  return (ret);
}

int	tab_len(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

int	is_room(char *input)
{
  if (input == NULL)
    return (FALSE);
  return (TRUE);
}
