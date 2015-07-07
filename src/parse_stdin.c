/*
** parse_stdin.c for lem_in in /home/guigui/working/CPE_2014_lemin/src
**
** Made by guigui
** Login   <guigui@epitech.net>
**
** Started on  Mon Apr 27 14:08:39 2015 guigui
** Last update Sat May  2 10:59:58 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "listes.h"
#include "my_mem.h"
#include "lemindata.h"

t_lid	*construct_lemin_data(t_lid *data)
{
  if (data == NULL ||
      (data->file = createlist(NULL, NULL)) == NULL ||
      (data->rooms = createlist(NULL, NULL)) == NULL ||
      (data->pipes = createlist(NULL, NULL)) == NULL)
    return (NULL);
  data->affFile = putstrlist;
  data->addFileLine = lid_file_add_line;
  data->addRoom = lid_add_room;
  data->addPipe = lid_add_pipe;
  data->existRoom = lid_exist_room;
  data->existPipe = lid_exist_pipe;
  return (data);
}

t_lid	*remove_last_line(t_lid *data)
{
  t_mls	*cpy;

  if (data == NULL || (cpy = data->file) == NULL)
    return (NULL);
  if (data->file->next == NULL)
    return (data);
  while (cpy->next->next != NULL)
    cpy = cpy->next;
  gbgc_free(NULL, cpy->next->item);
  gbgc_free(NULL, cpy->next);
  cpy->next = NULL;
  return (data);
}

t_lid	*parsestdin()
{
  t_lid	*data;
  char	*str;
  t_fle	*stdin;

  if ((data = gbgc_malloc(NULL, sizeof(t_lid))) == NULL ||
      (data = construct_lemin_data(data)) == NULL ||
      (stdin = openstdin()) == NULL)
    return (NULL);
  if (!readrooms(stdin, data))
    return (remove_last_line(data));
  while ((str = gnl_querat_g(0)) != NULL)
    {
      if (!createpipe(data))
	return (remove_last_line(data));
      data->addFileLine(data, str);
    }
  if (!createpipe(data))
    return (remove_last_line(data));
  return (data);
}
