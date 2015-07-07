/*
** create_room.c for lemin in /home/guigui/working/CPE_2014_lemin/src
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Sat May  2 10:53:55 2015 guigui
** Last update Sun May  3 15:56:33 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "lemindata.h"
#include "my_mem.h"

t_room		*create_room(char *name, int x, int y, int type)
{
  t_room	*out;

  if (name == NULL || (out = gbgc_malloc(NULL, sizeof(t_room))) == NULL)
    return (NULL);
  out->name = name;
  out->x = x;
  out->y = y;
  out->type = type;
  return (out);
}

int		createSpecialRoom(char *line, t_fle *stdin, t_lid *data)
{
  t_room	*room;
  char		*name;
  int		x;
  int		y;
  int		type;
  char		**tab2;

  if (line == NULL || stdin == NULL || data == NULL)
    return (FALSE);
  if (!my_strcmp(line, "##start") || !my_strcmp(line, "##end"))
    type = (!my_strcmp(line, "##start")) ? NEST_START : NEST_EXIT;
  else
    return (FALSE);
  if ((line = gnl_querat_g(0)) == NULL)
    return (FALSE);
  data->addFileLine(data, line);
  if ((tab2 = my_strtok(line, " ")) == NULL || tab_length(tab2) != 3)
    return (FALSE);
  name = my_strdup(tab2[0]);
  x = my_atoi(tab2[1]);
  y = my_atoi(tab2[2]);
  if ((room = create_room(name, x, y, type)) == NULL ||
      data->existRoom(data, room))
    return (FALSE);
  data->addRoom(data, room);
  free_strtab(tab2);
  return (TRUE);
}

int		createRoom(char *line, t_lid *data)
{
  t_room	*room;
  char		*name;
  int		x;
  int		y;
  char		**tab;

  if (line == NULL || data == NULL || (tab = my_strtok(line, " ")) == NULL ||
      tab_length(tab) != 3)
    return (FALSE);
  name = my_strdup(tab[0]);
  x = my_atoi(tab[1]);
  y = my_atoi(tab[2]);
  if ((room = create_room(name, x, y, 0)) == NULL ||
      data->existRoom(data, room))
    return (FALSE);
  data->addRoom(data, room);
  free_strtab(tab);
  return (TRUE);
}

int	lineistube(char *line)
{
  char	**tab;
  int	i;

  if (line == NULL || (tab = my_strtok(line, "-")) == NULL)
    return (FALSE);
  i = -1;
  while (tab[++i] != NULL);
  return ((i == 2) ? TRUE : FALSE);
}

int	readrooms(t_fle *stdin, t_lid *data)
{
  char	*line;

  if (data == NULL || stdin == NULL || (line = gnl_querat_g(0)) == NULL)
    return (FALSE);
  data->addFileLine(data, line);
  if (!(data->nb_ants = my_atoi(line)))
    return (FALSE);
  while ((line = gnl_querat_g(0)) != NULL)
    {
      data->addFileLine(data, line);
      if (is_specialstr(line))
	{
	  if (!createSpecialRoom(line, stdin, data))
	    return (FALSE);
	}
      else if (lineistube(line))
	return (TRUE);
      else if (line[0] != '#')
	{
	  if (!createRoom(line, data))
	    return (FALSE);
	}
    }
  return (FALSE);
}
