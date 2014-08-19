/*
** eval_expr.c for eval_expr in /home/odet_a/rendu/Bistro
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Mon Nov  4 16:23:30 2013 
** Last update Sat Nov  9 18:10:04 2013 
*/

#include <stdio.h>
#include <stdlib.h>
#include "bistromathique.h"

void	my_show_list(t_chain *begin)
{
  t_chain	*tmp;

  tmp = begin;
  while (tmp != NULL)
    {
      my_putstr(tmp->str);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

int	case_plus_minus(t_chain **ptr ,char *op)
{
  if ((*ptr)->next == NULL)
    my_error(1);
  if (my_strchr(op, (*ptr)->next->str[0]) > 3)
    my_error(1);
  if ((*ptr)->next->str[0] == op[2] || (*ptr)->next->str[0] == op[3])
    {
      if ((*ptr)->str[0] == op[2])
	{
	  (*ptr)->str[0] = (*ptr)->next->str[0];
	  my_rm_elem_next(ptr);
	  return (case_plus_minus(ptr, op));
	}
      else if ((*ptr)->str[0] == op[3])
	{
	  if ((*ptr)->next->str[0] == op[3])
	    (*ptr)->str[0] = op[2];
	  else
	    (*ptr)->str[0] = op[3];
	  my_rm_elem_next(ptr);
	  return (case_plus_minus(ptr, op));
	}
    }
  return (0);
}

void	case_ops(t_chain **ptr, char *op)
{
  if (my_strchr(op, (*ptr)->str[0]) > 3 &&
      ((*ptr)->next == NULL || (*ptr)->prev == NULL))
    my_error(1);
  else if (my_strchr(op, (*ptr)->str[0]) > 3 &&
		     my_strchr(op, (*ptr)->next->str[0]) > 3)
    my_error(1);
  if (my_strchr(op, (*ptr)->str[0]) == 0 &&
      my_strchr(op, (*ptr)->next->str[0]) > 3)
    my_error(1);
  if (my_strchr(op, (*ptr)->str[0]) == 1 && (*ptr)->next != NULL)
    {
      if (my_strchr(op, (*ptr)->next->str[0]) < 1)
	my_error(1);
    }
  if (my_strchr(op, (*ptr)->str[0]) == 2 || my_strchr(op, (*ptr)->str[0]) == 3)
    case_plus_minus(ptr, op);
}

void	case_nbr(t_chain **ptr, char *base, char *op)
{
  int	i;

  while ((*ptr)->str[0] == base[0] && my_strlen((*ptr)->str) != 1)
    {
      i = 0;
      while ((*ptr)->str[i + 1])
	{
	  (*ptr)->str[i] = (*ptr)->str[i + 1];
	  i++;
	}
      (*ptr)->str[i] = 0;
    }
  if ((*ptr)->next != NULL)
    {
      if (my_strchr(op, (*ptr)->next->str[0]) == 0)
	my_error(1);
    }
}

void	check_chain(t_chain **ptr, char *base, char *ops)
{
  t_chain	*tmp;

  tmp = *ptr;
  while (*ptr != NULL)
    {
      if (my_strchr(base, (*ptr)->str[0]) != -1)
	case_nbr(ptr, base, ops);
      else if (my_strchr(ops, (*ptr)->str[0]) != -1)
	case_ops(ptr, ops);
      *ptr = (*ptr)->next;
    }
  *ptr = tmp;
  if (my_list_size(*ptr) < 3)
    my_error(1);
}

char	*eval_expr(char *base, char *ops, char *expr, unsigned int size)
{
  t_chain	*ptr;
  t_base	tmp;
  char		*str;
  int		i;

  ptr = xmalloc(sizeof(t_chain));
  tmp.op = ops;
  tmp.base = base;
  str = my_strndup(expr, size);
  i = parentheses(str, ops);
  if (i == 1)
    exit(8);
  ptr = my_str_to_chain(str, ops);
  check_chain(&ptr, base, ops);
  ptr = my_npi(ptr, tmp);
  if (my_list_size(ptr) < 3)
    my_error(1);
  return (infinite_doop(ptr, base, ops));
}
