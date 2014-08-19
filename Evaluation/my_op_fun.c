/*
** my_compare_int.c for my_compare_int in /home/odet_a
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Wed Oct 30 17:07:17 2013 
** Last update Sat Nov  9 17:23:33 2013 
*/

#include "../bistromathique.h"

int	my_strchr(char *str, char src)
{
  int	i;

  i = 0;
  while (str[i] != src && str[i] != 0)
    i++;
  if (str[i] == 0)
    return (-1);
  else
    return (i);
}

int	my_compare_int(char *s1, char *s2, char *base)
{
  int	i;

  i = 0;
  if (my_strlen(s1) > my_strlen(s2))
    return (1);
  else if (my_strlen(s1) < my_strlen(s2))
    return (-1);
  else
    {
      while (my_strchr(base, s1[i]) == my_strchr(base, s2[i]) && s1[i] != 0)
	i++;
      if (my_strchr(base, s1[i]) > my_strchr(base, s2[i]))
	return (1);
      else if (my_strchr(base, s1[i]) < my_strchr(base, s2[i]))
	return (-1);
      else
	return (0);
    }
}

char	*inf_abs(char *str, char *op)
{
  int	i;

  i = 1;
  if (str[0] == op[3])
    {
      while (str[i])
	{
	  str[i - 1] = str[i];
	  i++;
	}
      str[i - 1] = 0;
    }
  return (str);
}

char	*inf_back_abs(char *str, char *op)
{
  int	i;
  char	*str_new;

  str_new = xmalloc(my_strlen(str) + 2);
  i = 1;
  if (str[0] != op[3])
    {
      str_new[0] = op[3];
      while (str[i - 1])
	{
	  str_new[i] = str[i - 1];
	  i++;
	}
      str_new[i] = 0;
    }
  else
    str_new = str;
  return (str_new);
}
