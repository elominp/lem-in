/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Wed Apr 22 15:15:40 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "my_graph.h"

void		free_nodes(void *data)
{
  t_node	*node;

  if ((node = data) == NULL)
    return ;
  destroy_slist(node->edges, NULL);
  gbgc_free(NULL, node);
}

void		free_network(t_net *g, void(*freefunc)(void*))
{
  t_slist	*cur;

  if (g != NULL && (cur = g->nodes) != NULL)
    destroy_slist(g->nodes, freefunc);
  if (g && g->name)
    gbgc_free(NULL, g->name);
  gbgc_free(NULL, g);
}
