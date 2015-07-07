/*
** my.h for libmy in /home/schmou_a/Progelem/corewar/corewar/include
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Apr 12 21:16:45 2015 adrien schmouker
** Last update Sat May  2 15:07:02 2015 schmou_a
*/

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>
#include "file.h"
#include "listes.h"

# define BOOL		char
# define MAX		214748364
# define BUFFER_SIZE	32000
# define MEOF		0
# define NEOF		1
# define BUFF		1024
# define TRUE		1
# define FALSE		0
# define NEST_START	2
# define NEST_EXIT     	3

struct s_gnl
{
  char	buff[BUFFER_SIZE + 1];
  t_fle	*fd;
  int	csr;
  int	status;
};

struct	s_room
{
  char	*name;
  int	x;
  int	y;
  int   nb_ants;
  int	type;
};

struct	s_pip
{
  char	*edge1;
  char	*edge2;
};

struct	s_lid
{
  t_mls	*file;
  t_mls	*rooms;
  t_mls	*pipes;
  int	nb_ants;
  int	(*affFile)(struct s_lid *);
  int	(*addFileLine)(struct s_lid *, char *);
  int	(*addRoom)(struct s_lid *, struct s_room *);
  int	(*addPipe)(struct s_lid *, struct s_pip *);
  int	(*existRoom)(struct s_lid *, struct s_room *);
  int	(*existPipe)(struct s_lid *, struct s_pip *);
};

struct		s_tre
{
  struct s_tre	*parent;
  void	*data;
  int	nb_ants;
  int	weight;
  struct s_tre	**branchs;
};

typedef struct s_gnl t_gnl;
typedef struct s_room t_room;
typedef struct s_pip t_pip;
typedef struct s_lid t_lid;
typedef struct s_tre t_tre;

char	*my_strdup(char *);
char	*my_strndup(char *, size_t);
int	my_verifc(char *, int);
int	tab_len(char **tab);
int	my_is_prime(int);
char	*my_strnbr(int, char *);
void	my_fill_tab(char, char **, int);
void	my_clean_tab(char **, int);
char	**my_str_to_wordtab(char *);
int	my_show_wordtab(char **);
int	*the_litlest(int *, int, int);
void	my_print_b_16(unsigned long, int);
int	my_printf(const char *, ...);
void	my_show_row(char *, int, int);
void	my_putchar(char );
int	my_isneg(int);
int	my_put_nbr(int);
void	my_swap(void *, void *);
int	my_putstr(char *);
int	my_strlen(char *);
int	my_getnbr(char *);
void	my_sort_int_tab(int *, int);
int	my_power_rec(int, int);
int	my_power_it(int, int);
int	my_squar_root(int);
int	my_is_prime(int);
int	my_find_prime_sup(int);
int	my_get_nbr(int);
int	my_putnbr_base(long, char *);
int	my_putnbr_base2(long, char *);
int	my_getnbr_base(char *, char *);
char	*my_strcpy(char *, char *);
char	*my_strncpu(char *, char *, int);
char	*my_revstr(char *);
char	*my_strstr(char *, char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strupcase(char *);
char	*my_strlowcase(char *);
char	*my_strcapitalize(char *);
int	my_str_isalpha(char *);
int	my_str_isnum(char *);
int	my_str_islower(char *);
int	my_str_isupper(char *);
int	my_str_isprintable(char *);
int	my_showstr(char *);
int	my_showmem(char *, int);
char	*my_strcat(char *, char *);
char	*my_strncat(char *, char *, int);
int	my_strlcat(char *, char *, int);
int	my_countnb_b(int, int);
int	my_get_el(char, char *);
int	my_string_to_int(char *, int);
char	*get_begin(char *, int *);
int	my_check(char *);
int	my_pow(int, int);
int	my_count_nb(int);
void	my_loop(int, int, int);
int	my_printnbr(long, char *, int);
int	my_atoi(char *);
int	my_isnum(char);
void	my_putchar2(char);
void	my_putstr2(char *);
long	my_round(double);
int	my_getnbenvdata(char **);
int	my_countpaths(char *);
void	my_setpathtrunc(char *);
char	**my_splitpaths(char *);
char	**my_getpath(char **);
void	my_freepath(char **);
char	*my_strstick(char *, char *);
char	**my_strtok(char *, char *);
void	my_tokcut(char *, char *);
int	cnt_tok(char *, char *);
int	is_del(char, char *);
int	my_count_strintab(char **);
char	**my_strtabdup(char **);
void	free_strtab(char **);
void	my_putstrtab(char **);
int	my_strtabsearch(char **, char *);
char	*get_next_line(t_fle *);
char	*gnl_querat_g(const int);
int	tab_len(char **);
char	*my_strncpy2(char *, char *, int);
void   	*my_memcpy(void *, void *, size_t);
void   	*my_ptrdup(void *, size_t);
int    	my_ptrcmp(void *, void *, size_t);
void   	nflip_endian(void *, size_t);
int	my_perror(char*);
void    do_output(t_tre *, t_lid *);
int	tab_length(char **);

#endif /* !MY_H_ */
