/*
** infinite_sub.c for infinite_sub in /home/odet_a
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Wed Oct 30 15:14:30 2013 
** Last update Sat Nov  9 17:21:07 2013 
*/

#include "../bistromathique.h"

char	*my_sub_loop(t_struct *t, int i, char *base)
{
  int	j;
  int	k;

  j = 0;
  k = 1;
  while (t->new1[i + j])
    {
      t->calc = my_strlen(base) + my_strchr(base, t->new1[i + j]) - t->ret;
      t->ret = CONV(t->calc / my_strlen(base));
      t->res[i + j] = base[t->calc % my_strlen(base)];
      j++;
    }
  while (t->res[i + j - k] == base[0] && i + j - k != 0)
    t->res[i + j - k++] = 0;
  return (t->res);
}

char	*my_sub(char *nb1, char *nb2, char *base)
{
  t_struct	*t;
  int	i;

  t = xmalloc(sizeof(t_struct));
  i = 0;
  t->res = generate_result_sub(nb1, nb2);
  t->new1 = my_revstr(my_strdup(nb1));
  t->new2 = my_revstr(my_strdup(nb2));
  t->ret = 0;
  while (t->new1[i] != '\0' && t->new2[i] != '\0')
    {
      t->calc = my_strlen(base) + my_strchr(base,
					      t->new1[i]) - my_strchr(base, t->new2[i]) - t->ret;
      t->ret = CONV(t->calc / my_strlen(base));
      t->res[i] = base[t->calc % my_strlen(base)];
      i++;
    }
  t->res = my_sub_loop(t, i, base);
  return (t->res);
}

char	*infinite_sub(char *nb1, char *nb2, char *base, char *op)
{
  char	*result;
  int	len;

  len = 0;
  result = generate_result_sub(nb1, nb2);
  if (nb1[0] == op[3] && nb2[0] == op[3])
      return (infinite_sub(inf_abs(nb2, op), inf_abs(nb1, op), base, op));
  else if (nb2[0] == op[3])
    return (infinite_add(nb1, inf_abs(nb2, op), base, op));
  else if (nb1[0] == op[3])
    return (infinite_add(nb1, inf_back_abs(nb2, op), base, op));
  else if (my_compare_int(nb1, nb2, base) >= 0)
      result = my_sub(nb1, nb2, base);
  else
    {
      result = my_sub(nb2, nb1, base);
      len = my_strlen(result);
      result[len++] = op[3];
      result[len] = 0;
    }
  my_revstr(result);
  return (result);
}

char	*generate_result_sub(char *nb1, char *nb2)
{
  char	*result;

  if (my_strlen(nb1) > my_strlen(nb2))
    result = xmalloc(sizeof(char) * (my_strlen(nb1) + 2));
  else
    result = xmalloc(sizeof(char) * (my_strlen(nb2) + 2));
  return (result);
}
