/*
** do_ant.c for lemin in /home/guigui/working/CPE_2014_lemin/lib_src
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Sun May  3 19:00:59 2015 guigui
** Last update Sun May  3 19:01:30 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "listes.h"

t_tre	*get_to_end(t_tre *start)
{
  t_tre	*ret;

  ret = start;
  while (ret->parent != NULL)
    ret = ret->parent;
  return (ret);
}

void	aff_tre(t_mls *ptr)
{
  t_tre *item;

  item = ptr->item;
  my_printf("Salle \"%s\", nb_fourmis: %d\n", item->data, item->nb_ants);
}

void	ant_move(t_tre *room, int *f, int *ant, int n)
{
  if (room == NULL || ant == NULL || f == NULL)
    return;
  my_printf("%sP%d-%s", (*f) ? "" : " ", *ant + n,
	    room->parent->data);
  room->nb_ants -= 1;
  room->parent->nb_ants += 1;
  *f = 0;
  *ant += 1;
}

void	ant_march(t_mls *end)
{
  t_tre	*room;
  t_tre	*endr;
  t_mls	*cpy;
  int	f;
  int	ant;
  int	n;

  if (end == NULL || (cpy = end->prev) == NULL || (endr = end->item) == NULL)
    return;
  f = 1;
  ant = 1;
  while (cpy != NULL)
    {
      if ((room = cpy->item) == NULL)
	return;
      n = (endr->nb_ants > 0) ? endr->nb_ants - 1 : 0;
      n += (f && endr->nb_ants > 0) ? 1 : 0;
      if (room->nb_ants > 0)
	ant_move(room, &f, &ant, n);
      cpy = cpy->prev;
    }
  my_putchar('\n');
}
