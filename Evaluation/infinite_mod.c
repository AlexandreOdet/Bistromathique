/*
** infinite_mod.c for infinite_mod in /home/odet_a
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Fri Nov  1 11:24:13 2013 
** Last update Sat Nov  9 18:36:48 2013 
*/

#include "../bistromathique.h"

char	*infinite_mod(char *nb1, char *nb2, char *base, char *op)
{
  char	*result;
  char	*nb3;
  char	*nb4;

  if (nb2[0] == base[0])
    my_error(3);
  else if (nb2[0] == op[3] && nb2[1] == base[0])
    my_error(3);
  nb3 = my_strdup(nb2);
  nb4 = my_strdup(nb1);
  result = xmalloc(sizeof(char) * my_strlen(nb2));
  result = infinite_div(nb1, nb2, base, op);
  result = infinite_mul(nb3, result, base, op);
  result = infinite_sub(nb4, result, base, op);
  return (result);
}
