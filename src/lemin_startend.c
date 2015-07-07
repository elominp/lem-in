/*
** lemin_startend.c for lemin in /home/guigui/working/CPE_2014_lemin/src
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Sat May  2 10:34:47 2015 guigui
** Last update Sat May  2 10:35:54 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "listes.h"
#include "lemin.h"

char		*get_start(t_mls *list)
{
  static t_room	*start;
  t_mls		*cpy;
  t_room	*tmp;

  if (list != NULL && (cpy = list->next) != NULL)
    {
      while (cpy != NULL && (tmp = cpy->item) != NULL)
	{
	  if (tmp->type == NEST_START)
	    {
	      start = tmp;
	      return (start->name);
	    }
	  cpy = cpy->next;
	}
    }
  else if (list == NULL && start != NULL)
    return (start->name);
  return (NULL);
}

char		*get_end(t_mls *list)
{
  static t_room	*end;
  t_mls		*cpy;
  t_room	*tmp;

  if (list != NULL && (cpy = list->next) != NULL)
    {
      while (cpy != NULL && (tmp = cpy->item) != NULL)
	{
	  if (tmp->type == NEST_EXIT)
	    {
	      end = tmp;
	      return (end->name);
	    }
	  cpy = cpy->next;
	}
    }
  else if (list == NULL && end != NULL)
    return (end->name);
  return (NULL);
}

BOOL	is_strstart(char *name)
{
  char	*start;

  if (name == NULL || (start = get_start(NULL)) == NULL ||
      my_strcmp(start, name))
    return (FALSE);
  return (TRUE);
}

t_tre		*add_start(t_tre *room)
{
  static t_tre	*start;

  if (start == NULL && room != NULL)
    start = room;
  else if (start != NULL && room != NULL && is_strstart(room->data))
    start = (room->weight < start->weight) ? room : start;
  return (start);
}
