/*
** infinite_div.c for infinite_div in /home/odet_a
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Thu Oct 31 15:07:57 2013 
** Last update Sat Nov  9 18:39:39 2013 
*/

#include "../bistromathique.h"

char	*generate_result_div(char *nb1, char *nb2)
{
  char	*result;

  result = xmalloc(sizeof(char) * (my_strlen(nb1) - (my_strlen(nb2))) + 1);
  return (result);
}

char	*my_div2(char *nb1, char *nb2, t_struct *t, char *base)
{
  int	j;
  int	k;
  int	len;
  char	*result;

  k = 0;
  result = generate_result_div(nb1, nb2);
  while (nb1[t->i])
    { 
      j = 0;
      while (my_compare_int(t->new1, nb2, base) >= 0)
	{
	  t->new1 = my_revstr(my_sub(t->new1, nb2, base));
	  j++;
	}
      result[k++] = base[j];
      if (t->new1[0] == base[0])
	len = 0;
      else
	len = my_strlen(t->new1);
      t->new1[len++] = nb1[++t->i];
      t->new1[len] = 0;
    }
  return (result);
}

char	*my_div(char *nb1, char *nb2, char *base)
{
  t_struct	*t;
  char		*stock;
 
  t = xmalloc(sizeof(t_struct));
  stock = xmalloc(2 * sizeof(char));
  stock[0] = base[0];
  stock[1] = 0;
  t->i = 0;
  t->res = generate_result_div(nb1, nb2);
  t->new1 = xmalloc(sizeof(char) * (my_strlen(nb2) + 1));
  t->new1[t->i] = nb1[t->i];
  if (my_compare_int(nb1, nb2, base) < 0)
    return (stock);
  while (my_compare_int(t->new1, nb2, base) < 0)
    {
      t->i++;
      t->new1[t->i] = nb1[t->i];
      t->new1[t->i + 1] = 0;
    }
  t->res = my_div2(nb1, nb2, t, base);
  return (t->res);
}

char	*infinite_div(char *nb1, char *nb2, char *base, char *op)
{
  if (nb2[0] == base[0])
    my_error(2);
  else if (nb2[0] == op[3] && nb2[1] == base[0])
    my_error(2);
  if ((nb1[0] == op[3] && nb2[0] == op[3]) ||
      (nb1[0] != op[3] && nb2[0] != op[3]))
    return (my_div(inf_abs(nb1, op), inf_abs(nb2, op), base));
  else
    return (inf_back_abs(my_div(inf_abs(nb1, op), inf_abs(nb2, op), base), op));
}
