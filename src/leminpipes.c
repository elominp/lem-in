/*
** leminpipes.c for lemin in /home/guigui/working/CPE_2014_lemin/src
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Sat May  2 10:56:51 2015 guigui
** Last update Sat May  2 10:57:37 2015 guigui
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "file.h"
#include "my_mem.h"
#include "lemindata.h"

t_fle	*openstdin()
{
  t_fle	*stdin;

  if ((stdin = gbgc_malloc(NULL, sizeof(t_fle))) == NULL)
    return (NULL);
  stdin->name = my_strdup("stdin");
  stdin->fmode = O_RDONLY;
  stdin->fd = 0;
  stdin->csr = 0;
  stdin->status = NEOF;
  stdin->state = NOT_FLUSHED;
  return (stdin);
}

t_pip	*create_pipe(char *edge1, char *edge2)
{
  t_pip	*out;

  if (edge1 == NULL || edge2 == NULL ||
      (out = gbgc_malloc(NULL, sizeof(t_pip))) == NULL ||
      (out->edge1 = my_strdup(edge1)) == NULL ||
      (out->edge2 = my_strdup(edge2)) == NULL)
    return (NULL);
  return (out);
}

char	*get_last_line(t_mls *list)
{
  t_mls	*cpy;

  if ((cpy = list) == NULL)
    return (NULL);
  while (cpy->next != NULL)
    cpy = cpy->next;
  return (my_strdup(cpy->item));
}

int	createpipe(t_lid *data)
{
  t_pip	*pipe;
  char	**tab;
  char	*line;

  if (data == NULL || (line = get_last_line(data->file)) == NULL)
    return (FALSE);
  if (line[0] == '#')
    return (TRUE);
  if ((tab = my_strtok(line, "-")) == NULL || tab_length(tab) != 2 ||
      (pipe = create_pipe(tab[0], tab[1])) == NULL ||
      data->existPipe(data, pipe))
    return (FALSE);
  data->addPipe(data, pipe);
  gbgc_free(NULL, line);
  free_strtab(tab);
  return (TRUE);
}
