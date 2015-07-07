/*
** search_tree.c for search_tree in /home/alexis/rendu/B2/CPE/CPE_2014_lemin/src
**
** Made by alexis
** Login   <alexis@epitech.net>
**
** Started on  Sun May  3 18:50:25 2015 alexis
** Last update Sun May  3 18:50:25 2015 alexis
*/

#include <stdlib.h>
#include "my.h"

BOOL	exist_in_tree(t_tre *node, void *data, int (*cmp)(void *, void *))
{
  t_tre	*cpy;

  if ((cpy = node) == NULL || data == NULL || cmp == NULL)
    return (FALSE);
  while (cpy != NULL)
    {
      if (cmp(cpy->data, data))
	return (TRUE);
      cpy = cpy->parent;
    }
  return (FALSE);
}
