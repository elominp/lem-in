/*
** build_lemintree.c for lemin in /home/guigui/working/CPE_2014_lemin/src
**
** Made by guigui
** Login   <guigui@epitech.net>
**
** Started on  Sat May  2 10:29:11 2015 guigui
** Last update Sat May  2 15:04:05 2015 schmou_a
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "listes.h"
#include "lemin.h"

char	**get_alllinkedrooms(char *room, t_mls *pipes)
{
  char	**tab;
  t_mls	*cpy;
  t_pip	*tmp;
  int	n;

  n = 0;
  if (room == NULL || pipes == NULL || (cpy = pipes->next) == NULL ||
      (tab = gbgc_malloc(NULL, sizeof(char *) * (n + 1))) == NULL)
    return (NULL);
  tab[0] = NULL;
  while (cpy != NULL && (tmp = cpy->item) != NULL)
    {
      if (my_strcmp(tmp->edge1, tmp->edge2) &&
	  (!my_strcmp(tmp->edge1, room) || !my_strcmp(tmp->edge2, room)))
	{
	  if ((tab = gbgc_realloc(tab, sizeof(char *) * (n + 1),
				  sizeof(char *) * (n + 2))) == NULL)
	    return (NULL);
	  tab[n] = my_strdup((my_strcmp(tmp->edge1, room)) ?
				 tmp->edge1 : tmp->edge2);
	  tab[++n] = NULL;
	}
      cpy = cpy->next;
    }
  return ((tab[0] != NULL) ? tab : NULL);
}

int	roomcmp(void *s1, void *s2)
{
  char	*t1;
  char	*t2;

  if ((t1 = s1) == NULL || (t2 = s2) == NULL || my_strcmp(s1, s2))
    return (FALSE);
  return (TRUE);
}

BOOL	build_branchs(t_tre *parent, t_mls *pipes, int stage)
{
  int	size;
  char	**rooms;
  int	i;

  if (stage >= 50)
    {
      my_printf("recursive tree too big, exit\n");
      exit(0);
    }
  if (parent == NULL || is_strstart(parent->data) ||
      (rooms = get_alllinkedrooms(parent->data, pipes)) == NULL ||
      (size = tab_length(rooms)) <= 0)
    return (FALSE);
  i = -1;
  while (++i < size && rooms[i] != NULL)
    {
      if (!exist_in_tree(parent, rooms[i], roomcmp))
	{
	  if (add_trenode(parent, rooms[i]) && parent->branchs[i] != NULL)
	    {
	      if ((build_branchs(parent->branchs[i], pipes, stage + 1)) == FALSE)
		return (FALSE);
	    }
	}
    }
  return ((rooms[i] != NULL) ? TRUE : FALSE);
}

BOOL	create_childs(t_tre *parent, t_lid *data)
{
  if (parent == NULL || data == NULL)
    return (FALSE);
  if ((build_branchs(parent, data->pipes, 0)) == FALSE)
    return (FALSE);
  return (FALSE);
}

t_tre	*create_lemin_tree(t_lid *data)
{
  t_tre	*out;
  char	*start;
  char	*end;

  if (data == NULL || (end = get_end(data->rooms)) == NULL ||
      (start = get_start(data->rooms)) == NULL ||
      (out = new_tree(end)) == NULL)
    return (NULL);
  create_childs(out, data);
  return (add_start(NULL));
}
