/*
** format_output.c for lemin in /home/schmou_a/Progelem/CPE_2014_lemin/src
**
** Made by schmou_a
** Login   <schmou_a@epitech.net>
**
** Started on  Wed Apr 29 10:26:46 2015 schmou_a
** Last update Sun May  3 19:03:09 2015 guigui
*/

#include <stdlib.h>
#include "listes.h"
#include "my.h"
#include "my_mem.h"
#include "lemin.h"

void    do_output(t_tre *start, t_lid *lemdata)
{
  t_mls *path_start;
  t_mls *path_end;
  t_tre *end_room;
  t_tre *tmp_list;


  if (start == NULL)
    return;
  if ((path_start = createlist(start, NULL)) == NULL)
    return;
  start->nb_ants = my_atoi(lemdata->file->next->item);
  tmp_list = start->parent;
  while (tmp_list != NULL)
    {
      if (tmp_list->parent == NULL)
	end_room = tmp_list;
      if (list_pushback(path_start, tmp_list, NULL) == MERROR)
	return;
      tmp_list = tmp_list->parent;
    }
  path_end = path_start;
  while (path_end->next != NULL)
    path_end = path_end->next;
  while (end_room->nb_ants < lemdata->nb_ants)
    ant_march(path_end);
}
