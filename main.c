/*
** main.c for bistromathique 
** 
** Made by Charlie Root
** Login   <rn@epita.fr>
** 
** Started on  Tue Oct 23 11:45:05 2001 Charlie Root
** Last update Sat Nov  9 18:00:19 2013 
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromathique.h"
#include <stdio.h>

static void	check_base(char *base);
static void	check_ops(char *ops);
static char*	get_expr(int sze);
static void	check_expr(char *str, char *base, char *ops);

int		main(int ac, char **av)
{
  char		*expr;
  unsigned int	size;

  if (ac != 4)
    {
      my_putstr("Usage : ");
      my_putstr(av[0]);
      my_putstr(" base ops\"()+-*/%\" exp_len\n");
      exit(1);
    }
  check_base(av[1]);
  check_ops(av[2]);
  size = my_getnbr(av[3]);
  expr = get_expr(size);
  check_expr(expr, av[1], av[2]);
  my_putstr(eval_expr(av[1], av[2], expr, size));
  my_putchar('\n');
  return (0);
}

static void	check_expr(char *str, char *base, char *ops)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (my_strchr(base, str[i]) == -1 && my_strchr(ops, str[i]) == -1)
	my_error(1);
      i++;
    }
}

static void	check_base(char *b)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlen(b) - 1;
  if (my_strlen(b) < 2)
    {
      my_putstr("Bad base\n");
      exit(1);
    }
  while (j)
    {
      if (b[i] == b[j])
	{
	  my_putstr("Bad base\n");
	  exit(1);
	}
      i++;
      if (i == j)
	{
	  i = 0;
	  j--;
	}
    }
}

static char	*get_expr(int size)
{
  char	*expr;
  
  if (size <= 0)
    {
      my_putstr("Bad expr len\n");
      exit(2);
    }
  expr = xmalloc(size + 1);
  if (expr == 0)
    {
      my_putstr("could not alloc\n");
      exit(3);
    }
  if (read(0, expr, size) > size)
    {
      my_putstr("could not read\n");
      exit(4);
    }
  expr[size] = 0;
  return (expr);
}

static void	check_ops(char *ops)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlen(ops) - 1;
  if (my_strlen(ops) != 7)
    {
      my_putstr("Bad ops\n");
      exit(5);
    }
  while (j)
    {
      if (ops[i] == ops[j])
	{
	  my_putstr("Bad ops\n");
	  exit(5);
	}
      i++;
      if (i == j)
	{
	  i = 0;
	  j--;
	}
    }
}
