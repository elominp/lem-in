/*
** lid_methods1.c for lemin in /home/guigui/working/CPE_2014_lemin/src
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Sat May  2 10:48:56 2015 guigui
** Last update Sat May  2 10:51:34 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"

int	putstrlist(t_lid *this)
{
  t_mls	*cpy;

  if (this == NULL || this->file == NULL || (cpy = this->file->next) == NULL)
    return (FALSE);
  while (cpy != NULL)
    {
      my_printf("%s\n", cpy->item);
      cpy = cpy->next;
    }
  return (TRUE);
}

int	lid_file_add_line(t_lid *this, char *line)
{
  t_mls	*cpy;

  if (this == NULL || line == NULL || (cpy = this->file) == NULL)
    return (FALSE);
  while (cpy != NULL && cpy->next != NULL)
    cpy = cpy->next;
  if ((cpy->next = gbgc_malloc(NULL, sizeof(t_mls))) == NULL)
    return (FALSE);
  cpy->next->prev = cpy;
  cpy = cpy->next;
  cpy->item = line;
  cpy->next = NULL;
  return (TRUE);
}

int	lid_add_room(t_lid *this, t_room *room)
{
  t_mls	*cpy;

  if (this == NULL || room == NULL || (cpy = this->rooms) == NULL)
    return (FALSE);
  while (cpy != NULL && cpy->next != NULL)
    cpy = cpy->next;
  if ((cpy->next = gbgc_malloc(NULL, sizeof(t_mls))) == NULL)
    return (FALSE);
  cpy->next->prev = cpy;
  cpy = cpy->next;
  cpy->item = room;
  cpy->next = NULL;
  return (TRUE);
}

int	lid_add_pipe(t_lid *this, t_pip *pipe)
{
  t_mls	*cpy;

  if (this == NULL || pipe == NULL || (cpy = this->pipes) == NULL)
    return (FALSE);
  while (cpy != NULL && cpy->next != NULL)
    cpy = cpy->next;
  if ((cpy->next = gbgc_malloc(NULL, sizeof(t_mls))) == NULL)
    return (FALSE);
  cpy->next->prev = cpy;
  cpy = cpy->next;
  cpy->item = pipe;
  cpy->next = NULL;
  return (TRUE);
}

int		lid_exist_room(t_lid *this, t_room *test)
{
  t_mls		*cpy;
  t_room	*tmp;

  if (this == NULL || test == NULL || this->rooms == NULL ||
      (cpy = this->rooms->next) == NULL)
    return (FALSE);
  while (cpy != NULL)
    {
      tmp = cpy->item;
      if (!my_strcmp(test->name, tmp->name))
	return (TRUE);
      cpy = cpy->next;
    }
  return (FALSE);
}
