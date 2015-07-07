/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Wed Apr 22 15:17:02 2015 gwendal querat
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"

size_t		count_slist(t_slist *list)
{
  t_slist	*cur;
  size_t	i;

  if ((cur = list) == NULL)
    return (0);
  i = 1;
  while (cur)
    {
      ++i;
      cur = cur->next;
    }
  return (i);
}

void		print_slist(t_slist *list, void (*func)(t_slist*))
{
  t_slist	*cur;

  if ((cur = list) == NULL)
    {
      my_perror("print_slist : null list");
      return ;
    }
  while ((cur))
    {
      func(cur);
      cur = cur->next;
    }
}

t_slist	*goto_last_slist(t_slist *list)
{
  t_slist	*cur;

  if ((cur = list) == NULL)
    return (NULL);
  while (cur->next)
    cur = cur->next;
  return (cur);
}

t_slist	*goto_pos_slist(t_slist *list, size_t pos)
{
  t_slist	*cur;
  size_t	i;

  i = 0;
  if ((cur = list) == NULL)
    return (NULL);
  while (cur->next && ++i < pos)
    {
      cur = cur->next;
    }
  return (cur);
}
