/*
** infinite_mul.c for infinite_mul in /home/odet_a
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Wed Oct 30 17:22:05 2013 
** Last update Fri Nov  8 15:12:38 2013 
*/

#include "../bistromathique.h"

char	*generate_result_mul(char *nb1, char *nb2)
{
  char	*result;

  result = xmalloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2)));
  return (result);
}

char	*my_rec_mul(t_struct *t, int ret, int i, char *base)
{
  int	j;
  int	k;
  char	*result;

  j = 0;
  k = 0;
  result = generate_result_mul(t->new1, t->new2);
  while (i != k)
    result[k++] = base[0];
  while (t->new1[j])
    {
      t->calc = my_strchr(base, t->new1[j]) * my_strchr(base, t->new2[i]) + ret;
      ret = t->calc / my_strlen(base);
      result[k + j++] = base[t->calc % my_strlen(base)];
    }
  if (ret != 0)
    result[k + j++] = base[ret];
  result[j + k] = 0;
  my_revstr(result);
  if (t->new2[++i])
    return (my_add(result, my_rec_mul(t, 0, i, base), base));
  else
    return (result);
}

char	*my_mul(char *nb1, char *nb2, char *base)
{
  t_struct	*t;
  int	i;

  t = xmalloc(sizeof(t_struct));
  i = 0;
  t->res = generate_result_mul(nb1, nb2);
  if (nb1[0] == base[0] || nb2[0] == base[0])
    {
      t->res[0] = base[0];
      t->res[1] = 0;
      return (t->res);
    }
  t->new1 = my_revstr(my_strdup(nb1));
  t->new2 = my_revstr(my_strdup(nb2));
  t->res = my_rec_mul(t, 0, i, base);
  return (t->res);
}


char	*infinite_mul(char *nb1, char *nb2, char *base, char *op)
{
  if ((nb1[0] == op[3] && nb2[0] == op[3]) ||
      (nb1[0] != op[3] && nb2[0] != op[3]))
    return (my_mul(inf_abs(nb1, op), inf_abs(nb2, op), base));
  else
    return (inf_back_abs(my_mul(inf_abs(nb1, op), inf_abs(nb2, op), base), op));
}
