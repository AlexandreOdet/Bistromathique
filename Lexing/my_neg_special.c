/*
** my_neg_special.c for my_neg_special in /home/thibaut.lopez/Piscine-C-eval_expr/Lexing
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Oct 30 10:34:14 2013 Thibaut Lopez
** Last update Sat Nov  9 16:17:30 2013 
*/

#include "../bistromathique.h"

void	my_neg_changement(t_chain **t, t_chain **sort, t_chain **pile, t_base tmp)
{
  int	chr;
  char	*operator;
  char	*base;

  operator = xmalloc(2 * sizeof(char));
  chr = my_strchr(tmp.op, (*t)->str[0]);
  operator[0] = tmp.op[chr];
  operator[1] = 0;
  base = xmalloc(2 * sizeof(char));
  base[0] = tmp.base[0];
  base[1] = 0;
  my_put_in_list(sort, base);
  if ((*t)->next->str[0] != tmp.op[0])
    {
      my_put_in_list(sort, (*t)->next->str);
      my_put_in_list(sort, operator); 
      *t = (*t)->next;
    }
  else
    my_put_in_list(pile, operator);
}

int	my_neg_special(t_chain **t, t_chain **sort, t_chain **pile, t_base tmp)
{
  if ((*t)->prev == NULL)
    {
      my_neg_changement(t, sort, pile, tmp);
      return (5);
    }
  else if (my_strchr(tmp.op, (*t)->prev->str[0]) != -1 &&
	   my_strchr(tmp.op, (*t)->prev->str[0]) != 1)
    {
      my_neg_changement(t, sort, pile, tmp);
      return (5);
    }
  else
    return (1);
}
