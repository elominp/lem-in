/*
** build_tree.c for build_tree in /home/alexis/rendu/B2/CPE/CPE_2014_lemin/src
**
** Made by alexis
** Login   <alexis@epitech.net>
**
** Started on  Sun May  3 18:49:07 2015 alexis
** Last update Sun May  3 18:49:07 2015 alexis
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "lemin.h"

t_tre	*new_tree(void *data)
{
  t_tre	*tree;

  if ((tree = gbgc_malloc(NULL, sizeof(t_tre))) == NULL)
    return (NULL);
  tree->parent = NULL;
  tree->data = data;
  tree->nb_ants = 0;
  tree->weight = 0;
  tree->branchs = NULL;
  return (tree);
}

BOOL	init_branchs(t_tre *tree)
{
  if (tree == NULL || (tree->branchs == NULL &&
		       (tree->branchs =
			gbgc_malloc(NULL, sizeof(t_tre *))) == NULL))
    return (FALSE);
  tree->branchs[0] = NULL;
  return (TRUE);
}

BOOL	add_trenode(t_tre *tree, void *data)
{
  int	i;

  if (tree == NULL || data == NULL ||
      (tree->branchs == NULL && !init_branchs(tree)))
    return (FALSE);
  i = -1;
  while (tree->branchs[++i] != NULL);
  if ((tree->branchs = gbgc_realloc(tree->branchs, sizeof(t_tre *) * (i + 1),
				    sizeof(t_tre *) * (i + 2))) == NULL ||
      (tree->branchs[i] = gbgc_malloc(NULL, sizeof(t_tre))) == NULL)
    return (FALSE);
  tree->branchs[i]->parent = tree;
  tree->branchs[i]->data = my_strdup((char *)data);
  tree->branchs[i]->weight = tree->weight + 1;
  tree->branchs[i]->branchs = NULL;
  tree->branchs[i]->nb_ants = 0;
  tree->branchs[i + 1] = NULL;
  if (is_strstart(tree->branchs[i]->data))
    add_start(tree->branchs[i]);
  return (TRUE);
}

BOOL	delete_node(t_tre *node, void (*delete)(void *))
{
  int	i;

  if (node == NULL)
    return (FALSE);
  if (node->data != NULL && delete != NULL)
    delete(node->data);
  else if (node->data != NULL)
    gbgc_free(NULL, node->data);
  if (node->branchs != NULL)
    {
      i = -1;
      while (node->branchs[++i] != NULL)
	delete_node(node->branchs[i], delete);
    }
  gbgc_free(NULL, node);
  return (TRUE);
}
