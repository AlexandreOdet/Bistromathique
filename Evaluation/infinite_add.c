/*
** infinite_add.c for infinite_add in /home/odet_a
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Tue Oct 29 14:04:30 2013 
** Last update Sat Nov  9 17:54:23 2013 
*/

#include "../bistromathique.h"

char	*my_loop(char *new, t_struct *t, int i, char *base)
{
  int	j;

  j = 0;
  while (new[i + j])
    {
      t->calc = my_strchr(base, new[i + j]) + t->ret;
      t->ret = t->calc / my_strlen(base);
      t->res[i + j] = base[t->calc % my_strlen(base)];
      j++;
    }
  if (t->ret == 1)
    {
      t->res[i + j] = base[1];
      j++;
    }
  t->res[i + j] = 0;
  return (t->res);
}

char	*my_add(char *nb1, char *nb2, char *base)
{
  t_struct	*t;
  int	i;

  t = xmalloc(sizeof(t_struct));
  i = 0;
  if ((t->res = generate_result_add(nb1, nb2)) == NULL)
    return (NULL);
  t->new1 = my_revstr(my_strdup(nb1));
  t->new2 = my_revstr(my_strdup(nb2));
  t->ret = 0;
  while (t->new1[i] != '\0' && t->new2[i] != '\0')
    {
      t->calc = my_strchr(base, t->new1[i]) + my_strchr(base, t->new2[i]) + t->ret;
      t->ret = t->calc / my_strlen(base);
      t->res[i] = base[t->calc % my_strlen(base)];
      i++;
    }
  if (my_strlen(t->new1) >= my_strlen(t->new2))
    t->res = my_loop(t->new1, t, i, base);
  else
    t->res = my_loop(t->new2, t, i, base);
  my_revstr(t->res);
  return (t->res);
}

char	*infinite_add(char *nb1, char *nb2, char *base, char *op)
{
  if (nb1[0] == op[3] && nb2[0] == op[3])
    return (inf_back_abs(my_add(inf_abs(nb1, op), inf_abs(nb2, op), base), op));
  else if (nb1[0] == op[3])
    return (infinite_sub(nb2, inf_abs(nb1, op), base, op));
  else if (nb2[0] == op[3])
    return (infinite_sub(nb1, inf_abs(nb2, op), base, op));
  else
    return (my_add(nb1, nb2, base));
}

char	*generate_result_add(char *nb1, char *nb2)
{
  char	*result;

  if (my_strlen(nb1) > my_strlen(nb2))
    result = xmalloc(sizeof(char) * (my_strlen(nb1) + 2));
  else
    result = xmalloc(sizeof(char) * (my_strlen(nb2) + 2));
  return (result);
}
