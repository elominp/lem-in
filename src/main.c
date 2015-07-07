/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Sat May  2 16:08:23 2015 schmou_a
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "my_graph.h"
#include "lemin.h"
#include "lemindata.h"

void		print_nodes_ptrs(t_slist *cur)
{
  t_node	*data;

  if ((data = cur->data) == NULL)
    return ;
  my_printf("list %p data connected to node which id is %d, at adress %p\n",
	    cur, data->id, data);
}

void		print_nodes(t_slist *cur)
{
  t_node	*node;
  t_slist	*node_edges;

  if ((node = cur->data) == NULL)
    {
      my_perror("print_nodes : null list");
      return ;
    }
  my_printf("\nprinting node !\n"
	    "adress of the node : %p\n"
	    "id of the node     : %d\n",
	    node, node->id);
  node_edges = cur->data;
  node_edges = node_edges;
  print_slist(node_edges, &print_nodes_ptrs);
  my_putchar('\n');
}

int	main(int ac, char **av)
{
  t_lid *lemdata;
  t_tre	*start;

  av = av;
  if (ac != 1)
    {
      my_printf("Usage: ./lem_in < data to stdin\n");
      return (0);
    }
  gbgc_init();
  if ((lemdata = parsestdin()) == NULL)
    return (my_perror("Either a malloc has failed or there is\
an incorrect number of ants. Exiting.\n"));
  if ((start = create_lemin_tree(lemdata)) == NULL)
    return (my_perror("error, there isn't a start\n"));
  lemdata->affFile(lemdata);
  do_output(start, lemdata);
  gbgc_erase(NULL);
  return (0);
}
