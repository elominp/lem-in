/*
** show_tree.c for lem_in in /home/guigui/working/CPE_2014_lemin/src
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Sat May  2 10:23:35 2015 guigui
** Last update Sat May  2 10:24:29 2015 guigui
*/

#include <stdlib.h>
#include "my.h"

void	show_branchs(t_tre *node)
{
  int	i;

  if (node == NULL)
    return;
  i = -1;
  my_printf("name = %s\n", node->data);
  if (node->parent != NULL)
    my_printf("parent = %s\n", node->parent->data);
  my_printf("weight = %d\n", node->weight);
  my_printf("===========\n");
  if (node->branchs != NULL)
    {
      while (node->branchs[++i] != NULL)
	show_branchs(node->branchs[i]);
    }
}

void	show_tree(t_tre *node)
{
  t_tre	*cpy;

  if ((cpy = node) == NULL)
    return;
  my_printf("node = %s\n", node->data);
  my_printf("weight = %d\n", node->weight);
  while (cpy->parent != NULL)
    cpy = cpy->parent;
  show_branchs(cpy);
}
