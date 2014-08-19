/*
** my_npi.c for my_npi in /home/thibaut.lopez/Piscine-C-eval_expr/Lexing
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Mon Oct 28 12:07:33 2013 Thibaut Lopez
** Last update Sat Nov  9 16:31:08 2013 
*/

#include "../bistromathique.h"
#include <stdio.h>

t_chain	*my_get_first_chain(t_chain *sort)
{
  t_chain	*tmp;
 
  tmp = sort;
  if (sort == NULL)
    return (sort);
  while (tmp->prev != NULL)
      tmp = tmp->prev;
  return (tmp);
}

void	my_unstack(t_chain **src, t_chain **dest, char *op)
{
  if ((*src) != NULL)
    {
      while (((*src)->prev != NULL) && ((*src)->str[0] != op[0]))
	{
	  my_put_in_list(dest, (*src)->str);
	  my_rm_current_elem(src);
	}
      if ((*src)->str[0] != op[0])
	{
	  my_put_in_list(dest, (*src)->str);
	  my_rm_current_elem(src);
	}
      else
	my_rm_current_elem(src);
    }
}

int	my_put_in_list(t_chain **list, char *str)
{
  t_chain	*elem;

  elem = xmalloc(sizeof(*elem));
  elem->str = str;
  elem->prev = *list;
  elem->next = NULL;
  if (*list != NULL)
    (*list)->next = elem;
  *list = elem;
  return (0);
}

void	my_stack_op(t_chain **t, t_chain **sort, t_chain **pile, t_base tmp)
{
  int		prior;

  prior = 2;
  if ((*t)->str[0] == tmp.op[3] || (*t)->str[0] == tmp.op[2])
    prior = my_neg_special(t, sort, pile, tmp);
  if (*pile != NULL)
    {
      if ((*pile)->str[0] == tmp.op[2] || (*pile)->str[0] == tmp.op[3])
	prior--;
      else
	prior = prior - 2;
      if (prior < 3 && (prior > 0 || (*pile)->str[0] == tmp.op[0]))
	my_put_in_list(pile, (*t)->str);
      else if (prior <= 0 && (*pile)->str[0] != tmp.op[0])
	{
	  my_put_in_list(sort, (*pile)->str);
	  my_rm_current_elem(pile);
	  my_put_in_list(pile, (*t)->str);
	}
    }
  else if (prior < 3)
    my_put_in_list(pile, (*t)->str);
}

t_chain	*my_npi(t_chain *t, t_base tmp)
{
  t_chain	*sort;
  t_chain	*pile;
  t_chain	*first;

  sort = NULL;
  pile = NULL;
  first = NULL;
  while (t != NULL)
    {
      if (t->str[0] == tmp.op[2] || t->str[0] == tmp.op[3] ||
	  t->str[0] == tmp.op[4] || t->str[0] == tmp.op[5] || t->str[0] == tmp.op[6])
	my_stack_op(&t, &sort, &pile, tmp);
      else if (t->str[0] == tmp.op[0])
	my_put_in_list(&pile, t->str);
      else if (t->str[0] == tmp.op[1])
	my_unstack(&pile, &sort, tmp.op);
      else
	my_put_in_list(&sort, t->str);
      if (first == NULL)
	first = my_get_first_chain(sort);
      t = t->next;
    }
  while (pile != NULL)
    my_unstack(&pile, &sort, tmp.op);
  return (first);
}
